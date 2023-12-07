// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int n, degree[100000], a, b;

int main() {
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b;
		degree[a-1] ++;
		degree[b-1] ++;
	}
	sort(degree, degree+n);
	cout << degree[n-1] + 1;
}
