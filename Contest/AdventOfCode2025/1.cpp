#include "pch.h"

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s;
    vector<string> strs;
    while (cin >> s) {
        strs.push_back(s);
    }

    int curr = 50;
    int res = 0;
    for (string s : strs) {
        int orig = curr;
        char dir = s[0];
        int num = stoi(s.substr(1));
        if (dir == 'R') {
            curr += num;
            res += (curr / 100);
        } else {
            curr -= num;
            res += abs(curr / 100);
            if (orig != 0 && curr <= 0) res++;
        }
        curr += 1000;
        curr %= 100;
        // cout << res << endl;
    }

    cout << res << endl;

    return 0;
}