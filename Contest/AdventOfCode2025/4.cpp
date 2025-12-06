using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    vector<pair<ll, ll>> ranges;

    string s;
    while (getline(cin, s) && s != "") {
    	int idx = s.find("-");
    	ranges.emplace_back(stoll(s.substr(0, idx)), stoll(s.substr(idx+1)));
    }

    vector<ll> ingrs;
    while (getline(cin, s)) {
    	ll x;
    	cin >> x;
    	ingrs.push_back(x);
    }

    sort(ranges.begin(), ranges.end());


    ll lasNum = -1;
    ll ans = 0;
    for (auto& p : ranges) {
    	if (p.second <= lasNum) continue;
    	if (p.first <= lasNum) {
    		ans += (p.second - lasNum);
    	} else {
    		ans += (p.second - p.first) + 1;
    	}
    	lasNum = max(lasNum, p.second);
    	cout << ans << endl;
    }

    cout << ans << endl;
    
	return 0;
}
