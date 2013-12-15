#ifndef SIMUTRON_STATE_PLAY_H
#define SIMUTRON_STATE_PLAY_H

#include "state.h"
#include "libsimutron/city.h"
#include "simutron/view/city.h"

namespace App
{
  class App;

  namespace State
  {

    class Manager;

    /**
    * @class Play
    * @brief The playing state controller.
    */
    class Play : public State
    {
      private:
      Play( App&, Manager&, const Simutron::City&  );
      virtual ~Play( void );

      Simutron::City m_city;
      View::City     m_city_view;

      /**
      * @fn    void mainMenu( void )
      * @brief Return the manager to the Menu state
      */
      void mainMenu( void );

      /**
      * @fn    void loadGui( void )
      * @brief Called during construction to create Gtk elements
      */
      void loadGui( void );
      /**
      * @fn    void connectSignals( void )
      * @brief Called during construction to connect class functions with Gtk
      *        gui elements
      */
      void connectSignals( void );
      /**
      * @fn    void btnZone( void )
      * @brief Called when zone button is pressed
      */
      void btnZone( void );
      /**
      * @fn    void btnUpdate( void )
      * @brief Called when update button is pressed
      * @todo  Put the update on a timer
      */
      void btnUpdate( void );

      public:
      /**
      * @fn     static Play& instance( App&, Manager&, City& )
      * @brief  Start playing a city
      * @return The one and only play instance
      * @note   The City copy constructor is called here, it should probably
      *         be a move.  The Play state should not know how to create a city.
      */
      static Play& instance( App&, Manager&, const Simutron::City&);

      void init( void );
      void quit( void );
    };
  }
}

#endif

