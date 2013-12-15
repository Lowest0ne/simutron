#ifndef SIMUTRON_VIEW_H
#define SIMUTRON_VIEW_H

#include <gtkmm/builder.h>

/**
* @namespace View
* @brief     Provide a namespace for all views
*/
namespace View
{
  /**
  * @class View::View
  * @brief Base class for all views
  */
  class View
  {
    protected:

    Glib::RefPtr< Gtk::Builder > m_builder; //!< The builder

    public:
    /**
    * @fn    View( const Glib::ustring& file_name )
    * @brief Construct a view from the given glade file
    */
    View( const Glib::ustring& );
    virtual ~View( void );

    /**
    * @fn    virtual void show( void ) = 0
    * @brief Show all gui elements
    */
    virtual void show( void ) = 0;
    /**
    * @fn    virtual voide hide( void ) = 0
    * @brief Hide all gui elements
    */
    virtual void hide( void ) = 0;
  };
}

#endif
