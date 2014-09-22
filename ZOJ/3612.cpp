/*
#Problem ID: 3612
#Submit Time: 2012-12-05 18:03:31
#Run Time: 850
#Run Memory: 320
#ZOJ User: calvinxiao
*/

#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <cstring>

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))

using namespace std;

const int MAX = 100;

int n, num;
char s[10];
multiset<int, greater<int> >::iterator t1;
multiset<int>::iterator t2;

void gao() {
	scanf("%d", &n);
	multiset<int, greater<int> > s1;
	multiset<int> s2;
	for(int i = 0; i < n; ++i) {
		scanf("%s %d", s, &num);
		//printf("Empty!\n");
		//cout << num << endl;
		if(s[0] == 'a') {
			if(s1.empty()) s1.insert(num);
			else {
				if(num <= *s1.begin()) 
					s1.insert(num);
				else
					s2.insert(num);
			}
		}
		else {
			if(num <= *s1.begin() && (t1 = s1.find(num)) != s1.end() ) {
				s1.erase(t1);
			}
			else if(num > *s1.begin() && (t2 = s2.find(num)) != s2.end() ) {
				s2.erase(t2);
			}
			else {
				printf("Wrong!\n");
				continue;
			}
		}

		if(s1.size() > s2.size() && s1.size() - s2.size() > 1) {
			s2.insert(*s1.begin());
			s1.erase(s1.begin());
		}
		else if(s1.size() < s2.size()) {
			s1.insert(*s2.begin());
			s2.erase(s2.begin());
		}

		if(s1.size() == s2.size()) {
			if(!s1.empty()) {
				long long diff = (long long)(*s2.begin()) - (long long)(*s1.begin());
				//cout << diff << ' ' << (diff >> 1) << endl;
				int show = *s1.begin() + (diff >> 1);
				if(diff&1) {
					if(show < 0) {
						printf("-");
						show = -show - 1;
					}
					printf("%d.5\n", show);
				} else {
					printf("%d\n", show);
				}

			}	
			else
				printf("Empty!\n");
		}
		else {
			printf("%d\n", *s1.begin());
		}
	}
}

int main()
{
	//freopen("0.in", "r", stdin);
	int TC;
	scanf("%d", &TC);
	while (TC--) {
		gao();
	}
	return 0;
}
