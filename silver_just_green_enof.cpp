#include <iostream>
#include <vector>
#define ll long long
using namespace std;
int n;
bool ok[1000][1000];
 
ll solve() {
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		vector<bool> all_ones(N,true);
		for (int j = i; j < n; ++j) { 
			int run = 0;
			for (int k = 0; k < n; ++k) {
				all_ones[k] = all_ones[k]&ok[j][k]; 
				if (all_ones[k]) ans += ++run;
				else run = 0;
			}
		}
	}
	return ans;
}
 
int main() {
	cin >> n;
	vector<vector<int>> pasture(n,vector<int>(n)); 
	for (vector<int>& a: pasture) 
		for (int& b: a) cin >> b;
 
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < n; ++j)
			ok[i][j] = pasture[i][j] >= 100;
	ll ans = solve();
 
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < n; ++j)
			ok[i][j] = pasture[i][j] > 100;
	ans -= solve();
 
	cout << ans << "\n";
