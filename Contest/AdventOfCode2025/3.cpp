#include "pch.h"

using namespace std;
using ll = long long;


bool isGood(vector<string>& grid, int a, int b) {
	int cnt = 0;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			int x = a + i;
			int y = j + b;
			if (i == 0 && j == 0) continue;
			if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) continue;
			if (grid[x][y] == '@') {
				cnt++;
			}
		}
	}
	// cout << cnt << endl;
	return cnt < 4;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    vector<string> grid;
    string s;
    while (cin >> s) {
    	grid.push_back(s);
    }

    int n = grid.size();
    int m = grid[0].size();

    ll res = 0;

    ll lastres = -1;
    vector<pair<int, int>> toRemove;
    while (res != lastres) {
    	lastres = res;
    	for (int i = 0; i < n; i++) {
	    	for (int j = 0; j < m; j++) {
	    		if (grid[i][j] == '@' && isGood(grid, i, j)) {
	    			toRemove.push_back({i, j});
	    			res++;
	    		}
	    	}
    	}

    	for (auto& p : toRemove) {
    		grid[p.first][p.second] = '.';
    	}
    	toRemove.clear();
    }
    

    cout << res << endl;
    
	return 0;
}
