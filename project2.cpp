#include<iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<sstream>
#include<string>
using namespace std;
int space_m[1000001];
int space_n[1000001];
int cleanmap[1002][1002];
int m_n_b[3];
int Cpoint_m[1],Cpoint_n[1];
int now_m,now_n;
int total=0;
int battery;
int Bnow;
int clean_or_not[1000001];
int number;
int total_length=0;
int level[1000001];
int parent[1000001];
int parent_number;
int visit_or_not[1000001];
int print_m[1000001],print_n[1000001];
int total_print_m[30000000],total_print_n[30000000];
int k = 0,h=0;
int g=0;
int howmanyson[1000000];
int lastone[1000000];
int store[1000000];
int c;
int record;

int scan_the_location(int m, int n)
{
    for(int i=0;i<total;i++)
    {
        if(space_m[i]==m&&space_n[i]==n)
        {
            return i;
        }
    }

}
void tree(int m , int n,int l)
{

    if(l==0)
    {
        if(cleanmap[m+1][n]==0)
        {

            number=scan_the_location( m+1,  n);

            if(visit_or_not[number]==0)
            {

                visit_or_not[number]=1;
                level[number]=l+1;
                parent[number]=1000000;
                tree(m+1,n,l+1);

            }

        }
        if(cleanmap[m-1][n]==0)
        {
            number=scan_the_location( m-1,  n);

            if(visit_or_not[number]==0)
            {
                visit_or_not[number]=1;
                level[number]=l+1;
                parent[number]=1000000;

                tree(m-1,n,l+1);
            }

        }
        if(cleanmap[m][n+1]==0)
        {
            number=scan_the_location(m, n+1);

            if(visit_or_not[number]==0)
            {
                visit_or_not[number]=1;
                level[number]=l+1;
                parent[number]=1000000;
                tree(m,n+1,l+1);
            }
        }
        if(cleanmap[m][n-1]==0)
        {
            number=scan_the_location( m,  n-1);

            if(visit_or_not[number]==0)
            {
                visit_or_not[number]=1;
                level[number]=l+1;
                parent[number]=1000000;
                tree(m,n-1,l+1);
            }

        }
    }
    else if(l!=0&&l+1<=battery/2)
    {
        if(cleanmap[m+1][n]==0)
        {

            number=scan_the_location( m+1,  n);
            if(visit_or_not[number]==0)
            {
                visit_or_not[number]=1;
                level[number]=l+1;
                parent_number=scan_the_location( m, n);
                parent[number]=parent_number;
                tree(m+1,n,l+1);
            }

        }
        if(cleanmap[m-1][n]==0)
        {


            number=scan_the_location(m-1, n);

            if(visit_or_not[number]==0)
            {
                visit_or_not[number]=1;
                level[number]=l+1;
                parent_number=scan_the_location( m, n);
                parent[number]=parent_number;
                tree(m-1,n,l+1);
            }

        }
        if(cleanmap[m][n+1]==0)
        {

            number=scan_the_location( m,  n+1);

            if(visit_or_not[number]==0)
            {
                visit_or_not[number]=1;
                level[number]=l+1;
                parent_number=scan_the_location( m,  n);
                parent[number]=parent_number;
                tree(m,n+1,l+1);
            }

        }
        if(cleanmap[m][n-1]==0)
        {

            number=scan_the_location( m,  n-1);

            if(visit_or_not[number]==0)
            {
                visit_or_not[number]=1;
                level[number]=l+1;
                parent_number=scan_the_location( m,  n);
                parent[number]=parent_number;
                tree(m,n-1,l+1);
            }

        }

    }

}
void clean(void)
{

    for(int q=0;q<total;q++)
    {
        for(int f=0;f<total;f++)
        {
            if(parent[f]==q)
            {
                howmanyson[g]=howmanyson[g]+1;
            }
            else if(f==total-1&&parent[f]!=q&&howmanyson[g]==0)
            {
                lastone[k]=q;
                k++;
            }
        }
        g++;
    }
    for(int i=0; i<k;i++)
    {
        c=0;

        record=lastone[i];
        while(parent[record]!=1000000)
        {
            store[c]=parent[record];
            record=parent[record];
            c++;



        }
        for(int j=c-1;j>=0;j--)
        {
            total_print_m[h]=space_m[store[j]];
            total_print_n[h]=space_n[store[j]];
            h++;
            total_length++;
        }
        total_print_m[h]=space_m[lastone[i]];
        total_print_n[h]=space_n[lastone[i]];
        h++;
        total_length++;
        for(int j=0;j<c;j++)
        {
            total_print_m[h]=space_m[store[j]];
            total_print_n[h]=space_n[store[j]];
            h++;
            total_length++;
        }
        total_print_m[h] = space_m[1000000] ;
        total_print_n[h] = space_n[1000000] ;
        total_length++;
        h++;

    }
}

int main(int argc, char *argv[])
{
    stringstream str1;
    str1 << "./" << argv[1] << "/floor.data";

    ifstream fin;
    fin.open(str1.str());
    if(!fin){
        cout << "can't open floor.data" << endl;
    }

    stringstream str2;
    str2<< "./" << argv[1] << "/final.path";

    ofstream fout;
    fout.open(str2.str());
    if(!fout){
        cout << "can't open final.path" << endl;
    }



    for(int temp1=0;temp1<1000;temp1++)
    {
        for(int temp2=0;temp2<1000;temp2++)
        {
            cleanmap[temp1][temp2]=-1;
        }
    }
    int m,n;

    fin >> m_n_b[0] >> m_n_b[1] >> m_n_b[2];
    char cmd;
    for(m=0;m<m_n_b[0];m++)
    {
        for(n=0;n<m_n_b[1];n++)
        {
            int temp=0;
            fin >> cmd;
            if(cmd=='R')
            {
                 temp =2;
                cleanmap[m][n]=temp;
                Cpoint_m[0] = m ;
                Cpoint_n[0] = n ;

            }
            else if(cmd=='0')
            {
                temp = 0;
                cleanmap[m][n]=temp;
                space_m[total]=m;
                space_n[total]=n;
                total++;

            }
            else if(cmd == '1')
            {
                temp = 1;
                cleanmap[m][n]=temp;
            }

        }

    }

    int p;

    now_m = Cpoint_m[0];
    now_n = Cpoint_n[0];
    battery = m_n_b[2];

    space_m[1000000]=Cpoint_m[0];
    space_n[1000000]=Cpoint_n[0];

    parent[1000000]=-1;
    tree(now_m, now_n,0);

    clean();
    fout << total_length << endl;

    for( p=0;p<total_length;p++)
    {
        fout << total_print_m[p] << ' ' << total_print_n[p] <<endl;
    }
    return 0;

}



