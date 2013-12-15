#include "menu.h"
#include "manager.h"
#include "play.h"

#include "simutron/simutron_app.h"
#include "libsimutron/city.h"

#include <gtkmm.h>


namespace App
{
  namespace State
  {
    Menu::Menu( App& app, Manager& manager )
      : State( app, manager )
      , m_builder( Gtk::Builder::create_from_file("res/views/menu_frame.glade"))
    {
      m_menu.add( "File" );
      m_menu.add( "File", "Quit", sigc::mem_fun( m_app, &App::quit ) );

      m_app.appendMenu( m_menu );


      Gtk::Button* button;
      m_builder->get_widget( "create_button", button );
      button->signal_pressed().connect( sigc::mem_fun( *this, &Menu::newCity ));

      m_builder->get_widget( "menu_box", m_box );
      m_app.pushBox( *m_box );
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
      Gtk::Entry *entry;
      m_builder->get_widget( "name_entry", entry );

      if ( entry->get_text() == "" )
      {
        m_app.status( "City must have a name" );
      }
      else
      {
        Simutron::City new_city( entry->get_text() );
        m_manager.change( Play::instance( m_app, m_manager, new_city ) );
      }
    }

    void Menu::init( void )
    {
      m_app.status( "Welcome to Simutron" );
      m_menu.show();
      m_box->show();
    }

    void Menu::quit( void )
    {
      m_menu.hide();
      m_box->hide();
    }
  }

}
