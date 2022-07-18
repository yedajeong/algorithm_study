#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Student{
public:
    int kor, eng, math;
    string name;
    Student(string _name, int _kor, int _eng, int _math){
        name = _name;
        kor = _kor;
        eng = _eng;
        math = _math;
    }
};

bool compare(Student a, Student b){
    if (a.kor == b.kor){
        if (a.eng == b.eng){
            if (a.math == b.math){
                int length = min(a.name.size(), b.name.size());
                for (int i=0; i<length; i++){
                    if (a.name[i] != b.name[i])
                        return a.name[i] < b.name[i];
                }
            }
            else
                return a.math > b.math;
        }
        else
            return a.eng < b.eng;
    }
    else
        return a.kor > b.kor;
}

int main(){
    int N, kor, eng, math;
    string name;

    cin >> N;

    vector<Student> v;
    for (int order=1; order<=N; order++){
        cin >> name >> kor >> eng >> math;
        v.push_back(Student(name, kor, eng, math));
    }
    
    sort(v.begin(), v.end(), compare); // 사용자 정의 함수로 sorting

    for (int i=0; i<N; i++)
        cout << v[i].name << '\n';

    return 0;
}
