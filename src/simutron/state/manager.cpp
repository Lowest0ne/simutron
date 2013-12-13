#include "state.h"

#include "manager.h"
#include "menu.h"

#include "simutron/simutron_app.h"

namespace Gui
{
  namespace State
  {
    Manager::Manager( App& app )
    {
      push( Menu::instance( app, *this ) );
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
      m_states.top()->init();
    }

    void Manager::pop( void )
    {
      if ( !m_states.empty() )
      {
        // Release the current state
        m_states.top()->quit();
        m_states.pop();

        // Initialize the last state
        if ( !m_states.empty() )
          m_states.top()->init();
      }
    }
  }
}
