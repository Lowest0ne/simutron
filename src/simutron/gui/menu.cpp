#include "menu.h"

#include <algorithm>

namespace Gui
{
  /*MENU LABEL*****************************************************************/
  Menu::Label::Label( const std::string& label )
    :label( label )
  {
    this->label.set_submenu( menu );
    menu.show();
  }

  Menu::Label::~Label( void )
  {
  }

  void Menu::Label::show( void )
  {
    label.show();
  }

  void Menu::Label::hide( void )
  {
    label.hide();
  }

  /*MENU LABELS****************************************************************/
  Menu::~Menu( void )
  {
    for ( auto& label: labels ) delete label;
    for ( auto& item:  items  ) delete item;
  }

  void Menu::add( const std::string& label )
  {
    labels.push_back( new Label( label ) );
  }

  void Menu::show( void )
  {
    for ( auto& label: labels ) label->show();
  }

  void Menu::hide( void )
  {
    for ( auto& label: labels ) label->hide();
  }

  Menu::Label* Menu::find( const std::string& label_name )
  {
    auto found = std::find_if( labels.begin(), labels.end(),
    [=]( const Label* label )
    {
      return label->label.get_label() == label_name;
    });

    if ( found == labels.end() ) return nullptr;

    return *found;
  }
}
