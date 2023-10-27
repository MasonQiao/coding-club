#include <bits/stdc++.h>
using namespace std;

int n, prefix[50001], ans, x;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        prefix[i] = (prefix[i-1] + x%7) % 7;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (prefix[i] == prefix[j]) {
                ans = max(ans, i-j);
            }
        }
    }
    cout << ans;
}
