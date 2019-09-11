#include <CGAL/Exact_integer.h>
#include <CGAL/Extended_homogeneous.h>
//#include <CGAL/leda_rational.h>
#include <CGAL/Quotient.h>
#include <CGAL/Gmpq.h>
#include <CGAL/Gmpz.h>
#include <CGAL/Filtered_extended_homogeneous.h>
#include <CGAL/MP_Float.h>
#include <CGAL/Exact_predicates_exact_constructions_kernel.h> 

/*
//work
Exact_integer
Gmpq
//doesn't work
Gmpz

Lazy_exact_nt<CGAL::Gmpq 
MP_Float



*/

//typedef CGAL::Gmpz NT;
typedef CGAL::Exact_integer NT;

//work
typedef CGAL::Extended_homogeneous<NT>  K;
typedef CGAL::Extended_homogeneous<NT> Kernel_nef;
//typedef CGAL::Exact_predicates_exact_constructions_kernel Kernel_nef;
typedef CGAL::Extended_homogeneous<NT> Exact_kernel;

// typedef CGAL::Exact_predicates_exact_constructions_kernel  K;
// typedef CGAL::Exact_predicates_exact_constructions_kernel Kernel_nef;
// typedef CGAL::Exact_predicates_exact_constructions_kernel Exact_kernel;