#ifndef SIMUTRON_WINDOW_H
#define SIMUTRON_WINDOW_H

#include <gtkmm/window.h>
#include <gtkmm/label.h>
#include <gtkmm/box.h>

#include "button.h"


#include "budget_gtkmm.h"

#include "simutron.h"

namespace Simutron
{
  class Window : public Gtk::Window
  {
    private:
    City   m_city;
    Button m_button;
    Gtk::Label m_label;
    Gtk::Box m_box;


    Simutron::Gui::Budget m_budget_view;

    protected:
    void printName( void );

    public:
    Window( void );
    virtual ~Window( void );

  };
}

#endif
