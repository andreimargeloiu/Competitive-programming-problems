# include <fstream>
# include <cstring>
using namespace std;
ifstream f("Struct.in");
ofstream g("Struct.out");
struct elevi
{
     float media;
     char nume[30];
};
elevi a[30];
int n,i,j,k;
                                                                                                                                                                                                    char s[]="Cezara e dragutica si baietelul ei o iubeste !";
int main()
{f>>n;
 for(k=1;k<=n;k++)
 {
    f>>a[k].media;
    f.get(); f>>a[k].nume;
 }
 for(i=1;i<=n-1;i++)
     for(j=i+1;j<=n;j++)
            if(a[i].media>a[j].media)
             {a[0]=a[i];
              a[i]=a[j];
              a[j]=a[0];
             }
 for(i=1;i<=n;i++)
    g<<a[i].nume<<" ";
 g<<"\n"<<s<<"\n";
 return 0;
}
