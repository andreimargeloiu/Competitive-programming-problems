# include <fstream>
# include <cstring>
# include <vector>
using namespace std;
ifstream f("fazan.in");
ofstream g("fazan.out");
vector <int> v[100];
int i,j,n,m,x,ok,okneg,VV,ok1,q,t;
int ap[100],nr[100];
char s[10005];
void initializare ()
{
    ok=1; VV=0;
    for (int i=1; i<=50; ++i)
        ap[i]=0;
    for (int i=1; i<=50; ++i)
    {
        v[i].clear();
        nr[i]=0;
    }
}
void DFS (int k)
{
    ap[k]=1;
    for (int i=0; i<v[k].size(); ++i)
    {
        if (ap[v[k][i]]==0) DFS(v[k][i]);
    }
}
int main ()
{
    f>>t;
    for (q=1; q<=t; ++q)
    {
        f>>n; f.get();
        initializare ();
        for (i=1; i<=n; ++i)
        {
            f.getline (s,1005);
            v[s[0]-'a'+1].push_back(s[strlen(s)-1]-'a'+1);
            v[s[strlen(s)-1]-'a'+1].push_back(s[0]-'a'+1);
            ++nr[s[0]-'a'+1]; --nr[s[strlen(s)-1]-'a'+1];
        }
        okneg=0; ok1=0;
        for (i=1; i<=50; ++i)
        {
            if (nr[i]==0) continue;
            if (nr[i]==-1) {++okneg; continue;}
            if (nr[i]==1) {++ok1; continue;}
            ok=0;
        }
        if (okneg>1 || ok1>1) ok=0;

        for (i=1; i<=26; ++i)
        {
            if (v[i].size()!=0 && ap[i]==0)
            {
                ++VV;
                DFS(i);
            }
        }
        if (VV>1) ok=0;
        if (ok) g<<"1\n";
           else g<<"0\n";
    }


    return 0;
}
