#ifndef SIMUTRON_STATE_MENU_H
#define SIMUTRON_STATE_MENU_H

#include "state.h"

#include <gtkmm/button.h>
#include <gtkmm/menuitem.h>

#include "simutron/gui/menu_label.h"

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

      Gui::MenuLabel m_label; // This is a menu bar label
      Gtk::MenuItem  m_item;  // A test item for functionality

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
