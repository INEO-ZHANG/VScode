#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<time.h>
clock_t start, end;

#define MAX(X,Y) (X > Y?X:Y)

unsigned long Buffon(double a, double b, double l, unsigned long numTrials);

int main(int argc, char* argv[])
{
    unsigned long N, iters = 0;
    double a, b, l;
    double x, y;
    double x0, y0, phi;
    unsigned long hits = 0;
    double P;

    if (argc < 5){
        fprintf(stderr,"%s a b l N\n", argv[0]);
        exit(-1);
    }


    a = atof(argv[1]);
    b = atof(argv[2]);
    l = atof(argv[3]);
    N = atol(argv[4]);

    if (a <=0 ||  b <= 0 || l <=0 || l >= MAX(a,b)){
        fprintf(stderr,"Invalid input\n");
        exit(-1);
    }
  
    srand((unsigned int)time((time_t *)NULL));
    start = clock();
    hits = Buffon(a, b, l, N);
    end = clock();
    double endtime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("time=%f ms", endtime * 1000);
    P = ((double)hits)/N;
  
    double myPI = (2*l*(a+b)-l*l)/a/b/P;
    printf("PI = %lf",myPI);

}


unsigned long Buffon(double a, double b, double l, unsigned long N)
{

  unsigned long iters = 0, hits = 0;
  double x, y, x0, y0, phi;
  
  for (iters = 0; iters < N; iters++){
    x0  = a*rand()/RAND_MAX;
    y0  = b*rand()/RAND_MAX;
    
    x = x0+l*cos(phi);
    y = y0+l*sin(phi);
    
    hits += (x<=0.0 || x >= a || y <= 0.0 || y >= b)?1:0;
  }

  return hits;
}
