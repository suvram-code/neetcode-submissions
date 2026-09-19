class Solution {
public:
    int findMin(vector<int> &nums) {

        if( nums.front() <= nums. back()) return nums.front();

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
        return nums[mid];
    }
};
