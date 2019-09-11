#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/Surface_mesh.h>
#include <CGAL/boost/graph/helpers.h>
#include <CGAL/Exact_integer.h>
#include <CGAL/draw_surface_mesh.h>
#include <CGAL/Extended_cartesian.h>
#include <CGAL/Extended_homogeneous.h>
#include <CGAL/Gmpq.h>

#include "DrawMesh.h"
#include "global.h"
#define CGAL_USE_BASIC_VIEWER 1
//typedef CGAL::Exact_predicates_exact_constructions_kernel K;
//typedef CGAL::Extended_cartesian< CGAL::Lazy_exact_nt<CGAL::Gmpq> > K;
//typedef CGAL::Exact_predicates_exact_constructions_kernel_with_sqrt K; //also work
///////////////typedef CGAL::Extended_homogeneous<NT>  K;
typedef K::Point_3 Point;
typedef CGAL::Surface_mesh<Point> Mesh;


int drawMesh(Mesh m)
{
  Mesh i;
  // Mesh::Vertex_index u = m.add_vertex(Point(0,10,0));
  // Mesh::Vertex_index v = m.add_vertex(Point(0,0,0));
  // Mesh::Vertex_index w = m.add_vertex(Point(10,0,0));
  // m.add_face(u, v, w);
 
  
  CGAL::draw(m);

  return 0;
}
