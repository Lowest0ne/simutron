#ifndef SIMUTRON_STATE_H
#define SIMUTRON_STATE_H

namespace Simutron
{
  class App;

  namespace State
  {
    class State
    {
      protected:
      App& m_app;

      public:
      State( App& );
      virtual ~State( void );
    };
  }
}

#endif
