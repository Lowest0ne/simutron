#include "play.h"
#include "simutron/simutron_app.h"

namespace Simutron
{
  namespace State
  {
    Play::Play( App& app )
      : State( app )
    {
      app.statusBar().push( "Welcome to the game" );
    }

    Play::~Play( void )
    {
    }

    Play& Play::instance( App& app )
    {
      static Play play( app );
      return play;
    }
  }
}
