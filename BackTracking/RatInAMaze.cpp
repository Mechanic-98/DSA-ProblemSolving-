#include <iostream>
using namespace std;

bool isSafe(int ** maze, int n, int x, int y, int ** solutionMatrix){
    if(x <n && y < n && x>=0 && y>=0 && maze[x][y] == 1 && solutionMatrix[x][y] == 0) return true;
    
    return false;
}

void printSolution(int ** solutionMatrix, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n; j++){
            cout<<solutionMatrix[i][j]<<" ";
        }
    }
    cout<<'\n';
}

void ratInAMaze(int ** maze, int n, int ** solutionMatrix, int x, int y){
    if(x == n-1 && y == n-1){
        solutionMatrix[x][y] = 1;
        printSolution(solutionMatrix, n);
        solutionMatrix[x][y] = 0;
        return;
    }
    
    if(isSafe(maze, n, x, y, solutionMatrix)){
        solutionMatrix[x][y] = 1;
        ratInAMaze(maze, n, solutionMatrix, x, y+1);
        ratInAMaze(maze, n, solutionMatrix, x+1, y);
        ratInAMaze(maze, n, solutionMatrix, x, y-1);
        ratInAMaze(maze, n, solutionMatrix, x-1, y);
        solutionMatrix[x][y] = 0;
    }
}

int main() {

	int n; cin>>n;
    int ** maze = new int *[n];
	for(int i=0;i<n;i++){
        maze[i] = new int[n];
        
        for(int j=0;j<n;j++){
        	int ele; cin>>ele;
            maze[i][j] = ele;
        }
    }
    
    int ** solutionMatrix = new int*[n];
    for(int i=0;i<n;i++){
        solutionMatrix[i] = new int[n];
    }

    for(int i=0; i<n; i++){
        memset(solutionMatrix[i], 0, n*sizeof(int));
    }
    
    ratInAMaze(maze, n, solutionMatrix, 0,0);
	return 0;
}
