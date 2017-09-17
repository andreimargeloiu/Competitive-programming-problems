# include <fstream>
# include <algorithm>
# include <vector>
# include <bitset>
# define mil 1000003
# define var (1<<31)-1
using namespace std;
ifstream f("arbore3.in");
ofstream g("arbore3.out");
vector <unsigned int> v[mil], HASH[mil];
bitset <mil> ap;
int i,tata,x,n,S,VV,s[mil];
unsigned int Suma;
void DFS (int k)
{
    int i; ap[k]=1;
    //adaugam la HASH
    Suma+=s[k];
    int VAR=Suma%mil;
    HASH[VAR].push_back(Suma);

    for (i=0; i<v[k].size(); ++i)
        if (! ap[v[k][i]])
            DFS(v[k][i]);

    //cautam sa facem sume
    int mod=(Suma-S)%mil;
    for (i=0; i<HASH[mod].size(); ++i)
        if (HASH[mod][i]==Suma-S)
        {
            ++VV;
        }

    HASH[VAR].erase(find(HASH[VAR].begin(), HASH[VAR].end(), Suma));
    Suma-=s[k];
}
int main ()
{
    f>>n>>S;
    for (i=1; i<=n; ++i)
    {
        f>>tata>>s[i];
        v[tata].push_back(i);
    }

    Suma=var; HASH[Suma%mil].push_back(Suma);
    DFS (1);

    g<<VV<<"\n";

    return 0;
}
