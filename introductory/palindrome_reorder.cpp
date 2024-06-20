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

void solve(string& s) {
	bool odd = true;
	unordered_map<char, ll> freq;

	for(ll i=0; i<s.length(); i++) {
		freq[s[i]]++;
	}

	string res (s.length(), ' ');
	int n = s.length(), k = 0;

	for(auto& [key, val] : freq) {
		if(val & 1) {
			if(!odd) {
				cout << "NO SOLUTION";
				return;
			} else {
				odd = false;
				res[n/2] = key;
			}
		}	
		for(int i=0; i<val/2; i++) {
			res[k] = key;
			res[n-k-1] = key;
			k++;
		}
	}
	cout << res;

}
 
int main() {
	string t;
	cin >> t;

	solve(t);

	return 0;
}