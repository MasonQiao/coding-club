#include <bits/stdc++.h>
using namespace std;

int n, k, ans, index1, extra, b[1000];

void print_list() {
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    index1 = k-1;
    sort(b, b + n, greater<int>());
    while (b[0]/2 > b[k-1]) {
        while (index1 > 0) {
            if (b[0]/(k-index1+2) > b[index1-1]) {
                index1 -= 1;
            }
            else {
                break;
            }
        }
        extra = b[0] % (k-index1+1);
        b[0] = b[0]/(k-index1+1);
        for (int i = index1; i < k; i++) {
            b[i] = b[0];
        }
        b[0] = b[0] + extra;
        sort(b, b + n, greater<int>());
    }
    for (int i = k/2; i < k; i++) {
        ans += b[i];
    }
    cout << ans;

    return 0;
}
