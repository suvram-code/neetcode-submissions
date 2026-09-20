class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        //find endpoints
        int c=nums.front();
        
        int p2; //endpoint form  right end
        if(c!=nums.back()) p2=0;
        else {
            p2=n-1;
            while(p2>=1 && nums[p2-1]==c) p2--;
            if(p2>=1 && nums[p2-1]==target) return true;
           

            /*int right=n-1;
            int left=0;
            while(left<=right){
                p2=left+(right-left)/2;
                //ba ecase
                if(left==right) break;
                if(nums[p2]!=c) left=p2+1;
                else right=p2;
            }
             cout<<p2<<"\n";
            if(p2==0){ //jumped to wrogng 
                int p1;//ep from left end
                int left=0;
                int right=n-1;
                while(left<=right){
                    p1=left+(right-left)/2;
                    if(left==right) break;

                    if(nums[p1]!=c) right=p1-1;
                    else {
                        if(right-left==1){
                            p1++;
                            break;
                        }
                        left=p1;
                    }
                }

                if(p1==n-1){ //singular value
                    if(target==c) return true;
                    else return false; 
                }
                else{
                    left=p1+1;
                    right=n-1;
                    while(left<=right){
                        p2=left+(right-left)/2;
                        if(left==right) break;

                        if(nums[p2]!=c) left=p2+1;
                        else right=p2;
                    }
                }

            }
            cout<<p2<<"\n";*/
        }

        bool sorted;
        int start;
        if(nums[p2]<nums[((p2-1)%n +n)%n]) {sorted =true;start=p2;}
        else{
            sorted =false;
            int left=0;
            int right=((p2-1)%n + n)%n;
            while(left<=right){
                start=left+(right-left)/2;
                if(left==right) break;

                if(nums[start]>=c) left=start+1;
                else right=start;
            }

        }

        int left=start;
        int right=nums.size()-1 + start;
 
        while(left<=right){
            int mid=(left + (right-left)/2) ;
            int val=nums[mid % nums.size()];

            if(val==target) return true;
            //else if(left==right)  break;
            else if (val <target) left=mid+1;
            else right=mid-1;
        }
        return false;

    }
};