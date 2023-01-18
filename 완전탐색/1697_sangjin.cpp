#include <iostream>
#include <algorithm>
using namespace std;

int subin[100001] = { 0 };

int main() {
	int N, K;

	cin >> N >> K;

	int cnt = 100001;

	for (int i = 0; i < 100001; i++) {
		if (i <= N) {
			subin[i] = N - i;
		}
		else {
			int mu = i / 2;
			if (i % 2 == 1) {
				int mu = i / 2;
				subin[i] = min(subin[i - 1] + 1, min(subin[mu] + 2, subin[mu + 1] + 2));
			}
			else {
				int mu = i / 2;
				subin[i] = min(subin[i - 1] + 1, subin[mu] + 1);
			}
		}
	}

	for (int i = 0; i < 100001; i++) {
		cnt = min(cnt, subin[i] + abs(K - i));
	}

	cout << cnt << endl;
}

/* 다른 사람 풀이 bfs로 푸는 문제였나보다 나는 dp로 풀었는데....
#include <iostream>
#include <queue>
using namespace std;
int n, k;
bool visit[100001];
void bfs(int a){
    queue<pair<int, int>> q;
    q.push(make_pair(a, 0));
    while(!q.empty()){
        int x = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(x==k){
            cout << cnt;
            break;
        }
        if(x+1 >=0 && x+1<100001){
            if(!visit[x+1] ){
                visit[x + 1] = true;
                q.push(make_pair(x + 1, cnt + 1));
            }
        }
        if(x-1 >=0 && x-1<100001){
            if(!visit[x-1]){
                visit[x - 1] = true;
                q.push(make_pair(x - 1, cnt + 1));
            }
        }
        if(2*x >=0 && 2*x<100001){
            if(!visit[2*x]){
                visit[2*x] = true;
                q.push(make_pair(2 * x, cnt + 1));
            }
        } // 각 다음 좌표마다 q에 넣어준다.
    }
}
int main(){
    cin >> n >> k;
    visit[n] = true;
    bfs(n);
    return 0;
}
*/
