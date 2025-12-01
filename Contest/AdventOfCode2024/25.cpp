#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <string>
#include <sstream>
#include <array>

using namespace std;
using ll = long long;

bool fits(array<int, 7>& lock, array<int, 7>& key) {
    for (int i = 0; i < 5; i++) {
        if (lock[i] + key[i] <= 7) continue;
        // cout << i << ": " << lock[i] << " + " << key[i] << endl;
        return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll size = 7;

    string s;
    vector<array<string, 7>> keys;
    vector<array<string, 7>> locks;
    while (getline(cin, s)) {
        if (s.size() == 0) continue;
        bool isLock;
        if (s[0] == '#') {
            // lock
            isLock = true;
        } else {
            isLock = false;
        }

        array<string, 7> thing;
        thing[0] = s;
        for (int i = 0; i < size - 1; i++) {
            getline(cin, s);
            thing[i+1] = s;
        }

        if (isLock) {
            locks.push_back(thing);
        } else {
            keys.push_back(thing);
        }
    }

    vector<array<int, 7>> keySizes;
    vector<array<int, 7>> lockSizes;
    for (int k = 0; k < locks.size();k++) {
        array<int, 7> lockSize;
        for (int j = 0; j < 5; j++) {
            int i = 0;
            for (; i < 7; i++) {
                if (locks[k][i][j] != '#') break;
            }
            lockSize[j] = i;
            // cout << lockSize[j] << " ";
        }
        lockSizes.push_back(lockSize);
        // cout << endl;
    }

    for (int k = 0; k < keys.size();k++) {
        array<int, 7> keySize;
        for (int j = 0; j < 5; j++) {
            int i = 0;
            for (; i < 7; i++) {
                if (keys[k][i][j] == '#') break;
            }
            keySize[j] = 7 - i;
        }
        keySizes.push_back(keySize);
    }

    ll result = 0;
    for (int i = 0; i < keySizes.size(); i++) {
        for (int j = 0; j < lockSizes.size(); j++) {
            if (fits(lockSizes[j], keySizes[i])) result++;
        }
    }

    cout << result << endl;



    return 0;
}