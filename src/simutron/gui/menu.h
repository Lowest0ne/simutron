#ifndef SIMUTRON_GUI_MENU_LABEL_H
#define SIMUTRON_GUI_MENU_LABEL_H

#include <gtkmm/menu.h>
#include <gtkmm/menuitem.h>

#include <string>
#include <vector>

namespace Gui
{
  /**
  * @struct Menu
  * @brief  A way to hold more than one Label
  */
  struct Menu
  {
    /**
    * @struct Menu::Label
    * @brief  Gtk::MenuBars need Gtk::MenuItems, which need to be paired
    *         with a Gtk::Menu to be on the top of the MenuBar...
    */
    struct Label
    {
      Gtk::MenuItem label; //!< The title of the menu: File, About, etc
      Gtk::Menu      menu; //!< The container to hold child items

      /**
      * @fn     Label( const std::string& label )
      */
      Label( const std::string& );
      virtual ~Label( void );

      /**
      * @fn    void show( void )
      * @brief Show the widgets in this struct
      */
      void show( void );
      /**
      * @fn    void hide( void )
      * @brief Hide the widgets in this struct
      */
      void hide( void );
    };

    std::vector< Label* > labels;         //!< The container for Labels
    std::vector< Gtk::MenuItem* > items;  //!< The container for MenuItems

    virtual ~Menu( void );

    /**
    * @fn    void add( const std::string& label )
    * @brief Add a label to the container
    * @param label The title of the label
    */
    void add( const std::string& );
    /**
    * @fn    void show( void )
    * @brief Show the labels in this struct
    */
    void show( void );
    /**
    * @fn    void hide( void )
    * @brief Hide the lables in this struct
    */
    void hide( void );
    /**
    * @fn     Label* find( const std::string& label )
    * @param  label The title of the label to find
    * @return The Label that was found, or nullptr
    */
    Label* find( const std::string& );
    /**
    * @fn void add( const std::string label, const std::string entry, T& func )
    * @brief Add a sub menu entry to a lable: New, Save, Load, Quit etc
    * @param label The Label to add the entry to
    * @param entry The name of the entry
    * @param func  The function associated with signal_activate
    */
    template <typename T>
    void add( const std::string& label, const std::string& entry, T func )
    {
      Label* found = find( label );
      if ( !found )
      {
        add( label );
        found = labels.back();
      }

      items.push_back( new Gtk::MenuItem( entry ) );
      items.back()->signal_activate().connect( func );
      items.back()->show();

      found->menu.append( *items.back() );
    }
  };
}
#endif

