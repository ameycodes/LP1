import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class HillClimbing {

    public static void main(String[] args) {

        Scanner sc=new Scanner(System.in);
        int startNode,goalNode;
        int numOfNodes;
        int adjMatrix[][];
        int heuristicValues[];

        System.out.println("Enter no of nodes");
        numOfNodes=sc.nextInt();
        adjMatrix=new int[numOfNodes+1][numOfNodes+1];
        heuristicValues=new int[numOfNodes+1];

        System.out.println("Enter the adjacency Matrix ");
        for(int i=1;i<=numOfNodes;i++){
            for(int j=1;j<=numOfNodes;j++){
                adjMatrix[i][j]=sc.nextInt();
            }
        }

        System.out.println("Enter the heuristic Values ");
        for(int i=1;i<=numOfNodes;i++){
            heuristicValues[i]=sc.nextInt();
        }

        System.out.println("Enter the start and goal node ");
        startNode=sc.nextInt();
        goalNode=sc.nextInt();

        PriorityQueue<Integer> openList=new PriorityQueue<>(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return heuristicValues[o1]-heuristicValues[o2];
            }
        });

        ArrayList<Integer> closedList=new ArrayList<>();

        openList.add(startNode);
        while (!openList.isEmpty()){

            int currentNode=openList.poll();
            openList.clear();
            closedList.add(currentNode);

            if(currentNode==goalNode){
                break;
            }
            else{
                for(int i=1;i<=numOfNodes;i++){

                    if(adjMatrix[currentNode][i]!=0 && !closedList.contains(i) &&
                            heuristicValues[i]  <heuristicValues[currentNode]){
                        openList.add(i);
                    }
                }
            }
        }

        boolean localMaxima=false;
        for(int i=0;i<closedList.size();i++){

            System.out.print(closedList.get(i)+"->");
            if(i==closedList.size()-1 && closedList.get(i)!=goalNode)
                localMaxima=true;
        }

        if(localMaxima)
            System.out.print("And Stuck in Local Maxima");
        else
            System.out.print("And Reached goal node");
    }
}

/*7

0 4 3 0 0 0 0
0 0 0 0 12 5 0
0 0 0 7 10 0 0
0 0 0 0 2 0 0
0 0 0 0 0 0 5
0 0 0 0 0 0 16
0 0 0 0 0 0 0

14 12 11 6 4 11 0

1
7*/