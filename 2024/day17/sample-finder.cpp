#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    freopen("sample-2.txt", "r", stdin);
    vector<ll> r(3);
    for (auto &v : r)
        cin >> v;
    vector<int> ops;
    while (!cin.eof()) {
        int op;
        cin >> op;
        ops.push_back(op);
    }

    auto r_ = r;

    auto combo = [&](int operand) { return operand < 4 ? operand : r[operand - 4]; };

    ll a = 0;
    for (int b = 0; b < ops.size(); b++) {
        r = r_;
        for (ll byte = 0; byte < 8; byte++) {
            r[0] = ((a << 3) + byte) << 3;
            vector<int> output;
            for (int i = 0; i + 1 < ops.size();) {
                int opcode = ops[i], operand = ops[i + 1];
                i += 2;
                switch (opcode) {
                case 0: // a = a / 2^c(operand)
                    r[0] >>= combo(operand);
                    break;
                case 1: // b = b ^ operand
                    r[1] ^= operand;
                    break;
                case 2: // b = c(operand) & 111
                    r[1] = combo(operand) & 0b111;
                    break;
                case 3: // jump to operand if a != 0
                    if (r[0])
                        i = operand;
                    break;
                case 4: // b = b ^ c
                    r[1] ^= r[2];
                    break;
                case 5: // print(c(operand) & 111)
                    output.push_back(combo(operand) & 0b111);
                    break;
                case 6: // b = a / 2^c(operand)
                    r[1] = r[0] >> combo(operand);
                    break;
                case 7: // c = a / 2^c(operand)
                    r[2] = r[0] >> combo(operand);
                    break;
                }
            }
            if (output[0] == ops[ops.size() - 1 - b]) {
                // cout << b << " " << a << " " << byte << " " << output[0] << "\n";
                a = (a << 3) + byte;
                break;
            }
            assert(byte != 7);
        }
    }
    cout << (a << 3) << "\n";
}