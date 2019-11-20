#include<iostream>
#include<vector>
using namespace std;

/* Given a non-empty array of digits representing a non-negative integer, plus one to the integer. */
vector<int> plusOne(vector<int>& digits) {
    int t = (digits[digits.size() - 1] + 1)/10;
    digits[digits.size() - 1] = (digits[digits.size() - 1]+1)%10;

    for (int i = digits.size() - 2; i >= 0; i--) {
        int oldVal = digits[i];
        digits[i] = (digits[i] + t)%10;
        t = (t + oldVal)/10;
    }

    if (t > 0) {
        vector<int>::iterator it = digits.begin();
        digits.insert(it, t);
    }

    return digits;
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
