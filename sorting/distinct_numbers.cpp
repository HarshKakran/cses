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

void solve(ll t) {
	set<ll> num;
	for(ll i=0; i<t; i++) {
		int n; 
		cin >> n;

		num.insert(n);
	}

	cout << num.size();
}
 
int main() {
	ll t;
	cin >> t;

	solve(t);

	return 0;
}