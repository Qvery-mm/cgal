#include "DrawMesh.h"
#include "ConvertToSurfaceMesh.h"
#include "ConstructPolyhedron.h"
#include "make_voronoi.h"
#include <string>
#include "NumberProcessing.h"


int main()
{
  Nef_polyhedron poly;
  poly = make_voronoi_cell();
  
  
  //drawMesh(convertToSurfaceMesh(poly));
  return 0;
}
