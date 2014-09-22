/*
#Problem ID: 2107
#Submit Time: 2014-05-25 16:31:35
#Run Time: 490
#Run Memory: 8012
#ZOJ User: calvinxiao
*/

#include <cstdio>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;

const double eps = 1e-15;

double min(double a, double b)
{
    if (a < b - eps)
        return a;
    return b;
}

double dist(pair<double, double> p1, pair<double, double> p2)
{
    double t = (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
    return sqrt(t);
}

int n;
pair<double, double> p[100005];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif // ONLINE_JUDGE
	while (1) {
        scanf("%d", &n);
        if (n == 0)
            break;
        for (int i = 0; i < n; i++){
            double x, y; scanf("%lf%lf", &x, &y);
            p[i].first = x, p[i].second = y;
        }
        double minD = 1e18;
        random_shuffle(p, p + n);
        for (int i = 0; i < n - 1; i++)
            minD = (minD, dist(p[i], p[i+1]));
        random_shuffle(p, p + n);
        for (int i = 0; i < n - 1; i++)
            minD = (minD, dist(p[i], p[i+1]));
        sort(p, p + n);
        for (int i = 0; i < n - 1; i++)
            minD = (minD, dist(p[i], p[i+1]));
        set<pair<double, double> > s;
        int leftMost = 0;
        for (int i = 0; i < n; i++) {
            while (p[i].first - p[leftMost].first > minD + eps) {
                s.erase(make_pair(p[leftMost].second, p[leftMost].first));
                leftMost++;
            }
            pair<double, double> head = make_pair(p[i].second - minD, p[i].first);
            pair<double, double> tail = make_pair(p[i].second + minD, p[i].first);
            set<pair<double, double> >::iterator it, it1, it2;
            it1 = s.lower_bound(head);
            it2 = s.upper_bound(tail);
            for (it = it1; it != it2; it++) {
                pair<double, double> pj = make_pair(it->second, it->first);
                double d = dist(p[i], pj);
                if (d + eps < minD)
                    minD = d;
            }
            s.insert(make_pair(p[i].second, p[i].first));
        }
        printf("%.2f\n", minD / 2);
	}
	return 0;
}
