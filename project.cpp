#include<iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<sstream>
#include<string>
using namespace std;
int c[1000001];
int d[1000001];
int b[1001][1001];
int a[2];
int m, n;
int k =0;
int main(int argc, char *argv[])
{
    stringstream str1;
    str1 << "./" << argv[1] << "/matrix.data";

    ifstream fin;
    fin.open(str1.str());
    if(!fin){
        cout << "can't open matrix.data" << endl;
    }

    stringstream str2;
    str2<< "./" << argv[1] << "/final.peak";

    ofstream fout;
    fout.open(str2.str());
    if(!fout){
        cout << "can't open final.peak" << endl;
    }




    fin >> a[0] >> a[1];

    for(m=0;m<a[0];m++)
    {
        for(n=0;n<a[1];n++)
        {
            fin >> b[m][n];

        }

    }


    for(m=0;m<a[0];m++)
    {
        for(n=0;n<a[1];n++)
        {
            if(m==0)
            {
                if(n==0)
                {
                    if(b[m][n]>=b[m+1][n]&&b[m][n]>=b[m][n+1])
                    {
                        c[k]=m;
                        d[k]=n;
                        k++;
                    }
                }
                else if(n!=0&&n!=a[1]-1)
                {
                    if(b[m][n]>=b[m][n-1]&&b[m][n]>=b[m][n+1]&&b[m][n]>=b[m+1][n])
                    {
                        c[k]=m;
                        d[k]=n;
                        k++;
                    }
                }
                else if(n==a[1]-1)
                {
                    if(b[m][n]>=b[m+1][n]&&b[m][n]>=b[m][n-1])
                    {
                        c[k]=m;
                        d[k]=n;
                        k++;
                    }
                }
            }
            else if(m!=0&&m!=a[0])
            {
                if(n==0)
                {
                    if(b[m][n]>=b[m+1][n]&&b[m][n]>=b[m][n+1]&&b[m][n]>=b[m-1][n])
                    {
                        c[k]=m;
                        d[k]=n;
                        k++;
                    }
                }
                else if(n!=0&&n!=a[1]-1)
                {
                    if(b[m][n]>=b[m][n-1]&&b[m][n]>=b[m][n+1]&&b[m][n]>=b[m+1][n]&&b[m][n]>=b[m-1][n])
                    {
                        c[k]=m;
                        d[k]=n;
                        k++;
                    }
                }
                else if(n==a[1]-1)
                {
                    if(b[m][n]>=b[m+1][n]&&b[m][n]>=b[m][n-1]&&b[m][n]>=b[m-1][n])
                    {
                        c[k]=m;
                        d[k]=n;
                        k++;
                    }
                }
            }
            else if(m==a[0])
            {
                if(n==0)
                {
                    if(b[m][n]>=b[m-1][n]&&b[m][n]>=b[m][n+1])
                    {
                        c[k]=m;
                        d[k]=n;
                        k++;
                    }
                }
                else if(n!=0&&n!=a[1]-1)
                {
                    if(b[m][n]>=b[m][n-1]&&b[m][n]>=b[m][n+1]&&b[m][n]>=b[m-1][n])
                    {
                        c[k]=m;
                        d[k]=n;
                        k++;
                    }
                }
                else if(n==a[1]-1)
                {
                    if(b[m][n]>=b[m-1][n]&&b[m][n]>=b[m][n-1])
                    {
                        c[k]=m;
                        d[k]=n;
                        k++;
                    }
                }
            }
        }
    }
   fout << k << endl;
   int p;
    for( p=0;p<k;p++)
    {
        fout << c[p] << ' ' << d[p] <<endl;
    }
    return 0;
}


