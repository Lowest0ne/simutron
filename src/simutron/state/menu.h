#ifndef SIMUTRON_STATE_MENU_H
#define SIMUTRON_STATE_MENU_H

#include "state.h"

#include <gtkmm/button.h>

namespace Gui
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
