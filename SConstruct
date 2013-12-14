import os

def env():
  return Environment( CXXFLAGS='-g -std=c++11 -Wall -Wextra -pedantic -Werror' )

lib_env = env()
lib_env.SharedLibrary('./lib/simutron', Glob( 'src/libsimutron/*.cpp' ))

sim_env = env()
sim_env.ParseConfig('pkg-config --cflags --libs gtkmm-3.0')
sim_env.Append(
  CPPPATH = ['./src'],
  LIBS = 'simutron',
  LIBPATH = './lib'
)

sim_env.Append( LINKFLAGS = '-Wl,-rpath=./lib' )
sim_env.Program('simutron',
  Glob( 'src/simutron/*.cpp' ) +
  Glob( 'src/simutron/state/*.cpp' )  +
  Glob( 'src/simutron/gui/*.cpp' )
)
