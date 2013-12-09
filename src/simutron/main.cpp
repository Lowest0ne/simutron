#include "simutron.h"
#include <iostream>
#include <iomanip>
#include <string>

template <typename T> void format( std::ostream&, const size_t, const T& );
std::ostream& operator<<( std::ostream&, const Simutron::City& );


int main( void )
{
  std::cout << "Welcome to Simutron\n\n";
  Simutron::City city("Boston");


  bool running = true;
  while ( running )
  {
    std::cout << city << std::endl;

    char choice;
    std::cin >> choice; std::cin.ignore( 80, '\n' );

    switch ( choice )
    {
      case 'q': running = false; break;
    }

    city.update();
  }
  return 0;
}

std::ostream& operator<<( std::ostream& out, const Simutron::City& city )
{
  static const std::string line( 80, '*' );
  static const size_t w = 16;

  out << line << "\nCity Name: " << city.name() << '\n' << line;
  out << std::endl;

  format( out, w, "Population" );
  format( out, 6, city.population() );
  format( out, w, "Treasury" );
  format( out, 6, city.budget().treasury() );

  return out << '\n' << line << "\n\n";
}

template <typename T>
void format( std::ostream& out, const size_t w, const T& value )
{
  out << std::setw( w ) << value;
}
