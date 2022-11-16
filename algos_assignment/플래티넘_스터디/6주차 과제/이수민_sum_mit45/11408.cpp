#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define MAX 888
using namespace std;
const int INF = 2e9;
struct Edge{
	int next,cap,flow,cost;
	Edge *rev;
	Edge(int n,int c,int co):next(n),cap(c),cost(co),flow(0),rev(NULL){}
	int Remain(){return cap-flow;}
	void AddFlow(int f){
		flow += f;
		rev->flow -= f;
	}
};
vector<Edge*>G[MAX];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N,M,a,b,c;
	cin >> N >> M;
	for(int w=1;w<=N;w++){
		cin >> a;
		while(a--){
			cin >> b >> c;
			Edge *e1 = new Edge(b+N,1,c),*e2 = new Edge(w,0,-c);
			G[w].push_back(e1);
			G[b+N].push_back(e2);
			e1->rev = e2;
			e2->rev = e1;
		}
	}
	long long min_cost = 0,max_flow = 0;
	int S = 0,T = M+N+1;
	for(int w=1;w<=N;w++){
		Edge *e1 = new Edge(w,1,0),*e2 = new Edge(S,0,0);
		G[S].push_back(e1);
		G[w].push_back(e2);
		e1->rev = e2;
		e2->rev = e1;
	}
	for(int w=N+1;w<=N+M;w++){
		Edge *e1 = new Edge(T,1,0),*e2 = new Edge(w,0,0);
		G[w].push_back(e1);
		G[T].push_back(e2);
		e1->rev = e2;
		e2->rev = e1;
	}
	while(true){
		Edge *path[MAX];
		int prev[MAX],dist[MAX];
		bool inQ[MAX];
		for(int w=0;w<=N+M+1;w++){
			dist[w] = INF;
			prev[w] = -1;
			inQ[w] = false;
		}
		dist[S] = 0;
		inQ[S] = true; 
		queue<int>q;
		q.push(S);
		while(!q.empty()){
			int v = q.front();q.pop();
			inQ[v] = false;
			for(const auto &e:G[v]){
				int next = e->next;
				if(e->Remain()>0 && dist[next] > dist[v] + e->cost){
					dist[next] = dist[v] + e->cost;
					prev[next] = v;
					path[next] = e;
					if(!inQ[next]){
						inQ[next] = true;
						q.push(next);
					}
				}
			}
		}
		if(prev[T] == -1)break;
		int f = INF;
		for(int w=T;w!=S;w=prev[w])
			f = min(f,path[w]->Remain());
		for(int w=T;w!=S;w=prev[w]){
			path[w]->AddFlow(f);
			min_cost += path[w]->cost * f;
		}		
		max_flow += f;
	}
	cout << max_flow << '\n'<< min_cost << '\n';
}
