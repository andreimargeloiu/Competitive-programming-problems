# include <fstream>
# include <algorithm>
# include <cstring>
# define NR 200005
using namespace std;
ifstream f("romania.in");
ofstream g("romania.out");
struct solutie {
    int x, y;
}sol[NR];
int i,j,n,m,K,VV,x,start,nrsol,scot,VV1;
int st[NR], ap[NR], a[NR], scos[NR];
int main ()
{
    f>>n>>K;
    for (i=1; i<=K; ++i) {
        f>>x; ++ap[x];
    }
    for (i=1; i<=n; ++i) {
        if (i!=1 && ap[i] && ap[i-1]==0) start=i;

        a[i]=a[n+i]=i;
    }

    for (i=start; i<=start+n; ++i) {
        if (ap[a[i-1]]==0) {
            ++scot;
            for (j=VV; j>=1; --j){
               if (scos[st[j]]==scot) break;
               else {
                   ++nrsol; scos[st[j]]=scot;
                   sol[nrsol].x=st[j];
                   sol[nrsol].y=a[i];
                   --VV;
               }
            }
        }
        if (ap[a[i]]) {
            for (j=1; j<=ap[a[i]]; ++j) st[++VV]=a[i];
            // e ocupat si il punem in stiva ca sa asteptam sa
                           // il cuplam
        }
    }
    if (nrsol!=K) g<<"-1\n";
    else {
        for (i=1; i<=K; ++i)
            g<<sol[i].x<<" "<<sol[i].y<<"\n";
    }

    return 0;
}
