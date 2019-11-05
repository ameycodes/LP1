#include<iostream>
#include<omp.h>
using namespace std;

#define size 1000
int mat1[size][size],mat2[size][size];
int result[size][size];

void sequential(){

    double starttime=omp_get_wtime();
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            for(int k=0;k<size;k++){
                result[i][j]+=mat1[i][k]*mat2[k][j];
            }
        }
    }
    double endtime=omp_get_wtime();
    cout<<"Sequential time: "<<endtime-starttime<<endl;

}

void parallel(int t){
    double starttime=omp_get_wtime();
    #pragma omp parallel for collapse(3) num_threads(t)
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            for(int k=0;k<size;k++){
                result[i][j]+=mat1[i][k]*mat2[k][j];
            }
        }
    }
    double endtime=omp_get_wtime();
    cout<<"Parallel time: "<<endtime-starttime<<endl;
}

int main(){
     for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            mat1[i][j]=rand()%size;
            mat2[i][j]=rand()%size;
        }
    }
    sequential();
    parallel(2);
    parallel(3);
}