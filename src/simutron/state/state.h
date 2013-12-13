#ifndef SIMUTRON_STATE_H
#define SIMUTRON_STATE_H

namespace Simutron
{
  class App;

  namespace State
  {
    class Manager;

    class State
    {
      protected:
      App&        m_app;
      Manager& m_manager;

      public:
      State( App&, Manager& );
      virtual ~State( void );

      virtual void init( void ) = 0;
      virtual void quit( void ) = 0;
    };
  }
}

#endif
