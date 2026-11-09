
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> busy;

        for (int i = 0; i < k; i++) {
            available.insert(i);
        }

        vector<int> count(k, 0);

        for (int i = 0; i < arrival.size(); i++) {
            int time = arrival[i];

            while (!busy.empty() && busy.top().first <= time) {
                available.insert(busy.top().second);
                busy.pop();
            }

            if (available.empty()) continue;

            int server = i % k;
            auto it = available.lower_bound(server);

            if (it == available.end()) {
                it = available.begin();
            }

            server = *it;
            available.erase(it);

            count[server]++;
            busy.push({time + load[i], server});
        }

        int mx = *max_element(count.begin(), count.end());

        vector<int> ans;
        for (int i = 0; i < k; i++) {
            if (count[i] == mx) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
