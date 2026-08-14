class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        int nextGreater[10001];
        int st[1000];
        int top = -1;

        for (int num : nums2) {

            while (top >= 0 && num > st[top]) {
                nextGreater[st[top]] = num;
                top--;
            }

            st[++top] = num;
        }

        while (top >= 0) {
            nextGreater[st[top]] = -1;
            top--;
        }

        vector<int> ans;

        for (int num : nums1) {
            ans.push_back(nextGreater[num]);
        }

        return ans;
    }
};