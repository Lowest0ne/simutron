#include "menu_label.h"

namespace Gui
{
  MenuLabel::MenuLabel( const std::string& label )
    :label( label )
  {
    this->label.set_submenu( menu );
    menu.show();
  }

  MenuLabel::~MenuLabel( void )
  {
  }

  void MenuLabel::show( void )
  {
    label.show();
  }

  void MenuLabel::hide( void )
  {
    label.hide();
  }
}
