#include "simutron.h"
#include <iostream>

int main( void )
{
  std::cout << "Welcome to Simutron\n\n";

  Simutron::City city("Boston");

  std::cout << "The name of your city is: " << city.name() << std::endl;

  return 0;
}
