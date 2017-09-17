# include <fstream>
# include <algorithm>
# include <queue>
# include <vector>
using namespace std;
ifstream f("castel.in");
ofstream g("castel.out");
bool ap[25000],key[25000];
queue <short> q;
vector <short> lst[25000];
short i,j,n,m,k,nr,var,VV,x;
short a[152][152];
short dx[]={-1,0,1,0}, dy[]={0,1,0,-1};
void numarare ()
{
    int i,la,ca,lv,cv;
    ap[k]=1; //daca am ajusn pana la camera x
    key[k]=1; //daca am cheia
    q.push(k);
    while (! q.empty())
    {
        x=q.front (); q.pop ();

        la=x/m+1; ca=x%m;
        if (ca==0) ca=m,--la;

        if (lst[x].size()>0)
        {
            for (i=0; i<lst[x].size(); ++i)//camere pe care le pot deschide dupa ce deschid X
            {
                var=lst[x][i];
                ++VV; key[var]=1;
                q.push(var);
            }
            lst[x].clear();
        }
        for (i=0; i<4; ++i)
        {
            lv=la+dx[i]; cv=ca+dy[i];
            if (lv>=1 && lv<=n && cv>=1 && cv<=m)
            {
                if (!ap[(lv-1)*m+cv])
                {
                    ap[(lv-1)*m+cv]=1;
                    if (key[a[lv][cv]]) {++VV; key[(lv-1)*m+cv]=1; q.push((lv-1)*m+cv);}
                    else {
                            lst[a[lv][cv]].push_back((lv-1)*m+cv);
                         }
                }
            }
        }
    }
}
int main ()
{
    f>>n>>m>>k;
    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j)
            f>>a[i][j];
    numarare ();
    g<<VV+1<<"\n";

    return 0;
}
