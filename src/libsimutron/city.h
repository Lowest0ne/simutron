#ifndef SIMUTRON_CITY_H
#define SIMUTRON_CITY_H

#include <string>
#include <cstdint>

#include "budget.h"

namespace Simutron
{
  class City
  {
    private:
    std::string   m_name;
    std::uint32_t m_population;

    Budget m_budget;

    public:
    City( void );
    City( const std::string& );

    virtual ~City( void );

    const std::string&       name( void ) const;
    std::uint32_t      population( void ) const;

    const Budget& budget( void ) const;

    void update( void );
  };
}

#endif
