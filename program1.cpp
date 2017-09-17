# include <fstream>
# include <cstring>
# include <vector>
# include <cstdlib>
using namespace std;
ifstream f("program1.in");
ofstream g("program1.out");
vector <int> v[10005];
int i,j,nr,K;
bool ap[10005];
char s[10005][30],var[30],*p;
void dfs (int k)
{
    int i;
    ++K; ap[k]=1;
    for (i=0; i<v[k].size(); ++i)
    {
        if (ap[v[k][i]]==0 && v[k][i]<=nr) dfs(v[k][i]);
    }
}
int main ()
{
    while (f.getline(var,30))
    {
        if (var[0]!='.') strcpy(s[++nr],var);
           else break;
        if (strcmp(var,"EXECUTA")==0) v[nr].push_back(nr+1);
        else {
                if (strstr(var,"SAU"))
                {
                    p=strtok(var," ");
                    p=strtok(NULL," ");
                    v[nr].push_back(atoi(p));
                    p=strtok(NULL," ");
                    p=strtok(NULL," ");
                    v[nr].push_back(atoi(p));
                }
                else
                {
                    p=strtok(var," ");
                    p=strtok(NULL," ");
                    v[nr].push_back(atoi(p));
                }
             }
    }
    ap[nr+1]=1;
    dfs (1);
    g<<nr-K<<"\n";

    return 0;
}
