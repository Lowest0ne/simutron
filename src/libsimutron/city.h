#ifndef SIMUTRON_CITY_H
#define SIMUTRON_CITY_H

#include <string>

namespace Simutron
{
  class City
  {
    private:
    std::string m_name;

    public:
    City( void );
    City( const std::string& );

    virtual ~City( void );

    const std::string& name( void ) const;

  };
}

#endif
