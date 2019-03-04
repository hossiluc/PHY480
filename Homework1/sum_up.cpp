// Lucas Jose Chaves Hossi
// hossiluc@msu.edu
// 5-Feb-2019 created program  trying to use vectors

//include header file
#include "sum_header.h"

//creating a function that will return a vector of values
vector<float> up(int N)
{
  vector<float> sum2;
  float num = 0;

  //Summing up loop
  for(int i= N; i > 0; i--)
  {
    num += (float)1/i;
    sum2.push_back(num);  
  }
  
return sum2;
}




 
