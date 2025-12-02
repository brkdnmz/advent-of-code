#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// sum of numbers in form XX where X <= r (concatenated)
ll get_sum(int r) {
    ll s = 0;
    ll pw10 = 1;
    for (; pw10 * 10 - 1 < r; pw10 *= 10) {
        // pw10 to pw10 * 10 - 1
        s += (pw10 * 10 + 1) * (pw10 * 9) * (pw10 * 11 - 1) / 2;
    }
    // pw10 to r
    s += (pw10 * 10 + 1) * (r - pw10 + 1) * (r + pw10) / 2;
    return s;
}

ll invalids_sum_up_to(ll r) {
    string s = to_string(r);
    ll pw10 = pow(10, s.size() / 2);
    if (s.size() % 2) {
        // 11 + 22 + ... + 99 + 1010 + 1111 + ... + 99999999
        return get_sum(pw10 - 1);
    }
    ll right_part = r % pw10;
    ll left_part = r / pw10;
    ll x = min(left_part, right_part);
    return get_sum(left_part - (left_part > right_part));
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