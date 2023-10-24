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
		sa = 0;
		sc = 0;
		sg = 0;
		st = 0;
		pa = 0;
		pg = 0;
		pc = 0;
		pt = 0;
		for(int j = 0; j < n; j++) {
			if (cows[j][i] == 'A') {
				sa = 1;
			}
			if (cows[j][i] == 'C') {
				sc = 1;
			}
			if (cows[j][i] == 'G') {
				sg = 1;
			}
			if (cows[j][i] == 'T') {
				st = 1;
			}
		}
		for(int j = n; j < 2*n; j++) {
			if (cows[j][i] == 'A') {
				pa = 1;
			}
			if (cows[j][i] == 'C') {
				pc = 1;
			}
			if (cows[j][i] == 'G') {
				pg = 1;
			}
			if (cows[j][i] == 'T') {
				pt = 1;
			}
		}
		if ((sa*pa == 0) && (sc*pc == 0) && (sg*pg == 0) && (st*pt == 0)) {
			ans ++;
		}
	}
	cout << ans;
	
}
