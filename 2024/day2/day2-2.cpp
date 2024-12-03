#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> read_report() {
    string s;
    getline(cin, s);

    istringstream iss(s);

    vector<int> report;
    int x;
    while (iss >> x)
        report.push_back(x);
    return report;
}

int main() {
    freopen("day2.txt", "r", stdin);
    int ans = 0;
    while (!cin.eof()) {
        auto report = read_report();
        bool inc = report[1] > report[0];
        bool ok = true;
        for (int i = 1; i < report.size(); i++) {
            int diff = abs(report[i] - report[i - 1]);
            ok &= report[i] > report[i - 1] == inc && 1 <= diff && diff <= 3;
        }
        for (int i = 0; i < report.size(); i++) {
            int x = report[i];
            bool cur_ok = true;
            report.erase(report.begin() + i);
            inc = report[1] > report[0];
            for (int i = 1; i < report.size(); i++) {
                int diff = abs(report[i] - report[i - 1]);
                cur_ok &= report[i] > report[i - 1] == inc && 1 <= diff && diff <= 3;
            }
            report.insert(report.begin() + i, x);
            ok |= cur_ok;
        }
        ans += ok;
    }
    cout << ans << "\n";
}