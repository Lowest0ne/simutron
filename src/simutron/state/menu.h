#ifndef SIMUTRON_STATE_MENU_H
#define SIMUTRON_STATE_MENU_H

#include "state.h"

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

      protected:
      /**
      * @fn    void play( void )
      * @brief A proof of concept action, switches Manager to the Play state
      */
      void play( void );

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
