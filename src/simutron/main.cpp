#include "window.h"


int main ( int argc, char **argv )
{
  Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "my.game.simutron");

  Simutron::Window window;

  return app->run( window );
}
