#include <bits/stdc++.h>
using namespace std;

int n, m, cows[3][20], ac[4][10], temps[101], mask, ans, cost;
bool fucked;
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> cows[0][i] >> cows[1][i] >> cows[2][i];
    }
    for (int i = 0; i < m; i++) {
        cin >> ac[0][i] >> ac[1][i] >> ac[2][i] >> ac[3][i];
    }
    ans = 10000;
    for (int i = 0; i < pow(2, m); i++) {
        mask = i;
        cost = 0;
        fucked = false;

        for (int j = 0; j < 101; j++) {
            temps[j] = 0;
        }

        for (int j = m-1; j>=0; j-=1) {
            if (pow(2, j) > mask) {
                for (int k = ac[0][j]; k <= ac[1][j]; k++) {
                    temps[k] += ac[2][j];
                }
                cost += ac[3][j];
            }
        }

        for (int j = 0; j < n; j++) {
            for (int k = cows[0][j]; k <= cows[1][j]; k++) {
                if (temps[k] < cows[2][j]) {
                    fucked = true;
                }
            }
        }

        if (!fucked) {
            ans = min(ans, cost);
        }
    }
    cout << ans;
}
