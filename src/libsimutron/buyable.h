#ifndef SIMUTRON_BUYABLE_H
#define SIMUTRON_BUYABLE_H

#include <cstdint>

namespace Simutron
{
  class Buyable
  {
    protected:

    std::int32_t m_cost;

    public:

    Buyable( const std::int32_t );

    virtual ~Buyable( void );

    virtual std::int32_t cost( void ) const = 0;
  };
}

#endif
