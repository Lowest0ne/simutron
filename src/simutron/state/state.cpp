#include "state.h"

namespace Simutron
{
  namespace State
  {
    State::State( App& app, Manager& manager )
      : m_app( app )
      , m_manager( manager )
    {
    }

    State::~State( void )
    {
    }
  }
}
