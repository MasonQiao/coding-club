#include <bits/stdc++.h>

using namespace std;


int n, t, cows[10000];


bool kcheck(int k) {

    multiset<int>  cows1;

    for (int l = 0; l < k; l++) {

        cows1.insert(cows[l]);

    }

    for (int j = k; j < n; j++) {

        int urmom = *cows1.begin();

        cows1.erase(cows1.begin());

        cows1.insert(cows[j] + urmom);

    }

    for (int i=0; i<k-1; i++)

    {

        cows1.erase(cows1.begin());

    }

    return *cows1.begin()<=t;

}


int right() {

    int l = 0;

    int r = n;

    while (l + 1 < r) {

        int m = (l + r) / 2;

        bool b = kcheck(m);

        if (!b) {

            l = m;

        } else {

            r = m;

        }

    }

    return r;

}


int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);


    cin >> n >> t;

    for (int i = 0; i < n; i++) {

        cin >> cows[i];

    }

    cout << right();

    return 0;

}
