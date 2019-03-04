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
//   1. output the answer with higher precision (more digits)
//   2. use a "predefined" value of pi or generate it with atan
//   3. define an inline square function
//   4. split the calculation off into a function (subroutine)
//   5. output to a file (and/or input from a file)
//   6. add checks of the input (e.g., for non-positive radii)
//   7. rewrite using a Circle class
//
//*********************************************************************// 

// include files
#include <iostream>
#include <math.h>
#include <fstream>
#include <iomanip>
using namespace std;
	      

//*********************************************************************//

// Lucas Jose Chaves Hossi
// hossiluc@msu.edu
// 5-Feb-2019 attempeted completion of 1-6 

// inline square function
inline double sqr(double x)
{

return x*x;

}

int main ()
{

// creating file to output to
  ofstream output;
  output.open("area_new.dat");

  double radius;    // every variable is declared as int or double or ...

  cout << "Enter the radius of a circle: ";	// ask for radius
  cin >> radius;

// checking to make sure the radius is positive  
  if(radius < 0)
  {
  output << "Radius must be positive";
  }

// if it is positive, the calculation goes through
  else
  {

// using math.h defined pi value and  sqaure function to calculate area
  double area = M_PI * sqr(radius);	// standard area formula

// output to file with 16 digits
  output << "radius = " << setprecision(16) << radius << ",  area = "<< setprecision(16) << area << endl;

// close file
  output.close();
  }

  return 0;			// "0" for successful completion
}

//*********************************************************************//
