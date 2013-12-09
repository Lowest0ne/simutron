#include "budget.h"
#include "city.h"

namespace Simutron
{
  Budget::Budget( void )
    :m_tax_rate( 7 )
  {
  }

  Budget::Budget( const double tax_rate )
    :m_tax_rate( tax_rate )
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

  std::int32_t Budget::revenue( const City& city ) const
  {
    return city.population() * ( m_tax_rate / 100.0 );
  }
}
