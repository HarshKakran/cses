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

void f(ll i, string& t, set<string>& res){
	if(i == t.length()) {
		res.insert(t);
		return;
	}

	for(int j=i; j<t.length(); j++) {
		swap(t[i], t[j]);
		f(i+1, t, res);
		swap(t[i], t[j]);
	}
}

void solve(string t) {
	set<string> res;

	for(ll i=0; i<t.length(); i++) {
		swap(t[0], t[i]);
		f(1, t, res);
		swap(t[0], t[i]);
	}

	cout << res.size() << "\n";
	for(string s:res) {
		cout << s << "\n";
	}
}
 
int main() {
	string t;
	cin >> t;

	solve(t);

	return 0;
}