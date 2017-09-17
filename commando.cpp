# include <iostream>
# include <fstream>
# include <vector>
# define INF 999999999
# define NR 1000005
using namespace std;
//ifstream cin("commando.in");
//ofstream cout("commando.out");
struct elem {
    long long m, b;
}st[NR];
int i,j,n,m,ST,SG,T,I;
long long pi[NR], X[NR], a, b, c, segm[NR], dp[NR], XX;
double unu=1;

long long f(long long X) {
    return a*X*X + b*X + c;
}
double intersect (long long m1, long long b1, long long m2, long long b2) {
    double X=unu * (b2 - b1) / (m1 - m2);
    return X;
}
void add_stiva (long long m, long long b) {
    double L1, L2;
    while (ST>=2) {
        L1=intersect (st[ST-1].m, st[ST-1].b, st[ST].m, st[ST].b);
        L2=intersect (m, b, st[ST].m, st[ST].b);

        if (L2 <= L1) {--ST; --SG;}
                 else break;
    }
    ++ST; st[ST].m=m; st[ST].b=b;
    if (ST>1) {++SG; segm[SG]=intersect (st[ST].m, st[ST].b, st[ST-1].m, st[ST-1].b);}
}
int main ()
{
    cin>>T;
    while (T--) {
        cin>>n;
        cin>>a>>b>>c;
        for (i=1; i<=n; ++i)
            cin>>X[i];

        //dp[i] - costul maxim cu care iau toti soldatii 1-i
        ST=0; SG=0; segm[++SG]=-INF; I=1;
        for (i=1; i<=n; ++i) {
           pi[i]=pi[i-1] + X[i];
           XX=pi[i];

           // acum facem pointer walk
           while (SG < I) --I; // acum e maxim pe ultimul segment
           while (segm[I+1] < XX && I+1<=SG) ++I;

           if (i>1) dp[i]=st[I].m*(XX) + st[I].b + f(pi[i]);
               else dp[i]=f(pi[i]);

           dp[i]=max(dp[i], f(pi[i]));

           add_stiva((-2)*a*pi[i], dp[i] + a*(pi[i]*pi[i]) - b*pi[i]);
        }
        cout<<(long long)(dp[n])<<"\n";
    }


    return 0;
}
