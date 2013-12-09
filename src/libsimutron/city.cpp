#include "city.h"

namespace Simutron
{
  City::City( void )
    : m_name( "No name" )
    , m_population( 0 )
    , m_free_zones( 0 )
  {
  }

  City::City( const std::string& name )
    : m_name( name )
    , m_population( 0 )
    , m_free_zones( 0 )
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

  std::uint32_t City::free_zones( void ) const
  {
    return m_free_zones;
  }

  const Budget& City::budget( void ) const
  {
    return m_budget;
  }

  void City::zone( const uint32_t amount )
  {
    const std::int32_t zone_cost = 10;
    if ( m_budget.purchace( amount * zone_cost ) )
      m_free_zones += amount;
  }

  void City::update( void )
  {
    m_budget.update( *this );
  }
}
