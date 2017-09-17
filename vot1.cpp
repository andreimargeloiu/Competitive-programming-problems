# include <fstream>
# include <queue>
using namespace std;
ifstream f("vot1.in");
ofstream g("vot1.out");
queue <int> q;
int ap[1005],a[1005],nr[1005];
int i,j,n,K,x;
void eliminare ()
{
    while (! q.empty())
    {
        x=q.front (); q.pop ();
        ap[x]=1; ++K;
        --nr[a[x]];
        if (nr[a[x]]==0) q.push(a[x]);
    }
}
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
    {
        f>>a[i];
        ++nr[a[i]];
    }
    for (i=1; i<=n; ++i)
        if (nr[i]==0) q.push(i);
    eliminare ();
    g<<n-K<<"\n";
    for (i=1; i<=n; ++i)
        if (!ap[i]) g<<i<<" ";
    g<<"\n";

    return 0;
}
