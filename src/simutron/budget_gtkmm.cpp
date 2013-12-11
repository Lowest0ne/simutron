#include "budget_gtkmm.h"
#include "budget.h"

#include <gtkmm.h>
#include <sstream>


namespace Simutron
{
  namespace Gui
  {
    Budget::Budget( Simutron::Budget& budget )
      :m_budget( budget )
    {
      Glib::RefPtr<Gtk::Builder> refBuilder = Gtk::Builder::create();
      refBuilder->add_from_file("res/gui/budget.glade");


      refBuilder->get_widget( "label1", m_label );
      update();

      Gtk::Grid *grid;
      refBuilder->get_widget("grid1", grid);

      add( *grid );
      grid->show();
    }

    Budget::~Budget( void )
    {
    }

    void Budget::update( void )
    {
      static const std::string str;
      ss << m_budget.treasury();
      m_label->set_text( ss.str() );
      ss.str( str );
    }
  }
}
