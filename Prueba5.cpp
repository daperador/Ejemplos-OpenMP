#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

void mxv(int m, int n, double * a, double * b, double * c){
    int i, j;
    //omp_set_num_threads(8);
    //#pragma omp parallel for default(none) shared(m,n,a,b,c) private(i,j)
    for (i=0; i<m; i++)
    {
        a[i] = 0.0;
        for (j=0; j<n; j++)
            a[i] += b[i*n+j]*c[j];
    }/*-- End of omp parallel for --*/
}


int main(int argc, char *argv[]){
    time_t start,end1,end2,end3;
    start=clock();
    double *a,*b,*c;
    int i, j, m, n;

    printf("Please give m and n: ");
    //scanf("%d %d",&m,&n);
    m = 10000;
    n = 10000;

    if ( (a=(double *)malloc(m*sizeof(double))) == NULL )
        perror("memory allocation for a");
    if ( (b=(double *)malloc(m*n*sizeof(double))) == NULL )
        perror("memory allocation for b");
    if ( (c=(double *)malloc(n*sizeof(double))) == NULL )
        perror("memory allocation for c");

    printf("Initializing matrix B and vector c\n");
    for (j=0; j<n; j++)
        c[j] = 2.0;
    for (i=0; i<m; i++)
        for (j=0; j<n; j++)
            b[i*n+j] = i;

    printf("Executing mxv function for m = %d n = %d\n",m,n);
    end1=clock();
    printf("Duracion1: %ld\n",(end1-start));
    (void) mxv(m, n, a, b, c);
    end2=clock();
    printf("Duracion2: %ld\n",(end2-end1));

    free(a);free(b);free(c);
    end3=clock();
    printf("Duracion2: %ld\n",(end3-end2));

    return(0);
}

