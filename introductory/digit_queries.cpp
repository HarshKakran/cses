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
#include<cmath>


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

// k >= 1*n1 + 2*n2 + 3*n3 + ...
// max(n1) --> 9
// max(n2) --> 90
// max(n3) --> 900
// .
// . 
// .

void solve() {
    ll k;
    cin >> k;

    ll start = 1;
    ll count = 9;
    ll length = 1;

    while(k > length * count) {
    	k -= length * count;
    	length++;
    	count *= 10;
    	start *= 10;
    }

    // Adjust the start number correctly
    start += (k + length - 1) / length - 1;

    cout << to_string(start)[(k-1)%length] << "\n";
}

int main() {
    ll t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}