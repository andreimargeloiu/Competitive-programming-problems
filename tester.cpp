# include <fstream>
# include <vector>
# include <algorithm>
using namespace std;
ifstream f("tester.in");
ofstream g("tester.out");
struct elem
{
    int x,y;
}a[5005];
vector <int> v[5005],st,nr[505];
int i,j,n,m,R,x,y,VV;
int sol[1000005],in[5005],out[5005];
void euler (int k)
{
    int y;
    st.push_back(k);
    while (st.size())
    {
        k=st.back();
        if (v[k].size())
        {
            y=v[k].back();
            v[k].pop_back();
            st.push_back(y);
        }
        else {
                 sol[++VV]=k;
                 st.pop_back();
             }
    }
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=m; ++i)
    {
        f>>a[i].x>>a[i].y;
        nr[a[i].x].push_back(i);//cu ce incepe
    }
    R=m+1;
    for (i=1; i<=m; ++i)
    {
        for (j=0; j<nr[a[i].y].size(); ++j)
        {
            v[i].push_back(nr[a[i].y][j]);
            ++in[nr[a[i].y][j]];
            ++out[i];
        }
    }
    for (i=1; i<=m; ++i)
    {
        if (in[i]>out[i])
        {
            for (j=1; j<=in[i]-out[i]; ++j)
                v[i].push_back(R);
        }
        else if (out[i]>in[i])
        {
            for (j=1; j<=out[i]-in[i]; ++j)
                v[R].push_back(i);
        }
    }
    euler (R);
    //afisarea
    for (i=VV-1; i>1; --i)
    {
        if (sol[i]==R) g<<"R ";
        else {
                 if (sol[i-1]==R) g<<a[sol[i]].x<<" "<<a[sol[i]].y<<" ";
                    else g<<a[sol[i]].x<<" ";
             }
    }
    g<<"\n";
    return 0;
}
