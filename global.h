#include <CGAL/Exact_integer.h>
#include <CGAL/Extended_homogeneous.h>
//#include <CGAL/leda_rational.h>
#include <CGAL/Quotient.h>
#include <CGAL/Gmpq.h>
#include <CGAL/Gmpz.h>
#include <CGAL/Filtered_extended_homogeneous.h>

/*
//types
Gmpz
Exact_integer
Lazy_exact_nt<CGAL::Gmpq 




*/


typedef CGAL::Exact_integer NT;

typedef CGAL::Extended_homogeneous<NT>  K;
typedef CGAL::Extended_homogeneous<NT> Kernel_nef;
typedef CGAL::Extended_homogeneous<NT> Exact_kernel;

// typedef CGAL::Exact_predicates_exact_constructions_kernel  K;
// typedef CGAL::Exact_predicates_exact_constructions_kernel Kernel_nef;
// typedef CGAL::Exact_predicates_exact_constructions_kernel Exact_kernel;