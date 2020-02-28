#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
 
#define TR(v,i) for(typeof((v).begin()) i=(v).begin();i!=(v).end();++i)
struct edge {
	int v, l, c; //vertex, length, cost
	edge(int v, int l, int c): v(v), l(l), c(c) {}
	bool operator < (const edge &a) const {
		return l > a.l;
	}
};
const int N = 111, K = 11111, INF = 1e9;
int d[N][K], n, k, m;
vector<vector<edge> > g;
 
void enter() {
	scanf("%d%d%d", &k, &n, &m);
	g.assign(n, vector<edge>());
	for(int i = 0; i < m; ++i) {
		int u, v, l, c;
		scanf("%d%d%d%d", &u, &v, &l, &c);
		g[--u].push_back(edge(--v, l, c));
	}
}
 
void dijkstra() {
	memset(d, 0x3f, sizeof d); d[0][k] = 0;
	priority_queue<edge> q; q.push(edge(0, 0, k));
	while(!q.empty()) {
		int u = q.top().v, dumo = q.top().l, mo = q.top().c; q.pop();
		if(dumo > d[u][mo]) continue;
		if(u == n-1) {
			printf("%d\n", dumo);
			return;
		}
		TR(g[u], it) {
			int v = it->v, w = it->l, c = it->c;
			if(mo >= c && d[v][mo - c] > dumo + w)
				q.push(edge(v, d[v][mo - c] = dumo + w, mo - c));
		}
	}
	printf("-1\n");
}
 
int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		enter();
		dijkstra();
	}
	return 0;
}

