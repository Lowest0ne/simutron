#include "simutron_app.h"
#include "state/manager.h"
#include "state/menu.h"

int main ( int argc, char **argv )
{
  App::App simutron( argc, argv, "Simutron", 800, 600 );
  App::State::Manager manager;
  manager.push( App::State::Menu::instance( simutron, manager ) );
  return simutron.run();
}
