#include "play.h"
#include "manager.h"
#include "menu.h"

#include "simutron/simutron_app.h"

namespace App
{
  namespace State
  {
    Play::Play( App& app, Manager& manager )
      : State( app, manager )
    {
      m_menu.add( "File", "Main Menu", sigc::mem_fun( *this, &Play::mainMenu ));
      m_menu.add( "File", "Quit", sigc::mem_fun( m_app, &App::quit ) );
      m_app.appendMenu( m_menu );
    }

    Play::~Play( void )
    {
    }

    Play& Play::instance( App& app, Manager& manager )
    {
      static Play play( app, manager );
      return play;
    }

    void Play::init( void )
    {
      m_app.statusBar().push( "Welcome to the game" );
      m_menu.show();
    }

    void Play::quit( void )
    {
      m_menu.hide();
    }

    void Play::mainMenu( void )
    {
      m_manager.change( Menu::instance( m_app, m_manager ) );
    }

  }
}
