#include <iostream>
#include<fstream>
#include<string.h>
using namespace std;
ifstream in("date.in");

char a[100][100][100],a2[100][100][100],a3[100][100][100][100];
int v[100],n,r[100][100],ok;


void AFN(int stare,char cuv[100],char stiva[100])
{

    if(cuv[0]=='*'&&v[stare]==1&&stiva[0]=='Z')
    {
        cout<<"DA";
        ok=1;
    }
    if(ok==0)
    {
        char c=cuv[0];
        int i,j;
        for(j=1; j<=n; j++)
            for(i=1; i<=r[stare][j]; i++)
            {

                if(a[stare][j][i]==c&&stiva[0]==a2[stare][j][i])
                {
//cout<<a[stare][j][i]<<" "<<c<<" "<<stiva[0]<<" "<<a2[stare][j][i]<<endl;
                    char cuv2[100],stiva2[100],stiva3[100];
                    strcpy(cuv2,cuv+1);
                    strcpy(stiva2,stiva);
                    strcpy(stiva2,stiva2+1);
                    strcpy(stiva3,a3[stare][j][i]);
                    strcat(stiva3,stiva2);
                    if(stiva3[0]=='@')
                        strcpy(stiva3,stiva3+1);
//cout<<j<<" "<<cuv2<<" "<<stiva3<<endl;
                    AFN(j,cuv2,stiva3);
                }
                if(c=='*'&&a2[stare][j][i]=='Z'&&stiva[0]=='Z')
                    AFN(j,cuv,"Z");
            }
    }
}

int main()
{

    int i,k,x,y,k2;
    char c,c2,c3[21];
    in>>n>>k;
    for(i=1; i<=k; i++)
    {
        in>>x>>y>>c>>c2;
        r[x][y]++;
        a[x][y][r[x][y]]=c;
        a2[x][y][r[x][y]]=c2;
        in.get(c3,21);
        strcpy(c3,c3+1);
        strcpy(a3[x][y][r[x][y]],c3);

    }
    in>>k2;
    for(i=1; i<=k2; i++)
    {
        in>>x;
        v[x]=1;
    }

    in.get();
    char cuv[23];
    in.get(cuv,23);


    if(strcmp(cuv,"lambda")==NULL)
    {
        if(v[1]==1)
            cout<<"DA";
        else
            cout<<"NU";
    }
    else
    {
        strcat(cuv,"*");
        AFN(1,cuv,"Z");

        if(ok!=1)
            cout<<"NU";
    }
}

/*
datele din fisier

nr de stari
nr de muchii
npdul de pornire, de final si litera
nr de stari finale
v[]-marchez cu 1 ndurile finale
cuvantul verificat

3
12
1 1 0 Z 0Z
1 1 1 Z 1Z
1 1 0 0 00
1 1 0 1 01
1 1 1 0 10
1 1 1 1 11
1 2 c Z Z
1 2 c 0 0
1 2 c 1 1
2 2 0 0 @
2 2 1 1 @
2 3 @ Z Z
1
3
01c10

023

0010101c1010100

011c110


3
5
1 1 a A AA
1 1 a Z AZ
1 2 b A @
2 2 b A @
2 3 @ Z @
1
3
aaaabbbb



3
6
1 1 a A AAA
1 1 a Z AAZ
1 2 b A @
2 2 b A @
2 3 @ Z @
1 3 @ Z @
1
3
aabbbb


5
9
1 2 a A AA
1 2 a Z AZ
2 1 a A A
1 3 b A BBBA
3 3 b B BBBB
3 4 c B @
4 4 d A @
4 4 c B @
4 5 @ Z @
1
5
aabcccd

*/
