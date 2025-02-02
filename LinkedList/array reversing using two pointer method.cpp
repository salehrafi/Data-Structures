// array reversing using two pointer method

#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n=6;
    int arr[n] = {1,2,3,4,5,6};
    
    int i=0,j=n-1;
    while(i<=j){
        swap(arr[i],arr[j]);
        i++;j--;
    }
    for(auto x:arr){
        cout << x << " ";
    }cout << '\n';
    
    return 0;
}
