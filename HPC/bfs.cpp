#include<iostream>
#include<omp.h>
#include<queue>
using namespace std;
#define sizee 10000

int graph[sizee][sizee];
bool visited[sizee];

void serialBFS(){
    
    queue<int> q;
    q.push(0);
    visited[0]=true;

    while(!q.empty()){

        int node=q.front();
        q.pop();

        for(int i=0;i<sizee;i++){
            if(graph[node][i]==1 && !visited[i]){
                q.push(i);
                visited[i]=true;
            }
        }
    }

}

void parallelBFS(){


    queue<int> q;
    q.push(0);
    visited[0]=true;

    while(!q.empty()){

        int s=q.size();
        #pragma omp parallel for 
        for(int i=0;i<s;i++){
            int node;

            #pragma omp critical
            {
                node=q.front();
                q.pop();
            }
            #pragma omp parallel for
            for(int i=0;i<sizee;i++){
                if(graph[node][i]==1 && !visited[i]){
                    #pragma omp critical
                    {
                        q.push(i);
                        visited[i]=true;
                    }    
                }
            }
        }
    }

}

int main(){

    for(int i=0;i<sizee;i++){
        graph[i][i]=0;
        for(int j=0;j<sizee;j++){
            graph[i][j]=rand()%2;
            graph[j][i]=graph[i][j];
        }

    }
    double starttime=omp_get_wtime();
    serialBFS();
    double endtime=omp_get_wtime();
    cout<<"Serial: "<<endtime-starttime<<endl;

    for(int i=0;i<sizee;i++){
        visited[i]=false;
    }

    starttime=omp_get_wtime();
    parallelBFS();
    endtime=omp_get_wtime();
    cout<<"Parallel: "<<endtime-starttime<<endl;


}


// #include <iostream>
// #include <omp.h>
// #include <time.h>
// #include <queue>

// #define SIZE 10000

// using namespace std;

// int mat[SIZE][SIZE];
// bool visited[SIZE];

// bool isConnected(int n) {
// 	for (int i = 0; i < n; i++) {
// 		if (!visited[i]) { 
// 			return false;
// 		}
// 	}
// 	return true;
// }

// void clearVisited(int n) {
// 	#pragma omp parallel for
// 	for (int i = 0; i < n; i++) {
// 		visited[i] = false;
// 	}
// }

// void serialBFS(int node, int n) {

// 	queue<int> q;
// 	q.push(node);
// 	visited[node] = true;

// 	while (!q.empty()) {
		
// 		node = q.front();
// 		q.pop();
			
// 		for (int i = 0; i < n; i++) {
// 			if (mat[node][i] == 1 && !visited[i]) {
// 				visited[i] = true;
// 				q.push(i);
// 			}
// 		}	
// 	}

// }




// void parallelBFS(int node, int n, int nthreads) {

// 	queue<int> q;
// 	q.push(node);
// 	visited[node] = true;

// 	while (!q.empty()) {
		
// 		int qsize = q.size();

// 		#pragma omp parallel for //num_threads(nthreads)
// 		for (int i = 0; i < qsize; i++) {
// 			int currNode; 

// 			#pragma omp critical 
// 			{
// 				currNode = q.front();
// 				q.pop();
// 			} 

// 			#pragma omp parallel for //num_threads(nthreads)
// 			for (int j = 0; j < n; j++) {
				
// 				if (mat[currNode][j] == 1 && !visited[j]) {
// 					#pragma omp critical 
// 					{
// 					visited[j] = true;			
// 					q.push(j);		
// 					}
// 				}			
// 			}

			
// 		}	
// 	}

// }


// int main() {

// 	//No. of nodes
// 	int n = SIZE;

// 	//Adjacency Matrix
// 	for (int i = 0; i < n; i++) {
// 		mat[i][i] = 0;
// 		for (int j = i + 1; j < n; j++) {
		
// 			mat[i][j] = rand() % 2;
// 			mat[j][i] = mat[i][j];		

// 		}
// 	}

// 	//Serial BFS
// 	double startTime = omp_get_wtime();
// 	serialBFS(0, n);
// 	double duration = omp_get_wtime() - startTime;
// 	cout << "Time elapsed for serial BFS : " << duration << endl;
// 	if (isConnected(n)) {
// 		cout << "Graph is connected (Serial)" << endl;
// 	} else {
// 		cout << "Graph is not connected (Serial)" << endl;
// 	}
// 	clearVisited(n);
// 	//

// 	for (int i = 1; i < 6; i++) {
// 		//Parallel BFS
// 		startTime = omp_get_wtime();
// 		parallelBFS(0, n, i);
// 		duration = omp_get_wtime() - startTime;
// 		cout << "Time elapsed for parallel BFS with " << i << " threads : " << duration << endl;
// 		if (isConnected(n)) {
// 			cout << "Graph is connected (Parallel)" << endl;
// 		} else {
// 			cout << "Graph is not connected (Parallel)" << endl;
// 		}
// 		clearVisited(n);
// 		//
// 	}

// 	return 0;

// }