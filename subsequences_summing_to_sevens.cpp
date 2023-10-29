#include <bits/stdc++.h>
using namespace std;

int n, x, y, first[6], dif[7];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        y += x;
        x = y % 7;
        y = x;
        if (x == 0) {
            dif[0] = i;
        }
        if (x == 1) {
            if (!first[0]) {
                first[0] = i;
            }
            else {
                dif[1] = i-first[0];
            }
        }
        if (x == 2) {
            if (!first[1]) {
                first[1] = i;
            }
            else {
                dif[2] = i-first[1];
            }
        }
        if (x == 3) {
            if (!first[2]) {
                first[2] = i;
            }
            else {
                dif[3] = i-first[2];
            }
        }
        if (x == 4) {
            if (!first[3]) {
                first[3] = i;
            }
            else {
                dif[4] = i-first[3];
            }
        }
        if (x == 5) {
            if (!first[4]) {
                first[4] = i;
            }
            else {
                dif[5] = i-first[4];
            }
        }
        if (x == 6) {
            if (!first[5]) {
                first[5] = i;
            }
            else {
                dif[6] = i-first[5];
            }
        }
    }

    cout << *max_element(dif, dif + 7);
}
