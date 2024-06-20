#include<iostream>
#include<vector>
#include<algorithm>
 
using namespace std;
 
bool check(vector<int>& res) {
	for(int i=1; i<res.size(); i++) {
		if(abs(res[i] - res[i-1]) == 1) return false;
	}
 
	return true;
}
 
vector<int> solve(int n) {
	vector<int> res;
 
	for(int i=2; i<=n; i+=2) {
		res.push_back(i);
	}
	for(int i=1; i<=n; i+=2) {
		res.push_back(i);
	}
 
	return res;
}
 
int main(){
	int n;
	cin >> n;
 
	vector<int> res = solve(n);
 
	if(check(res)) {
		for(int i=0; i<res.size(); i++) {
			cout << res[i] << " ";
		}
	} else {
		cout << "NO SOLUTION";
	}
 
	return 0;
}