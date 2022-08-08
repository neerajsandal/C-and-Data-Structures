#include<iostream>
#include<cmath>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int case1 = 0;
    int *out = new int[n];
    for(int i = 0; i < n; i++)
    	out[i] = 0;
    
	int n1 = n;	
    while(n!=0)
    {
        int x; cin >> x;
        int count = 1;
        int *arr = new int[x];
        for(int i = 0; i < x; i++)
        {
            cin >> arr[i];
        }
        
        if(arr[0] > arr[x-1])
        {
        	int	ans = arr[x-1];
        	arr[x-1] = arr[0];
        	arr[0] = ans;
		}
		sort(arr+1, arr+x);
        for(int i = 0; i < x; i++)
        {
        	cout << arr[i] << " ";
		}
		cout << endl;
		int ans = arr[0];
        for(int i = 1; i < x; i++)
        {
            if(ans <= arr[i])
            {
            //	cout << ans << " ";
                count++;
                ans = arr[i];
            }
        }
  //      cout << endl;
        out[case1] = count;
        case1++;
        n--;
    }
    
    for(int i = 0; i < n1; i++)
    {
    	cout << "Case #" << i+1 <<": "<<out[i] << endl;
	}
}

// 9 4 382 72 62 27 53 1
