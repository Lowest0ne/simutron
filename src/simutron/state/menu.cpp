#include "menu.h"
#include "simutron/simutron_app.h"

#include <iostream>

namespace Simutron
{
  namespace State
  {
    Menu::Menu( App& app )
      : State( app )
      , m_button( "Click To Play" )
    {
      m_app.statusBar().push( "Welcome to Simutron" );

      m_button.signal_clicked().connect( sigc::mem_fun( *this, &Menu::on_button ) );
      m_app.layout().add( m_button );
      m_button.show();
    }

    Menu::~Menu( void )
    {
    }

    Menu& Menu::instance( App& app )
    {
      static Menu menu( app );
      return menu;
    }

    void Menu::on_button( void )
    {
      std::cout << "You clicked it\n";
    }
  }

}
