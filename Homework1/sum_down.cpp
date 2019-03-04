// Lucas Jose Chaves Hossi
// hossiluc@msu.edu
// 5-Feb-2019 created program

//including the header file we created
#include "sum_header.h"

//storing values on the vector
vector <float> down(int N)
{
  vector <float> sum1;
  float num = 0;
  //sum down loop
  for(int i=1; i <= N; i++)
  {
    num += (float)1/i;
    sum1.push_back(num);
    
  }
return sum1;
}
  







 
