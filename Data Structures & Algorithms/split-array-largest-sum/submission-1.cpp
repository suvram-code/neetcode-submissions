class Solution {
public:
    int splitArray(vector<int>& nums, int k) {

        int min=0;
        int max=0;
        for(int x: nums){
            if (x>min) min=x;
            max+=x;
        }

        int mid;
        while(min<=max){
            mid=min+(max-min)/2;

            //base case
            if(min==max) break;

            int t=1;
            int total=0;

            for(int x: nums){
                if(total+x>mid){
                    t++;
                    total=0;
                }
                total+=x;
            }
            if(t>k) min=mid+1;
            else max=mid;

        }
        return mid;
        
    }
};