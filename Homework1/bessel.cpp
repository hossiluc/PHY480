/*
The logscale graph of the bessel function error takes a large dip down with increasing  x, levels out and then shoots back up.  
Looks to me like at a certain range the result for x values is the same whether we sum up or sum down.  
The first part of the graph is a downward slope representing it is approaching the  region stability,meaning that  a small x and large x the relative difference is of order 1
*/

//Lucas Jose Chaves Hossi
//hossiluc@msu.edu
//5-Feb-2019 last modified


// include files
#include <iostream>		// note that .h is omitted
#include <iomanip>		// note that .h is omitted
#include <fstream>		// note that .h is omitted
#include <cmath>
#include <gsl/gsl_sf_bessel.h>
using namespace std;		// we need this when .h is omitted

// function prototypes 
double down_recursion (double x, int n, int m);	// downward algorithm 
double up_recursion (double x, int n);	        // upward algorithm 

// global constants  
const double xmax = 100.0;	// max of x  
const double xmin = 0.1;	// min of x >0  
const double step = 0.1;	// delta x  
const int order = 10;		// order of Bessel function 
const int start = 50;		// used for downward algorithm 

//********************************************************************
int
main ()
{
  double ans_down, ans_up, ans_gsl;

  // open an output file stream
  ofstream my_out ("bessel.dat");

  my_out << "# Spherical Bessel functions via up and down recursion" 
         << endl;
  my_out <<"x"<< setw (18) << "ans_down"
      << setw (18) << "ans_up"
      << setw (18) << "error"
      << setw (18) << "ans_gsl"
      << endl;

  // step through different x values
  for (double x = xmin; x <= xmax; x += step)
    {
      ans_down = down_recursion (x, order, start);
      ans_up = up_recursion (x, order);
      ans_gsl = gsl_sf_bessel_j1(x);

      my_out << fixed << setprecision (8) << setw (10) << x << " "
	<< scientific << setprecision (8)
	<< setw (15) << ans_down << " "
	<< setw (15) << ans_up 
	<< setw (15) << abs(ans_down-ans_up)/(abs(ans_down)+abs(ans_up))
        << setw (15) << ans_gsl
	<< endl;
    }
  cout << "data stored in bessel.dat." << endl;

  // close the output file
  my_out.close ();
  return (0);
}


//------------------------end of main program----------------------- 

// function using downward recursion  
double
down_recursion (double x, int n, int m)
{
  double j[start + 2];		// array to store Bessel functions 
  j[m + 1] = j[m] = 1.;		// start with "something" (choose 1 here) 
  for (int k = m; k > 0; k--)
    {
      j[k - 1] = ((2.* double(k) + 1.) / x) * j[k] - j[k + 1];  // recur. rel.
    }
  double scale = (sin (x) / x) / j[0];	// scale the result 
  return (j[n] * scale);
}


//------------------------------------------------------------------ 

// function using upward recursion  
double
up_recursion (double x, int n)
{
  double term_three = 0.;
  double term_one = (sin (x)) / x;	// start with lowest order 
  double term_two = (sin (x) - x * cos (x)) / (x * x);	// next order
  for (int k = 1; k < n; k += 1)	// loop for order of function     
    { // recurrence relation
      term_three = ((2.*double(k) + 1.) / x) * term_two - term_one;	       
      term_one = term_two;
      term_two = term_three;
    }
  return (term_three);
}
