class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        size_t size=nums.size();
        while(k--)
        {
            int a=nums[size-1];
            for(int j=size-2;j>=0;j--)
            {
                //ÒÆ¶¯ÔªËØ
                nums[j+1]=nums[j];
            }
            nums[0]=a;
        }
    }
};
