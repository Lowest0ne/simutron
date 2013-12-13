#include "manager.h"
#include "menu.h"

#include "simutron/simutron_app.h"

namespace Simutron
{
  namespace State
  {
    Manager::Manager( App& app )
    {
      push( Menu::instance( app ) );
    }

    Manager::~Manager( void )
    {
    }

    void Manager::change( State& state )
    {
      pop();
      push( state );
    }

    void Manager::push( State& state )
    {
      m_states.push( &state );
    }

    void Manager::pop( void )
    {
      if ( !m_states.empty() ) m_states.pop();
    }
  }
}
