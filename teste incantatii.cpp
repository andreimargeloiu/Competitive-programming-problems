# include <fstream>
# include <algorithm>
# include <ctime>
using namespace std;
ifstream f("test.in");
ofstream g("test.out");
int m,M,k,T,k1,k2,j,var,i;
int mic[200], mare[200];
char s[40];
int main ()
{
    f>>m>>M>>T;
    srand(time(0));
    while(m) {
        k=1+rand()%200;
        if ('a'<=k && k<='z') {
            mic[m]=k;
            --m;
        }
    }
    while(M) {
        k=1+rand()%100;
        if ('A'<=k && k<='Z') {
            mare[M]=k;
            --M;
        }
    }

    for (i=1; i<=T; ++i) {
        //primele 3
        k1=1+rand()%3;
        k2=1+rand()%3;

        for (j=1; j<=k1; ++j) {
            var=1+rand()%7;
            s[j]=s[2*k1+k2-j+1]=(char)(mic[var]);
        }
        for (j=1; j<=k2; ++j) {
            var=1+rand()%7;
            s[k1+j]=(char)(mare[var]);
        }
        s[2*k1+k2+1]='\0';
        g<<s+1<<"\n";
    }


    return 0;
}
