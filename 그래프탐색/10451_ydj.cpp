#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX_NODE 1001

int BFS(int start, int N, vector<int> &graph);

int main(){
    int T, N, vertex;

    cin >> T;

    for(int i=0; i<T; i++){
        cin >> N;

        vector<int> graph(N+1);

        for(int n=1; n<=N; n++){
            cin >> vertex;
            graph[n] = vertex; // 단방향 연결
        }

        cout << BFS(1, N, graph) << "\n";
    }

    return 0;
}

int BFS(int start, int N, vector<int> &graph){
    queue<int> q;
    q.push(start);

    vector<bool> visited(N+1, false);
    visited[start] = true;

    int visit = 1; // 비연결 그래프
    int permutation = 1;

    while(visit < N){
        int vertex = q.front();
        q.pop();

        if(!visited[graph[vertex]]){
            q.push(graph[vertex]);
            visited[graph[vertex]] = true;
            visit++;
        }

        if(q.empty()){
            permutation++;

            for(int i=1; i<=N; i++){
                if(!visited[i]){
                    q.push(i);
                    visited[i] = true;
                    visit++;
                    break;
                }
            }
        }
    }
    
    return permutation;
}
