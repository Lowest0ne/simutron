#include "view.h"

namespace View
{
  View::View( const Glib::ustring& file_name )
    : m_builder( Gtk::Builder::create_from_file( file_name ) )
  {
  }

  View::~View( void )
  {
  }
}
