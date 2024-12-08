#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool solve(ll n, vector<int> &terms, ll cur, int i) {
    if (i == terms.size())
        return n == cur;
    bool ok = solve(n, terms, cur + terms[i], i + 1);
    if (cur <= n / terms[i])
        ok |= solve(n, terms, cur * terms[i], i + 1);
    int len = to_string(terms[i]).size();
    // cur * 10**len + terms[i] <= n
    if (cur <= (n - terms[i]) / pow(10, len)) {
        ok |= solve(n, terms, cur * pow(10, len) + terms[i], i + 1);
    }
    return ok;
}

vector<int> read_terms() {
    string s;
    getline(cin, s);

    istringstream iss(s);

    vector<int> terms;
    int x;
    while (iss >> x)
        terms.push_back(x);
    return terms;
}

int main() {
    freopen("day7.txt", "r", stdin);
    ll ans = 0;
    while (!cin.eof()) {
        ll n;
        cin >> n;
        auto terms = read_terms();
        ans += solve(n, terms, terms[0], 1) * n;
    }
    cout << ans << "\n";
}