
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

struct Point_m
{
	int x; int y; int z;

	Point_m(int a, int b, int c)
	{
		x = a; y = b; z = c;
	}

	Point_m()
	{
	}
};


//typedef CGAL::Spherical_kernel_3<CGAL::Exact_integer> Kernel_nef;
//typedef CGAL::Extended_homogeneous<NT> Kernel_nef;

typedef CGAL::Nef_polyhedron_3<Kernel_nef>  Nef_polyhedron;
typedef Kernel_nef::Plane_3  Plane_3;
typedef Kernel_nef::Point_3 Point;
typedef CGAL::Polyhedron_3<Kernel_nef>  Polyhedron;


Nef_polyhedron_t make_voronoi()
{
	int count;
	std::cout << "Input count of points: ";
	std::cin >> count;
	std::cout << "Input " << count << " points:\n";
	Point_m point_array[count] = {};
	int x, y, z;
	for(int i = 0; i < count; i++)
	{
		std::cin >> x >> y >> z;
		point_array[i] = Point_m(x, y, z); 
	}
 	

	Plane_3 plane_array[count];
	for(int i = 0; i < count; i++)
	{
		Point_m t = point_array[i];
		plane_array[i] = Plane_3(2 * t.x, 2 * t.y, 2 * t.z, -t.x * t.x - t.y * t.y - t.z * t.z);
	}

	Nef_polyhedron poly_array[count];

	for(int i = 0; i < count; i++)
	{
		if(point_array[i].z > 0)
			poly_array[i] = Nef_polyhedron(plane_array[i]);
		else
			poly_array[i] = Nef_polyhedron(plane_array[i]);
	}

	Nef_polyhedron Cube = poly_array[0];
	for(int i = 1; i < count; i++)
	{
		Cube *= poly_array[i];

	std::ofstream out1("New" + std::to_string(i) + ".nef3");
	out1 << Cube;
	out1.close();
	}
	Nef_polyhedron::Vertex_const_iterator it;
	CGAL_forall_vertices(it, Cube){
		std::cout << it->point() << std::endl;
	}
	std::cout << Cube.number_of_vertices() << std::endl;;
    return Cube;
}


// 0 1 1 0 1


/*
1 1 1
1 1 -1
1 -1 1
1 -1 -1
-1 1 1
-1 1 -1
-1 -1 1
-1 -1 -1

-1  0  0 
1  0  0
*/
