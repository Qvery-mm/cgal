#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/Polyhedron_3.h>
#include <CGAL/Surface_mesh.h>
#include <CGAL/Nef_polyhedron_3.h>
#include <CGAL/boost/graph/convert_nef_polyhedron_to_polygon_mesh.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <CGAL/Extended_cartesian.h>
#include <CGAL/Exact_integer.h>
#include <CGAL/Extended_homogeneous.h>
#include <CGAL/Gmpq.h>
#include "global.h"

//typedef CGAL::Exact_predicates_exact_constructions_kernel Exact_kernel;
////////////////////typedef CGAL::Extended_homogeneous<NT>  Exact_kernel;
typedef CGAL::Polyhedron_3<Exact_kernel> Polyhedron;
typedef CGAL::Surface_mesh<Exact_kernel::Point_3> Surface_mesh;
typedef CGAL::Nef_polyhedron_3<Exact_kernel> Nef_polyhedron;

Surface_mesh convertToSurfaceMesh(Nef_polyhedron);