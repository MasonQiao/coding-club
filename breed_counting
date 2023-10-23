// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int n, q, ones_seen[100001], twos_seen[100001], threes_seen[100001], x, a, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		if (x == 1) {
			ones_seen[i] = ones_seen[i-1] + 1;
		}
		else {
			ones_seen[i] = ones_seen[i-1];
		}
		if (x == 2) {
			twos_seen[i] = twos_seen[i-1] + 1;
		}
		else {
			twos_seen[i] = twos_seen[i-1];
		}
		if (x == 3) {
			threes_seen[i] = threes_seen[i-1] + 1;
		}
		else {
			threes_seen[i] = threes_seen[i-1];
		}
	}
	for (int i = 0; i < q; i++) {
		cin >> a >> b;
		cout << ones_seen[b] - ones_seen[a-1] << " " << twos_seen[b] - twos_seen[a-1] << " " << threes_seen[b] - threes_seen[a-1] << "\n";
	}
}
