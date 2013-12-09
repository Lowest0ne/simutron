#include "city.h"

namespace Simutron
{
  City::City( void )
    :m_name( "No name" )
  {
  }

  City::City( const std::string& name )
    :m_name( name )
  {
  }

  City::~City( void )
  {
  }

  const std::string& City::name( void ) const
  {
    return m_name;
  }
}
