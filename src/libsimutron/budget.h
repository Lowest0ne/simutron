#ifndef SIMUTRON_BUDGET_H
#define SIMUTRON_BUDGET_H

#include <cstdint>

namespace Simutron
{
  class City;
  class Buyable;

  /**
  * @class Budget
  * @brief Provide monetary functions
  */
  class Budget
  {
    private:
    std::uint16_t m_tax_rate;
    std::int32_t  m_treasury;

    public:
    /**
    * @fn Budget( void )
    * @brief Construct a default Budget
    */
    Budget( void );
    /**
    * @fn Budget( const std::uint16_t, const std::int32_t )
    * @brief Construct a Budget and set tax rate and treasury
    */
    Budget( const std::uint16_t, const std::int32_t );

    virtual ~Budget( void );

    /**
    * @fn std::uint16_t taxRate( void ) const
    * @brief Return the current tax rate.  Tax rate is a percent.
    * @return The current tax rate
    */
    std::uint16_t taxRate( void ) const;
    /**
    * @fn void taxRate( const std::uint16_t )
    * @brief Set the tax rate
    */
    void          taxRate( const std::uint16_t );

    /**
    * @fn std::int32_t treasury( void ) const
    * @brief Return the current treasury
    * @return The current treasury
    */
    std::int32_t  treasury( void ) const;

    /**
    * @fn void update( const City& city )
    * @brief Update the current treasury based on city's stats
    * @param city The city to base updates upon
    */
    void update( const City& );

    /**
    * @fn bool can_afford( const Buyable& buyable ) const
    * @brief Determine if the Budget can afford the Buyable
    * @return true if the Budget can afford the buyable
    */
    bool can_afford( const Buyable& ) const;
    /**
    * @fn bool purchace( const Buyable& buyable )
    * @brief Detract the Buyable's cost from treasury if it is affordable
    * @param buyable The Buyable to purchace
    */
    bool   purchace( const Buyable& );

  };
}

#endif
