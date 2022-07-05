#include <iostream>
using namespace std;

int main(){
    int T, n;
    int score[2][100000]={{0}};

    cin >> T;
    for (int i=0; i<T; i++){
        cin >> n;
        for (int row=0; row<2; row++){
            for (int col=0; col<n; col++)
                cin >> score[row][col];
        }

        int dp[2][n];

        dp[0][0] = score[0][0];
        dp[1][0] = score[1][0];

        dp[0][1] = dp[1][0] + score[0][1];
        dp[1][1] = dp[0][0] + score[1][1];

        for (int j=2; j<n; j++){
            dp[0][j] = max(dp[1][j-1], dp[1][j-2]) + score[0][j];
            dp[1][j] = max(dp[0][j-1], dp[0][j-2]) + score[1][j];
        }

        cout << max(dp[0][n-1], dp[1][n-1]) << "\n";
    }

    return 0;
}