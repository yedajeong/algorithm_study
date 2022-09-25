#include <iostream>
#include <queue>
using namespace std;

#define MAX_NODE 101
int maze[MAX_NODE][MAX_NODE]; // 미로 정보
int path[MAX_NODE][MAX_NODE]; // (i, j)까지의 최단거리
int N, M;
int dr[] = {-1, 0, 1, 0}; // 상 우 하 좌
int dc[] = {0, 1, 0, -1};

void BFS(int i, int j);

int main(){
    string input;

    cin >> N >> M;

    for(int i=1; i<=N; i++){
        cin >> input;
        for(int j=1; j<=M; j++){
            maze[i][j] = input[j-1] - '0'; // char to int
            path[i][j] = MAX_NODE*MAX_NODE; // 초기화
        }
    }

    path[1][1] = 1;
    BFS(1, 1);

    cout << path[N][M] << "\n";

    return 0;
}

void BFS(int i, int j){
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    maze[i][j] = 0; // 방문 표시

    while(!q.empty()){
        int row_bef = q.front().first;
        int col_bef = q.front().second;

        for(int i=0; i<4; i++){
            int row = row_bef + dr[i];
            int col = col_bef + dc[i];

            if(row>0 && row<=N && col>0 && col<=M){
                if(maze[row][col]){
                    q.push(make_pair(row, col));
                    path[row][col] = min(path[row_bef][col_bef]+1, path[row][col]);
                    maze[row][col] = 0; // 방문 표시
                }
            }
        }

        q.pop();
    }
}
