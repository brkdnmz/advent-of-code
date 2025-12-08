#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    freopen("1.txt", "r", stdin);
    string s;
    vector<array<ll, 3>> boxes;
    while (getline(cin, s)) {
        regex rgx("(\\d*),(\\d*),(\\d*)");
        smatch matches;
        regex_search(s, matches, rgx);
        ll x = stoll(matches[1].str()), y = stoll(matches[2].str()), z = stoll(matches[3].str());
        boxes.push_back({x, y, z});
    }
    int n = boxes.size();
    vector<int> p(n), sz(n);
    for (int i = 0; i < n; i++)
        p[i] = i, sz[i] = 1;
    auto f = [&](auto &&self, int x) -> int { return p[x] = (x == p[x] ? x : self(self, p[x])); };
    auto c = [&](int x, int y) {
        x = f(f, x), y = f(f, y);
        if (x == y)
            return 0;
        p[y] = x, sz[x] += sz[y];
        return 1;
    };
    auto sq = [](ll x) { return x * x; };
    vector<array<ll, 3>> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            edges.push_back(
                {sq(boxes[i][0] - boxes[j][0]) + sq(boxes[i][1] - boxes[j][1]) + sq(boxes[i][2] - boxes[j][2]), i, j});
        }
    }
    sort(edges.begin(), edges.end());
    for (int i = 0; i < min((int)edges.size(), 1000); i++) {
        c(edges[i][1], edges[i][2]);
    }

    vector<ll> sizes;
    for (int i = 0; i < n; i++)
        if (p[i] == i) {
            sizes.push_back(sz[i]);
        }
    sort(sizes.begin(), sizes.end());
    reverse(sizes.begin(), sizes.end());

    cout << sizes[0] * sizes[1] * sizes[2] << "\n";
}