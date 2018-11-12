#include <iostream>

using namespace std;
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
