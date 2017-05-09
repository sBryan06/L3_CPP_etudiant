CMAKE_MINIMUM_REQUIRED( VERSION 3.0 )
project( taxi )
set( CMAKE_CXX_STANDARD 14 )

set( CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++14 ${CMAKE_CXX_FLAGS} ")
#FIND_PACKAGE( Poco REQUIRED Foundation Data DataSQLite )
#INCLUDE_DIRECTORIES( ${Poco_INCLUDE_DIR} )

FIND_PACKAGE( Boost REQUIRED COMPONENTS iostreams system filesystem )

FIND_PACKAGE( PkgConfig REQUIRED )
pkg_check_modules( Pkg REQUIRED gtkmm-3.0 libglog )
INCLUDE_DIRECTORIES( ${Pkg_INCLUDE_DIRS} )

ADD_EXECUTABLE( taxi.out 
    src/taxi.cpp 
    src/GuiWindow.cpp )
TARGET_LINK_LIBRARIES( taxi.out 
    ${Poco_LIBRARIES} -lPocoFoundation -lPocoData -lPocoDataSQLite
    ${Pkg_LIBRARIES} 
    ${Boost_LIBRARIES} )

install (TARGETS taxi.out DESTINATION bin)

