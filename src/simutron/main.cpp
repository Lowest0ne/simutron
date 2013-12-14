#include "simutron_app.h"
#include "state/manager.h"

int main ( int argc, char **argv )
{
  App::App simutron( argc, argv, "Simutron", 800, 600 );
  App::State::Manager manager( simutron );
  return simutron.run();
}
