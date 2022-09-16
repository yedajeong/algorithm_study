#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX_NODE 20001

bool BG_BFS(int start, int V, vector<int> (&graph)[MAX_NODE]);

int main(){
    int K, V, E, vertex1, vertex2;

    cin >> K;

    for (int k=0; k<K; k++){
        cin >> V >> E;

        vector<int> graph[MAX_NODE];

        for (int e=0; e<E; e++){
            cin >> vertex1 >> vertex2;

            graph[vertex1].push_back(vertex2);
            graph[vertex2].push_back(vertex1);
        }

        if(BG_BFS(1, V, graph))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}

bool BG_BFS(int start, int V, vector<int> (&graph)[MAX_NODE]){
    queue<int> q;
    q.push(start);
    int color[V+1]; // 방문x: -1 방문1: 0 방문2: 1
    fill_n(color, V+1, -1);

    bool col = true; // 1
    color[start] = col;

    int visit = 1;

    while(visit<V){
        int vertex = q.front();
        col = !color[vertex]; // 색깔 switch
        q.pop();

        vector<int> next;

        for(int i=0; i<graph[vertex].size(); i++){
            if(color[graph[vertex][i]] == -1) // 아직 방문 x
                next.push_back(graph[vertex][i]);
        }

        sort(next.begin(), next.end());

        for(int i=0; i<next.size(); i++){
            if(color[next[i]] == -1){ // 방문 점검
                q.push(next[i]);
                color[next[i]] = col;
                visit++;
            }
        }

        for(int i=0; i<next.size(); i++){
            int current = next[i];
            for(int j=0; j<graph[current].size(); j++){
                if(color[current] == color[graph[current][j]])
                    return false;
            }
        }

        if(q.empty()){ // 연결 안 된 그래프일 경우
            for(int i=1; i<=V; i++){
                if(color[i] == -1){
                    q.push(i);
                    color[i] = col;
                    visit++;
                    break;
                }
            }
        }
    }
    
    return true;
}
