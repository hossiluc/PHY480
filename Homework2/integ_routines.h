//Lucas Jose Chaves Hossi
//hossiluc@msu.edu
//24-Feb-2019 created program

//initializing libraries and functions we will use
#ifndef header
#define header

// include files
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <gsl/gsl_integration.h>
using namespace std;

//Declaring all needed functions
double my_integrand (double x);
double my_gsl_integrand (double x, void *);

extern double simpsons_rule ( int num_pts, float x_min, float x_max, 
                       double (*integrand) (double x) );    // Simpson's rule 
   
extern double milne_rule ( int num_pts, float x_min, float x_max,
                       double (*integrand) (double x) );    // Milne's rule 

extern double GSL_integ ( float x_min, float x_max,
                       double (*integrand) (double x, void *params) );    // GSL integration  
#endif
