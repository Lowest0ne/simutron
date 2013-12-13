#ifndef SIMUTRON_STATE_PLAY_H
#define SIMUTRON_STATE_PLAY_H

#include "state.h"

namespace Simutron
{
  namespace State
  {
    class Play : public State
    {
      private:
      Play( App& );
      virtual ~Play( void );

      public:
      static Play& instance( App& );
    };
  }
}

#endif

