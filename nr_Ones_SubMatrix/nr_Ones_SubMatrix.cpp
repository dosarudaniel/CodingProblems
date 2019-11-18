#include <iostream>

/*
Return the number of elements equals to 1
*/

using namespace std;

int nrOnesInSubMatrix(int **map, int i, int j, int i1, int j1) {
    return map[i1+1][j1+1] - map[i][j1+1] - map[i1+1][j] + map[i][j];
}

int main() {
    // local variables
    int **mat, **map;
    int n, m;
    // Read matrix
    cout << "n=";
    cin >> n;
    cout << "m=";
    cin >> m;

    mat = new int*[n];
    for (int i = 0; i < n; i++) {
        mat[i] = new int[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "mat[" << i << "][" << j << "]=";
            cin >> mat[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    // Preprocess
    map = new int*[n+1];
    for (int i = 0; i <= n; i++) {
        map[i] = new int[m+1];
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                map[i][j] = 0;
            } else {
                map[i][j] = map[i][j-1] + map[i-1][j] + mat[i-1][j-1] - map[i-1][j-1];
            }
        }
    }

    // answer query
    int i, j, i1, j1;
    cout << "i=";
    cin >> i;
    cout << "j=";
    cin >> j;
    cout << "i1=";
    cin >> i1;
    cout << "j1=";
    cin >> j1;

    cout << "The following sub matrix: \n";
    for (int ii = i; ii <= i1; ii++) {
        for (int jj = j; jj <= j1; jj++) {
            cout << mat[ii][jj] << " ";
        }
        cout << endl;
    }
    cout << "has " << nrOnesInSubMatrix(map, i, j, i1, j1) << " elements equals to 1\n";

    return 0;
}
