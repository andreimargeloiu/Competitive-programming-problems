# include <fstream>
# include <cstring>
# include <algorithm>
# include <vector>
# define NR 6005
using namespace std;
ifstream f("party.in");
ofstream g("party.out");
vector <int> v[605];
int i,j,n,m,VV,L,act,o,S;
int ap[3][605];
char s[NR], a[605][15];
bool verificare (int v1, int v2)
{
    for (int i=1; i<n; ++i)
        if (a[v1][i]!=a[v2][i+1]) return 0;

    return 1;
}
int main ()
{
    f>>n>>L>>m; f.get();
    f.getline(s, NR);

    char *p;
    p=strtok (s, " "); n=strlen(p);
    while (p!=NULL)
    {
        ++VV;
        strcpy(a[VV]+1, p);
        p=strtok (NULL, " ");
    }

    if (n==1)
    {
        for (i=1; i<=m; ++i)
            for (j=1; j<=m; ++j)
                v[i].push_back(j);
    }
    else {
            for (i=1; i<=m; ++i)
                for (j=1; j<=m; ++j)
                    if (verificare (i, j)) v[i].push_back(j);
         }

    for (i=1; i<=m; ++i) //pot face fiecare ghirlanda de lungime n
        ap[0][i]=1;

    act=0;
    for (i=n+1; i<=L; ++i) {//fiecare lungime

        for (j=1; j<=m; ++j) //fiecare ghirlanda pe care vreau sa o adaug
            for (o=0; o<v[j].size(); ++o)  //de unde pot veni
                ap[1-act][j]+=ap[act][v[j][o]];

        for (j=1; j<=m; ++j)
            ap[act][j]=0;

        act=1-act;
    }

    //solutia
    for (i=1; i<=m && n<=L; ++i)
        S+=ap[act][i];
    g<<S<<"\n";


    return 0;
}
