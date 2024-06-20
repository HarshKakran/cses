#include<iostream>
#include<vector>
#include<algorithm>
#include<chrono>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>


#define cerr if(false)cerr
#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
#define ll unsigned long long
#define li long long

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



void solve(ll n, ll target) {
	unordered_set<ll> map;

	ll i = n;
	ll sum = 0;
	while(sum < target) {
		map.insert(i);
		sum += i;
		i--;
	}

	if(sum > target) {
		sum -= (i+1);
		map.erase(map.find(i+1));
		map.insert(target - sum);
	}

	cout << map.size() << "\n";
	for(auto& ele:map) {
		cout << ele << " ";
	}

	cout << "\n" << n - map.size() << "\n";
	for(i=1; i<=n; i++) {
		if(map.find(i) == map.end()) {
			cout << i << " ";
		}
	}
}
 
int main() {
	ll n;
	cin >> n;

	ll total_sum = n*(n+1)/2;
	if(total_sum & 1) {
		cout << "NO" << "\n";
	} else {
		cout << "YES" << "\n";
		solve(n, total_sum/2);
	}

	return 0;
}