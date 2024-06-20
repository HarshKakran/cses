#include<iostream>
#include<vector>
#include<algorithm>

#define cerr if(false)cerr
#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
#define ll unsigned long long
#define li unsigned long long

using namespace std;

// struct custom_hash {
// 	static uint64_t splitmix64(uint64_t x) {
// 		x += 0x9e3779b97f4a7c15;
//         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//         return x ^ (x >> 31);
// 	}

// 	size_t operator()(uint64_t x) const {
// 		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
// 		return splitmix64(x + FIXED_RANDOM);
// 	}
// };

void solve() {
	ll x, y;
	cin >> x >> y;
    if (x < y)
    {
        if (y % 2 == 1)
        {
            li r = y * y;
            cout << r - x + 1 << endl;
        }
        else
        {
            li r = (y - 1) * (y - 1) + 1;
            cout << r + x - 1 << endl;
        }
    }
    else
    {
        if (x % 2 == 0)
        {
            li r = x * x;
            cout << r - y + 1 << endl;
        }
        else
        {
            li r = (x - 1) * (x - 1) + 1;
            cout << r + y - 1 << endl;
        }
    }
}
 
int main(){
	ll t;
	cin >> t;

	while(t--) {
		solve();
	}

	return 0;
}