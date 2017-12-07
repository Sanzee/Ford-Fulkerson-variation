// Author : Muhammad Rifayat Samee
// Problem : ford fulkerson arbitrary path using adj_list
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

int C[205][205];
int graph[205][205];
int node[205];
int color[205];
int P[205];
int deg[205];

int n,N,m,B,D,source,sink;
void init(){
    int i;
    memset(graph,0,sizeof(graph));
    memset(deg,0,sizeof(deg));
}

int dfs(int u,int prev){
    color[u] = 1;
    P[u] = prev;
    int i;
    for(i=0;i<deg[u];i++){
        int v = graph[u][i];
        if(color[v] == 0 && C[u][v]>0){
            dfs(v,u);
        }
    }

}

int run_dfs(){
    memset(color,0,sizeof(color));
    dfs(source,source);
    if(color[sink] == 1)return 1;
    return 0;
}
int iteration,t_iteration;
int max_flow(){
	int i,j,k,res,u,v;
	res = 0;
	while(run_dfs()){
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

	freopen("Testfiles/test1.in","r",stdin);
	//freopen("1155.in","r",stdin);
	freopen("fukerson_ar_test1.out","w",stdout);

	int cases,i,j,k,s,u,v,c,ct=1;
    int start_s=clock();
	// the code you wish to time goes here

	scanf("%d",&cases);
    t_iteration = 0;
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
