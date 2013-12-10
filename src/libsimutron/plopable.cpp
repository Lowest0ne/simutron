#include "plopable.h"
#include "city.h"

namespace Simutron
{
  Plopable::Plopable( const std::int32_t cost )
    : Buyable( cost )
  {
  }

  Plopable::~Plopable( void )
  {
  }

  bool Plopable::buildableBy( const City& city ) const
  {
    return city.budget().canAfford( *this );
  }
}
