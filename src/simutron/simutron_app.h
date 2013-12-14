#ifndef SIMUTRON_APP_H
#define SIMUTRON_APP_H

#include <gtkmm/application.h>
#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/menubar.h>
#include <gtkmm/layout.h>
#include <gtkmm/statusbar.h>


namespace Gui
{
  struct Menu;
}

/**
* @namespace App
* @brief     Proivde a namespace for the Gtk gui
*/
namespace App
{
  /**
  * @class App::App
  * @brief The entry point to graphical simutron.
  *        Provides window and basic layout.
  */
  class App
  {
    private:
    Glib::RefPtr< Gtk::Application >    m_app;
    Gtk::Window                      m_window;
    Gtk::Box                            m_box;
    Gtk::MenuBar                    m_menubar;
    Gtk::Layout                      m_layout;
    Gtk::Statusbar                m_statusbar;

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
    * @fn     Gtk::Layout& layout( void )
    * @return The Application's layout
    */
    Gtk::Layout&       layout( void ){ return m_layout;    }
    /**
    * @fn     Gtk::Statusbar& statusBar( void )
    * @return The Application's status
    */
    Gtk::Statusbar& statusBar( void ){ return m_statusbar; }
    /**
    * @fn    void quit( void )
    * @brief Shutdown the application
    */
    void quit( void );
  };
}

#endif
