#include "city.h"
#include "zone.h"

#include <stdexcept>

namespace Simutron
{
  City::City( void )
    : m_name( "No name" )
    , m_population( 0 )
    , m_free_zones( 0 )
    , m_max_population( 100 )
  {
  }

  City::City( const std::string& name )
    : m_name( name )
    , m_population( 0 )
    , m_free_zones( 0 )
    , m_max_population( 100 )
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

  std::uint32_t City::freeZones( void ) const
  {
    return m_free_zones;
  }

  Budget& City::budget( void )
  {
    return m_budget;
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
    // Find the best growable
    const auto growable = bestGrowable();
    if ( growable == m_growables.end() )   return;
    if ( !growable->buildableBy( *this ) ) return;

    // Build as many as possible
    auto build_amount = growthPotential() / growable->capacity();
    if ( freeZones() < build_amount ) build_amount = freeZones();

    // Update variables
    m_population += build_amount * growable->capacity();
    m_free_zones -= build_amount;
  }

  void City::addGrowable( const Growable& growable )
  {
    m_growables.push_back( growable );
  }

  const City::growable_iterator City::bestGrowable( void ) const
  {
    return m_growables.cbegin();
  }

  std::uint32_t City::maxPopulation( void ) const
  {
    return m_max_population;
  }

  std::uint32_t City::growthPotential( void ) const
  {
    return maxPopulation() - population();
  }
}
