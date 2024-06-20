#include<iostream>
#include<math.h>
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

ll solve(ll i, ll sum, ll total, vector<ll>& nums) {
	if(i == nums.size()) {
		return abs(total - 2*sum);
	}

	return min(solve(i+1, sum+nums[i], total, nums), solve(i+1, sum, total, nums));
}
 
int main() {
	ll t;
	cin >> t;

	ll total = 0;
	vector<ll> nums;
	for(int i=0; i<t; i++) {
		ll temp;
		cin >> temp;
		total += temp;
		nums.push_back(temp);
	}

	cout << solve(0, 0, total, nums);

	return 0;
}