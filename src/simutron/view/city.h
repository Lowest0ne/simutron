#ifndef SIMUTRON_VIEW_CITY_H
#define SIMUTRON_VIEW_CITY_H

#include <gtkmm/builder.h>
#include <gtkmm/toolbutton.h>

#include <string>
#include <cstdint>

namespace Simutron
{
  class City;
}

namespace Gtk
{
  class Box;
}

namespace View
{
  class City
  {
    private:

    Glib::RefPtr< Gtk::Builder > m_builder;
    Gtk::Box*                        m_box;

    void updateLabel( const Glib::ustring&, const std::uint32_t );

    public:
    City( void );
    virtual ~City( void );

    void show( void );
    void hide( void );

    void updateData( const Simutron::City& );
    Gtk::Box& layout( void );

    template< typename T >
    void btnConnect( const Glib::ustring& value, T func )
    {
      Gtk::ToolButton *btn;
      m_builder->get_widget( value, btn );
      btn->signal_clicked().connect( func );
    }
  };
}

#endif
