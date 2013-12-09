#ifndef SIMUTRON_BUYABLE_H
#define SIMUTRON_BUYABLE_H

#include <cstdint>

namespace Simutron
{
  /**
  * @class Buyable
  * @brief Base class for all things buyable
  */
  class Buyable
  {
    private:

    std::int32_t m_cost;

    public:
    /**
    * @fn Buyable( const std::int32_t cost)
    * @brief Construct a Buyable with the given cost
    * @param cost The amount that the buyable costs
    */
    Buyable( const std::int32_t );

    virtual ~Buyable( void );

    /**
    * @fn virtual std::int32_t cost( void ) const = 0
    * @brief Return the cost of the Buyable
    * @return The cost of the Buyable
    */
    virtual std::int32_t cost( void ) const;
  };
}

#endif
