//Lucas Jose Chaves Hossi
//hossiluc@msu.edu
//25-Feb-2019 created program
//analysis on 28th, Feb 2019




// include files
#include "integ_routines.h"   // integration routine prototypes 

// Integration using Simpson's rule
double simpsons_rule ( int num_pts, float x_min, float x_max, 
                      double (*integrand) (double x) )
{  
   float interval = ((x_max - x_min)/float(num_pts - 1));  // called h in notes
   float sum=  0.;  // initialize integration sum to zero		 
   
   double x1, x2;
   for (int n=2; n<num_pts; n+=2)  // step through the integral, 2 points at a time  
   {
     x1 = x_min + interval * (n-1);
     x2 = x1 + interval;
     sum += 4. * integrand(x1) + 2. * integrand(x2);
   }
   sum += integrand(x_min) - integrand(x_max);    
   sum *= interval/3.; 
   return (sum);
}  

// Integration using Milne's rule
double milne_rule ( int num_pts, float x_min, float x_max,
                      double (*integrand) (double x) )
{
   float interval = ((x_max - x_min)/float(num_pts - 1));  // called h in notes
   float sum=  0.;  // initialize integration sum to zero 

               
   double x1, x2, x3; 
   for (int n=2; n<num_pts; n+=4)  // step through the integral, 4 points at a time  
   {
     x1 = x_min + interval * (n-1);
     x2 = x1 + interval;
     x3 = x2 + interval;

     sum += 2.*integrand(x1) - integrand(x2) + 2.*integrand(x3);

   }
   sum +=  integrand(x_min) -  integrand(x_max);
   sum *= interval*(4./3.);

   return (sum);
}

//GSL integrator(qags)
double GSL_integ ( float x_min, float x_max,
                      double (*integrand) (double x, void *params) )
{            

   gsl_integration_workspace *work_ptr 
    = gsl_integration_workspace_alloc (1000);
  
  double abs_error = 1.0e-8;    /* to avoid round-off problems */
  double rel_error = 1.0e-8;    /* the result will usually be much better */
  double result;                /* the result from the integration */
  double error;                 /* the estimated error from the integration */
  
  double alpha = 1.0;           // parameter in integrand
  
  gsl_function My_function;
  void *params_ptr = &alpha;

  My_function.function = integrand;
  My_function.params = params_ptr;

  gsl_integration_qags (&My_function, x_min, x_max,
                        abs_error, rel_error, 1000, work_ptr, &result,
                        &error);


   return (result);
}








