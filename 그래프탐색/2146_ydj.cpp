#include <iostream>
#include <queue>
#include <cstring> // memset
using namespace std;

#define MAX_NODE 100
int island[MAX_NODE][MAX_NODE];
bool visited[MAX_NODE][MAX_NODE];
int dr[4] = {-1, 0, 1, 0}; // 상 우 하 좌
int dc[4] = {0, 1, 0, -1};
int path;
int N, answer=1000000;
queue<pair<int, int>> Q;

int Min(int a, int b);
void Numbering(int x, int y, int land_num);
void Solve();
int BFS(int land_num);

int main(){

    cin >> N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> island[i][j];
            if(island[i][j] == 1){
                island[i][j] = -1;  //육지 넘버링 초기화: 1 > -1로 표기
                Q.push(make_pair(i, j));
            }
        }
    }

    Solve();

    return 0;

}

int Min(int a, int b){
    return (a < b) ? a : b;
}

void Numbering(int x, int y, int land_num){
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    island[x][y] = land_num;
    visited[x][y] = true;

    while(!q.empty()){
        int row_bef = q.front().first;
        int col_bef = q.front().second;
        q.pop();

        // 연결된 다른 노드 탐색
        for (int idx=0; idx<4; idx++){
            int row = row_bef + dr[idx];
            int col = col_bef + dc[idx];

            if((row >= 0 and row < N) and (col >= 0 and col < N)){
                if(island[row][col]==-1 && !visited[row][col]){  // 아직 방문x 육지
                    q.push(make_pair(row, col));
                    island[row][col] = land_num;
                    visited[row][col] = true;
                }
            }
        }
    }
}

void Solve(){
    // 섬 단위 numbering
    int land_num = 1;
    while(!Q.empty()){
        int row = Q.front().first;
        int col = Q.front().second;
        Q.pop();

        if(!visited[row][col] && island[row][col]==-1){
            Numbering(row, col, land_num);
            land_num++;
        }
    }

    // debug
    // for(int i=0; i<N; i++){
    //     cout << endl;
    //     for(int j=0; j<N; j++)
    //         cout << island[i][j] << " ";
    // }

    for(int i=1; i<land_num; i++){
        // 방문 기록 초기화
        memset(visited, false, sizeof(visited));
        answer = Min(answer, BFS(i));
    }

    cout << answer << "\n";
}

int BFS(int land_num){
    queue<pair<int, int>> q;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(island[i][j]==land_num){
                visited[i][j] = true;
                q.push(make_pair(i, j)); 
            }
        }
    }
    
    int result = 0;
    while(!q.empty()){
        int q_size = q.size();
        for(int i=0; i<q_size; i++){
            int row_bef = q.front().first;
            int col_bef = q.front().second;
            q.pop();

            // 연결된 다른 노드 탐색
            for (int idx=0; idx<4; idx++){
                int row = row_bef + dr[idx];
                int col = col_bef + dc[idx];

                if((row >= 0 and row < N) and (col >= 0 and col < N)){
                    // 다른 육지면 종료
                    if(island[row][col]!=0 && island[row][col]!=land_num)
                        return result;
                    // 방문 안 한 바다면 +1하고 더 탐색
                    else if(island[row][col]==0 && !visited[row][col]){
                        q.push(make_pair(row, col));
                        visited[row][col] = true;
                    }
                }
            }
        }
        result++;
    }
}
