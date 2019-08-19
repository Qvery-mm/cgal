#include "DrawMesh.h"
#include "ConvertToSurfaceMesh.h"
#include "ConstructPolyhedron.h"
#include <string>



int main()
{
  Nef_polyhedron poly;
  poly = createPolyhedron();
  
  // //std::string s;
  // Nef_polyhedron_t gg1;
  //Nef_polyhedron poly;
  // std::ifstream in("temp.nef3");
  // in >> gg1;
  // in.close();
  
  // std::ifstream in("temp.nef3");
  // in >> gg;
  // std::cout << s;
  drawMesh(convertToSurfaceMesh(poly));
  return 0;
}
