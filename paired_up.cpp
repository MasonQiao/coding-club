// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

long long n, x, y, cows[5000000], m, ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		x = min(x, x%2+2);
		for (int j = m; j < m+x; j++) {
			cows[j] = y;
		}
		m += x;
	}
	sort(cows, cows + m);
	for (int i = 0; i < m/2; i++) {
		ans = max(ans, cows[i] + cows[m-i-1]);
	}
	cout << ans;
}
