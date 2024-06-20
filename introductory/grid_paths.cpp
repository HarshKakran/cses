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

bool vis[7][7];
int step = 0;
int path = 0;
string s;


void solve(int r, int c) {
	if(r == 6 && c == 0){
		if(step == 48) {
			path++;
			// cout << path << endl;
		}
		return;
	}
	if(vis[r][c] || 
	 ((c >= 1 && c <= 5 && !vis[r][c-1] && !vis[r][c+1]) &&
	 	((r == 0 && vis[r+1][c]) || (r == 6 && vis[r-1][c])))
	 
	 ||

	 ((r >= 1 && r <= 5 && !vis[r-1][c] && vis[r+1][c]) &&
	 	((c == 0 && vis[r][c+1]) || (c == 6 && vis[r][c-1])))
	 
	 ||

	 ((r >= 1 && r <= 5 && c >= 1 && c <= 5 && vis[r][c-1] && 
	 	vis[r][c+1] && !vis[r-1][c] && !vis[r+1][c]) 

	 ||

	 (r >= 1 && r <= 5 && c >= 1 && c <= 5 && !vis[r][c-1] && 
	 	!vis[r][c+1] && vis[r-1][c] && vis[r+1][c]))) 			{return;}
	

	vis[r][c] = true;
	
	// cout << s[step] << "\t";

	switch (s[step]) {
	case 'D':
		if(r < 6 && !vis[r+1][c]) {
			step++;
			solve(r+1, c);
			step--;
		}
		break;
	case 'U':
		if(r > 0 && !vis[r-1][c]) {
			step++;
			solve(r-1, c);
			step--;
		}
		break;
	case 'L':
		if(c > 0 && !vis[r][c-1]) {
			step++;
			solve(r, c-1);
			step--;
		}
		break;
	case 'R':
		if(c < 6 && !vis[r][c+1]) {
			step++;
			solve(r, c+1);
			step--;
		}
		break;
	default:
		// down
		if(r < 6 && !vis[r+1][c]) {
			step++;
			solve(r+1, c);
			step--;
		}

		// up
		if(r > 0 && !vis[r-1][c]) {
			step++;
			solve(r-1, c);
			step--;
		}

		// right
		if(c < 6 && !vis[r][c+1]) {
			step++;
			solve(r, c+1);
			step--;
		}

		// left
		if(c > 0 && !vis[r][c-1]) {
			step++;
			solve(r, c-1);
			step--;
		}
	
	}

	vis[r][c] = false;
}
 
int main() {
	ios_base::sync_with_stdio(false);

	cin >> s;

	solve(0,0);
	cout << path;

	return 0;
}