#include <cstdio>
#include <queue>

#define IMPOSSIBLE "KAKTUS"
#define MAX 51

using namespace std;

typedef pair<int, int> pii; //지도 좌표
int r, c; //지도 크기

int dx[4] = { -1,1,0,0 }; //방향
int dy[4] = { 0,0,-1,1 };

char map[MAX][MAX]; //지도정보
int visit[MAX][MAX]; //방문표시
int time;

queue<pii> waterQueue, gosQueue;

void bfs() {
	//초기 조건
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 'S') {
				gosQueue.push(pii(i, j));
				visit[i][j] = 1;
			}
			else if (map[i][j] == '*') {
				waterQueue.push(pii(i, j));
			}
		}
	}

	for (time = 1; ; time++) {
		int waterSpot = waterQueue.size(); //홍수가 시작하는 곳 갯수
		for (int i = 0; i < waterSpot; i++) {
			pii frt = waterQueue.front();
			waterQueue.pop();

			for (int j = 0; j < 4; j++) {
				int nx = frt.first + dx[j];
				int ny = frt.second + dy[j];

				if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue; //지도 범위 초과시 continue
				
				if (map[nx][ny] == '.') {
					map[nx][ny] = '*';
					waterQueue.push(pii(nx, ny));
				}
			}
		}

		int gosSpot = gosQueue.size();

		if (gosSpot == 0) {
			time = -1;
			return;
		}

		for (int i = 0; i < gosSpot; i++) {
			pii frt = gosQueue.front();
			gosQueue.pop();

			for (int j = 0; j < 4; j++) {
				int nx = frt.first + dx[j];
				int ny = frt.second + dy[j];

				if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue; //지도 범위 초과시 continue
				
				if (map[nx][ny] == 'D') return;

				if (map[nx][ny] == '.' && visit[nx][ny] == 0) {
					visit[nx][ny] = 1;
					gosQueue.push(pii(nx, ny));
				}
			}
		}
	}
}

int main() {
	scanf("%d %d", &r, &c);

	for (int i = 0; i < r; i++) {
		scanf("%s", map[i]);
	}

	bfs();

	if (time == -1) {
		printf("%s", IMPOSSIBLE);
	}
	else printf("%d", time);
}
