// This is mostly to test functionality
#ifndef SIMUTRON_BUDGET_GTKMM_H
#define SIMUTRON_BUDGET_GTKMM_H

#include <gtkmm/frame.h>
#include <sstream>


namespace Gtk
{
  class Label;
}

namespace Simutron
{
  class Budget;

  namespace Gui
  {
    class Budget : public Gtk::Frame
    {
      private:
      std::stringstream ss;
      Simutron::Budget& m_budget;

      Gtk::Label *m_label;

      public:
      Budget( Simutron::Budget& );
      virtual ~Budget( void );

      // wih this function I don't need to store a budget
      void update( void );
    };
  }
}

#endif
