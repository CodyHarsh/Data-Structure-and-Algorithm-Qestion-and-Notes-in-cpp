int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(int i=0;i<nums.size();i++)
        st.insert(nums[i]);
        int maxi=0;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(st.find(nums[i]-1)!=st.end())
            continue;
            else{
                int num=nums[i];
                maxi=1;
                while(st.find(num+1)!=st.end())
                {
                    maxi++;
                    num++;
                }
            }
            ans=max(ans,maxi);
        }
        return ans;
