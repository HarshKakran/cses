#include<iostream>

using namespace std;

int main() {
	long long n, sum = 0;

	cin >> n;

	for(int i=0; i<n-1; i++) {
		int num;
		cin >> num;
		sum += num;
	}

	long long res = (n*(n+1)/2) - sum;

	cout << res;

	return 0;
}