import java.util.Comparator;
import java.util.PriorityQueue;

public class EightPuzzle {

    int dimension=3;
    int row[]={1,0,-1,0};
    int column[]={0,-1,0,1};

    public int calculateCost(int initial[][],int goal[][]){
        int count=0;

        for(int i=0;i<dimension;i++){
            for(int j=0;j<dimension;j++){
                if(initial[i][j]!=goal[i][j] && initial[i][j]!=0)
                    count++;
            }
        }
        return count;
    }

    void printMatrix(int matrix[][]){
        for(int i=0;i<dimension;i++){
            for(int j=0;j<dimension;j++){
                System.out.print(matrix[i][j]+" ");
            }
            System.out.println();
        }
    }

    boolean isSafe(int i,int j){
        return i>=0&&j>=0&&i<dimension&&j<dimension;
    }

    void printPath(Node node){
        if(node==null)
            return;
        printPath(node.parent);
        printMatrix(node.matrix);
        System.out.println();
    }

    public void solve(int initial[][],int goal[][],int x,int y){

        PriorityQueue<Node> pq=new PriorityQueue<>(new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                return (o1.cost+o1.level)-(o2.cost+o2.level);
            }
        });

        Node root=new Node(null,initial,0,x,y,x,y);
        root.cost=calculateCost(initial,goal);
        pq.add(root);

        while (!pq.isEmpty()){
            //System.out.print("here\n");
            Node min=pq.poll();
            if(min.cost==0){
                printPath(min);
                return;
            }
            else{
                for(int i=0;i<4;i++){
                    if(isSafe(min.x+row[i],min.y+column[i])){
                        Node node=new Node(min,min.matrix,min.level+1,min.x,min.y,min.x+row[i],min.y+column[i]);
                        node.cost=calculateCost(node.matrix,goal);
                        pq.add(node);
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
//        int initial[][]={{3,7,6},{5,1,2},{4,0,8}};
        int initial[][]={{1,8,2},{0,4,3},{7,6,5}};
        int goal[][]={{1,2,3},{4,5,6},{7,8,0}};
//        int goal[][]={{5,3,6},{7,0,2},{4,1,8}};
        int x=1,y=0;
        EightPuzzle eightPuzzle=new EightPuzzle();
        eightPuzzle.solve(initial,goal,x,y);
    }


    class Node{

        Node parent;
        int matrix[][];
        int cost;
        int level;
        int x,y;

        public Node(Node parent,int matrix[][],int level,int x,int y,int newX,int newY){

            this.parent=parent;
            this.level=level;
            this.cost=Integer.MAX_VALUE;
            this.matrix=new int[dimension][dimension];

            for(int i=0;i<dimension;i++){
                for(int j=0;j<dimension;j++){
                    this.matrix[i][j]=matrix[i][j];
                }
            }
            int temp=this.matrix[x][y];
            this.matrix[x][y]=this.matrix[newX][newY];
            this.matrix[newX][newY]=temp;

            this.x=newX;
            this.y=newY;
        }

    }
}
