#include <bits/stdc++.h>

using namespace std;


int n, leftmost, rightmost, bales[50000];

int leftmostindex, rightmostindex = 0;

int left(int a) {

	int l = rightmostindex - 1;

	int r = n-1;

	if (bales[n-1] <= a) {

		return bales[n-1];

	}

	while (l + 1 < r) {

		int m = (l + r + 1) / 2;

		if (bales[m] == a) {

			return a;

		}

		else if (bales[m] > a) {

			r = m - 1;

		}

		else {

			l = m;

		}

	}

	rightmostindex = l;

	return bales[l];

}


int right(int b) {

	int l = 0;

	int r = leftmostindex;

	if (bales[0] >= b) {

		return bales[0];

	}

	while (l + 1 < r) {

		int m = (l+r+1) / 2;

		if (bales[m] == b) {

			return b;

		}

		else if (bales[m] < b) {

			l = m + 1;

		}

		else {

			r = m;

		}	

	}

	return bales[r];

	leftmostindex = r;

}


bool rcheck(int f, int R) {

	int R1 = R;

	leftmost = f;

	rightmost = f;

	while (R > 0) {

		leftmost = right((leftmost - R));

		R = R - 2;

		if (leftmost <= bales[0]) {

			while (R1 > 0) {

				rightmost = left((rightmost + R1));

				R1 = R1 - 2;

				if (rightmost >= bales[n - 1]) {

					return true;

				}

			}

			if (rightmost >= bales[n - 1]) {

					return true;

			}

		}

	}

	return false;

}


int hijoshua() {

	int le = 1;

	int ri = bales[n-1]-bales[0];

	bool randomshit;

	int mid;

	while (le < ri) {

		mid = (le + ri) / 2;

		randomshit = false;

		for (int i = 0; i < n - 1; i++) {

			if (rcheck((bales[i] + bales[i+1])/2, mid)) {

				randomshit = true;

				break;

			}

		}

		

		if (randomshit) {

			ri = mid;

		}

		else {

			le = mid + 1;

		}

	}

	return le;

}



int main() {

	ios::sync_with_stdio(false);

	cin.tie(nullptr);


	cin >> n;

	leftmostindex = n - 1;

	int x;

	for (int i = 0; i < n; i++) {

		cin >> x;

		bales[i] = x * 2;

	}


	sort(bales, bales + n);

	printf("%.1f", hijoshua()/2.0);

}
