class Solution {
public:
    bool check(int mi,unordered_map<int,int>&mp,string&s, string& p)
    {
        int i=0,j=0,n=s.length(),m=p.length();
        while(i<n && j<m)
        {
            if(mp.find(i)==mp.end())
            {
                if(s[i]==p[j])
                {
                    ++i;
                    ++j;
                }
                else
                {
                    ++i;
                }
            }
            else
            {
                if(mp[i]>mi)
                {
                    if(s[i]==p[j])
                    {
                        ++i;
                        ++j;
                    }
                    else
                    {
                        ++i;
                    }
                }
                else
                {
                    ++i;
                }
            }
        }
        return j==m;
    }
    int maximumRemovals(string s, string p, vector<int>& removable) 
    {
        int ans=-1;
        int i=0;
        int j=removable.size()-1;
        unordered_map<int,int>mp;
        for(int x=0;x<removable.size();++x)
        {
            mp[removable[x]]=x;
        }
        while(i<=j)
        {
            int m=i+(j-i)/2;
            if(check(m,mp,s,p))
            {
                ans=m;
                i=m+1;
            }
            else
            {
                j=m-1;
            }
        }
        return ans+1;
    }
};
