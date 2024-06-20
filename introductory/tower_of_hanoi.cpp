#include<iostream>
#include<vector>
#include<algorithm>
#include<chrono>
#include<map>
#include<set>
#include<unordered_set>
#include<unordered_map>


#define cerr if(false)cerr
#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
#define ll long long

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

void solve(ll t, ll source, ll dest, ll via, vector<vector<ll> >& res) {
	if(t == 0) return;

	solve(t-1, source, via, dest, res);
	res.push_back({source, dest});
	solve(t-1, via, dest, source, res);
}
 
int main() {
	ll t;
	cin >> t;

	vector<vector<ll> > res;

	solve(t, 1, 3, 2, res);

	cout << res.size() << "\n";
	for(ll i=0; i<res.size(); i++) {
		cout << res[i][0] << " " << res[i][1] << "\n";
	}

	return 0;
}