// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int n, ans, randomshit;



int main() {
	cin >> n;
    int cows[n];

    for (int i = 0; i < n; i++) {
        cin >> randomshit;
        cows[i] = randomshit;
    }

    sort(cows, cows + n, greater<int>());

    for (int i = 0; i < n; i++) {
        if (cows[i] >= ans) {
            ans++;
        }
    }

    cout << ans;
    return 0;
}

