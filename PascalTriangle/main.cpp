#include<iostream>
#include<vector>
using namespace std;

/*
Given numRows, generate the first numRows of Pascal’s triangle.
Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.
*/

vector<vector<int> > solve(int A) {
    vector<vector<int> >  result;

    if (A == 0)
        return result;

    vector<int> current;
    current.push_back(1);
    result.push_back(current);
    for (int i = 0; i < A-1; i++) {
        vector<int> current;
        for (int j = 0; j <= result[i].size(); j++) {
            if (j == 0 || j == result[i].size()) {
                current.push_back(1);
            } else {
                current.push_back(result[i][j-1] + result[i][j]);
            }
        }

        result.push_back(current);
    }
    return result;
}

int main() {
    int nr_levels = 0;
    cout << "Nr_levels = ";
    cin>>nr_levels;
    vector<vector<int> > res = solve(nr_levels);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}
