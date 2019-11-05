#include <bits/stdc++.h>
#include<omp.h>
#include<windows.h>
using namespace std;

#define size 10000
int matrix[size][size];
int vect[size];
int result[size];

void sequential_matrix_vector_multiplication() {
    
    memset(result, 0, 10000);
    double starttime = omp_get_wtime();
    for(int i=0;i<size;i++) {
        for(int j=0;j<size;j++) {
            result[i] += matrix[j][i] * vect[i];
        }
    }
    Sleep(1000);
    double endtime = omp_get_wtime();



    cout<<"\n\nSequential matrix vector multiplication operation: ";
    cout<<endtime-starttime<<endl;
}


void parallel_matrix_vector_multiplication(int t) {
    

    memset(result, 0, 10000);
    double starttime = omp_get_wtime();

    #pragma omp parallel for collapse(2) num_threads(t)
    for(int i=0;i<size;i++) {
        for(int j=0;j<size;j++) {
            result[i] += matrix[j][i] * vect[i];
        }
    }
    double endtime = omp_get_wtime();

    cout<<"\nParallel matrix vector multiplication operation:  ";
    cout<<t<<" Threads: "<<endtime-starttime;

}

int main() {
    
    for(int i=0;i<size;i++) {
        for(int j=0;j<size;j++) {
            matrix[i][j] = rand();
        }
        vect[i] = rand();
    }

    sequential_matrix_vector_multiplication();
    parallel_matrix_vector_multiplication(2);
    parallel_matrix_vector_multiplication(3);
    parallel_matrix_vector_multiplication(4);

}
