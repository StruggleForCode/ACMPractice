#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;

vector<int> g[1100];
int colors[1100];
int n, m, x, y;
bool vis[1100];

bool dfs(int u, int c){
    colors[u] = c;
    for (int i = 0; i < g[u].size(); i++){
        if(!vis[g[u][i]] && colors[g[u][i]] == c){
            vis[g[u][i]] = true;
            return false;
        }
        if(!vis[g[u][i]] && colors[g[u][i]] == 0 && !dfs(g[u][i],-c)){
            vis[g[u][i]] = true;
            return false;
        }
    }
    return true;
}

void solve(){
    for (int i = 1; i <= n; i++){
        if(!vis[i] && colors[i] == 1){
            vis[i] = true;
            if(!dfs(i, 1)){
                printf("NO\n");
                return;
            }
        }
        else if(!vis[i] && colors[i] == -1){
            vis[i] = true;
            if(!dfs(i, -1)){
                printf("NO\n");
                return;
            }
        } 
    }
    for (int i = 1; i <= n; i++){
        if(!vis[i] && colors[i] == 0){
            vis[i] = true;
            if(!dfs(i, 1)){
                printf("NO\n");
                return;
            }
        }
    }
    for (int i = 1; i <= n; i++){
        if(!vis[i] && colors[i] == -5){
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
}

int main(){
    while(scanf("%d%d%d%d", &n, &m, &x, &y) !=EOF ){
        for (int i = 1; i <= n; i++){
            g[i].clear();
            vis[i] = false;
            colors[i] = -5;
        }
        for (int i = 1; i <= m; i++){
            int u, v;
            scanf("%d%d", &u, &v);
            colors[u] = 0;
            colors[v] = 0;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for (int i = 1; i <= x; i++){
            int u;
            cin >> u;
            colors[u] = 1;
        }
        for(int i = 1; i <= y; i++){
            int u;
            cin >> u;
            colors[u] = -1;
        }
        solve();
    }
    return 0;
} 

