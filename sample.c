#include <math.h>
#include <stdlib.h>
#include <stdio.h>


double randn(double mu, double sigma)
{/* initialize elements of array n to 0 */
   

        double U1, U2, W, mult;
	static double X1, X2;
	static int call = 0;

	double aleatorio=0.0;

	  if (call == 1)
	    {
	      call = !call;
	      return (mu + sigma * (double) X2);
	    }

	  do
	    {
	      U1 = -1 + ((double) rand () / RAND_MAX) * 2;
	      U2 = -1 + ((double) rand () / RAND_MAX) * 2;
	      W = pow (U1, 2) + pow (U2, 2);
	    }
	  while (W >= 1 || W == 0);

	  mult = sqrt ((-2 * log (W)) / W);
	  X1 = U1 * mult;
	  X2 = U2 * mult;

	  call = !call;

	  return(mu + sigma * (double) X1);
 /* set element at location i to i + 100 */
}

void* generator (double N, double mu, double sigma)
{
	double* values; 
	values = malloc(sizeof(double *)*N);

	int i; 
	for ( i = 0; i < N; i++)
	{
	values[i] = randn(mu, sigma);
	}

	FILE *sample = fopen("sample.dat", "w");

	for(int i = 0; i < N; i++)
	{
	fprintf(sample, "%f", values[i]);
	fprintf(sample, "\n");
	}
	fclose(sample);
	
}

void main(int argc, char *argv[]) {

	int N=1000; /*atoi(argv[0])*/
	double mu=3.0; /*atof(argv[1])*/
	double sigma=0.5;/*atof(argv[2])*/
	generator(N,mu,sigma);
   }

