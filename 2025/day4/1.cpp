#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    freopen("1.txt", "r", stdin);
    vector<string> v;
    while (!cin.eof()) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    int ans = 0;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[0].size(); j++) {
            int cnt = 0;
            for (int dx : {-1, 0, 1}) {
                for (int dy : {-1, 0, 1}) {
                    if (!dx && !dy)
                        continue;
                    int ni = i + dx, nj = j + dy;
                    if (ni < 0 || ni >= v.size() || nj < 0 || nj >= v[0].size())
                        continue;
                    cnt += v[ni][nj] == '@';
                }
            }
            ans += v[i][j] == '@' && cnt < 4;
        }
    }
    cout << ans << "\n";
}