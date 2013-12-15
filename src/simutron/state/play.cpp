#include "play.h"
#include "manager.h"
#include "menu.h"

#include "simutron/simutron_app.h"

#include "libsimutron/zone.h"
#include "libsimutron/growable.h"

namespace App
{
  namespace State
  {
    Play::Play( App& app, Manager& manager, const Simutron::City& city )
      : State( app, manager )
      , m_city( city )
    {
      m_menu.add( "File", "Main Menu", sigc::mem_fun( *this, &Play::mainMenu ));
      m_menu.add( "File", "Quit", sigc::mem_fun( m_app, &App::quit ) );
      m_app.appendMenu( m_menu );

      m_city_view.btnConnect( "btn_zone", sigc::mem_fun( *this, &Play::btnZone ));
      m_city_view.btnConnect( "btn_update", sigc::mem_fun( *this, &Play::btnUpdate ));

      m_app.pushBox( m_city_view.layout() );

      m_city.addGrowable( Simutron::Growable( 10 ) );
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
      m_app.status( m_city.name() + ": A swell place to be." );
      m_city_view.updateData( m_city );
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

    void Play::btnZone( void )
    {
      Simutron::Zone zone( 1 );
      m_city.zone( zone );
      m_city_view.updateData( m_city );
    }

    void Play::btnUpdate( void )
    {
      m_city.update();
      m_city_view.updateData( m_city );
    }
  }
}
