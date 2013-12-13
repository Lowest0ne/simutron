#include "play.h"
#include "manager.h"

#include "simutron/simutron_app.h"

namespace Gui
{
  namespace State
  {
    Play::Play( App& app, Manager& manager )
      : State( app, manager )
    {
    }

    Play::~Play( void )
    {
    }

    Play& Play::instance( App& app, Manager& manager )
    {
      static Play play( app, manager );
      return play;
    }

    void Play::init( void )
    {
      m_app.statusBar().push( "Welcome to the game" );
    }

    void Play::quit( void )
    {
    }

  }
}
