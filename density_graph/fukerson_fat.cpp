// Author : Muhammad Rifayat Samee
// Problem : ford fulkerson fattest path
// Algorithm:

#pragma warning (disable : 4786)
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<cstring>
#include<algorithm>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<ctime>
#define MAX(a,b) (a>b)?a:b
#define MIN(a,b) (a<b)?a:b
#define INF 987654321
#define pi (2*acos(0.0))
#define eps 1e-7

#ifdef ONLINE_JUDGE
#define i64 long long
#else
#define i64 __int64
#endif


using namespace std;
struct Node{
    int u;
    int cost;
    operator<(const Node & a)const{
        return cost<a.cost;
    };
};

int C[205][205];
int graph[205][205];
int node[205];
int color[205];
int P[205];
int deg[205];
int Dist[205];
int n,N,m,B,D,source,sink;
void init(){
    int i;
    memset(graph,0,sizeof(graph));
    memset(deg,0,sizeof(deg));
    for(i=0;i<=n;i++){
        Dist[i] = INF;
    }
}
int SSSP(){
    priority_queue<Node>Q;
    int i,v;
    Node t,tmp;
    for(i=0;i<=n;i++){
        Dist[i] = 0;
    }
    t.u = source;
    t.cost = INF;
    Dist[source] = INF;
    Q.push(t);
    //printf("start!!\n");
    while(!Q.empty()){
        t = Q.top();
        Q.pop();
        int i,v;
        //printf("%d %d\n",t.u,t.cost);
        if(t.u == sink)return 1;
        for(i=0;i<deg[t.u];i++){
            v = graph[t.u][i];
            int m = min(t.cost,C[t.u][v]);
            if(Dist[v]<m && C[t.u][v]>0){
                tmp.u = v;
                tmp.cost = m;
                Dist[v] = m;
                P[v] = t.u;
                Q.push(tmp);
            }
        }

    }
    //printf("End!! %d\n",Dist[sink]);
    //printf("%d\n",sink);
    if(Dist[sink])return 1;
    return 0;
}

int iteration,t_iteration;

int max_flow(){
	int i,j,k,res,u,v;
	res = 0;
	while(SSSP()){
        iteration++;
        v = sink;
		u = P[sink];
		k = INF;
		while(v!=source){
			if(k>C[u][v])
				k = C[u][v];
			v = u;
			u = P[v];
		}
		v = sink;
		u = P[sink];

		while(v!=source){
			C[u][v] = C[u][v] - k;
			C[v][u] = C[v][u] + k;
			v = u;
			u = P[v];
		}
		res = res + k;
	}
	return res;
}

int main(){

	freopen("Testfiles/d_test1.in","r",stdin);
    //freopen("smp.in","r",stdin);
	//freopen("fukerson_fat_d_test1.out","w",stdout);

	int cases,i,j,k,s,u,v,c,ct=1;
    int start_s=clock();
    t_iteration = 0;
	scanf("%d",&cases);


	while(cases--){

		scanf("%d",&n);
		memset(C,0,sizeof(C));
		scanf("%d",&m);
        init();
		for(i=0;i<m;i++){
			scanf("%d %d %d",&u,&v,&c);
			C[u][v] = c;
            graph[u][deg[u]++] = v;
            graph[v][deg[v]++] = u;
		}

		source = 1;
		sink = n;
        iteration = 0;
		int res = max_flow();
		t_iteration = t_iteration + iteration;
        printf("Case %d: max_flow: %d iteration: %d\n",ct++,res,iteration);
        fprintf(stderr,"case %d done!!\n",ct-1);
	}
	int stop_s=clock();
    printf("Total_time: %.5lf\n",(stop_s-start_s)/double(CLOCKS_PER_SEC)*1000);
    printf("Total Iteration for this testdata: %d\n",t_iteration);
    fprintf(stderr,"Iteration: %d\n",t_iteration);
	return 0;
}
