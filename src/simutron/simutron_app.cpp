#include "simutron_app.h"
#include "simutron/gui/menu.h"

namespace App
{
  App::App( int argc, char** argv, const Glib::ustring& title, const int width, const int height )
    : m_app( Gtk::Application::create( argc, argv, "my.game.simutron" ) )
    , m_box( Gtk::Orientation::ORIENTATION_VERTICAL )
  {
    m_window.set_title( title );
    m_window.set_default_size( width, height );

    m_box.add( m_menubar );
    m_menubar.show();

    m_layout.set_vexpand( true );
    m_box.add( m_layout );
    m_layout.show();

    m_box.add( m_statusbar );
    m_statusbar.show();

    m_window.add( m_box );
    m_box.show();
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
      m_menubar.append( item->label );
  }

  void App::quit( void )
  {
    m_window.hide();
  }
}
