#include<iostream>
#include<vector>
#include<algorithm>
#include<chrono>
#include<map>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<stack>


#define cerr if(false)cerr
#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
#define ll long long
#define pii pair<ll, ll>

using namespace std;

struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

bool isSafe(ll n, ll x, ll y, vector<bool>& col, vector<bool>& dia1, vector<bool>& dia2) {
	return col[y] == 0 && dia1[x+y] == 0 && dia2[n-x+y-1] == 0;
}

ll backtrack(ll row, ll n, vector<string>& board, vector<bool>& col, vector<bool>& dia1, vector<bool>& dia2) {
	if(row >= n) {
		return 1;
	}

	ll res = 0;

	for(ll j=0; j<n; j++) {
		if(board[row][j] != '*' && isSafe(n, row, j, col, dia1, dia2)) {
			col[j] = dia1[row+j] = dia2[n-row+j-1] = 1;
			board[row][j] = 'q';
			res += backtrack(row+1, n, board, col, dia1, dia2);
			board[row][j] = '.';
			col[j] = dia1[row+j] = dia2[n-row+j-1] = 0;
		}
	}

	return res;
}

void solve(vector<string>& board) {
	ll n = board.size();
	vector<bool> col(n, 0), dia1(2*n-1, 0), dia2(2*n-1, 0);

	cout << backtrack(0, n, board, col, dia1, dia2);
}
 
int main() {
	vector<string> board;

	for(ll i=0; i<8; i++) {
		string temp;
		cin >> temp;

		board.push_back(temp);
	}

	solve(board);

	return 0;
}