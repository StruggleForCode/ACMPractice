#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstring>
using namespace std;

const int MAX = 1000;

map<string, int> m;

bool relation[MAX][MAX];

int main(){
    //cout << "HH" << endl;
    int n;
    cin >> n;
    int eid = 0;
    memset(relation, false, sizeof(relation));
    while(n--){
        string s1, s2;
        cin >> s1 >> s2;
        if(!m.count(s1) && !m.count(s2)){
            m[s1] = eid++;
            m[s2] = eid++;
        }else if(!m.count(s1) && m.count(s2)){
            m[s1] = eid++;
        }else if(m.count(s1) && !m.count(s2)){
            m[s2] = eid++;
        }
        //cout << eid << endl;
        relation[m[s1]][m[s2]] = true;
        
        relation[m[s2]][m[s1]] = true;
    }

    int q;
    cin >> q;
    while(q--){
        string s1, s2;
        cin >> s1 >> s2;
        //太坑了， 这一点没有想到 嘤嘤嘤~~~~ 
        if(!m.count(s1)|| !m.count(s2)){
        	cout << "No" << endl;
        	continue;
		}
        if(relation[m[s1]][m[s2]] && relation[m[s2]][m[s1]]){
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    }
    return 0;
}

