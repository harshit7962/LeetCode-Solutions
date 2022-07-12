class Solution {
public:
                      /// Very Good Problem ///
    int dp[16][32768];
    bool solve(vector<int> &ms, int &sum, int curr, int  cnt, int mask)
    {
        
        if(mask == (1<<ms.size())-1)
        {
            //cout<<cnt<<endl;
            if(cnt==4)
               return true;
            else
               return false;
        }
        
        if(cnt>4)
            return false;
        
        if(dp[cnt][mask]!=-1)
            return dp[cnt][mask];
        
        bool f=false;
        for(int i=0;i<ms.size();i++)
        {
            if((mask & (1<<i))==0)
            {
                mask = mask ^ (1<<i);
                if(curr+ms[i]<sum)
                {
                    f = f || solve(ms,sum,curr+ms[i],cnt,mask);
                }
                else if(curr+ms[i]==sum)
                {
                    //cout<<i<<" "<<cnt<<endl;
                    f = f || solve(ms,sum,0,cnt+1,mask);
                }
                mask = mask ^ (1<<i);
            }
        }
        
        return dp[cnt][mask]=f;
    }
    
    bool makesquare(vector<int>& ms) {
        int sum=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<ms.size();i++)
        {
            sum += ms[i];
        }
        //cout<<sum<<endl;
        if(sum%4!=0)
            return false;
        sum = sum/4;
        int mask=0;
        return solve(ms, sum, 0, 0, mask);
    }
};