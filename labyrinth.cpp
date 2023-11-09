#include <bits/stdc++.h>
using namespace std;

int n, m, startx, starty, endx, endy, minlength, a, b, c;
queue <tuple <int, int, int, string>> q;
string z, d, path;
bool labyrinth[1000][1000], visited[1000][1000], possible;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	minlength = 1000000;
	cin >> n >> m;
	for (int y = 0; y < n; y++) {
		cin >> z;
		for (int x = 0; x < m; x++) {
			if (z[x] == 'A') {
				startx = x;
				starty = y;
			}
			if (z[x] == 'B') {
				endx = x;
				endy = y;
			}
			if (z[x] == '.') {
				labyrinth[x][y] = 1;
			}
		}
	}
	q.push(make_tuple(startx, starty, 0, ""));
	visited[startx][starty] = 1;
	while (!q.empty()) {
		a = get<0>(q.front());
		b = get<1>(q.front());
		c = get<2>(q.front());
		d = get<3>(q.front());
		q.pop();
		if (a + 1 < m) {
			if ((endx == a+1) & (endy == b)) {
				if (c+1 < minlength) {
					possible = true;
					minlength = c+1;
					path = d+'R';
				}
			}
			else if (labyrinth[a+1][b] & !visited[a+1][b]) {
				visited[a+1][b] = 1;
				q.push(make_tuple(a+1, b, c+1, d+'R'));
			}
		}
		if (a > 0) {
			if ((endx == a-1) & (endy == b)) {
				if (c+1 < minlength) {
					possible = true;
					minlength = c+1;
					path = d+'L';
				}
			}
			else if (labyrinth[a-1][b] & !visited[a-1][b]) {
				visited[a-1][b] = 1;
				q.push(make_tuple(a-1, b, c+1, d+'L'));
			}
		}
		if (b + 1 < n) {
			if ((endx == a) & (endy == b+1)) {
				if (c+1 < minlength) {
					possible = true;
					minlength = c+1;
					path = d+'D';
				}
			}
			else if (labyrinth[a][b+1] & !visited[a][b+1]) {
				visited[a][b+1] = 1;
				q.push(make_tuple(a, b+1, c+1, d+'D'));
			}
		}
		if (b > 0) {
			if ((endx == a) & (endy == b-1)) {
				if (c+1 < minlength) {
					possible = true;
					minlength = c+1;
					path = d+'U';
				}
			}
			else if (labyrinth[a][b-1] & !visited[a][b-1]) {
				visited[a][b-1] = 1;
				q.push(make_tuple(a, b-1, c+1, d+'U'));
			}
		}
	}
	if (possible) {
		cout << "YES" << "\n" << minlength << "\n" << path;
	}
	else {
		cout << "NO" << "\n";
	}

	return 0;
}
