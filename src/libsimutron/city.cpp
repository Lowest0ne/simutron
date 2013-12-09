#include "city.h"

namespace Simutron
{
  City::City( void )
    : m_name( "No name" )
    , m_population( 0 )
    , m_treasury( 1000 )
  {
  }

  City::City( const std::string& name )
    : m_name( name )
    , m_population( 0 )
    , m_treasury( 1000 )
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

  std::int32_t City::treasury( void ) const
  {
    return m_treasury;
  }

  void City::update( void )
  {
    std::int32_t revenue = m_budget.revenue( *this );
    m_treasury += revenue;
  }
}
