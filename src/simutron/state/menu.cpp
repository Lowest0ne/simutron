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
      , m_label( "File" )
      , m_item( "New" )
    {
      m_button.signal_clicked().connect( sigc::mem_fun( *this, &Menu::on_button ) );
      m_app.layout().add( m_button );

      m_item.signal_activate().connect( sigc::mem_fun( *this, &Menu::on_button ) );
      m_label.menu.append( m_item );
      m_item.show();

      m_app.menu().append( m_label.label );
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
      m_label.show();
    }

    void Menu::quit( void )
    {
      m_button.hide();
      m_label.hide();
    }
  }

}
