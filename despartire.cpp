# include <fstream>
# include <cstring>
using namespace std;
ifstream f("strtok.in");
ofstream g("strtok.out");
int i,j,n,l;
char *p,s[100];
int main ()
{
    f.getline(s,100);
    char var[]=" ,.!?";
    p=strtok(s,var);
    while (p)
    {
        g<<p<<"\n";
        p=strtok(NULL,var);
    }



    return 0;
}
