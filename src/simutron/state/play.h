#ifndef SIMUTRON_STATE_PLAY_H
#define SIMUTRON_STATE_PLAY_H

#include "state.h"

namespace Simutron
{
  class App;

  namespace State
  {

    class Manager;

    class Play : public State
    {
      private:
      Play( App&, Manager&  );
      virtual ~Play( void );

      public:
      static Play& instance( App&, Manager& );

      void init( void );
      void quit( void );
    };
  }
}

#endif

