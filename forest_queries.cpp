#include <bits/stdc++.h>
using namespace std;

int n, q, x1, yy1, x2, y2;
int32_t forest[1001][1001], prefix[1001][1001];
string tree;

int main() {

    cin >> n >> q;
    for (int y = 1; y <= n; y++) {
        cin >> tree;
        for (int x = 1; x <= n; x++) {
            if (tree[x-1] == '*') {
                forest[x][y] = 1;
            }
        }
    }

    for (int x = 1; x <= n; x++) {
        prefix[x][0] = forest[x][0];
    }
    for (int y = 1; y <= n; y++) {
        prefix[0][y] = forest[0][y];
    }

    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= n; x++) {
            prefix[x][y] = prefix[x-1][y] + prefix[x][y-1] - prefix[x-1][y-1] + forest[x][y];
        }
    }

    for (int i = 0; i < q; i++) {
        cin >> yy1 >> x1 >> y2 >> x2;
        cout << prefix[x2][y2] - prefix[x2][yy1-1] - prefix[x1-1][y2] + prefix[x1-1][yy1-1] << "\n";
    }
}
