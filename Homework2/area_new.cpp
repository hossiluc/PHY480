//  file: area.cpp
//
//  This program calculates the area of a circle, given the radius.
//
//  Programmer:  Dick Furnstahl  furnstahl.1@osu.edu
//
//  Revision history:
//      02-Jan-2004  original version, for 780.20 Computational Physics
//      01-Jan-2010  updates to "To do" wishlist
//      12-Jan-2016  comment out "using namespace std;"
//
//  Notes:  
//   * compile with:  "g++ -o area.x area.cpp"
//
//  To do:
//   1.  D- output the answer with higher precision (more digits) 
//   2.  D- use a "predefined" value of pi or generate it with atan
//   3.  D- define an inline square function
//   4.  D- split the calculation off into a function (subroutine)
//   5. output to a file (and/or input from a file)
//   6. add checks of the input (e.g., for non-positive radii)
//   7. rewrite using a Circle class
//
//*********************************************************************// 

// include files
#include <iostream>	     // this has the cout, cin definitions
#include <iomanip>       
#include <cmath>
using namespace std;     // if omitted, then need std::cout, std::cin 

//*********************************************************************//

//const double pi = 3.1415926535897932385;   // define pi as a constant 
inline int square_function(double r){
	return pow(r,2);}

int
main ()
{	int order=1;
	ofstream data_out("Area_new.dat", ios::out);
  	data_out << "# Area of circle,"  << endl;

  double radius;    // every variable is declared as int or double or ...

  cout << "Enter the radius of a circle: ";	// ask for radius
  cin >> radius;

  double area = M_PI * square_function(radius);	// standard area formula

  data_out << "radius = " << radius << setprecision (8)  << ",  area = " << area <<endl;

  return 0;			// "0" for successful completion
}

//*********************************************************************//
