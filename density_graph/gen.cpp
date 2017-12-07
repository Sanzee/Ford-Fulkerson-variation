// Author : Muhammad Rifayat Samee
// Problem : test case generator
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
#include<ctime>
#include<stack>
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

int cases;
int cap[101][101];

int main() {
	freopen("test3.in", "w", stdout);

	cases = 50;
	printf("%d\n", cases);
	while( cases-- ) {
		srand(time(NULL));
		fprintf( stderr, "%d\n", cases );
		memset( cap, 0, sizeof(cap) );
		int n = 100 - rand() % 90;
		if( cases % 5 == 4 ) n = 100;

		if( cases % 3 ) n = 100 - rand() % 10;

		if( cases == 17 ) n = 2;
		if( cases == 18 ) n = rand() % 10 + 2;
		if( cases == 19 ) n = 100;

		printf("%d\n", n);

		puts("");

		int save[10005][3];
		int m =  (n * n)/2;

		if( cases & 1 ) m = rand() % m;

		memset( cap, 0, sizeof(cap) );
		int k = 0;
		while( m-- ) {
			int i = rand() % n + 1;
			int j = rand() % n + 1;
			if( i == j || cap[i][j] ) {
				if( rand() % 2 ) m++;
				continue;
			}
			cap[i][j] = 1;
			save[k][0] = i;
			save[k][1] = j;
			int x = rand() % 1000 + 1;
			if( rand() % 5 || ( cases & 1 ) ) x = rand() % 100 + 20;
			save[k++][2] = x;
		}
		printf("%d\n", k);
		while( k-- ) {
			printf("%d %d %d\n", save[k][0], save[k][1], save[k][2]);
		}
		puts("");
	}
	return 0;
}
