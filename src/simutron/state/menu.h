#ifndef SIMUTRON_STATE_MENU_H
#define SIMUTRON_STATE_MENU_H

#include "state.h"
#include <gtkmm/builder.h>

namespace Gtk
{
  class Box;
}

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

      Menu( App&, Manager& );
      virtual ~Menu( void );

      Glib::RefPtr< Gtk::Builder > m_builder;
      Gtk::Box *m_box;

      protected:
      /**
      * @fn    void newCity( void )
      * @brief Start a game of simutron with new Simutron::City
      */
      void newCity( void );

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
