# include <fstream>
# include <algorithm>
# define inf 9999999999
using namespace std;
ifstream f("secvmax.in");
ofstream g("secvmax.out");
struct elem
{
    int nr,i,sol;
}a[100005],cp[100005];
bool cmp (elem x, elem y)
{
    if (x.nr>=y.nr) return 0;
        else return 1;
}
bool cmp2 (elem x, elem y)
{
    if (x.i>=y.i) return 0;
        else return 1;
}
int i,n,m,VV,poz,maxx;
int st[100005], dr[100005], v[100005], ap[100005];
void procesare ()
{
    int i;
    VV=1;
    for (i=1; i<=m; ++i) //pt fiecare intrebare
    {
        while (VV<=n && a[i].nr>=cp[VV].nr)
        {
            poz=cp[VV].i; ++VV; ap[poz]=1;
            st[poz]=poz; dr[poz]=poz;
            maxx=max(maxx,1);
            if (st[poz-1] && dr[poz+1])
            {
                maxx=max(maxx, dr[poz+1]-st[poz-1]+1);
                st[dr[poz+1]]=st[poz-1];
                dr[st[poz-1]]=dr[poz+1];
                continue;
            }
            if (st[poz-1])
            {
                maxx=max(maxx, poz-st[poz-1]+1);
                st[poz]=st[poz-1];
                dr[st[poz-1]]=poz;
                continue;
            }
            if (dr[poz+1])
            {
                maxx=max(maxx, dr[poz+1]-poz+1);
                st[dr[poz+1]]=poz;
                dr[poz]=dr[poz+1];
                continue;
            }
        }
        a[i].sol=maxx;
    }
    sort (a+1, a+m+1, cmp2);
    for (i=1; i<=m; ++i)
        g<<a[i].sol<<"\n";
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=n; ++i)
    {
        f>>v[i];
        cp[i].nr=v[i];
        cp[i].i=i;
    }
    for (i=1; i<=m; ++i)
    {
        f>>a[i].nr;
        a[i].i=i;
    }
    sort (a+1, a+m+1, cmp);
    sort (cp+1, cp+n+1, cmp);
    procesare ();

    return 0;
}
