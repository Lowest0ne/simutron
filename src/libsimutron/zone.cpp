#include "zone.h"

namespace Simutron
{
  Zone::Zone( const std::uint32_t size, const std::int32_t cost )
    : Buyable( cost )
    , m_size( size )
  {
  }

  Zone::~Zone( void )
  {
  }

  std::uint32_t Zone::size( void ) const
  {
    return m_size;
  }

  void Zone::size( const std::uint32_t size )
  {
    m_size = size;
  }

  std::int32_t Zone::cost( void ) const
  {
    return m_cost * m_size;
  }
}
