#include<iostream>
using namespace std;
#define nn 10
class OBST{
            public:
            int i,j,n;
            int a[nn];
            int r[nn][nn];
            float p[nn],q[nn],w[nn][nn],c[nn][nn];
             
             
void obstaccept()
{  
     
    cout<<"Enter The Total No Of Elements ";
    cin>>n;
    cout<<"::ENTER ELEMENTS AND THERE PROBABILITY ::";
    for(int i=1;i<=n;i++)
    {
        cout<<"a["<<i<<"]::";
        cin>>a[i];
        cout<<"p["<<i<<"]::";
        cin>>p[i];
    }
    cout<<"::ENTER FAILURE POBABILITY ::";
    for(int i=0;i<=n;i++)
    {
        cout<<"q["<<i<<"]:: ";
        cin>>q[i];
         
    }
}
void logic()
{
int k;
     
    for(int i=0;i<n;i++)
    {
        w[i][i]=q[i];
        c[i][i]=r[i][i]=0;
         
        w[i][i+1]=p[i+1]+q[i+1]+q[i];
        c[i][i+1]=w[i][i+1];
        r[i][i+1]=i+1;
         
    }
        w[n][n]=q[n];
        c[n][n]=r[n][n]=0;
     
     
    for(int m=2;m<=n;m++)
    {
        for(int i=0;i<=n-m;i++)
        {
            j=i+m;
             
            w[i][j]=w[i][j-1]+p[j]+q[j];
             
             k=knuthmin(i,j);
//find minimum value in the range r[i-1][j] to r[i][j-1]               
            c[i][j]=w[i][j]+c[i][k-1]+c[k][j];
            r[i][j]=k;
        }
    }
     
    cout << "::ROOT NODE IS:: " << a[r[0][n]];
    cout << "\nLEFT CHILD OF " << a[r[0][n]] << " is ";
    tree(0, r[0][n] - 1);
    cout << "\nRIGHT CHILD OF" << a[r[0][n]] << " is ";
    tree(r[0][n], n);
}
int knuthmin(int i, int j)
{  
    int min = 999, k, z;
    for (k = r[i][j - 1]; k <= r[i + 1][j]; k++)
    {
        if (min > c[i][k - 1] + c[k][j])
        {
            min = c[i][k - 1] + c[k][j];
            z = k;
        }
    }
    return (z);
}
void tree(int i, int j) {
    if (r[i][j] == 0)
    {
        cout<<" NULL\n";
        return;
    }
     
    cout << " :: " << a[r[i][j]];
     
    cout << "\nLEFT CHILD OF IS  ::" << a[r[i][j]];
     
    tree(i, r[i][j] - 1);
     
    cout << "\nRIGHT CHILD OF IS:: " << a[r[i][j]];
     
    tree(r[i][j], j);
}
}O;
int main()
{  
    O.obstaccept();
    O.logic();
}
