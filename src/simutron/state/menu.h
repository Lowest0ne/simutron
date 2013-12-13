#ifndef SIMUTRON_STATE_MENU_H
#define SIMUTRON_STATE_MENU_H

#include "state.h"

#include <gtkmm/button.h>

namespace Simutron
{
  class App;

  namespace State
  {
    class Menu : public State
    {
      private:
      Gtk::Button m_button; // this should be a "play" button

      Menu( App& );
      virtual ~Menu( void );

      protected:
      void on_button( void );

      public:
      static Menu& instance( App& );
    };
  }
}

#endif
