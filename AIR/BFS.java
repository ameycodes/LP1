import java.util.*;

public class BFS {

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

        int parent[]=new int[numOfNodes+1];

        openList.add(startNode);
        while (!openList.isEmpty()){

            int currentNode=openList.poll();
            closedList.add(currentNode);

            if(currentNode==goalNode){
                break;
            }
            else{
                for(int i=1;i<=numOfNodes;i++){

                    if(adjMatrix[currentNode][i]!=0 && !closedList.contains(i)){
                        openList.add(i);
                        parent[i]=currentNode;
                    }
                }
            }
        }


        int i=goalNode;
        Stack<Integer> s=new Stack<>();
        s.push(goalNode);

        while(i!=startNode){
            i=parent[i];
            s.push(i);
        }


        System.out.println("Traced Path is: ");
        while(!s.isEmpty()){
            System.out.print(s.pop()+"->");
        }


    }
}
