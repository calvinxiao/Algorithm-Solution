/*
#Problem ID: 3228
#Submit Time: 2012-10-24 15:42:38
#Run Time: 1590
#Run Memory: 80752
#ZOJ User: calvinxiao
*/

    /* 
     * AC自动机，每个节点 添加一个d表示节点代表的字符串的查询类型1表示只有查询0，2表示只有查询1,3表示有查询 
     * 0和查询1，len表示该节点代表的字符串的长度。 
     */  
    #include <cstdio>  
    #include <cstring>  
    #include <map>  
    using namespace std;  
    const int N=100005*6; //节点个数的最大值  
    const int S=26; //不同的字符 个数  
    const int L=100005;  
    struct node{  
        node *sons[S], *fail;  
        int num; //该节点出现的次数  
        int d;  
        int len;  
    }nodes[N], *root;  
    int cnt;  //cnt是树中节点的 个数  
    node *que[N];  
    char text[L];  
    int ids[L], type[L], nums[2][N], last[N];  
    int n;  
    void clear(){  
        cnt=0;  
        root=NULL;  
    }  
    node* newNode(){  
        node* ans=&nodes[cnt++];  
        memset(ans->sons, 0, S*sizeof(node*));  
        ans->fail=NULL;  
        ans->num=0;  
        ans->d=0;  
        return ans;  
    }  
    int hash(char ch){ //字符的哈希函数，根据不同的需要而定  
        return ch-'a';  
    }  
    int id(node*& t){ //计算该节点的id  
        return t-nodes;  
    }  
    //j表示当前关键字的标号  
    int insert(node*& root, char* str, int d){  
        node* t=root;  
        int i, k;  
        for(i=0; str[i]; i++){  
            if(t->sons[k=hash(str[i])]==NULL){  
                t->sons[k] = newNode();  
            }  
            t->len=i;  
            t=t->sons[k];  
        }  
        t->len=i;  
        t->num++;  
        t->d|=d;  
        return id(t);  
    }  
    void getFail(node*& root){  
        int l, r, i;  
        node *t;  
        l=r=0;  
        root->fail=root; //这样可以保证每个节点的fail指针都是非空的  
        for(que[r++]=root; l!=r; ){  
            t=que[l++];  
            for(i=0; i<S; i++){  
                if(t->sons[i]){  
                    que[r++]=t->sons[i];  
                    if(t==root){  
                        t->sons[i]->fail=t;  
                    }else{  
                        t->sons[i]->fail=t->fail->sons[i];  
                    }  
                }else{ //增设虚拟节点  
                    if(t==root) t->sons[i]=t;  
                    else t->sons[i]=t->fail->sons[i];  
                }  
            }  
        }  
    }  
    bool input(){  
        if(scanf("%s", text)==EOF) return false;  
        clear();  
        root=newNode();  
        scanf("%d", &n);  
        int i;  
        char str[7];  
        for(i=0; i<n; i++){  
            scanf("%d%s", type+i, str);  
            ids[i]=insert(root, str, 1<<type[i]);  
        }  
        return true;  
    }  
    int ca=0;  
    void solve(){  
        int i;  
        node *t, *p;  
        for(i=0; i<cnt; i++){  
            last[i]=-1;  
            nums[0][i]=nums[1][i]=0;  
        }  
        getFail(root);  
        for(t=root, i=0; text[i]; i++){  
            t=t->sons[hash(text[i])];  
            for(p=t; p!=root; p=p->fail){  
                if(p->num>0){  
                    if(p->d&1){  
                        nums[0][id(p)]++;  
                    }  
                    if(p->d&2){  
                        if(i-p->len+1>last[id(p)]){  
                            nums[1][id(p)]++;  
                            last[id(p)]=i;  
                        }  
                    }  
                }  
            }  
        }  
        printf("Case %d\n", ++ca);  
        int k;  
        for(i=0; i<n; i++){  
            if(type[i]==0){  
                k=0;  
            }else{  
                k=1;  
            }  
            k=nums[k][ids[i]];  
            printf("%d\n", k);  
        }  
        printf("\n");  
    }  
    int main(){  
        //freopen("in.txt", "r", stdin);  
      
        while(input()) solve();  
        return 0;  
    }  