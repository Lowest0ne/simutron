#include "simutron_app.h"
#include "simutron/gui/menu.h"

#include <gtkmm/box.h>
#include <gtkmm/statusbar.h>
#include <gtkmm/menubar.h>
#include <gtkmm/frame.h>

namespace App
{
  App::App( int argc, char** argv, const Glib::ustring& title, const int width, const int height )
    : m_app( Gtk::Application::create( argc, argv, "my.game.simutron" ) )
    , m_builder( Gtk::Builder::create_from_file("res/views/main_window.glade") )
  {
    m_window.set_title( title );
    m_window.set_default_size( width, height );

    m_builder->get_widget( "main_display", m_main_display );
    m_builder->get_widget( "menubar",      m_menubar      );
    m_builder->get_widget( "layout",       m_frame        );
    m_builder->get_widget( "statusbar",    m_statusbar    );

    m_window.add( *m_main_display );
    m_main_display->show();
  }

  App::~App( void )
  {
  }

  int App::run( void )
  {
    return m_app->run( m_window );
  }

  void App::appendMenu( Gui::Menu& menu )
  {
    for ( auto& item: menu.labels )
      m_menubar->append( item->label );
  }

  Gtk::Frame& App::frame( void )
  {
    return *m_frame;
  }

  Gtk::Statusbar& App::statusBar( void )
  {
    return *m_statusbar;
  }

  void App::quit( void )
  {
    m_window.hide();
  }
}
