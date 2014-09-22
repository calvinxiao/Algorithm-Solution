/*
#Problem ID: 2527
#Submit Time: 2012-07-02 05:27:02
#Run Time: 40
#Run Memory: 4104
#ZOJ User: calvinxiao
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int a[1001];
int dp[1001][1001];
int main()
{
    int N;
    while(cin >> N){
        vector<int> t(N);
        int ans0 = 1;
        int idx = 0;
        int cnt = 1;
        for( int i = 0; i < N; ++i) cin >> t[i];
        sort(t.begin(), t.end());
        a[0] = t[0];
        //cout<<t[0]<<" ";
        for( int i = 1; i < N; ++i){
            if(t[i] == t[i-1]){
                ++cnt;
                ans0 = max(ans0, cnt);
            }
            else{
                cnt = 1;
                a[++idx] = t[i];
                //cout<<t[i]<<" ";
            }
        }

        int n = idx + 1;
        //cout<<n<<endl;
        sort(a, a + n);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j)
                dp[i][j] = -1;
        }

        int ans = 2;

        for(int i = 0; i < n; ++i){
            for (int j = i + 1; j < n; ++j){
                if(dp[i][j] != -1) continue;

                dp[i][j] = 2;
                int ii = i;
                int jj = j;
                int d = a[j] - a[i];
                while(true){
                    int ne = a[jj] + d;
                    int find = -1;
                    int L = jj;
                    int H = n-1;
                    while(L <= H){
                        int mid = L + (H - L )/2;
                        if(a[mid] == ne){
                            find = mid;
                            break;
                        }
                        if(ne > a[mid])
                            L = mid + 1;
                        else
                            H = mid - 1;
                        //cout<<"sdsdf"<<endl;
                    }
                    //cout<<i<<" "<<j<<" "<<find<<endl;
                    if( find == -1) break;
                    else{
                        int pre = dp[ii][jj];
                        ii = jj;
                        jj = find;
                        dp[ii][jj] = 1 + pre;
                        ans = max(ans, dp[ii][jj]);
                        //cout<<ii<<" "<<jj<<" "<<endl;
                    }

                }
            }
        }

        cout << max(ans0, ans) <<endl;



    }
}
