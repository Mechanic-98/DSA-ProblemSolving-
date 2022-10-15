#include <cmath>

// Brute force
int balancedBTs(int n) {
    if(n <= 1) return 1;
    
    int mod = (int) (pow(10, 9)) + 7;
    
    int possibleHeight1 = balancedBTs(n-1);  
    int possibleHeight2 = balancedBTs(n-2);  
    
    // subtrees of height (n-1) at both sides.
    int tempStorageVar1 = (int)(( (long)(possibleHeight1) *possibleHeight1) % mod); 

    // subtrees of height (n-2) at one end and (n-1) at other and vice-versa.
    int tempStorageVar2 = (int)((2* (long)(possibleHeight1) *possibleHeight2) % mod); 
    
    int ans = (tempStorageVar1 + tempStorageVar2) % mod;
    
    return ans;
}

// Memoization

int balancedBTs2(int n, int * ans){
    if(n <= 1) return 1;

    int mod = (int) (pow(10, 9)) + 7;

    if(ans[n] != -1) return ans[n];

    int possibleHeight1 = balancedBTs2(n-1, ans);  
    int possibleHeight2 = balancedBTs2(n-2, ans);  
    
    // subtrees of height (n-1) at both sides.
    int tempStorageVar1 = (int)(( (long)(possibleHeight1) *possibleHeight1) % mod); 

    // subtrees of height (n-2) at one end and (n-1) at other and vice-versa.
    int tempStorageVar2 = (int)((2* (long)(possibleHeight1) *possibleHeight2) % mod); 
    
    int answer =  (tempStorageVar1 + tempStorageVar2) % mod;
    ans[n] = answer;

    return ans[n];    
}

int balancedBTs2(int n){
    int * ans = new int[n+1];
    for(int i=0; i<n; i++){
        ans[i] = -1;
    }

    return balancedBTs2(n, ans);
}

// DP

int balancedBTs3(int n){
    int * ans = new int[n+1];
    ans[0] = 1;
    ans[1] = 1;

    int mod = (int) (pow(10, 9)) + 7;

    for(int i=2; i<=n; i++){
        // subtrees of height (n-1) at both sides.
        int tempStorageVar1 = (int)(( (long)(ans[i-1]) * ans[i-1]) % mod); 

        // subtrees of height (n-2) at one end and (n-1) at other and vice-versa.
        int tempStorageVar2 = (int)((2* (long)(ans[i-1]) * ans[i-2]) % mod); 

        ans[i] = (tempStorageVar1 + tempStorageVar2) % mod;
    }

    return ans[n];
}