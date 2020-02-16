#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1000;
int head[maxn], dis[maxn], cnt, n, m;
bool vis[maxn];
struct edge
{
	int v, w, next;
}Edge[maxn];
struct node
{
	int point, distance;
	node() {}
	node(int _point, int _distance) { point = _point; distance = _distance; }
	bool operator < (const node &other)const
	{
		return distance > other.distance;
	}
};
void add_Edge(int u, int v, int w)
{
	Edge[cnt].v = v;
	Edge[cnt].w = w;
	Edge[cnt].next = head[u];
	head[u] = cnt++;
}
void Dijkstra(int s)
{
	for (int i = 0; i <= n; i++)
		dis[i] = INF;
	memset(vis, false, sizeof(vis));
	dis[s] = 0;
	priority_queue<node> q;
	q.push(node(s, dis[s]));
	while (!q.empty())
	{
		node now = q.top();
		q.pop();
		if (vis[now.point])
			continue;
		vis[now.point] = true;
		for (int i = head[now.point]; i != -1; i = Edge[i].next)
		{
			int to = Edge[i].v;
			if (dis[to] > dis[now.point] + Edge[i].w)
			{
				dis[to] = dis[now.point] + Edge[i].w;
				q.push(node(to, dis[to]));
			}
		}
	}
}
int main()
{
	int u, v, w;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		if (n == 0 && m == 0)
			break;
		cnt = 0;
		memset(head, -1, sizeof(head));
		while (m--)
		{
			scanf("%d%d%d", &u, &v, &w);
			add_Edge(u, v, w);
			add_Edge(v, u, w);
		}
		Dijkstra(1);
		cout << dis[n] << endl;
	}
	return 0;
}
