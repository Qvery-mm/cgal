#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
//#include <CGAL/Exact_predicates_exact_constructions_kernel_with_sqrt.h>
#include <CGAL/Surface_mesh.h>
#include <CGAL/boost/graph/helpers.h>
#include <CGAL/draw_surface_mesh.h>
#include <CGAL/Extended_cartesian.h>
#include <CGAL/Exact_integer.h>
#include <CGAL/Extended_homogeneous.h>
#include <CGAL/Gmpq.h>
#include "global.h"

#define CGAL_USE_BASIC_VIEWER 1
//typedef CGAL::Exact_predicates_exact_constructions_kernel K;


/////////////////////typedef CGAL::Extended_homogeneous<NT>  K;
//typedef CGAL::Exact_predicates_exact_constructions_kernel_with_sqrt K; //also work
typedef K::Point_3 Point;
typedef CGAL::Surface_mesh<Point> Mesh;


int drawMesh(Mesh);