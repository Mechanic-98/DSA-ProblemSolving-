#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    // 1. Brute Force
    
//     void setZeroes(vector<vector<int>>& matrix) {
//         int m = matrix.size();
//         int n = matrix[0].size();
        
//         vector<pair<int,int>> v;
//         for(int i=0; i<m; i++){            // O(m x n)
//             for(int j = 0; j<n; j++){
//                 if(matrix[i][j] == 0){
//                     v.push_back({i,j});
//                 }
//             }
//         }
        
//         for(auto ele: v){                    // O(N x (m+n))
//             for(int i=0; i<n; i++){
//                 matrix[ele.first][i] = 0;
//             }
//             for(int j=0; j<m; j++){
//                 matrix[j][ele.second] = 0;
//             }
//         }
//     }
    
    // 2. Optimised Approach
    void setZeroes(vector< vector<int> >& matrix) {       //O(2(m x n))
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> row (n,-1);
        vector<int> col (m,-1);
    
        for(int i=0; i<m; i++){          // O(m x n)
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0) {
                    row[j] = 0;
                 col[i] = 0;
                }
            }
        }
    
        for(int i=0; i<m; i++){            // O(m x n)
            for(int j=0; j<n; j++){
                if(row[j] == 0 || col[i] == 0){
                 matrix[i][j] = 0;
             }
            }
        }
    }
    
};

int main() {
    Solution sol;
    vector< vector<int> > inputVector;
    inputVector = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    sol.setZeroes(inputVector);
    int m = inputVector.size();
    int n = inputVector[0].size();
    for(int i=0; i<m; i++){
        cout<<"[";
        for(int j=0; j<n; j++){
            cout<<inputVector[i][j]<<" ";
        }
        cout<<"]"<<endl;
    }
}