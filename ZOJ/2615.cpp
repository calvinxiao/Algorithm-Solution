/*
#Problem ID: 2615
#Submit Time: 2012-11-27 10:58:23
#Run Time: 730
#Run Memory: 84168
#ZOJ User: calvinxiao
*/

#include <cstdio>
#include <cstring>

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))

//using namespace std;

#define PARENT_CNT 300205
#define MAX 20000005
int TC, n, m, a, b, c, first[PARENT_CNT], cnt[PARENT_CNT], in[PARENT_CNT], out[PARENT_CNT];
int st[PARENT_CNT], sp;
int p[MAX];
char ri;

int main()
{
	//printf("123\n");
	//freopen("0.in", "r", stdin);
	
	scanf(" %d", &TC);

	for(int tc = 0; tc < TC; ++tc) {
		if(tc) puts("");
		printf("Case %d:\n", tc+1);

		scanf("%d", &n);
		int next = 1;

		//memset(first, 0, sizeof first);
		memset(in, 0, sizeof in);
		memset(out, 0, sizeof out);
		//memset(cnt, 0, sizeof cnt);
		//memset(p, 0, sizeof p);

		for(int i = 0; i < n; ++i) {
			scanf("%d", &c);
			//wereadint(c);
			cnt[i] = c;
			first[i] = next;
			while(c--) p[next++] = i;
		}

		//DFS
		//stack<int> st;
		//st.push(0);
		sp = 0;
		st[sp++] = 0;
		int TIME = 1;
		while(sp != 0) {
			int top = st[sp-1];
			if(top >= n) {
				TIME += 2;
				//st.pop();
				--sp;
				continue;
			}
			if(in[top] == 0)
				in[top] = TIME++;

			if(cnt[top] > 0) {
				//st.push(first[top]);
				st[sp++] = first[top];
				first[top]++;
				cnt[top]--;
			}
			else {
				out[top] = TIME++;
				--sp;
				//st.pop();
			}
		}

		// for(int i = 0; i < n; ++i) {
		// 	cout << i << ' ' << in[i] << ' ' << out[i] << endl;
		// }

		scanf("%d", &m);
		for(int i = 0; i < m; ++i) {
			scanf("%d%d", &a, &b);
			//readint(a);
			//readint(b);
			if(a >= n || a == b) {
				puts("No");
				continue;
			}
			if(b >= n) b = p[b];
			//printf("%d %d %d %d\n", a, b, in[a], in[b]);
			if(in[a] <= in[b] && out[a] >= out[b])
				puts("Yes");
			else
				puts("No");

		}


	}
	
    return 0;
}
