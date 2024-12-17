#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// this took way too long

vector<ll> r(3), r_;
vector<int> ops;

ll combo(int operand) { return operand < 4 ? operand : r[operand - 4]; }

void solve(int b, ll a) {
    if (b == ops.size()) {
        cout << a << "\n";
        exit(0); // uncomment to get all solutions
    }
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
            solve(b + 1, a + byte);
        }
    }
}

int main() {
    freopen("day17-modified.txt", "r", stdin);
    for (auto &v : r)
        cin >> v;
    r_ = r;
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

    solve(0, 0);
}