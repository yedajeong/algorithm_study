#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_NODE 51

int graph[MAX_NODE][MAX_NODE];
bool visited[MAX_NODE][MAX_NODE];

int island;
int w, h;

int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

void BFS(int i, int j);

int main(){
    cin >> w >> h;

    while(w!=0 && h!=0){
        island = 0;

        for(int i=1; i<=h; i++){
            for(int j=1; j<=w; j++){
                visited[i][j] = false;
                cin >> graph[i][j];
            }
        }

        for(int i=1; i<=h; i++){
            for(int j=1; j<=w; j++){
                if(graph[i][j] && !visited[i][j]){
                    BFS(i, j);
                    }
            }
        }

        cout << island << "\n";

        cin >> w >> h;
    }

    return 0;
}

void BFS(int i, int j){
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    visited[i][j] = true;

    while(!q.empty()){
        for(int i=0; i<8; i++){
            int row = q.front().first + dr[i];
            int col = q.front().second + dc[i];

            if(row>0 && row<=h && col>0 && col<=w){
                if(graph[row][col] && !visited[row][col]){
                    q.push(make_pair(row, col));
                    visited[row][col] = true;
                }
            }
        }
        q.pop();
    }

    island++;
}
