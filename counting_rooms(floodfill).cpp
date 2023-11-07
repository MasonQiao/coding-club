// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int n, m, building[1000][1000], visited[1000][1000], ans, c, d;
string a;
queue<tuple <int, int>> q;

void floodfill(int x, int y) {
	q.push(make_tuple(x, y));
	visited[x][y] = 1;
	while (!q.empty()) {
		c = get<0>(q.front());
		d = get<1>(q.front());
		q.pop();
		if (c + 1 < m) {
			if (building[c+1][d] && !visited[c+1][d]) {
				visited[c+1][d] = 1;
				q.push(make_tuple(c+1, d));
			}
		}
		if (c > 0) {
			if (building[c-1][d] && !visited[c-1][d]) {
				visited[c-1][d] = 1;
				q.push(make_tuple(c-1, d));
			}
		}
		if (d + 1 < n) {
			if (building[c][d+1] && !visited[c][d+1]) {
				visited[c][d+1] = 1;
				q.push(make_tuple(c, d+1));
			}
		}
		
		if (d > 0) {
			if (building[c][d-1] && !visited[c][d-1]) {
				visited[c][d-1] = 1;
				q.push(make_tuple(c, d-1));
			}
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a;
		for (int j = 0; j < m; j++) {
			if (a[j] == '.') {
				building[j][i] = 1;
			}
		}
	}
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			if (building[x][y] && !visited[x][y]) {
				floodfill(x, y);
				ans ++;
			}
		}
	}
	cout << ans;
}
