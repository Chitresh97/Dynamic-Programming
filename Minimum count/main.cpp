#include<bits/stdc++.h>
using namespace std;

int minCountHelper(int n, int*ans){
  if(n<=1)
    return n;
  if(ans[n-1]!=-1)
    return ans[n-1];

  int s=sqrt(n);
  int *arr=new int[s];

  for(int i=0;i<s;i++){
    arr[i]=1+minCountHelper(n-pow((i+1),2),ans);
  }
  int min=*min_element(arr,arr+s);
  ans[n-1]=min;
  return min;
}
int minCount(int n){

  int *ans=new int[n];
  for(int i=0;i<n;i++){
    ans[i]=-1;
  }
  return minCountHelper(n,ans);
}

int main()
{
    cout <<minCount(101) << endl;
    return 0;
}
