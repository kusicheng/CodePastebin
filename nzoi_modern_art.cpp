#include <bits/stdc++.h>
using namespace std;
struct rect {
 	int x, y, u, v;
 	char colour;
};
vector<int> row, col;
int r (int val) {
 	return lower_bound(row.begin(), row.end(), val) - row.begin();
}
int c (int val) {
 	return lower_bound(col.begin(), col.end(), val) - col.begin();
}
char canvas[100][100];
int main() {
 	int height, width, n_throws;
 	cin >> height >> width >> n_throws;
 	row = {0, height};
 	col = {0, width};
 	vector<rect> to_process;
 	for (int i = 0; i < n_throws; ++i) {
 		int zx, zy, spread;
 		cin >> zx >> zy >> spread;
 		char colour;
 		cin >> colour;
 		int x = max(0, zx - spread);
 		int y = max(0, zy - spread);
 		int u = min(width, zx + spread + 1);
 		int v = min(height, zy + spread + 1);
 		to_process.push_back({x, y, u, v, colour});
 		col.push_back(x);
 		col.push_back(u);
 		row.push_back(y);
 		row.push_back(v);
 	}
 	sort(row.begin(), row.end());
 	sort(col.begin(), col.end());
 	row.erase(unique(row.begin(),row.end()), row.end());
 	col.erase(unique(col.begin(),col.end()), col.end());
 	for(rect p : to_process)
 		for(int i = r(p.y); i < r(p.v); i++)
 			for(int j = c(p.x); j < c(p.u); j++)
 				canvas[i][j] = p.colour;
 	char colour;
 	cin >> colour;
 	long long res = 0;
 	for(size_t i = 0; i < row.size() - 1; i++)
 		for(size_t j = 0; j < col.size() - 1; j++)
 			if(canvas[i][j] == colour) {
 				long long r = row[i + 1] - row[i];
 				long long c = col[j + 1] - col[j];
 				res += r * c;
 			}
 	cout << res;
}
