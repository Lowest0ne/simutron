#include "simutron_app.h"


int main ( int argc, char **argv )
{
  Simutron::App app( argc, argv, "Simutron", 800, 600 );
  return app.run();
}
