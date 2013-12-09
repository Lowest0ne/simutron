#include "city.h"

namespace Simutron
{
  City::City( void )
    : m_name( "No name" )
    , m_population( 0 )
  {
  }

  City::City( const std::string& name )
    : m_name( name )
    , m_population( 0 )
  {
  }

  City::~City( void )
  {
  }

  const std::string& City::name( void ) const
  {
    return m_name;
  }

  std::uint32_t City::population( void ) const
  {
    return m_population;
  }

  const Budget& City::budget( void ) const
  {
    return m_budget;
  }

  void City::update( void )
  {
    m_budget.update( *this );
  }
}
