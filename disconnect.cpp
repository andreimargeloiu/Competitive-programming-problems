# include <fstream>
# include <vector>
# include <algorithm>
using namespace std;
ifstream f("disconnect.in");
ofstream g("disconnect.out");
vector <int> v[100005];
int i,j,n,m,a,b,V,x,y,tip,I,maxx,Ra,Rb;
int R[100005],grad[100005];
bool ap[100005];
void DFS (int k)
{
    ap[k]=1;
    for (int i=0; i<v[k].size(); ++i)
        if (! ap[v[k][i]])
        {
            R[v[k][i]]=k;
            DFS(v[k][i]);
        }
}
int radacina(int k)
{
    while (k!=R[k])
        k=R[k];
    return k;
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=n-1; ++i)
    {
        f>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
        ++grad[x]; ++grad[y];
        if (grad[x]>maxx) maxx=grad[x], I=x;
        if (grad[y]>maxx) maxx=grad[y], I=y;
    }
    R[I]=I; DFS(I);
    for (i=1; i<=m; ++i)
    {
        f>>tip>>x>>y;

        a=x^V;
        b=y^V;
        if (a==b) {g<<"YES\n"; V=a; continue;}
        if (tip==1)
        {
            if(R[a]==b) R[a]=a;
            else R[b]=b;
        }
        else {
                Ra=radacina(a);
                Rb=radacina(b);
                if (Ra==Rb) {g<<"YES\n"; V=a;}
                else {g<<"NO\n"; V=b;}
             }
    }

    return 0;
}
