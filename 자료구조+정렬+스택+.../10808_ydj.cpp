#include <iostream>
using namespace std;

int main(){
    string S;

    cin >> S;

    int alphabet[26] = {0};

    for (int i=0; i<S.size(); i++){
        switch(S[i]){
            case 'a':
                alphabet[0]++;
                break;
            case 'b':
                alphabet[1]++;
                break;
            case 'c':
                alphabet[2]++;
                break;
            case 'd':
                alphabet[3]++;
                break;
            case 'e':
                alphabet[4]++;
                break;
            case 'f':
                alphabet[5]++;
                break;
            case 'g':
                alphabet[6]++;
                break;
            case 'h':
                alphabet[7]++;
                break;
            case 'i':
                alphabet[8]++;
                break;
            case 'j':
                alphabet[9]++;
                break;
            case 'k':
                alphabet[10]++;
                break;
            case 'l':
                alphabet[11]++;
                break;
            case 'm':
                alphabet[12]++;
                break;
            case 'n':
                alphabet[13]++;
                break;
            case 'o':
                alphabet[14]++;
                break;
            case 'p':
                alphabet[15]++;
                break;
            case 'q':
                alphabet[16]++;
                break;
            case 'r':
                alphabet[17]++;
                break;
            case 's':
                alphabet[18]++;
                break;
            case 't':
                alphabet[19]++;
                break;
            case 'u':
                alphabet[20]++;
                break;
            case 'v':
                alphabet[21]++;
                break;
            case 'w':
                alphabet[22]++;
                break;
            case 'x':
                alphabet[23]++;
                break;
            case 'y':
                alphabet[24]++;
                break;
            case 'z':
                alphabet[25]++;
                break;
        }
    }

    for (int i=0; i<26; i++)
        cout << alphabet[i] << " ";

    return 0;
}
