class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int, vector<int> , greater<int>> p;

        for(int x : nums){
            if(p.size()==k){
                if(p.top() < x){
                    p.pop();
                    p.push(x);
                }
            }
            else p.push(x);
        }

        return p.top();
    }
};
