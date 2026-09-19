class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int right=0;
        for(int x: piles) {
            if(x>right) right=x;
        }
        int left=1;
        int mid;
        while(left<=right){
            //bas ecase
            
            mid=left+(right-left)/2;

            if(left==right) break;
            
            int total=0;
            for(int x: piles){
                if (x%mid==0) total+=x/mid;
                else total+=(x/mid+1);
            }
            if(total>h) left=mid+1;
            else right=mid;
        }
        return mid;
    }
};
