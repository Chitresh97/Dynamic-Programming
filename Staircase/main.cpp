#include <iostream>

using namespace std;
//Using brute force
long staircase(int n){

  if(n==0||n==1){
    return 1;
  }
  if(n==2)
    return 2;
  if(n==3){
    return 4;
  }
  else
    return staircase(n-1)+staircase(n-2)+staircase(n-3);
}

int main()
{

}
