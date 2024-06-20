#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	long long n;
	long long prev;
	long long res = 0;

	cin >> n;
	cin >> prev;

	for(int i=1; i<n; i++) {
		long long curr;
		cin >> curr;

		if(curr < prev) {
			res += prev - curr;
			curr = prev;
		}

		prev = curr;
	}

	cout << res;

	return 0;
}