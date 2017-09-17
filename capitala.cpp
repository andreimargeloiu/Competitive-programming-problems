# include <fstream>
# include <cstring>
# include <algorithm>
# include <vector>
# define NR 200005
# define inf 999999999
using namespace std;
ifstream f("capitala.in");
ofstream g("capitala.out");
vector <int> v[NR];
int i,j,n,m,x,y,I,k,R;
int fii[NR],l;
long long S[NR], sum[NR], minn;
char s[105];
void read (int &x, int &y)
{
    x=0; y=0;
    f.getline (s+1, 100); l=strlen (s+1);
    int i=1;
    while ('0'<=s[i] && s[i]<='9')
    {
        x=x*10+(s[i]-'0');
        ++i;
    }
    ++i;
    while ('0'<=s[i] && s[i]<='9')
    {
        y=y*10+(s[i]-'0');
        ++i;
    }
}
void DFS (int k, int tata)
{
    fii[k]=1;
    for (int i=0; i<v[k].size(); ++i)
        if (v[k][i]!=tata)
        {
            DFS (v[k][i], k);

            fii[k]+=fii[v[k][i]];
            sum[k]+=sum[v[k][i]]+fii[v[k][i]];
        }
}
void numara (int k, int tata)
{
    if (k!=R)
    {
        S[k]=S[tata]+n-2*(fii[k]); //scadem din total ramura actuala;
        if (S[k]<minn) minn=S[k], I=k;
    }

    for (int i=0; i<v[k].size(); ++i)
        if (v[k][i]!=tata) numara (v[k][i], k);
}
int main ()
{
    f>>n; f.get();
    for (i=1; i<n; ++i)
    {
        read (x, y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (i=1; i<=n; ++i)
        if (v[i].size()==1) {R=i; break;}

    DFS (R, 0);

    S[R]=sum[R]; minn=S[R]; I=R;
    numara (R, 0);
    g<<I<<" "<<minn<<"\n";

    return 0;
}
