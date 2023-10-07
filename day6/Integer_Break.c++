#define ll long long

class Solution {
public:
    int integerBreak(int n) {
        if(n<=3) return n-1;
        
        vector<vector<ll>> dp(n+1,vector<ll>(n+1, 1));
        
        for(int i=2;i<=n;i++){
            for(int j=1;j<= n;j++){
                
                ll pro= INT_MIN;
                if(j<=i){
                    pro= dp[i-j][j]*j ;
                }
                dp[i][j]= max(pro, dp[i][j-1]);
            }
        }
        

        return dp[n][n];
    }
};
