#include<iostream>
#include<vector>
#include<algorithm>
#include<chrono>
#include<map>
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

void solve() {
	ll a, b;
	cin >> a >> b;

	if((a+b)%3 == 0 && max(a,b) <= min(a,b)*2) {
		cout << "YES" << "\n";
	} else {
		cout << "NO" << "\n";
	}
}
 
int main() {
	ll t;
	cin >> t;

	while(t--){solve();}

	return 0;
}