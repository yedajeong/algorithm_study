#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[1001];
vector<bool> visited(1001, false);

void DFS(int vertex){
    visited[vertex] = true;

    for(int i=0; i<graph[vertex].size(); i++){
        if(!visited[graph[vertex][i]])
            DFS(graph[vertex][i]);
    }
}

int main(){
    int N, M;

    cin >> N >> M;

    int vertex1, vertex2;
    for(int i=0; i<M; i++){
        cin >> vertex1 >> vertex2;
        graph[vertex1].push_back(vertex2);
        graph[vertex2].push_back(vertex1);
    }

    int connect = 0;
    for(int i=1; i<=N; i++){
        if(!visited[i]){
            DFS(i);
            connect++;
        }
    }

    cout << connect << "\n";

    return 0;
}
