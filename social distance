#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[200000];

int bplace (int b, int w[]) {
    int l = 0;
    int r = 2*m - 1;
    while (l + 1 < r) {
        int middle1 = (l + r + 1) / 2;
        if (b == w[middle1]) {
            return b;
        }
        else if (b > w[middle1]) {
            l = middle1;
        }
        else if (b < w[middle1]) {
            r = middle1;
        }
    }
    if (l % 2 == 0) {
        return b;
    }
    else {
        return w[r];
    }
}

bool dcheck(int d, int c[]) {
    int placed = c[0];
    for (int i = 1; i < n; i++) {
        int b = placed + d;
        if (b > c[2*m - 1]) {
            return false;
        }
         placed = bplace(b, c);
    }
    return true;
}
int left(int z[]) {
    int l = 0;
    int r =((z[2 * m - 1] - z[0]) / (n-1)) + 1;
    while (l < r) {
        int middle = (l + r + 1) / 2;
        bool d = dcheck(middle, z);
        if (!d) {
            r = middle - 1;
        }
        else {
            l = middle;
        }
    }
    return l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int randomshit1, randomshit2;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> randomshit1 >> randomshit2;
        a[2*i] = randomshit1;
        a[2*i+1] = randomshit2;
    }
    sort(a, a + 2*m);

    cout << left(a);


    return 0;
}
