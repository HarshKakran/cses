#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	string dna;
	cin >> dna;

	int res = 1;
	int maxHere = 1;

	for(int i=1; i<dna.length(); i++) {
		if(dna[i-1] != dna[i]) {
			maxHere = 1;
		} else {
			maxHere++;
		}
		res = max(res, maxHere);
	}

	cout << res;

	return 0;
}