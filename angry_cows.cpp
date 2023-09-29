#include <bits/stdc++.h>

using namespace std;


int n, bales[50000], leftthreshold, rightthreshold;

bool rcheck(int f, int R) {
	leftthreshold = 0;
	rightthreshold = 0;
	if (f%2 == 0) {
		for (int i = 0; i < f/2; i++) {
			leftthreshold = max(leftthreshold, bales[i+1]-bales[i] + (f-i-1));
		}
		for (int i = f/2; i < n - 1; i++) {
			rightthreshold = max(rightthreshold, bales[i+1]-bales[i] + (i-f));
		}
		return max(leftthreshold, rightthreshold) <= R;
	}
	else {
		leftthreshold = (bales[(f+1)/2] - bales[(f-1)/2]) / 2;
		for (int i = 0; i < (f-1)/2; i++) {
			leftthreshold = max(leftthreshold, bales[i+1]-bales[i] + (f-i-1));
		}
		rightthreshold = (bales[(f+1)/2] - bales[(f-1)/2]) / 2;
		for (int i = (f+1)/2; i < n - 1; i++) {
			rightthreshold = max(rightthreshold, bales[i+1]-bales[i] + (i-f));
		}
		return max(leftthreshold, rightthreshold) <= R;
	}
}


int hijoshua() {

	int le = 1;

	int ri = bales[n-1]-bales[0];

	bool randomshit;

	int mid;


	while (le < ri) {

		mid = (le + ri) / 2;

		randomshit = false;

		for (int i = 0; i + 1 < 2*n; i++) {

			if (rcheck(i, mid)) {

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

	int x;

	for (int i = 0; i < n; i++) {

		cin >> x;

		bales[i] = x * 2;

	}


	sort(bales, bales + n);
	printf("%.1f", hijoshua()/2.0);

}
