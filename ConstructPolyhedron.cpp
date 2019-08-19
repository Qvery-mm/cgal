
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/Exact_integer.h>
#include <CGAL/Extended_homogeneous.h>
#include <CGAL/Homogeneous.h>
#include <CGAL/Nef_polyhedron_3.h>
#include <CGAL/Polyhedron_3.h>
#include <bits/stdc++.h>
#include <CGAL/boost/graph/convert_nef_polyhedron_to_polygon_mesh.h>
#include <CGAL/Spherical_kernel_3.h>
#include <CGAL/Extended_cartesian.h>
#include <CGAL/IO/Nef_polyhedron_iostream_3.h>

#include "ConstructPolyhedron.h"
#include <CGAL/Gmpq.h>
#include "global.h"




#include <CGAL/Exact_predicates_exact_constructions_kernel.h> 

//typedef CGAL::Exact_predicates_exact_constructions_kernel Kernel_nef;
//typedef CGAL::Spherical_kernel_3<CGAL::Exact_integer> Kernel_nef;
//typedef CGAL::Extended_homogeneous<NT> Kernel_nef;
typedef CGAL::Nef_polyhedron_3<Kernel_nef>  Nef_polyhedron_t;
typedef Kernel_nef::Plane_3  Plane_3;
typedef CGAL::Polyhedron_3<Kernel_nef>  Polyhedron_t;


Nef_polyhedron_t createPolyhedron()
{
 

  Nef_polyhedron_t N1(Plane_3(1, 0, 0, -1));	
  Nef_polyhedron_t N2(Plane_3(-1, 0, 0, -1));
  Nef_polyhedron_t N3(Plane_3(1, 1, 0, -1));
  Nef_polyhedron_t N4(Plane_3(0, -1, 0, -1));
  Nef_polyhedron_t N5(Plane_3(0, 0, 1, -1));
  Nef_polyhedron_t N6(Plane_3(0, 0, -1, -1));


	// Plane_3 pp(0, 0, -1, -1);
	// Nef_polyhedron_t poly(pp, Nef_polyhedron_t::INCLUDED);
  Nef_polyhedron_t Cube = N1 * N2 * N3 * N4 * N5 * N6;
    if(Cube.is_bounded()) {
    std::ofstream out("temp.nef3");
    out << Cube;
    out.close();
    std::cerr << "Cube loaded" << std::endl;
//     std::ifstream in("temp.nef3");
//     in >> Cube;
//     in.close();
 }
  return Cube;
}



