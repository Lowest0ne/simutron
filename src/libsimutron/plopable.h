#ifndef SIMUTRON_PLOPABLE_H
#define SIMUTRON_PLOPABLE_H

#include "buildable.h"
#include "buyable.h"

namespace Simutron
{
  /**
  * @class Plopable
  * @brief Base class for all things plopable ( police stations, parks, etc )
  */
  class Plopable : public Buildable, public Buyable
  {
    public:
    /**
    * @fn Plopable( const std::int32_t cost )
    * @brief Construct a Plopable given a cost
    * @param cost The cost of ploping it
    */
    Plopable( const std::int32_t );
    virtual ~Plopable( void );

    bool buildableBy( const City& ) const override;
  };
}

#endif
