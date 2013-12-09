#include "city.h"
#include "zone.h"

#include <stdexcept>

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

  void City::zone( const Zone& zone )
  {
    if ( m_budget.purchace( zone ) )
      m_free_zones += zone.size();
  }

  void City::update( void )
  {
    grow();
    m_budget.update( *this );
  }

  void City::grow( void )
  {
    m_population += m_free_zones * bestGrowable().capacity();
    m_free_zones = 0;
  }

  void City::addGrowable( const Growable& growable )
  {
    m_growables.push_back( growable );
  }

  const Growable& City::bestGrowable( void ) const
  {
    if ( m_growables.size() == 0 ) throw std::out_of_range( "City has nothing");
    return m_growables.front();
  }
}
