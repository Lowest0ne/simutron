#ifndef SIMUTRON_BUDGET_H
#define SIMUTRON_BUDGET_H

#include <cstdint>

namespace Simutron
{
  class City;

  class Budget
  {
    private:
    std::uint16_t m_tax_rate;

    public:
    Budget( void );
    Budget( const double );

    virtual ~Budget( void );

    std::uint16_t taxRate( void ) const;
    void          taxRate( const std::uint16_t );

    std::int32_t revenue( const City& ) const;

  };
}

#endif
