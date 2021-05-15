
#include <iostream>

using namespace std;

void read(float a[][100],float b[],int n);
void print(float a[][100],float b[],int n);
void mul(float a[][100],float b[],int n,int i,int j,float t);
int main()
{
    int n,k;
    cout<<"enter size of matrix : ";
    cin>>n;
    cout<<endl;
    float a[100][100],b[n],sum=0.0,s,x[n];
    float t;
    read(a,b,n);
    print(a,b,n);

    for(int j=0;j<n;j++)
    {
        for(int i=j+1;i<n;i++)
        {
            if(a[i][j]!=0)
            {
                t=(((-1)*a[i][j])*1.0)/a[j][j];
                mul(a,b,n,i,j,t);
            }

        }
    }

    print(a,b,n);

    for(int i=0;i<n;i++)
    {
        x[i]=1;
    }

    for(int i=n-1;i!=-1;i--)
    {
        sum=0.0;
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            {

                a[i][j]=a[i][j]*x[j];
                sum+=a[i][j];
            }
            else
            {
                s=a[i][j];
            }
        }
        x[i]=(b[i]-sum)/s;
    }

    k=1;
    for(int i=0;i<n;i++)
    {
       cout<<'X'<<k<<" = "<<x[i]<<endl;
       k++;
    }

    return 0;
}





void read(float a[][100],float b[],int n)
{
    cout<<"{ Enter elements of matrix }"<<endl<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
         cout<<"Matrix"<<"["<<i<<"]"<<"["<<j<<"]"<<"=";
         cin>>a[i][j];
        }
        cout<<"b["<<i<<']'<<"=";
        cin>>b[i];
        cout<<endl;
    }

}



void print(float a[][100],float b[],int n)
{
    cout<<"The matrix you have entered is:"<<endl<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"  |  ";
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<"  ";
        }
        cout<<"   | "<<b[i]<<" |";
        cout<<endl;
        cout<<endl;

    }


}



void mul(float a[][100],float b[],int n,int i,int j,float t)
{
    float x;
    x=t*b[j];
    b[i]=b[i]+x;
    for(int k=0;k<n;k++)
    {
        x=t*a[j][k];
        a[i][k]=a[i][k]+x;
    }

}

