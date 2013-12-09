#ifndef SIMUTRON_ZONE_H
#define SIMUTRON_ZONE_H

#include <cstdint>

#include "buyable.h"

namespace Simutron
{

  /**
  * @class Zone
  * @brief Cities purchase zones, which are then developed for population
  */
  class Zone : public Buyable
  {
    private:
    std::uint32_t m_size;

    public:

    /**
    * @fn Zone( const std::uint32_t size, const std::int32_t cost )
    * @brief Construct a Zone
    * @param size The size of the zone, in tiles ( though tiles aren't defined )
    * @param cost The cost of each tile
    */
    Zone( const std::uint32_t, const std::int32_t cost = 10 );
    virtual ~Zone( void );

    /**
    * @fn std::uint32_t size( void ) const
    * @return The size of the Zone
    */
    std::uint32_t size( void ) const;
    /**
    * @fn void size( const std::uint32_t size )
    * @brief Set the size of the Zone
    * @param size The new size of the Zone
    */
    void          size( const std::uint32_t );

    std::int32_t  cost( void ) const override;

  };
}

#endif
