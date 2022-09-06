#include <iostream>
#include <cmath>
using namespace std;

int two_count(int n){
    int result = 0;
    
    for(int i=1; n>=pow(2, i); i++)
        result += n/pow(2,i); //2^i의 배수인 수만큼 더해줌

    return result;
}

int five_count(int n){
    int result = 0;
    
    for(int i=1; n>=pow(5, i); i++)
        result += n/pow(5,i); //5^i의 배수인 수만큼 더해줌

    return result;
}

int main(){
    int n, m, five, two;

    cin >> n >> m; //nCm

    two = two_count(n) - two_count(m) - two_count(n-m);
    five = five_count(n) - five_count(m) - five_count(n-m);

    cout << min(two, five) << "\n";

    return 0;
}
