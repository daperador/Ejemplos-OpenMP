#include <omp.h>
#include <stdio.h>

int main(){
    switch (_OPENMP){
        case 200805:
            printf("hola mundo 200805");
            break;
        case 200505:
            printf("hola mundo 200505");
            break;
        default:
            printf("hola mundo %d",_OPENMP);
    }


    return 0;
}
