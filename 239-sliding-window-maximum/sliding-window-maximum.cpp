class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        vector<int> res;
        deque<int> dq;

        for (int i = 0; i < a.size(); i++) {
            while (!dq.empty() && a[dq.back()] < a[i]) dq.pop_back();
            dq.push_back(i);
            if (!dq.empty() && dq.front() <= i - k) dq.pop_front();
            if (i >= k - 1) res.push_back(a[dq.front()]);
        }

        return res;
    }
};