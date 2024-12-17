#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// this took way too long

// this solution fails because it's greedily choosing the smallest byte each time,
// instead of considering other candidates
// this ends up finding no valid solution! (the assertion byte != 7 fails)

int main() {
    freopen("day17-modified.txt", "r", stdin);
    vector<ll> r(3);
    for (auto &v : r)
        cin >> v;
    vector<int> ops;
    while (!cin.eof()) {
        int op;
        cin >> op;
        ops.push_back(op);
    }

    /*
        Program:
        while(a){
            b = a & 0b111
            b ^= 1
            c = a >> b
            b ^= 5
            b ^= c
            a >>= 3
            print(b)
        }

        Can construct a right-to-left, 3 bits each time
    */

    auto r_ = r;

    auto combo = [&](int operand) { return operand < 4 ? operand : r[operand - 4]; };

    ll a = 0;
    for (int b = 0; b < ops.size(); b++) {
        a <<= 3;
        for (ll byte = 0; byte < 8; byte++) {
            r = r_;
            r[0] = a + byte;
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
                // for (int x : output)
                //     cout << x << " ";
                // cout << "\n";
                a += byte;
                break;
            }
            // assert(byte != 7);
        }
    }
    cout << a << "\n";
}