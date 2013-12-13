#include "simutron_app.h"
#include "state/manager.h"

int main ( int argc, char **argv )
{
  Gui::App simutron( argc, argv, "Simutron", 800, 600 );
  Gui::State::Manager manager( simutron );
  return simutron.run();
}
