#ifndef SIMUTRON_GROWABLE_H
#define SIMUTRON_GROWABLE_H

#include <cstdint>

#include "buildable.h"

namespace Simutron
{
  /**
  * @class Growable
  * @brief Base class for all things growable
  */
  class Growable : public Buildable
  {
    private:

    std::uint32_t m_capacity;

    public:
    /**
    * @fn Growable( const std::uint32_t capacity )
    * @brief Construct a Growable with said capacity
    * @param capacity The capacity of the Growable
    */
    Growable( const std::uint32_t );
    virtual ~Growable( void );

    bool buildableBy( const City& ) const override;

    /**
    * @fn std::uint32_t capacity( void ) const
    * @return The capacity of the growable
    */
    std::uint32_t capacity( void ) const;


  };
}

#endif
