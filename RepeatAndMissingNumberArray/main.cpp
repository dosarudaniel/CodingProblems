#include<iostream>
#include<vector>

using namespace std;

vector<int> repeatedNumber(const vector<int> &A) {
    vector <int> result;
    int a, b;
    int *mem = new int[A.size() + 1];
    for (int i = 1; i <= A.size(); i++) {
        mem[i] = 0;
    }

    for (int i = 0; i < A.size(); i++) {
        mem[A[i]]++;
    }

    for (int i = 1; i <= A.size(); i++) {
        if (mem[i] == 2) {
            a = i;
        } else if (mem[i] == 0) {
            b = i;
        } else if (mem[i] > 2){
            cout << "Wrong input\n";
        }
    }

    result.push_back(a);
    result.push_back(b);

    return result;
}


int main() {
    std::vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(4);

    vector<int> res = repeatedNumber(v);

    cout << res[0] << " " << res[1] << endl;
}
