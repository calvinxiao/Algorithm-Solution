/*
#Problem ID: 3686
#Submit Time: 2013-08-19 23:44:17
#Run Time: 680
#Run Memory: 12012
#ZOJ User: calvinxiao
*/

/**
Calvin's Code
*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std ;

inline int read_int(){
    int a=0;
    int b=1,c=getchar();
    if(c=='-')b=-1;
    else a=c-48;
    while((c=getchar())!=' '&&c!='\n')
        a=a*10+c-48;
    a*=b;
    return a;
}

const int maxint = -1u>>2 ;
const double eps = 1e-6 ;

const int maxn = 100001;
int n, m, node, start[maxn], end[maxn], TIME, change[maxn<<3], ones[maxn<<3];
vector<int> e[maxn];
char c;

void push_down(int l, int r, int rt) {
    if (change[rt]) {
        change[rt << 1] ^= change[rt];
        change[rt << 1 | 1] ^= change[rt];
        change[rt] = 0;

        int mid = (l + r) >> 1;
        ones[rt << 1] = mid - l + 1 - ones[rt << 1];
        ones[rt << 1 | 1] = r - mid - ones[rt << 1 | 1];
    }
}

void push_up(int rt) {
    ones[rt] = ones[rt << 1] + ones[rt << 1 | 1];
}

void muppet(int ll, int rr, int l, int r, int rt) {
    //printf("%d %d %d %d %d\n", ll, rr, l, r, rt);
    if (ll <= l && r <= rr) {
        change[rt] ^= 1;
        ones[rt] = r - l + 1 - ones[rt];
        return ;
    }
    push_down(l, r, rt);
    int mid = (l + r) >> 1;
    if (ll <= mid) muppet(ll, rr, l, mid, rt << 1);
    if (mid < rr)  muppet(ll, rr, mid + 1, r, rt << 1 | 1);
    push_up(rt);
}

int get(int ll, int rr, int l, int r, int rt) {
    if (ll <= l && r <= rr)
        return ones[rt];
    push_down(l, r, rt);
    int mid = (l + r) / 2;
    int ret = 0;
    if (ll <= mid) ret += get(ll, rr, l, mid, rt << 1);
    if (mid < rr)  ret += get(ll, rr, mid + 1, r, rt << 1 | 1);
    return ret;
}

void dfs() {
    stack<int> st;
    st.push(1);
    TIME = 0;
    while (!st.empty()) {
        int top = st.top();
        //printf("stack %d %d\n", top, e[top].size());
        if (start[top] == -1)
            start[top] = ++TIME;
        for (int i = 0; i < e[top].size(); ++i) {
            int v = e[top][i];
            //cout <<v << ' ' << end[v] << endl;
            if (end[v] == -1) {
                st.push(v);
            }
        }
        //cout << st.size() << endl;
        if (st.top() == top) {
            st.pop();
            end[top] = ++TIME;
        }
    }
}

int main() {
    //freopen("0.in", "r", stdin);
    while (~scanf(" %d %d ", &n, &m)) {
        for (int i = 1; i <= n; ++i) {
            e[i].clear();
        }
        for (int i = 2; i <= n; ++i) {
            //scanf(" %d", &node);
            node = read_int();
            e[node].push_back(i);
        }

        memset(start, -1, sizeof start);
        memset(end, -1, sizeof end);
        memset(change, 0, sizeof change);
        memset(ones, 0, sizeof ones);

        dfs();

        for (int i = 0; i < m; ++i) {
            scanf(" %c ", &c);
            node = read_int();
            //printf("%c %d\n", c, node);
            if (c == 'o') {
                muppet(start[node], end[node], 1, n + n, 1);
            } else {
                printf("%d\n", get(start[node], end[node], 1, n + n, 1) >> 1);
            }
        }

        puts("");
    }
    return 0;
}