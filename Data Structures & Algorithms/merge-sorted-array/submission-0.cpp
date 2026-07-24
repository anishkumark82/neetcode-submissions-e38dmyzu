class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> L(nums1.begin(), nums1.begin()+m);
        int k = 0;
        int l = 0;
        int r = 0;

        while(l < L.size() && r < nums2.size())
        {
            if(L[l] <= nums2[r])
                nums1[k++] = L[l++];
            else
                nums1[k++] = nums2[r++];
        }

        while(l < L.size())
            nums1[k++] = L[l++];

        while(r < nums2.size())
            nums1[k++] = nums2[r++];
    }
};