#include "budget.h"
#include "city.h"

namespace Simutron
{
  Budget::Budget( void )
    : m_tax_rate( 7 )
    , m_treasury( 1000 )
  {
  }

  Budget::Budget( const std::uint16_t tax_rate, const std::int32_t treasury )
    : m_tax_rate( tax_rate )
    , m_treasury( treasury )
  {
  }

  Budget::~Budget( void )
  {
  }

  std::uint16_t Budget::taxRate( void ) const
  {
    return m_tax_rate;
  }

  void Budget::taxRate( const std::uint16_t tax_rate )
  {
    m_tax_rate = tax_rate;
  }

  std::int32_t Budget::treasury( void ) const
  {
    return m_treasury;
  }

  void Budget::update( const City& city )
  {
    m_treasury += city.population() * ( m_tax_rate / 100.0 );
  }

  bool Budget::can_afford( const std::int32_t amount ) const
  {
    return amount <= treasury();
  }

  bool Budget::purchace( const std::uint32_t amount )
  {
    if ( can_afford( amount ) )
    {
      m_treasury -= amount;
      return true;
    }
    else
    {
      return false;
    }
  }
}
