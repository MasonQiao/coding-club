// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int n, m, sa, sc, sg, st, pa, pc, pg, pt, ans;
string cows[200];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < 2*n; i++) {
		cin >> cows[i];
	}
	for (int i = 0; i < m; i++) {
		for(int j = 0; i < n; j++) {
			if (cows[j][i] == 'a') {
				sa = 1;
			}
			if (cows[j][i] == 'c') {
				sc = 1;
			}
			if (cows[j][i] == 'g') {
				sg = 1;
			}
			if (cows[j][i] == 't') {
				st = 1;
			}
		}
		for(int j = n; i < 2*n; j++) {
			if (cows[j][i] == 'a') {
				pa = 1;
			}
			if (cows[j][i] == 'c') {
				pc = 1;
			}
			if (cows[j][i] == 'g') {
				pg = 1;
			}
			if (cows[j][i] == 't') {
				pt = 1;
			}
		}
		if (sa*pa == 0 && sc*pc == 0 && sg*pg == 0 && st*pt == 0) {
			ans ++;
		}
	}
	cout << ans;
}
