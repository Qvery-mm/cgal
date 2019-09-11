/*
* 
*
**/

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
#include <boost/multiprecision/gmp.hpp>
#include <boost/multiprecision/mpfr.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <CGAL/Exact_predicates_exact_constructions_kernel.h> 

typedef CGAL::Nef_polyhedron_3<Kernel_nef>  Nef_polyhedron;
typedef Kernel_nef::Plane_3  Plane_3;
typedef Kernel_nef::Point_3 Point;
typedef CGAL::Polyhedron_3<Kernel_nef>  Polyhedron;

struct Point_m
{
	int x, y, z;
	long long SqDist;
	Point_m(int a, int b, int c)
	{
		x = a;
		y = b;
		z = c;
	}
};

bool cmp(Point_m a, Point_m b)
{
	return a.SqDist < b.SqDist;
}



double GetSquareMaxDist(Nef_polyhedron poly)
{
	const long long INF = 1e18;
	double SquareMaxDist = 0;
	double x, y, z;
	Nef_polyhedron::Vertex_const_iterator it = NULL;
	CGAL_forall_vertices(it, poly)
	{	
		auto point = it->point();
		
		std::stringstream ss;
		ss.clear();
		std::string s1, s2, s3, s4;
		long long p, q;

		ss << point.x();
		ss >> s1 >> s2 >> s3 >> s4;
		if(s1 == "1")
			continue;
		//std::cout << "debug " << s2 << ' ' << s4 << '\n';
		ss.clear();
		ss << s2 << " " << s4;
		ss >> p >> q;
		//std::cout << "debug int" << p << ' ' << q << '\n';
		x = (double) p / q;


		ss.clear();
		ss << point.y();
		ss >> s1 >> s2 >> s3 >> s4;
		//std::cout << "debug " << s2 << ' ' << s4 << '\n';
		if(s1 == "1")
			continue;
		ss.clear();
		ss << s2 << " " << s4;
		ss >> p >> q;
		//std::cout << "debug int" << p << ' ' << q << '\n';
		y = (double) p / q;


		ss.clear();
		ss << point.z();
		ss >> s1 >> s2 >> s3 >> s4;
		//std::cout << "debug " << s2 << ' ' << s4 << '\n';
		if(s1 == "1")
			continue;
		ss.clear();
		ss << s2 << " " << s4;
		ss >> p >> q;
		//std::cout << "debug int" << p << ' ' << q << '\n';
		z = (double) p / q;
		SquareMaxDist = std::max(SquareMaxDist, x * x + y * y + z * z);
		//std::cout << x / 10000 << ' ' << y /10000 << ' ' << z / 10000 << '\n';

	}
	return SquareMaxDist;
}




