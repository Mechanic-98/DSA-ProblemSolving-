#include <vector>
#include <stack>
using namespace std;


/*
Brute force: calculate max on the left and max on the right for every element,
             minimum among max on the left and max on the right,
             diff between min(maxL, maxR) - height[i]... this diff would be the height of water
             above the tower.

             Add these differences.

             TC: O(3N) SC: O(2N)
*/

int trap1(vector<int> &height) {
        int n = height.size();
        int maxL[n];
        int maxR[n];
        int ans = 0;
        
        // max on the left
        maxL[0] = height[0];
        for(int i=1; i<n; i++) {
            maxL[i] = max(maxL[i-1],height[i]);
        }
        
        // max on the right
        maxR[n-1] = height[n-1];
        for(int i = n-2; i>=0; i--){
            maxR[i] = max( maxR[i+1], height[i] );
        }
        
        for(int i=0; i<n; i++){
            ans += min( maxL[i], maxR[i] ) - height[i];
        }
        
        return ans;
}

// Two pointer approach TC: O(N) SC: O(1)
int trap2(vector<int> &height){
    int n = height.size(), l=0, r=n-1, res=0, lmax = 0, rmax = 0;
    while(l <= r){
        if(height[l] <= height[r]){  // to make sure there'll be a larger or equal block at right
            if(height[l] >= lmax) lmax = height[l];
            else res += lmax - height[l];
            l++;
        } else { // it's guaranted that there'll be no more larger block at left
            if(height[r] >= rmax) rmax = height[r];
            else res += rmax - height[r];
            r--;
        }
    } 
    return res;
}

// Stack approach

int trap3(vector<int> &height) {
    stack<int> st;
    int ans = 0;
    for(int i = 0; i<height.size(); i++){
        /*
        Till stack is decreasing there'll be no water stored, so just push ele in stack.
        Once decreasing patter breaks, we'll find out water stored above st.top() block.
        */
        while(!st.empty() && height[st.top()] < height[i]){
            int curr = st.top();
            st.pop();
            if(st.empty()){break;}
            int diff = i - st.top() - 1;
            ans += (min(height[st.top()], height[i]) - height[curr]) * diff;
        }
        st.push(i);            
    }
    return ans;
}