#ifndef SIMUTRON_VIEW_CITY_H
#define SIMUTRON_VIEW_CITY_H

#include "view.h"

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
  /**
  * @class View::City
  * @brief Provide the gui elements for a city
  */
  class City : public View
  {
    private:
    Gtk::Box*                        m_box;

    void updateLabel( const Glib::ustring&, const std::uint32_t );

    public:
    /**
    * @fn    City( void )
    * @brief Constuct the view, which is loaded from glade file
    */
    City( void );
    virtual ~City( void );

    void show( void ); //!< Inherited
    void hide( void ); //!< Inherited

    /**
    * @fn    void updateData( const Simutron::City& )
    * @brief Update labels to match the data of the city
    * @note  It is assumed that this will be called less than a draw function
    */
    void updateData( const Simutron::City& );
    /**
    * @fn    Gtk::Box& layout( void )
    * @brief Return the main Gtk::Box so it can be added to the main window
    */
    Gtk::Box& layout( void );

    /**
    * @fn    template <typename T> void btnConnect( const Glib::ustring& value, T func)
    * @brief Connects a button provided in the glade file with an outside function
    * @note  This will only work on Gtk::ToolbarButtons...
    */
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
