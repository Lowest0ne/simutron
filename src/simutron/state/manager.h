#ifndef SIMUTRON_STATE_MANAGER_H
#define SIMUTRON_STATE_MANAGER_H

#include <stack>

namespace Simutron
{
  class App;


  namespace State
  {
    class State;

    class Manager
    {
      private:
      std::stack< State* > m_states;

      public:
      Manager( App& );
      virtual ~Manager( void );

      void change( State& );
      void   push( State& );
      void    pop( void   );
    };
  }
}

#endif
