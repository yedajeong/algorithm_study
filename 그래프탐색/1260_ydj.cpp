#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> edge[1001];
vector<bool> visited(1001, false);

void DFS(int vertex){ //재귀
    visited[vertex] = true;

    cout << vertex << " ";

    vector<int> next;

    for(int i=0; i<edge[vertex].size(); i++){
        if(!visited[edge[vertex][i]]){ // 방문 점검
            next.push_back(edge[vertex][i]);
        }
    }

    sort(next.begin(), next.end());

    for(int i=0; i<next.size(); i++){
        if(!visited[next[i]])
            DFS(next[i]);
    }
}

void BFS(int start){ //큐
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()){
        int vertex = q.front();
        cout << vertex << " ";
        q.pop();

        vector<int> next;

        for(int i=0; i<edge[vertex].size(); i++){
            if(!visited[edge[vertex][i]])
                next.push_back(edge[vertex][i]);
        }

        sort(next.begin(), next.end());

        for(int i=0; i<next.size(); i++){
            if(!visited[next[i]]) // 방문 점검
                q.push(next[i]);
                visited[next[i]] = true;
        }
    }
}

int main(){
    int N, M, V;

    cin >> N >> M >> V;

    int vertex1, vertex2;

    for(int i=0; i<M; i++){
        cin >> vertex1 >> vertex2;

        edge[vertex1].push_back(vertex2);
        edge[vertex2].push_back(vertex1); //간선은 양방향 
    }

    DFS(V);
    cout << "\n";

    //초기화
    for(int i=1; i<=N; i++)
        visited[i] = false;

    BFS(V);

    return 0;
}
