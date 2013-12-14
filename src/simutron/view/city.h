#ifndef SIMUTRON_VIEW_CITY_H
#define SIMUTRON_VIEW_CITY_H

#include <gtkmm.h>

namespace Simutron
{
  class City;
}

namespace View
{
  class City
  {
    private:
    Simutron::City& m_city;

    Gtk::Box* m_box;
    Gtk::Toolbar* m_toolbar;

    Gtk::ToolButton m_button;

    public:
    City( Simutron::City& );
    virtual ~City( void );

    void show( void );
    void hide( void );

    Gtk::Box& layout( void );
  };
}

#endif
