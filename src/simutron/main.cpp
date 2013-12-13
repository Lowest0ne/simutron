#include "simutron_app.h"
#include "state/manager.h"

int main ( int argc, char **argv )
{
  Simutron::App app( argc, argv, "Simutron", 800, 600 );
  Simutron::State::Manager manager( app );
  return app.run();
}
