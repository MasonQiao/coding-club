#include <bits/stdc++.h>
using namespace std;

int n, arr[200000], prefix[200000], ans, x;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    prefix[0] = arr[0];
    ans = arr[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i-1] + arr[i];
    }
    x = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, prefix[i] - x);
        if (prefix[i] < x) {
            x = prefix[i];
        }
    }
    cout << ans;
}
