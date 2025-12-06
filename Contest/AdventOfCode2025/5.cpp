using namespace std;
using ll = long long;



ll calcFromStrings(vector<string>& strs, bool op, int maxlen) {
	ll tmpRes;
	if (op) {
		tmpRes = 1;
	} else {
		tmpRes = 0;
	}

	int n = strs.size();

	vector<ll> nums;

	// cout << maxlen << endl;
	for (int i = 0; i < maxlen; i++) {
		string here;
		for (int j = 0; j < strs.size(); j++) {
			if (i >= strs[j].size()) continue;
			if (strs[j][i] == ' ') continue;
			here.push_back(strs[j][i]);
		}
		// cout << " hereee:" << here << " ";
		nums.push_back(stoll(here));
	}

	for (ll num : nums) {
		if (op) {
			tmpRes *= num;
		} else {
			tmpRes += num;
		}
	}


	return tmpRes;

}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    vector<string> grid;
    vector<bool> ops; // true for mult
    vector<int> idxes;

    string s;
    while (getline(cin, s)) {
    	if (s[0] == '*' || s[0] == '+') {
    		stringstream ss(s);
    		char c;
    		while (ss >> c) {
    			if (c == '*') {
    				ops.push_back(true);
    			} else {
    				ops.push_back(false);
    			}
    		}

    		for (int i = 0; i < s.size(); i++) {
    			if (s[i] != ' ') {
    				idxes.push_back(i);
    			}
    		}
    		idxes.push_back(s.size() + 1);
    	} else {
    		grid.push_back(s);
    	}
    }

    int n = grid.size();
    ll res = 0;

    for (int i = 0; i < idxes.size() - 1; i++) {
    	vector<string> strs;
    	for (int j = 0; j < n; j++) {
    		strs.push_back(grid[j].substr(idxes[i], idxes[i+1] - idxes[i] - 1));
    	}
    	// cout << calcFromStrings(strs, ops[i], idxes[i+1] - idxes[i] - 1) << endl;
    	res += calcFromStrings(strs, ops[i], idxes[i+1] - idxes[i] - 1);
    }

    cout << "END: " << endl;
    cout << res << endl;


    
	return 0;
}
