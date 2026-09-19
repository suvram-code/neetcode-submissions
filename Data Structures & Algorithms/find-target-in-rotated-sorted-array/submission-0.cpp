class Solution {
public:
    int search(vector<int>& nums, int target) {
        //find minm index
        int start;
        if( nums.front() <= nums. back()) start=0;
        else{
            int left=0;
            int right=nums.size()-1;
            int mid;
            int c=nums[0];

            while(left<=right){
                mid=left +(right-left)/2;
                //bas ecasse
                if(left==right) break;

                if(nums[mid]>=c) left=mid+1;
                else right = mid;

            }
            start=mid;
        }

        int left=start;
        int right=nums.size()-1 + start;
 
        while(left<=right){
            int mid=(left + (right-left)/2) ;
            int val=nums[mid % nums.size()];

            if(val==target) return mid% nums.size();
            else if (val <target) left=mid+1;
            else right=mid-1;
        }
        return -1;

        
        
    }
};
