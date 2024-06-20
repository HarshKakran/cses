// COMPILATION -> g++ --std=c++20 -O2 -Wall <>.cpp -o <>
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

void solve(ll n, ll m, vector<ll>& price, vector<ll>& bids) {
	vector<ll> ans(m, -1);
	vector<bool> vis(n+1, false);
	sort(price.begin(), price.end());

	// cout << "\n";
	// for(int i=0; i<n; i++) cout << price[i] << " ";
	// cout << "\n";

	for(int i=0; i<m; i++) {
		ll lb = upper_bound(price.begin(), price.end(), bids[i]) - price.begin();
		if(lb > 0) {
			lb--;
			// cout << lb << " " << price[lb] << " " << vis[lb] << " ";
			if(vis[lb]) {
				auto it = find(vis.begin(), vis.begin()+lb, false);
				if(it != vis.begin() + lb) {
					lb = it - vis.begin() + 1;
				}
			}
			if(!vis[lb]) {
				cout << price[lb] << "\n";
				vis[lb] = true;
			} else {
				cout << "-1" << "\n";
			}
		} else {
			cout << "-1" << "\n";
		}
	}
}
 
int main() {
	ll n, m;
	cin >> n >> m;

	vector<ll> price(n), bids(m);

	for(int i=0; i<n; i++) {
		ll temp;
		cin >> temp;
		price[i] = temp;
	}
	for(int i=0; i<m; i++) {
		ll temp;
		cin >> temp;
		bids[i] = temp;
	}

	solve(n, m, price, bids);

	return 0;
}