#include<iostream>
#include<vector>
#include<algorithm>
#include<chrono>
#include<map>
#include<unordered_map>


#define cerr if(false)cerr
#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
#define ll unsigned long long
#define li unsigned long long

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

void solve(ll i) {
	ll res = 0;
    
    cout << ((i*i)*((i*i)-1)/2) - (i-3+1)*(i-2+1)*4 << "\n";

}
 
int main() {
	ll n;
	cin >> n;

	for(ll i=1; i<=n; i++) {
        solve(i);
    }

	return 0;
}