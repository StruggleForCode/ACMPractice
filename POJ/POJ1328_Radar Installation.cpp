#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


typedef pair<int, int> pp;
struct range{
	double l, r;
	range(double _l = 0, double _r = 0):l(_l), r(_r){}
};
bool cmp(const range a, const range b){
	if(a.r == b.r){
		return a.l > b.l;
	}else{
		return a.r < b.r;
	}
}
vector<range> ver;

int main(){
	int n, d;
	int cnt = 0;
	while(cin >> n >> d && n){
		cnt++;
		ver.clear();
		bool ok = true;
		for (int i = 0; i < n; i++){
			double x, y;
			cin >> x >> y;
			if(y > d){
				ok = false;
				//break;
			} 
			if(ok){
				double l = x - sqrt(d * d - y * y);
				double r = x + sqrt(d * d - y * y);
				ver.push_back(range(l, r));
			}
		} 
		if(!ok){
			cout << "Case " << cnt << ": " << -1 << endl;
			continue;
		}
		sort(ver.begin(), ver.end(), cmp);
		int ans = 1;
		double t = ver[0].r;
		for (int i = 1; i < n; i++){
			if(ver[i].l > t){
				t = ver[i].r;
				ans++;
			}
		}
		cout << "Case " << cnt << ": " << ans << endl;
	}
	return 0;
}
