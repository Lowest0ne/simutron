#include "play.h"
#include "manager.h"
#include "menu.h"

#include "simutron/simutron_app.h"

namespace App
{
  namespace State
  {
    Play::Play( App& app, Manager& manager, const Simutron::City& city )
      : State( app, manager )
      , m_city( city )
      , m_city_view( m_city )
    {
      m_menu.add( "File", "Main Menu", sigc::mem_fun( *this, &Play::mainMenu ));
      m_menu.add( "File", "Quit", sigc::mem_fun( m_app, &App::quit ) );
      m_app.appendMenu( m_menu );

      m_app.frame().add( m_city_view.layout() );

    }

    Play::~Play( void )
    {
    }

    Play& Play::instance( App& app, Manager& manager, const Simutron::City& city )
    {
      static Play play( app, manager, city );
      return play;
    }

    void Play::init( void )
    {
      m_app.statusBar().push( "Welcome to: " + m_city.name() );
      m_menu.show();
      m_city_view.show();
    }

    void Play::quit( void )
    {
      m_menu.hide();
      m_city_view.hide();
    }

    void Play::mainMenu( void )
    {
      m_manager.change( Menu::instance( m_app, m_manager ) );
    }

  }
}
