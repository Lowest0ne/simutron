#ifndef SIMUTRON_STATE_PLAY_H
#define SIMUTRON_STATE_PLAY_H

#include "state.h"

namespace App
{
  class App;

  namespace State
  {

    class Manager;

    /**
    * @class Play
    * @brief The playing state controller.
    */
    class Play : public State
    {
      private:
      Play( App&, Manager&  );
      virtual ~Play( void );

      protected:
      /**
      * @fn    void mainMenu( void )
      * @brief Return the manager to the Menu state
      */
      void mainMenu( void );

      public:
      /**
      * @fn     static Play& instance( App&, Manager& )
      * @return The one and only play instance
      */
      static Play& instance( App&, Manager& );

      void init( void );
      void quit( void );
    };
  }
}

#endif

