#ifndef SIMUTRON_APP_H
#define SIMUTRON_APP_H

#include <gtkmm/application.h>
#include <gtkmm/window.h>
#include <gtkmm/builder.h>

namespace Gtk
{
  class Statusbar;
  class Box;
  class MenuBar;
}


namespace Gui
{
  struct Menu;
}

/**
* @namespace App
* @brief     Provide a namespace for the Gtk gui
*/
namespace App
{
  /**
  * @class App::App
  * @brief The entry point to graphical simutron.
  *        Provides window and basic layout.
  * @note  This class provides a menu bar, an empty frame, and a status bar
  *        To any class, currently State, that may want to spruce them up
  *        Menus are currently built programatically.
  */
  class App
  {
    private:
    Glib::RefPtr< Gtk::Application >     m_app;
    Gtk::Window                       m_window;
    Glib::RefPtr< Gtk::Builder >     m_builder;

    // Non dynamic pointers.  They are derived from a ui file
    Gtk::Box     *m_main_display;
    Gtk::MenuBar      *m_menubar;
    Gtk::Box    *m_child_display;  // Boxes allow more than one child widget
    Gtk::Statusbar  *m_statusbar;

    public:
    /**
    * @fn    App( int argc, char** argv, const Glib::ustring& title, const int width, const int height )
    * @brief Construct a new Gtkmm application
    * @param argc Argument count passed to main.
    * @param argv Arguments passed to main.
    * @param title The name of the window to create
    * @param width The width of the window
    * @param height The height of the window
    */
    App( int, char**, const Glib::ustring&, const int, const int );
    virtual ~App( void );

    /**
    * @fn     int run( void )
    * @brief  Calls Gtk::Application::run() on the window
    * @return The return value of the called function
    */
    int run( void );

    /**
    * @fn     void appendMenu( Gui::Menu& menu )
    * @brief  Add a Gui::Menu to the menu bar
    */
    void appendMenu( Gui::Menu& );
    /**
    * @fn     void pushBox( Gtk::Box& widget )
    * @return Add a widget to the child display
    * @todo   Figure out if this can be const
    */
    void pushBox( Gtk::Box& );
    /**
    * @fn     void status( const std::string& str )
    * @brief  Set the message in the status bar
    */
    void status( const std::string& );
    /**
    * @fn    void quit( void )
    * @brief Shutdown the application
    */
    void quit( void );
  };
}

#endif
