#include "delayedresponse.h"
#include "protocole.h"
#include <QTimer>
#include <QDebug>

DelayedResponse::DelayedResponse(JsonClient * client, const QtJson::JsonObject & command, int interval, int timerOut) :
                                 QObject(client),
                                 m_client(client),
                                 m_hasResponded(false),
                                 m_nbCall(0)
{
    Q_ASSERT(client);
    m_timer.setInterval(interval);
    connect(&m_timer, SIGNAL(timeout()), this, SLOT(timerCall()));

    QTimer::singleShot(timerOut, this, SLOT(onTimerOut()));
    
    m_action = command["action"].toString();
}

void DelayedResponse::start() {
    m_timer.start();
}

void DelayedResponse::timerCall() {
    if (! m_hasResponded) {
        execute(m_nbCall);
        m_nbCall += 1;
    }
}

void DelayedResponse::onTimerOut() {
    if (! m_hasResponded) {
        writeResponse(jsonClient()->createError("DelayedResponseTimeOut",
                                                QString::fromUtf8("Délai de non réponse dépassé pour %2")
                                                .arg(staticMetaObject.className())));
    }
}

void DelayedResponse::writeResponse(const QtJson::JsonObject & result) {
    m_timer.stop();
    emit aboutToWriteResponse(result);
    m_hasResponded = true;

    bool success;
    QByteArray response = QtJson::serialize(result, success);

    if (!success) {
        qDebug() << "unable to serialize result to json" << m_action;
        m_client->protocole()->close();
        return;
    }
    
    m_client->protocole()->sendMessage(response);
}
