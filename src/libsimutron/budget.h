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
    std::int32_t  m_treasury;

    public:
    Budget( void );
    Budget( const std::uint16_t, const std::int32_t );

    virtual ~Budget( void );

    std::uint16_t taxRate( void ) const;
    void          taxRate( const std::uint16_t );

    std::int32_t  treasury( void ) const;

    void update( const City& );

    bool can_afford( const std::int32_t ) const;
    bool   purchace( const std::uint32_t );

  };
}

#endif
