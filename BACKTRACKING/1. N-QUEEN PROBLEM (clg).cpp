#include <iostream>
#include<cmath>
using namespace std;
int x[15];
bool place(int k,int i)
{
    for(int j=1;j<=k-1;j++)
    {
        if((x[j]==i)|(abs(x[j]-i)==abs(j-k)))
        {
            return false;
        }
    }
        return true;
    
}
void nqueen(int k,int n)
{
    for (int i=1;i<=n;i++)
    {
        if(place (k,i))
          { x[k]=i;
        if(k==n)
        {
            for(int i=1;i<=n;i++)
            {
                cout<<x[i];
            }
            cout<<endl;
        }
        else
        nqueen(k+1,n);
    }
}
}
int main()
{
   nqueen(1,8); 

    return 0;
}
