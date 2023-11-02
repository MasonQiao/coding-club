// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

long long n, x, y, cows[400000], m, ans;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		x = max(x, x%2+2);
		m += x;
		for (int j = 0; j < x; j++) {
			cows[i+j] = y;
		}
	}
	sort(cows, cows + m);
	for (int i = 0; i < m/2; i++) {
		ans = max(ans, cows[i] + cows[i+m/2]);
	}
	cout << ans;
}
