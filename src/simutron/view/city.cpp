#include "city.h"
#include "libsimutron/city.h"

#include <gtkmm/box.h>
#include <gtkmm/label.h>

#include <sstream>
#include <string>

namespace View
{
  City::City( void )
    : m_builder( Gtk::Builder::create_from_file( "res/views/city.glade" ) )
  {
    m_builder->get_widget( "box1", m_box );
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

  void City::updateData( const Simutron::City& city )
  {
    updateLabel( "population_value", city.population() );
    updateLabel( "max_population_value", city.maxPopulation() );
    updateLabel( "taxrate_value", city.budget().taxRate() );
    updateLabel( "funds_value", city.budget().treasury() );
    updateLabel( "free_zone_value", city.freeZones() );
  }

  void City::updateLabel( const Glib::ustring& name, const std::uint32_t value )
  {
    static std::stringstream ss;
    ss << value;

    static Gtk::Label *label;
    m_builder->get_widget( name, label );
    label->set_label( ss.str() );

    ss.str( "" );
  }
}
