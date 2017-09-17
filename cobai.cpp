# include <fstream>
# include <queue>
# include <cstring>
using namespace std;
ifstream f("cobai.in");
ofstream g("cobai.out");
struct elem
{
    short l,c,niv;
}x,y;
queue <elem> q;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int i,j,n,m,l,nrsol,avaible,P;
int a[55][55],ap[55][55],dir[1005];
char s[1005];
float p;
void coada ()
{
    int la,ca,lv,cv,i,niv;
    while (! q.empty())
    {
        x=q.front (); q.pop ();
        la=x.l; ca=x.c; niv=x.niv;
        if (niv==l) {++nrsol; continue;}
        if (dir[niv+1]==1)//in nord
        {
            --la;
            while (la>=1)
            {
                if (a[la][ca]==1) break;
                if (ap[la][ca]==niv+1) break;
                y.l=la; y.c=ca; y.niv=niv+1;
                q.push(y); ap[la][ca]=niv+1;
                --la;
            }
        }
        if (dir[niv+1]==2)//in est
        {
            ++ca;
            while (ca<=m)
            {
                if (a[la][ca]==1) break;
                if (ap[la][ca]==niv+1) break;
                y.l=la; y.c=ca; y.niv=niv+1;
                q.push(y); ap[la][ca]=niv+1;
                ++ca;
            }
        }
        if (dir[niv+1]==3)//in sud
        {
            ++la;
            while (la<=n)
            {
                if (a[la][ca]==1) break;
                if (ap[la][ca]==niv+1) break;
                y.l=la; y.c=ca; y.niv=niv+1;
                q.push(y); ap[la][ca]=niv+1;
                ++la;
            }
        }
        if (dir[niv+1]==4)//in vest
        {
            --ca;
            while (ca>=1)
            {
                if (a[la][ca]==1) break;
                if (ap[la][ca]==niv+1) break;
                y.l=la; y.c=ca; y.niv=niv+1;
                q.push(y); ap[la][ca]=niv+1;
                --ca;
            }
        }
    }
}
int main ()
{
    f>>n>>m; f.get();
    avaible=n*m;
    for (i=1; i<=n; ++i)
    {
        f.getline(s,55);
        for (j=1; j<=m; ++j)
            if (s[j-1]=='+') a[i][j]=1,--avaible;
                else if (s[j-1]=='*') {
                                          x.l=i; x.c=j; x.niv=0; q.push(x);
                                          a[i][j]=1; --avaible;
                                      }
    }
    f.getline (s,1005);
    l=strlen(s);
    for (i=0; i<l; ++i)
    {
        if (s[i]=='N') dir[i+1]=1;
        if (s[i]=='E') dir[i+1]=2;
        if (s[i]=='S') dir[i+1]=3;
        if (s[i]=='V') dir[i+1]=4;
    }
    coada ();
    p=10000*nrsol/avaible;
    P=p;
    g<<P/100<<"."<<P%100<<"\n";
    return 0;
}
