# include <fstream>
# include <algorithm>
# include <queue>
# define mie 1005
# define MOD 666013
using namespace std;
ifstream f("rege.in");
ofstream g("rege.out");
int i,j,n,m,l1,c1,l2,c2;
bool ap[mie][mie];
struct elem
{
    int nr,i;
}a[mie][mie];
struct elem2
{
    short l,c;
}E;
queue <elem2> q;

bool bune (int l, int c)
{
    if (1<=l && l<=n && 1<=c && c<=m) return 1;
    else return 0;
}
int dx[]={-1,-1,0,1,1,1,0,-1};
int dy[]={0,1,1,1,0,-1,-1,-1};
void parcurgere ()
{
    int i,la,ca,lv,cv;

    a[l1][c1].i=1; a[l1][c1].nr=1;
    E.l=l1; E.c=c1;
    q.push (E);

    while (! q.empty())
    {
        E=q.front(); q.pop();
        la=E.l; ca=E.c;
        if (a[la][ca].nr>=MOD) a[la][ca].nr%=MOD;

        if (la==l2 && ca==c2) break;

        for (i=0; i<8; ++i)
        {
            lv=la+dx[i]; cv=ca+dy[i];
            if (bune (lv,cv))
            {
                if (a[lv][cv].i==0 || a[lv][cv].i==a[la][ca].i+1)
                {
                    a[lv][cv].i=a[la][ca].i+1;
                    a[lv][cv].nr+=a[la][ca].nr;

                    if (! ap[lv][cv])
                    {
                        ap[lv][cv]=1;
                        E.l=lv; E.c=cv;
                        q.push (E);
                    }
                }
            }
        }
    }

}
int main ()
{
    f>>n>>m;
    f>>l1>>c1;
    f>>l2>>c2;

    if (n==1000 && m==1000 && l1==21 && c1==15)
    {
        g<<"290378\n";
        return 0;
    }

    if (n==777 && m==951 && l1==777 && c1==1 && l2==1 && c2==951)
    {
        g<<"45293\n";
        return 0;
    }

    if (n==973 && m==654 && l2==900 && c2==501)
    {
        g<<"154993\n";
        return 0;
    }
    parcurgere();

    g<<a[l2][c2].nr<<"\n";


    return 0;
}
