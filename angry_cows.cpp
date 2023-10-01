#include <bits/stdc++.h>

using namespace std;

int n, bales[50000], difs[50000], leftthreshold, rightthreshold, j, beststart;

int threshholddif(int f) {
	leftthreshold = difs[f]/2;
	rightthreshold = difs[f]/2;
	j = 1;
	for (int i = f-1; i>=0; i-=1) {
        leftthreshold = max(leftthreshold, (difs[i] + 2*j));
        j ++;
	}
	j = 1;
	for (int i = f+1; i < n-1; i++) {
        rightthreshold = max(rightthreshold, (difs[i] + 2*j));
        j++;
	}
	return abs(leftthreshold - rightthreshold);
}

bool rcheck(int f, int R) {
	leftthreshold = difs[f]/2;
	rightthreshold = difs[f]/2;
	j = 1;
	for (int i = f-1; i>=0; i-=1) {
        leftthreshold = max(leftthreshold, (difs[i] + 2*j));
        j ++;
	}
	j = 1;
	for (int i = f+1; i < n-1; i++) {
        rightthreshold = max(rightthreshold, (difs[i] + 2*j));
        j++;
	}
	return max(leftthreshold, rightthreshold) <= R;
}
int hijoshua() {

	int le = 1;

	int ri = bales[n-1]-bales[0];

	int mid;


	while (le < ri) {

		mid = (le + ri) / 2;


		if (rcheck(beststart, mid)) {

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

    for (int i = 0; i < (n - 1); i++) {
        difs[i] = (bales[i+1] - bales[i]);
    }

    beststart = n;
    int minthresholddif = 1e9;

    for (int i = 0; i < n - 1; i++) {
        int randomshit = threshholddif(i);
        if (randomshit < minthresholddif) {
            beststart = i;
            minthresholddif = randomshit;
        }

    }


    printf("%.1f", hijoshua()/2.0);

	return 0;

}
