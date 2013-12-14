#ifndef SIMUTRON_GUI_MENU_LABEL_H
#define SIMUTRON_GUI_MENU_LABEL_H

#include <gtkmm/menu.h>
#include <gtkmm/menuitem.h>

#include <string>

namespace Gui
{
  /**
  * @class MenuLabel
  * @brief Gtk::MenuBars need Gtk::MenuItems, which need to be paired
  *        with a Gtk::Menu to be on the top of the MenuBar...
  */
  struct MenuLabel
  {
    Gtk::MenuItem label; //!< The title of the menu: File, About, etc
    Gtk::Menu      menu; //!< The container to hold child items

    /**
    * @fn     MenuLabel( const std::string& label )
    */
    MenuLabel( const std::string& );
    virtual ~MenuLabel( void );

    /**
    * @fn    void show( void )
    * @brief Show the widgets in this struct
    */
    void show( void );
    /**
    * @fn    void hide( void )
    * @brief Hide the widgets in this struct
    */
    void hide( void );
  };
}
#endif