Nef_polyhedron processNumber(double h, double x, double y, double *A)
{
	//globals
	std::cout << "___" << h << std::endl;
	const long long INF = 1e18;
	bool IS_BOUNDED = false;
	double SquareMinDist = 1e18;
	double SquareMaxDist = INF;
	 // x = 1.3247, y = 1.75483009 (x10^7)
	long long N = 1000000;
	long long multiplier = 10000;
	
	
	
	std::vector<Point_m> point_array;

	// for(int i = -N; i <= N; i++)
	// {
	// 	for(int j = -N; j <= N; j++)
	// 	{
	// 		for(int k = -N; k <= N; k++)
	// 		{
	// 			if((abs(i + x * k) <= 1) && (abs(j + y * k) <= 1) && (abs(k * h) <= 1) && (i != 0 || j != 0 || k != 0))
	// 			{
	// 				std::cerr << i + x * k << ' ' << j + y * k << ' ' << k * h << '\n';
	// 				point_array.push_back(Point_m(multiplier * (i + x * k), multiplier * (j + y * k), multiplier * k * h));
					
	// 			}
	// 		}
	// 	}
	// }

	double m, n, p;
	
	for(int i = -1; i <= 1; i++)
		for(int j = -1; j <= 1; j++)
			for(int k = -1; k <= 1; k++)
				if(i != 0 || j != 0 || k != 0)
					point_array.push_back(Point_m(multiplier * (i + x * k), multiplier * (j + y * k), multiplier * k * h));

	for(int k = -N; k <= N; k++)
	{
		if(k == 0)
			continue;
		m = x * k;
		n = y * k;
		p = h * k;

		if(abs(p) > 10)
			continue;

		m -= (int) m;
		n -= (int) n;
		
		if(m < 0)
			m += 1;
		if(n < 0)
			n += 1;
		//std::cerr << m << ' ' << n << ' ' << p << '\n';
		point_array.push_back(Point_m(multiplier * m, multiplier * n, multiplier * p));
		point_array.push_back(Point_m(multiplier * m, multiplier * (n - 1), multiplier * p));
		point_array.push_back(Point_m(multiplier * (m - 1), multiplier * n, multiplier * p));
		point_array.push_back(Point_m(multiplier * (m - 1), multiplier * (n - 1), multiplier * p)); 
	
	}
	int count = point_array.size();
	std::cerr << "count " << count << '\n';
	for(int i = 0; i < count; i++)
	{
		point_array[i].SqDist  = (long long) point_array[i].x * point_array[i].x + (long long) point_array[i].y * point_array[i].y + (long long) point_array[i].z * point_array[i].z;
	}
	
	std::sort(point_array.begin(), point_array.end(), cmp);
	count = std::min(count, 100);


	Plane_3 plane_array[count];
	std::vector<Nef_polyhedron> poly_array;
	for(int i = 0; i < count; i++)
	{
		
		//std::cerr << i << " plane\n";
		Point_m t = point_array[i];
		plane_array[i] = Plane_3(2 * t.x, 2 * t.y, 2 * t.z, -t.x * t.x - t.y * t.y - t.z * t.z);
	}
	
	
	for(int i = 0; i < count; i++)
	{
		//std::cerr << i << " polyhedron\n";
		try
		{
			poly_array.push_back(Nef_polyhedron(plane_array[i]));
		}
		catch(std::exception)
		{
			std::cerr << "ERROR at" << point_array[i].x << " " << point_array[i].y << " " << point_array[i].z << "\n";
		}
	}
	// std::cerr << "arr 0 "<< point_array[0].x << ' ' << point_array[0].y << ' ' << point_array[0].z << '\n';
	// std::cerr << "sqdist 0 "<< point_array[0].SqDist << '\n';
	Nef_polyhedron Cube = poly_array[0];
	SquareMinDist = (double) (point_array[0].SqDist / 4);
	for(int i = 1; i < count; i++)
	{
		//std::cerr << "IS_BOUNDED " << IS_BOUNDED << '\n';
		if(IS_BOUNDED || Cube.is_bounded())
		{
			IS_BOUNDED = true;
			SquareMaxDist = GetSquareMaxDist(Cube);
			std::cout << SquareMaxDist << '\n';
		}
		
		if(SquareMaxDist > (point_array[i].SqDist / 4))
		{   
			std::cerr << i << " cube\n";
			Cube *= poly_array[i];	
	    }
		
	}
	
	SquareMaxDist = GetSquareMaxDist(Cube);

	std::cout << "max " << (double) std::sqrt(SquareMaxDist) / multiplier << '\n';
	std::cout << "min " << (double) std::sqrt(SquareMinDist) / multiplier << '\n'; 

	*A = std::sqrt(SquareMaxDist) / std::sqrt(SquareMinDist);
	// std::ofstream out1("New" + std::to_string(i) + ".nef3");
	// out1 << Cube;
	// out1.close();
    return Cube;
}


Nef_polyhedron_t make_voronoi_cell()
{
	double x = 2.71828183, y = 7.38905611;
	double h = 1;
	int N = 200;
	//std::cout << "Input N: ";
	//std::cin >> N;
	
	double A;
	Nef_polyhedron r;

	for(int i = 1; i <= N; i++)
	{
	    r = processNumber(h / ( i * i), x, y, &A);
	    std::ofstream output("A(h) - 3.txt", std::ofstream::app);
	    std::cout << "i " << i << '\n';
	    std::cout << "A(n) = " << A << '\n';
		output << i * i << ' ' << A << '\n';
		output.close();
	}

	x = 1.61803399, y = 0.618033999;
    h = 1;
	
	//std::cout << "Input N: ";
	//std::cin >> N;
	
	

	for(int i = 1; i <= N; i++)
	{
	    r = processNumber(h / ( i * i), x, y, &A);
	    std::ofstream output("A(h) - 4.txt", std::ofstream::app);
	    std::cout << "i " << i << '\n';
	    std::cout << "A(n) = " << A << '\n';
		output << i * i << ' ' << A << '\n';
		output.close();
	}

	
	return r;
}