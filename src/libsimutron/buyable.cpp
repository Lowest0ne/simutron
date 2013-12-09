#include "buyable.h"

namespace Simutron
{
  Buyable::Buyable( const std::int32_t cost )
    : m_cost( cost )
  {
  }

  Buyable::~Buyable( void )
  {
  }

  std::int32_t Buyable::cost( void  ) const
  {
    return m_cost;
  }

}
