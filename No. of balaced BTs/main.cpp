#include<bits/stdc++.h>
using namespace std;


int binaryTreesOfHeightHHelper(int h,int *ans){
  if(h <= 1) {
		return 1;
	}
  if(ans[h-1]!=-1)
    return ans[h-1];

	int mod = (int) (pow(10, 9)) + 7;
	int x = binaryTreesOfHeightHHelper(h - 1,ans);
	int y = binaryTreesOfHeightHHelper(h - 2,ans);

	int temp1 = (int)(((long)(x)*x) % mod);
	int temp2 = (int)((2* (long)(x) * y) % mod);
	int an = (temp1 + temp2) % mod;


	//int ans = (x*x + 2*x*y) % mod;
  ans[h-1]=an;
	return an;
}

//Using memoization
int binaryTreesOfHeightH(int h) {
    // Write your code here
  int *ans=new int[h];
  for(int i=0;i<h;i++){
    ans[i]=-1;
  }
  binaryTreesOfHeightHHelper(h,ans);

}


//Using brute force
int balancedBTs(int h) {
  if(h <= 1) {
		return 1;
	}

	int mod = (int) (pow(10, 9)) + 7;
	int x = balancedBTs(h - 1);
	int y = balancedBTs(h - 2);

	int temp1 = (int)(((long)(x)*x) % mod);
	int temp2 = (int)((2* (long)(x) * y) % mod);
	int ans = (temp1 + temp2) % mod;
	//int ans = (x*x + 2*x*y) % mod;
	return ans;

}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
