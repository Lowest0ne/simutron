#ifndef SIMUTRON_CITY_H
#define SIMUTRON_CITY_H

#include <string>
#include <cstdint>
#include <vector>

#include "budget.h"
#include "growable.h"

namespace Simutron
{
  class Zone;

  /**
  * @class City
  * @brief A representation of a city
  */
  class City
  {
    private:
    std::string   m_name;
    std::uint32_t m_population;
    std::uint32_t m_free_zones;

    Budget m_budget;
    std::vector< Growable > m_growables;

    private:
    /**
    * @fn void grow( void )
    * @brief Calculate the new population of the City
    */
    void grow( void );
    /**
    * @fn const Growable& bestGrowable( void ) const
    * @brief Select the best growable to build
    * @throw std::out_of_range
    */
    const Growable& bestGrowable( void ) const;

    public:
    /**
    * @fn City( void )
    * @brief Construct a City with default values
    */
    City( void );
    /**
    * @fn City( const std::string& name )
    * @brief Construct a City with a name
    */
    City( const std::string& );

    virtual ~City( void );

    /**
    * @fn const std::string& name( void ) const
    * @return The name of the City
    */
    const std::string& name( void ) const;
    /**
    * @fn std::uint32_t population( void ) const
    * @return The population of the City
    */
    std::uint32_t population( void ) const;
    /**
    * @fn std::uint32_t free_zones( void ) const
    * @return The available zones the City contains
    */
    std::uint32_t free_zones( void ) const;
    /**
    * @fn const Budget& budget( void ) const
    * @return The City's Budget
    */
    const Budget& budget( void ) const;
    /**
    * @fn void zone( const Zone& zone )
    * @brief Atempt to purchace a Zone
    * @param zone The zone to purchase
    */
    void zone( const Zone& );
    /**
    * @fn void update( void )
    * @brief Update the City's members
    */
    void update( void );
    /**
    * @fn void addGrowable( const Growable& growable )
    * @brief Add a Growable for the city to choose from when it groes
    * @param growable The Growable to add
    */
    void addGrowable( const Growable& );

  };
}

#endif
