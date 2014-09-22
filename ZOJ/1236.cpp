/*
#Problem ID: 1236
#Submit Time: 2012-09-04 22:11:25
#Run Time: 2240
#Run Memory: 236
#ZOJ User: calvinxiao
*/

#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<memory.h>

using namespace std;

int tc, TC, N, cnt[1001], tcnt[11], t[1001][11], v[1001], C, D, ansD, i, j, k;

int main()
{
    cin >> TC;
    for(tc = 0; tc < TC; ++tc) {
        C = 0; D = 0, ansD = 0;
        cin >> N;
        memset(v, 0, sizeof v);
        memset(tcnt, 0, sizeof tcnt);
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq[11][11];
        //set<pair<int, int> > pq[11][11];
        for(i = 0; i < N; ++i) {
            cin >> cnt[i];
            tcnt[cnt[i]] += 1;
            for(j = 0; j < cnt[i]; ++j) {
                cin >> t[i][j];
                pq[cnt[i]][j].push(make_pair(t[i][j], i));
            }
        }

        if(N == 1) {
            cout << 0 << ' ' << 1 << endl;
            continue;
        }

        for(D = 0; ; ++D) {
            int term, topm = 10000, topi = 0, topterm = 0, topcnt = 0;
            for(term = 1; term <= 10; ++term)
                if(tcnt[term]) {
                    while(pq[term][D%term].size()) {
                        if(v[pq[term][D%term].top().second])
                            pq[term][D%term].pop();
                        else
                            break;
                    }

                    if(pq[term][D%term].empty()) continue;

                    if(pq[term][D%term].top().first < topm) {
                        topcnt = 1;
                        topm = pq[term][D%term].top().first;
                        topi = pq[term][D%term].top().second;
                        topterm = term;
                    }
                    else if(pq[term][D%term].top().first == topm) {
                        topcnt = 2;
                    }
                }

            if(!topcnt || D - ansD + 1 >= 2520) break;

            if(topcnt == 1) {
                //check the same term to see if there same milk;
                pq[topterm][D%topterm].pop();
                while(pq[topterm][D%topterm].size()) {
                    if(v[pq[topterm][D%topterm].top().second])
                        pq[topterm][D%topterm].pop();
                    else
                        break;
                }

                if(pq[topterm][D%topterm].size() && pq[topterm][D%topterm].top().first == topm) {
                    pq[topterm][D%topterm].push(make_pair(topm, topi));
                    continue;
                }
                else {
                    C += 1;
                    ansD = D + 1;
                    tcnt[topterm] -= 1;
                    v[topi] = 1;
                    //pq[topi][D%topi].pop();
                }
            }

            if(C + 1 == N) {
                C += 1;
                ansD += 1;
                break;
            }
        }

        cout << N - C << ' ' << ansD << endl;
    }
    return 0;
}
