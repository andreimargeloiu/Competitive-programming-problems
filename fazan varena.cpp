# include <fstream>
# include <cstring>
# include <vector>
# include <algorithm>
# define NR 100005
# define L 25
using namespace std;
struct elem
{
    int y, i;
}E;
vector <elem> v[10005];
struct elem2
{
    int k, cuv;
}F;
vector <elem2> st;
vector <int> vt[10005];
ifstream f("fazan.in");
ofstream g("fazan.out");
int i,j,n,m,Plus,Min,N1,N2,nr1,nr2,VV,conexe,nrsol,l,R,varfuri;
int sol[NR], grad[NR];
bool ap[NR];
char s[L],mat[NR][L];
void DFS (int k)
{
    ap[k]=1; ++conexe;
    for (int i=0; i<vt[k].size(); ++i)
        if (! ap[vt[k][i]]) DFS (vt[k][i]);
}
void euler (int k)
{
    int y;
    F.k=k; F.cuv=0;
    st.push_back(F);
    while (st.size())
    {
        F=st.back();
        k=F.k;
        if (v[k].size())
        {
            E=v[k].back(); v[k].pop_back();
            y=E.y;

            F.k=y; F.cuv=E.i;
            st.push_back(F);
        }
        else {
                sol[++nrsol]=F.cuv;
                st.pop_back();
             }
    }
}
void afisare (int ci, int cs)
{
    for (int i=cs; i>=ci; --i)
        g<<mat[sol[i]]+1<<"\n";
}
int main ()
{
    f>>n; f.get();
    for (i=1; i<=n; ++i)
    {
        f.getline (s+1, L); l=strlen(s+1);
        strcpy(mat[i]+1, s+1);
        nr1=(s[1]-'a'+1)*100+(s[2]-'a'+1);
        nr2=(s[l-1]-'a'+1)*100+(s[l]-'a'+1);

        E.y=nr2; E.i=i;
        v[nr1].push_back(E); ++grad[nr1]; --grad[nr2];

        vt[nr1].push_back(nr2); if (vt[nr1].size()==1) ++varfuri;
        vt[nr2].push_back(nr1); if (vt[nr2].size()==1) ++varfuri;
    }
    DFS (nr1);
    if (conexe!=varfuri)
    {
        g<<"imposibil\n";
        return 0;
    }
    //grad - +1 cand e exterior
    //       -1 cand e interior
    for (i=1; i<=10005; ++i)
    {
        if (grad[i]>1 || grad[i]<-1)
        {
            g<<"imposibil\n";
            return 0;
        }
        else if (grad[i]==-1)
        {
            if (Min==0) N1=i, Min=1;
            else {
                    g<<"imposibil\n";
                    return 0;
                 }
        }
        else if (grad[i]==1)
        {
            if (Plus==0) N2=i, Plus=1;
            else {
                    g<<"imposibil\n";
                    return 0;
                 }
        }
    }
    if (!Min && !Plus)
    {
        R=(mat[1][1]-'a'+1)*100+(mat[1][2]-'a'+1);
        euler (R);
        afisare (1, n);
        return 0;
    }
    if (Min && Plus)
    {
        R=1;
        E.y=N2; v[R].push_back(E);
        E.y=R;  v[N1].push_back(E);

        euler (R);
        afisare (2, n+1);
        return 0;
    }

    g<<"imposibil\n";
    return 0;
}
