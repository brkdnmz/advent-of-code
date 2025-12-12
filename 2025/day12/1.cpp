#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    freopen("1.txt", "r", stdin);
    string s;
    int ub = 0;
    int lb = 0;
    vector<vector<string>> presents;
    while (getline(cin, s)) {
        regex rgx("^(\\d+):");
        smatch matches;
        regex_search(s, matches, rgx);
        if (regex_match(s, rgx)) {
            // next 3 lines describe the present
            presents.push_back({});
            for (int i = 0; i < 3; i++) {
                getline(cin, s);
                presents.back().push_back(s);
            }
        }
        rgx = "^(\\d+)x(\\d+):";
        regex_search(s, matches, rgx);
        if (matches.size() == 3) {
            int w = stoi(matches[1]), h = stoi(matches[2]);
            vector<int> present_counts;
            rgx = " (\\d+)";
            for (auto it = sregex_iterator(s.begin(), s.end(), rgx); it != sregex_iterator(); it++) {
                present_counts.push_back(stoi((*it)[1]));
            }
            int to_fill = 0;
            for (int i = 0; i < presents.size(); i++) {
                int cur = 0;
                for (auto x : presents[i])
                    for (auto y : x)
                        cur += y == '#';
                to_fill += cur * present_counts[i];
            }
            ub += to_fill <= w * h;
            lb += (w / 3) * (h / 3) >= accumulate(present_counts.begin(), present_counts.end(), 0);
            cout << to_fill << " " << w * h << endl;
        }
    }
    cout << lb << " " << ub << "\n";
    // turns out lower bound = upper bound, wow!
}