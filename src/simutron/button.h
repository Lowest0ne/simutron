#ifndef SIMUTRON_BUTTON_H
#define SIMUTRON_BUTTON_H

#include <gtkmm/button.h>

namespace Simutron
{
  class Button : public Gtk::Button
  {
    public:
    Button( const Glib::ustring& );
    virtual ~Button( void );

    template<typename T>
    void onClick( T func )
    {
      signal_clicked().connect( func );
    }
  };
}

#endif
