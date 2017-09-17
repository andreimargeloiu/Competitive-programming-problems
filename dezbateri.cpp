# include <cstdio>
# include <cstring>
# include <vector>
# include <queue>
using namespace std;
vector <int> v[1005];
queue <int> q;
int i,j,n,m,nr,nr1,nr2,l,R,VV;
int in[1005],sol[1005], nivel[1005];
char s[105];
void topologica ()
{
    int i,k,ok=1,minn;
    for (i=1; i<=n && ok; ++i)
    {
        ok=0; minn=9999;
        for (j=1; j<=n; ++j)
            if (in[j]==0) {ok=1; minn=j; in[j]=-1; break;}
        sol[++VV]=minn;
        if (! ok) break;
        for (j=0; j<v[minn].size(); ++j)
            if (in[v[minn][j]]>0) --in[v[minn][j]];
    }
}
int main ()
{
    freopen ("dezbateri.in", "r", stdin);
    freopen ("dezbateri.out", "w", stdout);
    scanf ("%d %d\n", &n, &R);
    for (i=1; i<=R; ++i)
    {
        scanf ("%s\n", &s);

        j=0; nr=0; nr1=0; nr2=0;
        while ('0'<=s[j] && s[j]<='9')
            {nr=nr*10+(s[j]-'0'); ++j;}
        if (s[j]=='>') //cand arcele duc la el
        {
            ++j;
            while ('0'<=s[j] && s[j]<='9')
                {nr1=nr1*10+(s[j]-'0'); ++j;}
            ++j;
            while ('0'<=s[j] && s[j]<='9')
                {nr2=nr2*10+(s[j]-'0'); ++j;}

            v[nr1].push_back(nr); v[nr2].push_back(nr);
            ++in[nr];             ++in[nr];
        }
        else //cand acele sunt invers
        {
            ++j;
            while ('0'<=s[j] && s[j]<='9')
                {nr1=nr1*10+(s[j]-'0'); ++j;}
            ++j;
            while ('0'<=s[j] && s[j]<='9')
                {nr2=nr2*10+(s[j]-'0'); ++j;}

            v[nr2].push_back(nr); v[nr2].push_back(nr1);
            ++in[nr];             ++in[nr1];
        }
    }

    topologica ();
    if (VV!=n) printf ("0\n");
    else {
            for (i=1; i<=n; ++i)
                printf ("%d ", sol[i]);
         }
    return 0;
}
