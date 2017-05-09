cmake_minimum_required( VERSION 2.6 )
project( euler2d )

set( CMAKE_CXX_FLAGS "-std=c++14 -Wall -Wextra" )
include_directories( src )

# pkgconfig 
find_package( PkgConfig REQUIRED )
pkg_check_modules( MYPKG REQUIRED cpputest gtkmm-2.4 )
include_directories( ${MYPKG_INCLUDE_DIRS} )

# euler2d
add_library( euler2d STATIC src/euler2d/Vecteur2d.cpp )

# euler2d_cli
add_executable( euler2d_cli.out src/euler2d_cli/euler2d_cli.cpp )
target_link_libraries( euler2d_cli.out ${MYPKG_LIBRARIES} euler2d )

# euler2d_gui
add_executable( euler2d_gui.out src/euler2d_gui/euler2d_gui.cpp 
    src/euler2d_gui/Dessin.cpp )
target_link_libraries( euler2d_gui.out ${MYPKG_LIBRARIES} euler2d )

# tests
add_executable( tests.out src/tests/tests.cpp 
    src/tests/Vecteur2d_test.cpp )
target_link_libraries( tests.out ${MYPKG_LIBRARIES} euler2d )

# install binaries
install (TARGETS euler2d_cli.out euler2d_gui.out DESTINATION bin)

