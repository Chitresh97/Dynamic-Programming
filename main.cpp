#include <iostream>
#include <limits.h>

using namespace std;

int helperCountStepsTo1(int n, int * arr){
  if(n<=1)
    return 0;

  if(arr[n]!=-1)
    return arr[n];

  int n1=helperCountStepsTo1(n-1,arr);
  int n2=INT_MAX, n3=INT_MAX;


  if(n%2==0){
    n2=helperCountStepsTo1(n/2,arr);
  }

 if(n%3==0){
    n3=helperCountStepsTo1(n/3,arr);
  }

  int output= min(n1,min(n2,n3)) + 1;
  arr[n]=output;
  return output;
}

//Using memoization
int countStepsTo1M(int n){
  int *arr = new int[n+1];
  for(int i=0;i<=n;i++){
    arr[i]=-1;
  }
  return helperCountStepsTo1(n,arr) ;

}


//Using brute force
int countStepsTo1(int n){

  if(n==1)
    return 0;

  int n1=countStepsTo1(n-1);
  int n2=(n%2==0)?countStepsTo1(n/2):INT_MAX;
  int n3=(n%3==0)?countStepsTo1(n/3):INT_MAX;

  return min(n1,min(n2,n3))+1;
}

int main()
{
    countStepsTo1(4);
    return 0;
}
