#ifndef SIMUTRON_STATE_MENU_H
#define SIMUTRON_STATE_MENU_H

#include "state.h"

#include <gtkmm/button.h>
#include <gtkmm/menuitem.h>
#include <gtkmm/menu.h>

namespace App
{
  class App;

  namespace State
  {
    class Manager;

    /**
    * @class Menu
    * @brief The main menu state controller
    */
    class Menu : public State
    {
      private:
      Gtk::Button m_button; // this should be a "play" button

      Gtk::MenuItem m_menu; // the menu's menu bar
      Gtk::Menu item;       // menu's go into menu items

      Menu( App&, Manager& );
      virtual ~Menu( void );

      protected:
      /**
      * @fn    void on_button( void )
      * @brief A proof of concept action, switches Manager to the Play state
      */
      void on_button( void );

      public:
      /**
      * @fn     static Menu& instance( App&, Manager& )
      * @return The one and only menu instance
      */
      static Menu& instance( App&, Manager& );

      void init( void );
      void quit( void );
    };
  }
}

#endif
