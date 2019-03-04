/*The graph of error vs. step on a logscale starts flat but takes a sharp bend
downward after about 100 steps. This means that the as the numbers of steps inceases, the error decreases. The most accurate region of the graph is after a large number of steps. Only the flat portion of the graph at the beginning resembleda power law. With a linear fit of the region, I found the power to be -3.

Summing downward is more precise because starting with the smallest number forces the computer to look at the most decimal places. With summing up, the first number is 1, and the computer in single precision will look at the ones place and ignore decimals as it adds smaller numbers.
*/


// Lucas Jose Chaves Hossi
// hossiluc@msu.edu
// 5-Feb-2019 created program
// For some odd reason seems like the result is a litle off but can't figure out how to fix it

//including header file
#include "sum_header.h"

int main()
{
 //creating output file
 ofstream output;
 output.open("summing.dat");

 //define number of steps
 const int N = 1000;

 //get the values from the sum_up and sum_down functions
 vector <float> sum1 = up(N);
 vector <float> sum2 = down(N);
 
 //column headers
 output <<"N"<<"     "<<"Sum up"<<"     "<< "Sum down"<<endl; 
 //print out the values into a file
 for(int i= 0; i < N; i++)
   {
     output << i+1 << "      "<< setprecision(8) <<sum1[i]<<"       " <<sum2[i]<<endl;
   }

 output.close(); 
 return 0;
}


