#include<iostream>
#include<omp.h>
using namespace std;
#define size 100000
int a[size];

void sequential(){
    double starttime=omp_get_wtime();
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
    double endtime=omp_get_wtime();
    // for(int i=0;i<size;i++)
    //     cout<<a[i]<<" ";
    cout<<"Sequential time: "<<endtime-starttime<<endl;

}

void parallel(int t){
    double starttime=omp_get_wtime();

    
    for(int i=0;i<size;i++){
        int first=i%2;
        #pragma omp parallel for shared(a,first) num_threads(t)
        for(int j=first;j<size;j+=2){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
    double endtime=omp_get_wtime();
    // for(int i=0;i<size;i++)
    //     cout<<a[i]<<" ";
    cout<<"Parallel time with "<<t<<" threads: "<<endtime-starttime<<endl;

}

int main(){
    for(int i=0;i<size;i++){
        a[i]=rand()%size;
    }

    //sequential();
    parallel(2);
    parallel(3);
   // parallel(4);
}