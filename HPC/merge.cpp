#include<iostream>
#include<omp.h>
using namespace std;
#define size 200000
int a[size];

void merge(int left[],int right[],int nl,int nr,int a[]){

    int i=0,j=0,k=0;

    while(i<nl && j<nr){
        if(left[i]< right[j])
            a[k++]=left[i++];
        else
            a[k++]=right[j++];
    }

    while(i<nl)
        a[k++]=left[i++];
    while(j<nr)
        a[k++]=right[j++];    
}

void mergesort(int a[],int n){


    if(n<2)
        return;
    
    int mid=n/2;
    int left[mid];
    int right[n-mid];

    for(int i=0;i<mid;i++)
        left[i]=a[i];
    for(int i=mid;i<n;i++)
        right[i-mid]=a[i];

    mergesort(left,mid);
    mergesort(right,n-mid);
    merge(left,right,mid,n-mid,a);       
}

void parallelmergesort(int a[],int n,int t){


    if(n<2)
        return;
    
    int mid=n/2;
    int left[mid];
    int right[n-mid];

    for(int i=0;i<mid;i++)
        left[i]=a[i];
    for(int i=mid;i<n;i++)
        right[i-mid]=a[i];

    #pragma omp parallel sections num_threads(t)
    {   
        #pragma omp section
        {
            mergesort(left,mid);
        }
        #pragma omp section
        {    
            mergesort(right,n-mid);
        }
    }    
        merge(left,right,mid,n-mid,a);       
}

int main(){

    for(int i=0;i<size;i++){
        a[i]=rand()%size;
    }

    double starttime=omp_get_wtime();
    mergesort(a,size);
    double endtime=omp_get_wtime();
    cout<<"Serial Merge Sort time: "<<endtime-starttime<<endl;
    starttime=omp_get_wtime();
    parallelmergesort(a,size,2);
    endtime=omp_get_wtime();
    cout<<"Parallel Merge Sort time: "<<endtime-starttime<<endl;
    // for(int i=0;i<size;i++){
    //     cout<<a[i]<<" ";
    // }
}