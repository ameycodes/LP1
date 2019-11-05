#include<iostream>
#include<bits/stdc++.h>
#include<omp.h>
using namespace std;

#define size 100000

int vect1[size], vect2[size];
int result[size];

void sequential_vector_addition() {

    
    memset(result, 0, 100000);
    double starttime = omp_get_wtime();
    for(int i=0;i<size;i++) {
        result[i] = vect1[i] + vect2[i];
    }
    double endtime = omp_get_wtime();

    cout<<"Sequential vector addition:  ";
    cout<<endtime-starttime<<endl;
}


void parallel_vector_addition(int t) {
    
    memset(result, 0, 100000);
    double starttime = omp_get_wtime();
    #pragma omp parallel for collapse(1) num_threads(t)
    for(int i=0;i<size;i++) {
        result[i] = vect1[i] + vect2[i];
    }
    double endtime = omp_get_wtime();

    cout<<"Parallel vector addition with ";
    cout<<t<<" threads: "<<endtime-starttime<<endl;
}


int main(){


    for(int i=0;i<size;i++){
        vect1[i]=rand();
        vect2[i]=rand();
    }

    sequential_vector_addition();
    parallel_vector_addition(2);
    parallel_vector_addition(3);
    parallel_vector_addition(4);

}
