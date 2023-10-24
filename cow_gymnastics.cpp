// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int k, n, rankings[10][20], ans, c, d, cow;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> k >> n;

	for (int contest = 0; contest < k; contest++) {
		for (int placement = 1; placement <= n; placement++) {
			cin >> cow;
			rankings[contest][cow-1] = placement;
		}
	}


	for (int a = 0; a < n; a++) {
		for (int b = a+1; b < n; b++) {
			c = 0;
			d = 0;
			for (int i = 0; i < k; i++) {
				if (rankings[i][a] > rankings[i][b]) {
					c = 1;
				}
				else {
					d = 1;
				}
			}
			if (!(c&&d)) {
				ans++;
			}
		}
	}

	cout << ans;

}
