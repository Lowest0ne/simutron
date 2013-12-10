#include "budget.h"
#include "city.h"
#include "buyable.h"

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
    m_treasury += ( city.population() * m_tax_rate ) / 100.0;
  }

  bool Budget::canAfford( const Buyable& buyable ) const
  {
    return buyable.cost() <= treasury();
  }

  bool Budget::purchace( const Buyable& buyable )
  {
    if ( canAfford( buyable ) )
    {
      m_treasury -= buyable.cost();
      return true;
    }
    else
    {
      return false;
    }
  }
}
