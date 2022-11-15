#include <bits/stdc++.h>
using namespace std;
int dp[100][100];


int KnapSack(int wt[], int val[], int W, int n){
    if (W == 0 || n == 0) return 0;
    
    if (dp[n][W]!= -1) return dp[n][W];
    if (wt[n-1] <= W){
        return dp[n][W] = max(val[n-1] + KnapSack(wt, val, W-wt[n-1], n-1), KnapSack(wt, val, W, n-1));
    }else{
        return dp[n][W] = KnapSack(wt, val, W, n-1);
    }
}


int main(){
    int wt[] = {2, 1, 3, 2};
    int val[] = {12, 10, 20, 15};
    int W = 5;
    memset(dp, -1, sizeof(dp));
    cout << KnapSack(wt, val, W, 4)<< endl;
    return 0;
}