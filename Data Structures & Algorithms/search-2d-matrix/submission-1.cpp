class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int start=0;
        int end=rows*cols-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            int r=mid/cols;
            int c=mid%cols;
            int val=matrix[r][c];
            if(val==target) return true;
            else if(val<target) start=mid+1;
            else if(target<val) end=mid-1;
        }
        return false;
    }
};
