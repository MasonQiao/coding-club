// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

long long n, s, l, r, prefix[100001], x, ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> s;
	for (long long i = 1; i <= n; i++) {
		cin >> x;
		prefix[i] = prefix[i-1] + x;
	}
	
	while (r <= n) {
		if (prefix[r] - prefix[l] <= s) {
			ans = max(ans, r-l);
			r++;
		}
		else {
			l++;
		}
	}

	cout << ans;

}
