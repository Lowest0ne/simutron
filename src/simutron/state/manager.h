#ifndef SIMUTRON_STATE_MANAGER_H
#define SIMUTRON_STATE_MANAGER_H

#include <stack>

namespace App
{
  class App;

  namespace State
  {
    class State;

    /**
    * @class Manager
    * @brief Provide a fluid way to move between Simutron states
    * @note  It is undecided if this class is a good idea.
    *        On the one hand, it separates concerns from the App
    *        On the other, the two seem to be always be used together
    */
    class Manager
    {
      private:
      std::stack< State* > m_states;

      public:
      /**
      * @fn    Manager( App& app )
      * @param app The App reference that this belongs to.
      */
      Manager( App& );
      virtual ~Manager( void );

      /**
      * @fn    void change( State& state )
      * @brief Switch to a new State, removing the current one
      * @param state The new State
      */
      void change( State& );
      /**
      * @fn    void push( State& state )
      * @brief Switch to a new State, the current State is preserved
      * @param state The new State
      */
      void   push( State& );
      /**
      * @fn    void pop( void )
      * @brief Remove the current State, initializing a previous State
      */
      void pop( void );
    };
  }
}

#endif
