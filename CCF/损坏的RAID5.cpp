#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;

struct node{
	int id;
	string s;
};


bool cmp(node a, node b){
	return a.id < b.id;
}

node save[1000 + 5];

int dsk[1000 + 5][1000 + 5];

int main(){
	int n, w, l;
	cin >> n >> w >> l;
	for (int i = 0; i < l; i++){
		cin >> save[i].id >> save[i].s;
	//	scanf("%d %s", &save[i].id, &save[i].s);
	//	cout << save[i].id << endl; 
	}
	cout << "fuck" << endl;
	//sort(save, save + l, cmp);
	cout << "sdfhk" << endl;
	int len = save[0].s.size();  // ����һ��Ӳ�����ַ�����ʾ�ĳ��� 
	int sw =  len / (8 * w);  // ��ʾһ��Ӳ���ж������� 
	cout << sw << endl;
	memset(dsk, -1, sizeof(dsk));
	
	if(n == l){
//		int ans = l - 1;   // ��ʾP���Ǹ�Ӳ�̣� ��ʼֵ��l�ϡ� 
//		int ant = 0;   //��ʾ��Ŷ����� 
//		int temp = 0;  // 
//		while(sw){
//			int j = (ans + 1) % l; //��ʾ�������Ŀ�ʼ������  j
//			for (int time = 0; time < l - 1; time++){ // ��ʾ���ٴ� 
//				if(j != ans){
//					for (int i = temp; i < temp + w; i++){
//						dsk[i][j] = ant;
//						ant++;
//					}
//					j++; 
//					j %= l; 
//				}
//			}
//			sw--;
//			ans--;
//			if(ans < 0) ans = l - 1;
//			temp += w;
//		}		
		int m;
		cin >> m;
		while(m--){
			int u;
			scanf("%d", &u);
//			int x = -1, y = -1;
//			for (int i = 0; i < len / 8; i++){
//				for (int j = 0; j < l; j++){
//					if(u == dsk[i][j]){
//						x = i; y = j;
//						break;
//					}
//				}
//			}
//			if(x == -1 && y == -1){
//				cout << "-" << endl;
//				continue;
//			} 
//			for (int i = (x) * 8; i < (x + 1) * 8; i++){
//				cout << save[y].s[i];
//			}
			cout << endl;
		}
		
	} 
	else{
	
	}
	
	return 0;
} 




/*
20 5 20 
0 000102030405060710111213141516172021222324252627
1 A0A1A2A3A4A5A6A7B0B1B2B3B4B5B6B7C0C1C2C3C4C5C6C7


lxw5952212

*/

/*
2 1 2
0 000102030405060710111213141516172021222324252627
1 000102030405060710111213141516172021222324252627
*/


