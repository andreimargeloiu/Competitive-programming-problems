# include <cstdio>
# include <vector>
using namespace std;
vector <int> v[20000];
int i,j,n,x,y,VV;
int sol[20000], tata[20000], frate[20000], J[20000], S[20000]; // J, S sunt 1 daca cel care incepe de acolo castiga, 0 daca pierde
void jos (int k)
{
    if (!v[k].size()) J[k]=1;
    else {
             jos(v[k][0]);
             jos(v[k][1]);
             if (J[v[k][0]]==0 && J[v[k][1]]==0) J[k]=1;
         }
}
void sus (int k)
{
    if (k==1) S[k]=1;
    else {
             if (J[frate[k]]==1 || S[tata[k]]==0) S[k]=1;
         }
    if (v[k].size())
    {
        sus(v[k][0]);
        sus(v[k][1]);
    }
}
int main ()
{
    freopen ("color.in", "r", stdin);
    freopen ("color.out", "w", stdout);
    scanf ("%d", &n);
    for (i=1; i<n; ++i)
    {
        scanf ("%d%d", &x, &y);
        v[x].push_back(y);
        tata[y]=x;
    }
    for (i=1; i<=n; ++i)
    {
        if (v[i].size())
        {
            frate[v[i][0]]=v[i][1];
            frate[v[i][1]]=v[i][0];
        }
    }
    jos(1);
    sus(1);
    for (i=1; i<=n; ++i)
        if (J[i] && S[i]) sol[++VV]=i;
    printf ("%d\n", VV);
    for (i=1; i<=VV; ++i)
        printf ("%d ", sol[i]);

    return 0;
}
