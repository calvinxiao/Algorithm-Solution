/*
#Problem ID: 1013
#Submit Time: 2012-07-01 13:28:33
#Run Time: 380
#Run Memory: 188
#ZOJ User: calvinxiao
*/

#include <iostream>
#include <string>
#include <memory.h>
using namespace std;

int main( )
{
    const int MAXN=501;
    int pre[ MAXN ][ MAXN ],now[ MAXN ][ MAXN ];
    int w1,s1,d1,w2,s2,d2,w3,s3,d3,c1,c2,c3,d4,n;
    int ma,mb;
    int cases=0;
    while(cin>>n) {
        cases++;
        if( n==0 ) break;
        cin>>w1>>s1>>d1>>w2>>s2>>d2>>w3>>s3>>d3>>c1>>c2>>c3>>d4;
        memset( pre,255,sizeof( pre ) );
        d4-=c1*d1+c2*d2+c3*d3;
        pre[ 0 ][ 0 ]=0;
        memcpy(now,pre,sizeof(pre));
        ma=mb=0;
        for( int i=0; i<n; i++ ) {
            int cw,cs;
            cin>>cw>>cs;
            int maa=ma,mbb=mb;
            for( int i1=0; i1<=maa; i1++ )
                for( int j1=0; j1<=mbb; j1++ ) {
                    if( pre[ i1 ][ j1 ]<0 ) continue;
                    for( int i11=i1,tw1=0,ts1=0; tw1<=cw&&ts1<=cs; i11++,tw1+=w1,ts1+=s1 )
                        for( int j11=j1,tw2=tw1,ts2=ts1; tw2<=cw&&ts2<=cs; j11++,tw2+=w2,ts2+=s2 ) {
                            if( ma<i11 ) ma=i11;
                            if( mb<j11 ) mb=j11;
                            int da=( cw-tw2 )/w3;
                            int db=( cs-ts2 )/s3;
                            if( da>db ) da=db;
                            if( now[ i11 ][ j11 ]<pre[ i1 ][ j1 ]+da )
                                now[ i11 ][ j11 ]=pre[ i1 ][ j1 ]+da;
                        }

                }
            for( int i11=0; i11<=ma; i11++ )
                for( int j11=0; j11<=mb; j11++ )
                    pre[ i11 ][ j11 ]=now[ i11 ][ j11 ];
        }
        int max=0;
        for( int i=0; i<=ma; i++ )
            for( int j=0; j<=mb; j++ ) {
                if( now[ i ][ j ]<0 ) continue;
                int t=i*d1+j*d2+now[ i ][ j ]*d3;
                int a=i/c1;
                int b=j/c2;
                int c=now[ i ][ j ]/c3;
                if( a>b ) a=b;
                if( a>c ) a=c;
                if( d4>0 ) t+=a*d4;
                if( t>max ) max=t;
            }
        if( cases>1 )
            cout<<endl;
        cout<<"Case "<<cases<<": "<<max<<endl;
    }
    return 0;
}
