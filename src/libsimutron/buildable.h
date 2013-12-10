#ifndef SIMUTRON_BUILDABLE_H
#define SIMUTRON_BUILDABLE_H

namespace Simutron
{
  class City;
  /**
  * @class Buildable
  * @brief Base class for all things buildable
  */
  class Buildable
  {
    public:
    virtual ~Buildable( void );

    /**
    * @fn bool buildableBy( const City& city ) const
    * @returns true if the City can build the Buildable
    */
    virtual bool buildableBy( const City& city ) const = 0;
  };
}

#endif
