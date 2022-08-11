#include <iostream>
using namespace std;

int main(){
    int N, prime, cnt=0;

    cin >> N;

    for (int i=0; i<N; i++){
        cin >> prime;
        cnt++;

        if(prime==1){
            cnt--;
            continue;
        }
        else{
            int div = 2;
            while(div < prime-1){
                if(prime%div == 0){
                    cnt--;
                    break;
                }
                else
                    div++;
            }
        }   
    }

    cout << cnt << "\n";
    return 0;
}
