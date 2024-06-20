#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cstdint>

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

bool cmp(pii& a, pii& b) {
    return a.first < b.first;
}

void solve(vector<vector<ll> >& interval) {
	vector<pii> event;

	for(ll i=0; i<interval.size(); i++) {
		event.push_back({interval[i][0], 0});
		event.push_back({interval[i][1], 1});
	}

	sort(event.begin(), event.end(), cmp);

	ll active_interval = 0;
	ll res = 0;

	for(ll i=0; i<event.size(); i++) {
		if(event[i].second == 0) active_interval++;
		else active_interval--;

		res = max(res, active_interval);
	}
    
    cout << res;
}

int main() {
    ll t;
    cin >> t;

    vector<vector<ll>> interval;

    for (int i = 0; i < t; i++) {
        ll a, b;
        cin >> a >> b;
        interval.push_back({a, b});
    }

    solve(interval);

    return 0;
}
