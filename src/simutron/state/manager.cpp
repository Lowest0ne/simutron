#include "state.h"
#include "manager.h"

#include "simutron/simutron_app.h"

namespace App
{
  namespace State
  {
    Manager::Manager( void )
    {
    }

    Manager::~Manager( void )
    {
    }

    void Manager::change( State& state )
    {
      quitCurrent();
      startState( state );
    }

    void Manager::push( State& state )
    {
      pauseCurrent();
      startState( state );
    }

    void Manager::pop( void )
    {
      quitCurrent();
      resumeState();
    }

    void Manager::quitCurrent( void )
    {
      if ( hasState() )
      {
        m_states.top()->quit();
        m_states.pop();
      }
    }

    void Manager::startState( State& state )
    {
      m_states.push( &state );
      state.init();
    }

    void Manager::pauseCurrent( void )
    {
      if ( hasState() ) m_states.top()->quit();
    }

    void Manager::resumeState( void )
    {
      if ( hasState() ) m_states.top()->init();
    }

    bool Manager::hasState( void )
    {
      return !m_states.empty();
    }
  }
}
