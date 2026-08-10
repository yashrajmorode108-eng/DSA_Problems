class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        // sort(nums1.begin(),nums1.end());
        // sort(nums2.begin(),nums2.end());

        priority_queue<pair<long long, pair<int,int>>,vector<pair<long long, pair<int,int>>>, greater<pair<long long, pair<int,int>>>> pq;
        set<pair<int,int>> visited;

        pq.push({nums1[0] + nums2[0] , {0,0}});
        visited.insert({0,0});

       vector<vector<int>> result;
       if(n==0 || k==0 || m == 0) return result;
        while(k-- > 0 && !pq.empty()){
            auto current = pq.top();
            pq.pop();
            long long largest_sum = current.first;
            int i_th = current.second.first;
            int j_th = current.second.second;
            
            result.push_back({nums1[i_th], nums2[j_th]});

            if(i_th + 1 < n && visited.find({i_th + 1,j_th}) == visited.end() ){
                pq.push({(long long)nums1[i_th+1] +  nums2[j_th],{i_th +1, j_th}});
                visited.insert({i_th +1, j_th});
            }

            
            if(j_th + 1 < m && visited.find({i_th,j_th+1}) == visited.end() ){
                pq.push({nums1[i_th] +  nums2[j_th + 1],{i_th, j_th + 1}});
                visited.insert({i_th , j_th + 1});
            }
        }
        return result;
    }
};