cmake_minimum_required(VERSION 3.1)
project(analysis)
#CGAL_Qt5 is needed for the drawing and CGAL_Core is needed for this special Kernel.

find_package(CGAL REQUIRED COMPONENTS Qt5 Core)
#find_package(Boost REQUIRED COMPONENTS thread)

if(CGAL_FOUND AND CGAL_Qt5_FOUND)
  #required to use basic_viewer
  add_definitions(-DCGAL_USE_BASIC_VIEWER -DQT_NO_KEYWORDS)
  #create the executable of the application
  
  add_executable(main_ main.cpp DrawMesh.cpp DrawMesh.h  ConstructPolyhedron.cpp ConstructPolyhedron.h global.h ConvertToSurfaceMesh.cpp ConvertToSurfaceMesh.h make_voronoi.cpp make_voronoi.h NumberProcessing.cpp NumberProcessing.h)
  #add_executable(main_ main.cpp ConstructPolyhedron.cpp ConstructPolyhedron.h)
  #link it with the required CGAL libraries
  target_link_libraries(main_ CGAL::CGAL CGAL::CGAL_Qt5 CGAL::CGAL_Core  ${CGAL_LIBRARIES}  ${CGAL_3RD_PARTY_LIBRARIES})
else()
  message("ERROR: this program requires CGAL and CGAL_Qt5 and will not be compiled.")
endif()
