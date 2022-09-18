#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX_NODE 26

int graph[MAX_NODE][MAX_NODE];
bool visited[MAX_NODE][MAX_NODE];
vector<int> house_cnt; // 오름차순 정렬
int N;

void BFS(int i, int j);

int main(){
    cin >> N;

    string input;

    for(int i=0; i<N; i++){
        cin >> input;
        for(int j=0; j<N; j++){
            visited[i+1][j+1] = false;

            if(input[j] == '1')
                graph[i+1][j+1] = 1; // 1-based indexing
            else if(input[j] == '0')
                graph[i+1][j+1] = 0;
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(graph[i][j] && !visited[i][j])
                BFS(i, j);
        }
    }

    sort(house_cnt.begin(), house_cnt.end());

    cout << house_cnt.size() << "\n";
    for(int i=0; i<house_cnt.size(); i++)
        cout << house_cnt[i] << "\n";

    return 0;
}

void BFS(int i, int j){
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    visited[i][j] = true;
    int cnt = 1;

    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        if(row>1){
            if(graph[row-1][col] && !visited[row-1][col]){ //상
                q.push(make_pair(row-1, col));
                visited[row-1][col] = true;
                cnt++;
                }
        }

        if(row<N){
            if(graph[row+1][col] && !visited[row+1][col]){ //하
                q.push(make_pair(row+1, col));
                visited[row+1][col] = true;
                cnt++;
                }
        }

        if(col>1){
            if(graph[row][col-1] && !visited[row][col-1]){ //좌
                q.push(make_pair(row, col-1));
                visited[row][col-1] = true;
                cnt++;
                }
        }

        if(col<N){
            if(graph[row][col+1] && !visited[row][col+1]){ //우
                q.push(make_pair(row, col+1));
                visited[row][col+1] = true;
                cnt++;
                }
        }

    }
    house_cnt.push_back(cnt);
}
