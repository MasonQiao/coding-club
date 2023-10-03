// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int n;
int cows[10][10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	string randomshit;
	for (int i = 0; i < n; i++) {
		cin >> randomshit;
		for (int k = 0; k < n; k++) {
			cows[k][i] = randomshit[k]-'0';
		}
	}

	int ans = 0;

	for (int y = n-1; y >= 0; y -= 1) {
		for (int x = n-1; x >= 0; x -= 1) {
			if (cows[x][y] == 1) {
				ans += 1;
				for (int x2 = x; x2 >= 0; x2-=1) {
					for (int y2 = y; y2 >= 0; y2-=1) {
						cows[x2][y2] = 1 - cows[x2][y2];
					}
				}

			}
		}
	}

	cout << ans;

}
