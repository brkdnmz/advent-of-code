#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// overkilled with inclusion-exclusion but worth it

// sum of numbers in form XXX..X (rep times) where X <= r (concatenated)
ll get_sum(int r, int rep) {
    ll s = 0;
    ll pw10 = 1;
    for (; pw10 * 10 - 1 < r; pw10 *= 10) {
        // pw10 to pw10 * 10 - 1
        ll coef = 0;
        ll p = 1;
        for (int i = 0; i < rep; i++)
            coef += p, p *= pw10 * 10;
        s += coef * (pw10 * 9) * (pw10 * 11 - 1) / 2;
    }
    // pw10 to r
    ll coef = 0;
    ll p = 1;
    for (int i = 0; i < rep; i++)
        coef += p, p *= pw10 * 10;
    s += coef * (r - pw10 + 1) * (r + pw10) / 2;
    return s;
}

ll invalids_sum_up_to(ll r) {
    string s = to_string(r);
    int n = s.size();
    ll ans = 0;

    // https://usaco.guide/plat/PIE?lang=cpp
    vector<int> mobius(n + 1);
    mobius[1] = -1;
    for (int i = 1; i <= n; i++) {
        if (mobius[i]) {
            mobius[i] = -mobius[i];
            for (int j = 2 * i; j <= n; j += i) {
                mobius[j] += mobius[i];
            }
        }
    }
    for (int rep = 2; rep <= n; rep++) {
        ll lim = pow(10, n / rep) - 1;
        if (n % rep == 0) {
            string first = s.substr(0, n / rep);
            lim = stoll(first);
            for (int i = 1; i < rep; i++) {
                string cur = s.substr(n / rep * i, n / rep);
                if (cur > first)
                    break;
                if (cur < first) {
                    lim--;
                    break;
                }
            }
        }
        ans += get_sum(lim, rep) * -mobius[rep];
    }
    return ans;
}

int main() {
    freopen("1_pretty.txt", "r", stdin);
    ll tot = 0;
    while (!cin.eof()) {
        ll id1, id2;
        cin >> id1 >> id2;
        tot += invalids_sum_up_to(id2) - invalids_sum_up_to(id1 - 1);
    }
    cout << tot << "\n";
}