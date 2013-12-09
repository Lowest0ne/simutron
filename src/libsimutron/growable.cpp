#include "growable.h"

namespace Simutron
{
  Growable::Growable( const std::uint32_t capacity )
    : m_capacity( capacity )
  {
  }

  Growable::~Growable( void )
  {
  }

  std::uint32_t Growable::capacity( void ) const
  {
    return m_capacity;
  }
}
