#include <bits/stdc++.h>

using namespace std;


long long n1;

long long k1;

long long m1;


bool checkx(long long x, long long n, long long k, long long m) {

	long long g = 0;

	long long y;

	long long days;

	long long i = 0;

	while (i < k) {

		y = (n - g) / x;

		if (y < m) {

			g += m*(k-i);

			return g >= n;

		}

		days = llround(((n - g) - (x*y)) / y) + 1;

		i += days;

		g += y*days;

	}

	return g >= n;

}


long long right() {

	long long l = 1;

	long long r = min(n1/m1, k1);

	long long mid;

	while (l < r) {

		mid = (l + r + 1) / 2;

		if (checkx(mid, n1, k1, m1)) {

			l = mid;

		}

		else {

			r = mid - 1;

		}

	}

	return l;

}


int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);


	

	cin >> n1 >> k1 >> m1;

	cout << right();


	return 0;

}
