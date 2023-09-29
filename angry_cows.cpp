#include <bits/stdc++.h>

using namespace std;


int n, bales[50000];

bool rcheck(int f, int R) {

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
