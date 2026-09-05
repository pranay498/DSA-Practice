class Solution {
public:
    int hIndex(vector<int>& citations) {
         sort(citations.begin(), citations.end());
        int start=0,end=citations.size()-1,n=citations.size();
        while(start<=end)
        {
        int mid=start+(end-start)/2;
        int h=n-mid;
        if(citations[mid]==h)
        return h;
        else if (citations[mid]<=h)
        start=mid+1;
        else
        end=mid-1;
        }
        return n-start;
    }
};