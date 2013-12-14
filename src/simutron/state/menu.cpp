#include "menu.h"
#include "manager.h"
#include "play.h"

#include "simutron/simutron_app.h"

#include <gtkmm.h>

#include "libsimutron/city.h"

namespace App
{
  namespace State
  {
    Menu::Menu( App& app, Manager& manager )
      : State( app, manager )
    {
      m_menu.add( "File" );
      m_menu.add( "Options" );
      m_menu.add( "Help" );
      m_menu.add( "About" );

      m_menu.add( "File", "New", sigc::mem_fun( *this, &Menu::newCity ) );
      m_menu.add( "File", "Quit", sigc::mem_fun( m_app, &App::quit ) );

      m_app.appendMenu( m_menu );
    }

    Menu::~Menu( void )
    {
    }

    Menu& Menu::instance( App& app, Manager& manager )
    {
      static Menu menu( app, manager );
      return menu;
    }

    void Menu::newCity( void )
    {
      Simutron::City new_city( "City name Hardcoded" );
      m_manager.change( Play::instance( m_app, m_manager, new_city ) );
    }

    void Menu::init( void )
    {
      m_app.statusBar().push( "Welcome to Simutron" );
      m_menu.show();
    }

    void Menu::quit( void )
    {
      m_menu.hide();
    }
  }

}
