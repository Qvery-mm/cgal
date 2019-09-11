
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


//typedef CGAL::Spherical_kernel_3<CGAL::Exact_integer> Kernel_nef;
//typedef CGAL::Extended_homogeneous<NT> Kernel_nef;

typedef CGAL::Nef_polyhedron_3<Kernel_nef>  Nef_polyhedron;
typedef Kernel_nef::Plane_3  Plane_3;
typedef Kernel_nef::Point_3 Point;
typedef CGAL::Polyhedron_3<Kernel_nef>  Polyhedron;


Nef_polyhedron_t createPolyhedron()
{
 

 //  Nef_polyhedron_t N1(Plane_3(1, 0, 0, -1));	
 //  Nef_polyhedron_t N2(Plane_3(-1, 0, 0, -1));
 //  Nef_polyhedron_t N3(Plane_3(1, 1, 0, -1));
 //  Nef_polyhedron_t N4(Plane_3(0, -1, 0, -1));
 //  Nef_polyhedron_t N5(Plane_3(0, 0, 1, -1));
 //  Nef_polyhedron_t N6(Plane_3(0, 0, -1, -1));


	// // Plane_3 pp(0, 0, -1, -1);
	// // Nef_polyhedron_t poly(pp, Nef_polyhedron_t::INCLUDED);
 //  Nef_polyhedron_t Cube = N1 * N2 * N3 * N4 * N5 * N6;
 //  if(Cube.is_bounded()) 
 //  {
 //    std::ofstream out("temp.nef3");
 //    out << Cube;
 //    out.close();
 //    std::cerr << "Cube loaded" << std::endl;
 //  }
	// Point p1(0, 0, 1);
	// Point p2(1, -1, 0);
	// Point p3(1, 1, 0);
	// Point p4(-1, 1, 0);
	// Point p5(-1, -1, 0);
	// Point p6(0, 0, -0.5);

	// Plane_3 plane1(p1, p2, p3);
	// Plane_3 plane2(p1, p3, p4);
	// Plane_3 plane3(p1, p4, p5);
	// Plane_3 plane4(p1, p5, p2);

	// Plane_3 plane5(p6, p2, p3);
	// Plane_3 plane6(p6, p3, p4);
	// Plane_3 plane7(p6, p4, p5);
	// Plane_3 plane8(p6, p5, p2);	

	// Nef_polyhedron poly1(plane1);
	// Nef_polyhedron poly2(plane2);
	// Nef_polyhedron poly3(plane3);
	// Nef_polyhedron poly4(plane4);

	// Nef_polyhedron poly5(plane5);
	// Nef_polyhedron poly6(plane6);
	// Nef_polyhedron poly7(plane7);
	// Nef_polyhedron poly8(plane8);
	Point p1(1, -1, 0);
	Point p2(1, 1, 0);
	Point p3(-1, 1, 0);
	Point p4(-1, -1, 0);

	Point p5(1, -1, 1);
	Point p6(1, 1, 1);
	Point p7(-1, 1, 1);
	Point p8(-1, -1, 1);

	Plane_3 plane1(p1, p2, p3);
	Plane_3 plane2(p1, p2, p7);
	Plane_3 plane3(p3, p4, p5); //p5

	Plane_3 plane4(p1, p4, p5);
	Plane_3 plane5(p2, p3, p6);

	Nef_polyhedron poly1(plane1);
	Nef_polyhedron poly2(plane2);
	Nef_polyhedron poly3(plane3);
	Nef_polyhedron poly4(plane4);

	Nef_polyhedron poly5(plane5);
	int a, b, c, d, e;
	std::cin >> a >> b >> c >> d >> e;

	Nef_polyhedron Cube = (a ? poly1 : ! poly1) * (b ? poly2 : ! poly2) * (c ? poly3 : ! poly3) * (d ? poly4 : ! poly4) * (e ? poly5 : ! poly5);
	std::ofstream out1("prism.nef3");
	out1 << Cube;
	out1.close();

	std::cout << Cube.number_of_vertices() << std::endl;;
    return Cube;
}


// 0 1 1 0 1
