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

void solve(ll n, ll m, ll k, vector<ll>& apartment_size, vector<ll>& desired_size) {
	sort(apartment_size.begin(), apartment_size.end());
	sort(desired_size.begin(), desired_size.end());
	vector<bool> vis(m, false);
	ll ans = 0;

	for(ll i=0; i<n; i++) {
		auto lb = lower_bound(apartment_size.begin(), apartment_size.end(), desired_size[i] - k);
		while(*lb >= desired_size[i]-k && *lb <= desired_size[i]+k) {
			if(!vis[lb - apartment_size.begin()]) {
				ans++;
				vis[lb - apartment_size.begin()] = true;
			} else {
				lb++;
			}
		}
	}

	cout << ans;
}
 
int main() {
	ll n, m, k;
	cin >> n >> m >> k;

	vector<ll> desired_size, apartment_size;

	for(ll i=0; i<n; i++) {
		ll a;
		cin >> a;
		desired_size.emplace_back(a);
	}
	for(ll i=0; i<m; i++) {
		ll a;
		cin >> a;
		apartment_size.emplace_back(a);
	}

	solve(n, m, k, apartment_size, desired_size);

	return 0;
}