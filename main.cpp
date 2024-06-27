#include <iostream>
#include <fstream>
#include <stack>
#define N 13

using namespace std;

const int Up = 0, Down = 1 , Left = 2, Right = 3;

int maze[N][N];
bool visited[N][N]{{0}};


bool solve(pair<int,int> start, pair<int,int> end){;
    visited[start.first][start.second] = true;
    if(start.first-1>=0 && maze[start.first-1][start.second] == 0 && !visited[start.first-1][start.second]){
        if (start.first-1 == end.first && start.second == end.second){
            maze[start.first-1][start.second] = 2;
            return true;
        } else if (solve(make_pair(start.first-1,start.second),end)){
            maze[start.first-1][start.second] = 2;
            return true;
        }
    }
    if (start.first+1<N && maze[start.first+1][start.second] == 0 && !visited[start.first+1][start.second]){
        if (start.first+1 == end.first && start.second == end.second){
            maze[start.first+1][start.second] = 2;
            return true;
        } else if (solve(make_pair(start.first+1,start.second),end)){
            maze[start.first+1][start.second] = 2;
            return true;
        }
    }
    if (start.second-1>=0 && maze[start.first][start.second-1] == 0 && !visited[start.first][start.second-1]){
        if (start.first == end.first && start.second-1 == end.second){
            maze[start.first][start.second-1] = 2;
            return true;
        } else if (solve(make_pair(start.first,start.second-1),end)){
            maze[start.first][start.second-1] = 2;
            return true;
        }
    }
    if (start.second+1<N && maze[start.first][start.second+1] == 0 && !visited[start.first][start.second+1]){
        if (start.first == end.first && start.second+1 == end.second){
            maze[start.first][start.second+1] = 2;
            return true;
        } else if (solve(make_pair(start.first,start.second+1),end)){
            maze[start.first][start.second+1] = 2;
            return true;
        }
    }
    return false;
}


int main(){
    fstream fin;
    fin.open("maze.txt",ios::in);
    if(!fin){
        cout << "file cannot be opened!" << endl;
        return 0;
    }else{
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                fin>>maze[i][j];
            }
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            switch(maze[i][j]) {
                case 0 : cout << "  "; break;
                case 1 : cout << "OO"; break;
            }
        }
        cout << endl;
    }

    pair<int,int> start(1,0);
    pair<int,int> end(11,12);
    if (solve(start,end)) {
        maze[start.first][start.second] = 2;
        cout << "maze finished" << endl;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                switch(maze[i][j]) {
                    case 0 : cout << "  "; break;
                    case 1 : cout << "OO"; break;
                    case 2 : cout << "* "; break;
                }
            }
            cout << endl;
        }
    }else{
        cout << "cannot finish maze" << endl;
    }
    return 0;
}