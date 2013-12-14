#ifndef SIMUTRON_STATE_H
#define SIMUTRON_STATE_H


namespace Gui
{

  class App;
  /**
  * @namespace Gui::State
  * @brief     Provide a namespace for all things state related
  */
  namespace State
  {
    class Manager;

    /**
    * @class State
    * @brief The base class for all states
    * @note  Derived classes are expected to be final, as well as singletons.
    * @note  It is undecided whether its member variables should be static
    *        As this would require less passing around references.
    * @note  It is undecided whether states should include gui elements,
    *        or contain instances of views.  Currently, the idea is that states
    *        will contain instances of gui elements needed to change states,
    *        but then contain instances of views that are non state related.
    *        For example, a City's budget has no ability to change state, and
    *        is therefore not within the state namespace.
    */
    class State
    {
      protected:
      App&         m_app; //!< Provide information about base gui elements
      Manager& m_manager; //!< Provide ability to change state

      public:
      /**
      * @fn State( App& app, Manager& manager )
      * @brief Construct a new state
      * @param app The App this state needs
      * @param manager The manager this state belongs to
      * @note  States need the App because this is how access to the main
      *        window's elements are accessed.
      */
      State( App&, Manager& );
      virtual ~State( void );

      /**
      * @fn    virtual void init( void ) = 0
      * @brief This method is called by the Manager when it changes state.
      *        It is a place to do things like show widgets
      */
      virtual void init( void ) = 0;
      /**
      * @fn    virtual void quit( void ) = 0
      * @brief This method is called by the Manager when it changes state.
      *        It is a place to do things like hide widgets
      */
      virtual void quit( void ) = 0;
    };
  }
}

#endif
