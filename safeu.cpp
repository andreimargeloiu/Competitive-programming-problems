# include <fstream>
# include <cstring>
# include <algorithm>
# include <queue>
using namespace std;
ifstream f("safeu.in");
ofstream g("safeu.out");
struct elem
{
    int l,c,L,C;
}E,F;
queue <elem> q;
int i,j,n,m,L,C,ok;
int a[55][55],ap[55][55][55][55];//coord pct liber / coord pct X
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
char s[205];
void bordare ()
{
    int i;
    for (i=0; i<=n+1; ++i)
        a[i][0]=a[i][m+1]=2;
    for (i=1; i<=m+1; ++i)
        a[0][i]=a[n+1][i]=2;
}
void procesare ()
{
    int i,l,c,L,C,lv,cv;
    while (! q.empty())
    {
        E=q.front(); q.pop();
        l=E.l; c=E.c; L=E.L; C=E.C;
        if (L==1 && C==1)
        {
            g<<ap[L][C][l][c]<<"\n";
            ok=1;
            break;
        }
        for (i=0; i<4; ++i)
        {
            lv=l+dx[i]; cv=c+dy[i];
            if (lv==L && cv==C)
            {
                if (! ap[lv][cv][l][c])
                {
                    ap[L][C][l][c]=ap[l][c][L][C]+1;
                    E.l=L; E.c=C; E.L=l; E.C=c;
                    q.push(E);
                }
            }
            else {
                     if (a[lv][cv]!=2 && !ap[lv][cv][L][C])
                     {
                         {
                            ap[lv][cv][L][C]=ap[l][c][L][C]+1;
                            E.l=lv; E.c=cv; E.L=L; E.C=C;
                            q.push(E);
                         }
                     }
                 }
        }
    }
}
int main ()
{
    f>>n>>m; f.get();
    //2-inaccesibil
    //5-pct X
    //1-bucati care se pot misca
    for (i=1; i<=n; ++i)
    {
        f.getline(s+1, 200);
        for (j=1; j<=m; ++j)
        {
            if (s[j]=='#') a[i][j]=2;
                else if (s[j]=='X') {a[i][j]=5; L=i; C=j;}
        }
    }
    bordare();
    if (a[1][2]==a[2][1] && a[1][2]==2)
    {
        g<<"Impossible\n";
        return 0;
    }

    E.l=1; E.c=1; E.L=L; E.C=C;
    ap[1][1][L][C]=1;
    q.push(E);

    procesare ();

    if (!ok) g<<"Impossible\n";

    return 0;
}
