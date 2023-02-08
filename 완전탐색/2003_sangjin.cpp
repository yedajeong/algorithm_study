#include <iostream>
using namespace std;

int num[10001] = { 0 };

//이건 내 풀이인데 시간복잡도 생각하면 옳지 않다.
int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	int cnt = 0;
	for (int start = 0; start < N; start++) {
		int result = 0;
		for (int j = start; j < N; j++) {
			
			result += num[j];

			if (result == M) {
				cnt++;
				break;
			}
			else if (result > M) 
				break;

			if (j == N - 1 && result < M) {
				cout << cnt << endl;
				return 0;
			}
		}
	}
	cout << cnt << endl;
}

/*Two-Pointer를 통해 푼 풀이
#include <iostream>
using namespace std;

int main(){
	int N, M, arr[10000];
	cin >> N >> M;
	for(int i=0; i<N; i++){
		cin >> arr[i];
	}

	int answer = 0, sum = 0, s = 0, e = 0;
	while(s<N){
		if(sum >= M){
			sum -= arr[s];
			s++;
		}else{
			sum += arr[e];
			e++;
		}
		if(sum == M) answer++;
	}

	cout << answer;
}
*/
