#include <iostream>
using namespace std;

int main(){
    string S;

    cin >> S;

    int alphabet[26];
    fill_n(alphabet, 26, -1);

    for (int i=0; i<S.size(); i++){
        switch(S[i]){
            case 'a':
                if (alphabet[0] == -1)
                    alphabet[0] = i;
                break;
            case 'b':
                if (alphabet[1] == -1)
                    alphabet[1] = i;
                break;
            case 'c':
                if (alphabet[2] == -1)
                    alphabet[2] = i;
                break;
            case 'd':
                if (alphabet[3] == -1)
                    alphabet[3] = i;
                break;
            case 'e':
                if (alphabet[4] == -1)
                    alphabet[4] = i;
                break;
            case 'f':
                if (alphabet[5] == -1)
                    alphabet[5] = i;
                break;
            case 'g':
                if (alphabet[6] == -1)
                    alphabet[6] = i;
                break;
            case 'h':
                if (alphabet[7] == -1)
                    alphabet[7] = i;
                break;
            case 'i':
                if (alphabet[8] == -1)
                    alphabet[8] = i;
                break;
            case 'j':
                if (alphabet[9] == -1)
                    alphabet[9] = i;
                break;
            case 'k':
                if (alphabet[10] == -1)
                    alphabet[10] = i;
                break;
            case 'l':
                if (alphabet[11] == -1)
                    alphabet[11] = i;
                break;
            case 'm':
                if (alphabet[12] == -1)
                    alphabet[12] = i;
                break;
            case 'n':
                if (alphabet[13] == -1)
                    alphabet[13] = i;
                break;
            case 'o':
                if (alphabet[14] == -1)
                    alphabet[14] = i;
                break;
            case 'p':
                if (alphabet[15] == -1)
                    alphabet[15] = i;
                break;
            case 'q':
                if (alphabet[16] == -1)
                    alphabet[16] = i;
                break;
            case 'r':
                if (alphabet[17] == -1)
                    alphabet[17] = i;
                break;
            case 's':
                if (alphabet[18] == -1)
                    alphabet[18] = i;
                break;
            case 't':
                if (alphabet[19] == -1)
                    alphabet[19] = i;
                break;
            case 'u':
                if (alphabet[20] == -1)
                    alphabet[20] = i;
                break;
            case 'v':
                if (alphabet[21] == -1)
                    alphabet[21] = i;
                break;
            case 'w':
                if (alphabet[22] == -1)
                    alphabet[22] = i;
                break;
            case 'x':
                if (alphabet[23] == -1)  
                    alphabet[23] = i;
                break;
            case 'y':
                if (alphabet[24] == -1)
                    alphabet[24] = i;
                break;
            case 'z':
                if (alphabet[25] == -1)
                    alphabet[25] = i;
                break;
        }
    }

    for (int i=0; i<26; i++)
        cout << alphabet[i] << " ";

    return 0;
}
