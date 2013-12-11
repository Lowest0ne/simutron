#include "window.h"
#include <sstream>

#include <gtkmm.h>

namespace Simutron
{
  Window::Window( void )
    : m_city("Boston")
    , m_button( m_city.name() )
    , m_label( "Nothing" )
    , m_budget_view( m_city.budget() )
  {
    m_button.onClick( sigc::mem_fun( *this, &Window::printName ));
    m_box.pack_start( m_button );
    m_box.pack_start( m_label  );


    m_box.pack_start( m_budget_view );

    add( m_box );

    m_button.show();
    m_label.show();
    m_budget_view.show();
    m_box.show();

    m_city.addGrowable( Growable( 10 ));
  }

  Window::~Window( void )
  {
  }

  void Window::printName( void )
  {
    m_city.zone( 1 );
    m_city.update();

    std::stringstream ss;
    ss << m_city.population();
    m_label.set_text( ss.str() );

    m_budget_view.update();
  }

}
