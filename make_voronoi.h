#include <CGAL/Exact_integer.h>
#include <CGAL/Extended_homogeneous.h>
#include <CGAL/Homogeneous.h>
#include <CGAL/Nef_polyhedron_3.h>
#include <CGAL/Polyhedron_3.h>
#include <bits/stdc++.h>
#include <CGAL/boost/graph/convert_nef_polyhedron_to_polygon_mesh.h>
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/Spherical_kernel_3.h>
#include <CGAL/Extended_cartesian.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Gmpq.h>
#include "global.h"


// #include <CGAL/MP_Float.h>

// typedef CGAL::MP_Float NT1;

// typedef CGAL::Extended_homogeneous<NT1> Kernel_nef;



//typedef CGAL::Extended_homogeneous<NT>  Kernel_nef;
//typedef CGAL::Exact_predicates_exact_constructions_kernel Kernel_nef;
//typedef CGAL::Spherical_kernel_3<CGAL::Exact_integer> Kernel_nef;
typedef CGAL::Nef_polyhedron_3<Kernel_nef>  Nef_polyhedron_t;
typedef Kernel_nef::Plane_3  Plane_3;
typedef CGAL::Polyhedron_3<Kernel_nef>  Polyhedron_t;

Nef_polyhedron_t make_voronoi();