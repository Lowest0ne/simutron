#include "city.h"

#include "libsimutron/city.h"

namespace View
{
  City::City( Simutron::City& city )
    :m_city( city )
  {
    Glib::RefPtr< Gtk::Builder > builder = Gtk::Builder::create_from_file( "res/views/city.glade" );
    builder->get_widget( "box1", m_box );
  }

  City::~City( void )
  {
  }

  void City::show( void )
  {
    m_box->show();
  }

  void City::hide( void )
  {
    m_box->hide();
  }

  Gtk::Box& City::layout( void )
  {
    return *m_box;
  }
}
