#ifndef SIMUTRON_STATE_PLAY_H
#define SIMUTRON_STATE_PLAY_H

#include "state.h"
#include "libsimutron/city.h"

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
      Play( App&, Manager&, const Simutron::City&  );
      virtual ~Play( void );

      Simutron::City m_city;

      protected:
      /**
      * @fn    void mainMenu( void )
      * @brief Return the manager to the Menu state
      */
      void mainMenu( void );

      public:
      /**
      * @fn     static Play& instance( App&, Manager&, City& )
      * @brief  Start playing a city
      * @return The one and only play instance
      */
      static Play& instance( App&, Manager&, const Simutron::City&);

      void init( void );
      void quit( void );
    };
  }
}

#endif

