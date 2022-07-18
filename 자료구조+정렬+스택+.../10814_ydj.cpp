#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Judge{
public:
    int age, order;
    string name;
    Judge(int _age, string _name, int _order){
        age = _age;
        name = _name;
        order = _order;
    }
};

bool compare(Judge a, Judge b){
    if (a.age == b.age)
        return a.order < b.order;
    else
        return a.age < b.age;
}

int main(){
    int N, age;
    string name;

    cin >> N;

    vector<Judge> v;
    for (int order=1; order<=N; order++){
        cin >> age >> name;
        v.push_back(Judge(age, name, order));
    }
    
    sort(v.begin(), v.end(), compare); // 사용자 정의 함수로 sorting

    for (int i=0; i<N; i++)
        cout << v[i].age << " " << v[i].name << '\n';

    return 0;
}
