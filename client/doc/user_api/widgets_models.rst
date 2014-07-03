Widgets et autres classes pour manipuler les composants graphiques
==================================================================

.. currentmodule:: funq.models

Classe de base Widget
---------------------

Un widget est récupéré depuis la méthode :meth:`funq.client.FunqClient.widget` .

Exemple::
  
  mon_widget = self.funq.widget('mon_widget')

.. autoclass:: Widget
  
  .. automethod:: Widget.properties
  
  .. automethod:: Widget.set_properties
  
  .. automethod:: Widget.set_property
  
  .. automethod:: Widget.wait_for_properties
  
  .. automethod:: Widget.click
  
  .. automethod:: Widget.dclick
  
  .. automethod:: Widget.keyclick
  
  .. automethod:: Widget.shortcut
  
  .. automethod:: Widget.drag_n_drop
  
  .. automethod:: Widget.close
  
  .. automethod:: Widget.call_slot

Manipulation des données du framework Model/View de QT
------------------------------------------------------

Pour manipuler des item provenants de QAbstractTableModel, il faut récupérer
la vue adéquate (QAbstractItemView). L'instance retournée héritera de
:class:`AbstractItemView` et les données du modèle rattaché seront accessibles
via la méthode :meth:`AbstractItemView.model_items`.

Exemple::
  
  view = self.funq.widget('ma_tableview')
  assert isinstance(view, AbstractItemView)
  
  model_items = view.model_items()
  item = model_items.item_by_named_path(['item1'])
  
  item.dclick()


.. inheritance-diagram:: AbstractItemView

.. autoclass:: AbstractItemView
  
  .. automethod:: AbstractItemView.model_items
  
  .. automethod:: AbstractItemView.current_editor


.. autoclass:: ModelItems
  
  .. automethod:: ModelItems.iter
  
  .. automethod:: ModelItems.item_by_named_path
  
  .. automethod:: ModelItems.row_by_named_path


.. autoclass:: ModelItem
  
  .. automethod:: ModelItem.select
  
  .. automethod:: ModelItem.edit
  
  .. automethod:: ModelItem.click
  
  .. automethod:: ModelItem.dclick
  
  .. automethod:: ModelItem.is_checkable
  
  .. automethod:: ModelItem.is_checked

Manipulation des données du framework Graphics View de QT
---------------------------------------------------------

La manipulation des QGraphicsItem depuis le framework de test est assez
similiaire à la manipulation des données du framework Model/View de QT.

Il faut récupérer la vue adéquate, héritant de QGraphicsView. L'instance
python retournée sera une instance de :class:`GraphicsView` et les items
graphiques seront accessibles via la méthode :meth:`GraphicsView.gitems`.

Exemple::
  
  gview = self.funq.widget('ma_gview')
  
  gitems = gview.gitems()
  
  for item in gitems.iter():
      # faire quelque chose sur les items


.. inheritance-diagram:: GraphicsView

.. autoclass:: GraphicsView
  
  .. automethod:: GraphicsView.gitems
  
  .. automethod:: GraphicsView.dump_gitems


.. autoclass:: GItems
  
  .. automethod:: GItems.iter

.. autoclass:: GItem
  
  .. automethod:: GItem.is_qobject
  
  .. automethod:: GItem.properties
  
  .. automethod:: GItem.click
  
  .. automethod:: GItem.dclick

Autres widgets
--------------

.. inheritance-diagram:: TabBar

.. autoclass:: TabBar
  
  .. automethod:: TabBar.tab_texts
  
  .. automethod:: TabBar.set_current_tab


.. inheritance-diagram:: ComboBox

.. autoclass:: ComboBox
  
  .. automethod:: ComboBox.model_items
  
  .. automethod:: ComboBox.set_current_text