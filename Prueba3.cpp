#include  <omp.h >
#include  <stdio.h >
#include  <time.h >
#include  <sys/time.h>

int main (int argc, char *argv[])
{
    time_t start,end1,end2;
    start=clock();

    double area,x;
    int i,n;
    area = 0.0;
    printf("n=");
    //scanf("%d",&n);
    n = 10000000;
    end1=clock();
    printf("Duracion1: %ld\n",(end1-start));
    printf("Paralelo %d \n", n);
    omp_set_num_threads(8);
    #pragma omp parallel for private(x) reduction(+:area)
    for (i=0;i<n;i++)
    {     x=(i+0.5)/n;
          area += 4.0/(1.0+x*x);
    }
    end2=clock();
    printf("Duracion2: %ld\n",(end2-end1));
    printf("pi = %lf\n", area/n);
    return 0;
}
