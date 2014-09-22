/*
#Problem ID: 2445
#Submit Time: 2012-09-21 12:56:26
#Run Time: 640
#Run Memory: 19048
#ZOJ User: calvinxiao
*/

#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

//I want to name it point, but I suddenly think shorter is better, just do it in contest, just in contest...
struct po
{
    int v, idx, num;
};

bool operator <(const po &a, const po &b)
{
    return a.v < b.v;
}

int X[250001], Y[250001];
char S[250002];

int main()
{
    int n;
    char c, pre;
    int x, y, num;
    //string S;
    while(scanf(" %d", &n) != EOF)
    {
        //cin >> S;
        scanf(" %s", S);
        pre = S[0];
        map<int, vector<po> > DX, DY;
        //I found that if I just declare the DX and DY, the memory reduces, strange..hehe, maybe that's why C++ is bad
        //DX.clear();
        //DY.clear();
        x = 0, y = 0, num = 0;
        po px, py;
        px.v = 0, px.idx = 0, px.num = 0;
        py.v = 0, py.idx = 0, py.num = 0;
        DX[0].push_back(px), DY[0].push_back(py);
        for(int i = 0; i < n; ++i)
        {
            if(S[i] == 'N')
                y++;
            else if(S[i] == 'E')
                x++;
            else if(S[i] == 'S')
                y--;
            else
                x--;
            if(pre != S[i])
            {
                pre = S[i];
                num++;
            }
            X[i+1] = x;
            Y[i+1] = y;
            px.v = y, px.idx = i + 1, px.num = num;
            py.v = x, py.idx = i + 1, py.num = num;

            DX[x].push_back(px), DY[y].push_back(py);
        }
        int ansL = 10000000;
        int ansS = 0;
        int ansE = 0;

        int tempL, tempS, tempE, numdiff, length;
        char ansD = 'N';//just kidding, it won't be 'N' because it will be changed in the first ever comparison, due to the large ansL;
        //loop DX
        for(map<int, vector<po> >::iterator itr = DX.begin(); itr != DX.end(); ++itr)
        {
            vector<po> &p = itr->second;
            sort(p.begin(), p.end());
            length = p.size();
            for(int i = 1; i < length; ++i)
            {
                // if your num is i, then i is in your line, you cannot reach i + 1 by any vetical line and horizontal line, so abs(numdiff) > 1
                numdiff = p[i].num - p[i-1].num;
                if(numdiff == -1 || numdiff == 0 || numdiff == 1) continue;

                tempL = p[i].v - p[i-1].v;
                tempS = min(p[i].idx, p[i-1].idx);
                tempE = max(p[i].idx, p[i-1].idx);
                if(tempL < ansL)
                    ansL = tempL, ansS = tempS, ansE = tempE;
                else if(tempL == ansL && tempS < ansS)
                    ansS = tempS, ansE = tempE;
                else if(tempL == ansL && tempS == ansS && tempE > ansE)
                    ansE = tempE;
            }
        }
        //loop DY
        for(map<int, vector<po> >::iterator itr = DY.begin(); itr != DY.end(); ++itr)
        {
            vector<po> &p = itr->second;
            sort(p.begin(), p.end());
            length = p.size();
            for(int i = 1; i < length; ++i)
            {
                numdiff = p[i].num - p[i-1].num;
                if(numdiff == -1 || numdiff == 0 || numdiff == 1) continue;

                tempL = p[i].v - p[i-1].v;
                tempS = min(p[i].idx, p[i-1].idx);
                tempE = max(p[i].idx, p[i-1].idx);
                if(tempL < ansL)
                    ansL = tempL, ansS = tempS, ansE = tempE;
                else if(tempL == ansL && tempS < ansS)
                    ansS = tempS, ansE = tempE;
                else if(tempL == ansL && tempS == ansS && tempE > ansE)
                    ansE = tempE;
            }
        }

        // now we know the start index of the answer and the end index of the answer, it's easy to know the direction.
        if(X[ansS] == X[ansE])
            if (Y[ansS] < Y[ansE])
                ansD = 'N';
            else
                ansD = 'S';
        else if (X[ansS] < X[ansE])
            ansD = 'E';
        else
            ansD = 'W';

        printf("%d %d %d %c\n", ansL, ansS, ansE, ansD);

        //cout << ansL << ' ' << ansS << ' ' << ansE << ' ' << ansD << endl;

    }
    return 0;
}
