#include <iostream>
#include<fstream>
#include<string.h>
using namespace std;
ifstream in("date.in");

char a[100][100][100];
int v[100],n,r[100][100],ok,inchideri[100][100];
int stari[100][100],curent,reuniune[100][100];
long long frecv[100];
void BFS(int x)
{
    //x-nod inceput
    int  v[100], c[100],  i,j;

    for(i = 0; i <= 99; i++)
        v[i] = c[i] = 0;


    int p = 1;
    int u = 1;
    v[x] = 1;
    c[1] = x;

    while(p <= u)
    {
        for(i = 1; i <= n; i++)
            for(j=1; j<=r[c[p]][i]; j++)
                if(a[c[p]][i][j] == '@' && v[i] == 0)
                {
                    u++;
                    c[u] = i;
                    v[i] = 1;
                }

        p++;
    }
    inchideri[x][0]=u;
    for(i=1; i<=u; i++)
        inchideri[x][c[i]]=1;
}

int main()
{

    int i,k,x,y,k2,nr_alfabet;
    char alfabet[100];
    char c;
    in>>n>>k;
    for(i=1; i<=k; i++)
    {
        in>>x>>y>>c;
        r[x][y]++;
        a[x][y][r[x][y]]=c;

    }
    in>>k2;
    for(i=1; i<=k2; i++)
    {
        in>>v[i];
    }
    in>>nr_alfabet;
    for(i=1; i<=nr_alfabet; i++)
        in>>alfabet[i];

    for(i=1; i<=n; i++)
        BFS(i);



    int p=0,nou[100];
    for(int u=1; u<=nr_alfabet; u++)
    {
        p=0;
        for(i=1; i<=n; i++)

            if(inchideri[1][i]!=0)
            {

                for(int j=1; j<=n; j++)
                    for(int q=1; q<=r[i][j]; q++)

                        if(a[i][j][q]==alfabet[u])
                        {
                            p++;
                            nou[p]=j;

                        }

            }
        int h=0;
        curent++;
        stari[curent][0]=p;
        for(int q2=1; q2<=p; q2++)
        {
            stari[curent][q2]=nou[q2];

            for(int q3=1; q3<=n; q3++)
                if(inchideri[stari[curent][q2]][q3]==1)
                {
                    h++;
                    reuniune[curent][h]=q3;
                }

            reuniune[curent][0]=h;

        }
    }
    cout<<'1'<<endl;
    for(i=1; i<=curent; i++)
    {
        frecv[i]=0;
        cout<<alfabet[i]<<": ";
        for(int j=1; j<=reuniune[i][0]; j++)
        {
            cout<<reuniune[i][j]<<" ";
            if(reuniune[i][j]<10)
                frecv[i]=frecv[i]*10+reuniune[i][j];
            else
                frecv[i]=frecv[i]*100+reuniune[i][j];
        }
        cout<<endl;
    }

    int ok=1;
    while(ok<=curent)
    {
        cout<<frecv[ok]<<endl;
        p=0;
        long long rex=0;
        for(int u=1; u<=nr_alfabet; u++)
        {
            p=0;
            rex=0;
            cout<<alfabet[u]<<": ";
            for(int j=1; j<=reuniune[ok][0]; j++)

                for(i=1; i<=n; i++)
                    for(int q=1; q<=r[reuniune[ok][j]][i]; q++)

                        if(a[reuniune[ok][j]][i][q]==alfabet[u])
                        {
                            p++;
                            nou[p]=i;
                        }



            curent++;
            int h=0;
            stari[curent][0]=p;
            for(int q2=1; q2<=p; q2++)
            {
                stari[curent][q2]=nou[q2];

                for(int q3=1; q3<=n; q3++)
                    if(inchideri[stari[curent][q2]][q3]==1)
                    {
                        h++;
                        reuniune[curent][h]=q3;
                        if(q3<10)
                            rex=rex*10+q3;
                        else
                            rex=rex*100+q3;
                        cout<<q3<<" ";
                    }

                reuniune[curent][0]=h;

            }

            int ok2=0;
            for(int l=1; l<curent&&ok2==0; l++)
                if(rex==frecv[l])
                {
                    curent--;
                    ok2=1;
                }
            if(ok2==0)
                frecv[curent]=rex;
            cout<<endl;


        }



        ok++;
    }
    cout<<"Stari finale: ";
    for(i=1; i<=curent; i++)
    {
        int ok=1;
        for(int j=1; j<=reuniune[i][0]&&ok==1; j++)
            for(int l=1; l<=k2&&ok==1; l++)
                if(v[l]==reuniune[i][j])
                {
                    cout<<frecv[i]<<"  ";
                    ok=0;
                }
    }

    return 0;
}

/*
datele din fisier

n-nr de stari
k-nr de muchii
nodul de pornire, de final si litera
k2-nr de stari finale
v[]-marchez cu 1 nourile finale
cuvantul verificat
1-stare initiala

11
13
1 2 @
2 3 @
2 5 @
1 8 @
3 4 a
5 6 b
4 7 @
6 7 @
7 2 @
7 8 @
8 9 a
9 10 b
10 11 b
1
11
2
a b


*/
