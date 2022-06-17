#include<iostream>
using namespace std;

int main(){
    int n,a[1000000],sum=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        sum=sum+a[i];
    }
    cout<<sum<<endl;
    return 0;
}

/*
Sample Input :
3
9 8 9
Sample Output :
26
*/
