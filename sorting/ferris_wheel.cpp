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

void solve(ll n, ll x, vector<ll> &wt) {
	vector<bool> vis(n, false);
	ll count = 0;

	sort(wt.begin(), wt.end());

	for(ll i=0; i<n; i++) {
		if(!vis[i]) {
			vis[i] = true;

			ll ub = upper_bound(wt.begin()+i+1, wt.end(), abs(x - wt[i])) - wt.begin() - 1;

			if(ub < n && ub > i && vis[ub]) {
				ub = upper_bound((vis.begin()+i+1), (vis.begin()+ub), false) - vis.begin() - 1;
			}

			if(ub < n && ub > i) {
				vis[ub] = true;
			}
			count++;
		}
	}

	cout << count << endl;
}
 
int main() {
	ll n, x;
	cin >> n >> x;
	vector<ll> wt(n);

	for(ll i=0; i<n; i++) {
		ll temp;
		cin >> temp;
		wt[i] = temp;
	}

	solve(n, x, wt);

	return 0;
}