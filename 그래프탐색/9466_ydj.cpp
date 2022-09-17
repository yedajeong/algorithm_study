#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_NODE 100001

vector<bool> visited(MAX_NODE, false);
vector<bool> done(MAX_NODE, false);
vector<int> graph(MAX_NODE);
int belong; // 한 팀에 포함되는 팀원 수

void DFS(int vertex);

int main(){
    int T, n;

    cin >> T;

    for(int t=0; t<T; t++){
        // 벡터 초기화
        fill(visited.begin(), visited.end(), false);
        fill(done.begin(), done.end(), false);
        fill(graph.begin(), graph.end(), -1);
        belong = 0;

        cin >> n;

        for(int i=1; i<=n; i++)
            cin >> graph[i];

        for(int i=1; i<=n; i++){
            if(!visited[i])
                DFS(i);
        }
    
    cout << n-belong << "\n";

    }

    return 0;
}

void DFS(int vertex){ //재귀
    visited[vertex] = true;

    int next = graph[vertex];

    if(!visited[next]) // 아직 방문 x
        DFS(next);

    else if(!done[next]){ // 방문 했지만 사이클에 포함
        // 사이클에 포함된 vertex만큼 카운트
        for(int i=next; i!=vertex; i=graph[i])
            belong++; 
        belong++; // vertex(자기자신)
    }

    done[vertex] = true;
}
