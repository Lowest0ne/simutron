#ifndef SIMUTRON_ZONE_H
#define SIMUTRON_ZONE_H

#include <cstdint>

#include "buyable.h"

namespace Simutron
{

  class Zone : public Buyable
  {
    protected:

    std::uint32_t m_size;

    public:

    Zone( const std::uint32_t, const std::int32_t cost = 10 );
    virtual ~Zone( void );

    std::uint32_t size( void ) const;
    void          size( const std::uint32_t );

    std::int32_t  cost( void ) const override;

  };
}

#endif
