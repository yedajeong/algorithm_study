#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_NODE 1000
int graph[MAX_NODE][MAX_NODE];
int M, N; // M: 가로 칸 수  N: 세로 칸 수
int days = -1;

int dr[] = {-1, 0, 1, 0}; // 상 하 좌 우
int dc[] = {0, 1, 0, -1};

void BFS(queue<pair<int, int>> &tomato);

int main(){
    cin >> M >> N;

    queue<pair<int, int>> tomato;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> graph[i][j];
            if(graph[i][j]==1)
                tomato.push(make_pair(i, j));    
        }
    }

    BFS(tomato); // 최초의 익은 토마토 위치 정보

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(graph[i][j]==0){
                cout << -1 << "\n";
                return 0;
            }
        }
    }

    cout << days << "\n";

    return 0;
}

void BFS(queue<pair<int, int>> &tomato){
    queue<pair<int, int>> q;

    while(!tomato.empty()){
        while(!tomato.empty()){
            q.push(make_pair(tomato.front().first, tomato.front().second));
            tomato.pop();
        }

        while(!q.empty()){
            for(int i=0; i<4; i++){
                int row = q.front().first + dr[i];
                int col = q.front().second + dc[i];

                if(row>=0 && row<N && col>=0 && col<M){
                    if(graph[row][col]==0){ // 인접한 곳의 익지 않은 토마토
                        tomato.push(make_pair(row, col));
                        graph[row][col] = 1;
                    }
                }
            }
            q.pop();
        }
        days++; // 1일 익음
    }
}
