#include "menu.h"
#include "manager.h"
#include "play.h"

#include "simutron/simutron_app.h"

#include <gtkmm.h>

namespace App
{
  namespace State
  {
    Menu::Menu( App& app, Manager& manager )
      : State( app, manager )
      , m_button( "Click To Play" )
      , m_menu( "File" )
    {
      m_button.signal_clicked().connect( sigc::mem_fun( *this, &Menu::on_button ) );
      m_app.layout().add( m_button );


      m_menu.set_submenu( item );
      item.show();
      m_app.menu().append( m_menu );
    }

    Menu::~Menu( void )
    {
    }

    Menu& Menu::instance( App& app, Manager& manager )
    {
      static Menu menu( app, manager );
      return menu;
    }

    void Menu::on_button( void )
    {
      m_manager.change( Play::instance( m_app, m_manager ) );
    }

    void Menu::init( void )
    {
      m_app.statusBar().push( "Welcome to Simutron" );
      m_button.show();
      m_menu.show();
    }

    void Menu::quit( void )
    {
      m_button.hide();
      m_menu.hide();
    }
  }

}
