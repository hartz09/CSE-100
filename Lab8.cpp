#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void printOptimalParentheses(const vector<vector<int> >& split, int start, int end) {
    if (start == end) {
        cout << "A" << start;
    } else {
        cout << "(";
        printOptimalParentheses(split, start, split[start][end]);
        printOptimalParentheses(split, split[start][end] + 1, end);
        cout << ")";
    }
}

void matrixChainMultiplication(const vector<int>& dimensions) {
    int n = dimensions.size() - 1;
    vector<vector<int> > Matrix1(n, vector<int>(n, 0));
    vector<vector<int> > Matrix2(n, vector<int>(n, 0));

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            Matrix1[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = Matrix1[i][k] + Matrix1[k + 1][j] + dimensions[i] * dimensions[k + 1] * dimensions[j + 1];
                if (cost < Matrix1[i][j]) {
                    Matrix1[i][j] = cost;
                    Matrix2[i][j] = k;
                }
            }
        }
    }
    cout << Matrix1[0][n - 1] << endl;
    printOptimalParentheses(Matrix2, 0, n - 1);
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> dimensions(n + 1);

    for (int i = 0; i <= n; i++) {
        cin >> dimensions[i];
    }
    matrixChainMultiplication(dimensions);
    return 0;
}