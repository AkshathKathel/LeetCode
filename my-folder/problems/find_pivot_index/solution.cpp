class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> v2(nums.size(),0);
        int sum = 0,sum2 = 0,a=0;
        int ans = -1;
            for(int i=0;i<nums.size();i++){
                sum+=nums[i];
                sum2+=nums[nums.size()-1-i];
                
                int f = (-1*sum)+v2[i];
                v2[i] = f;
                int b = sum2+v2[nums.size()-1-i];
                
                v2[nums.size()-1-i] = b;

                if(i>=nums.size()-1-i){
                    if(f==0){
                        ans = ans!=-1?min(ans,i):i;
                    }
                    if(b==0){
                        a = nums.size()-1-i;
                        ans = ans!=-1?min(ans,a):a;
                    }
                }


            }
            return ans;
        }
};