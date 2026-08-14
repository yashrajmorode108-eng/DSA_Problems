class Solution {
public:
    int count_pairs(vector<int> &nums, int low, int mid, int high){
        int left = low;
        int right = mid+1;
        int count = 0;
        for(int i =low;i<=mid;i++){
            while(right <= high && 1LL*nums[i] > 2*1LL*nums[right]){
                right++;
            }
            count += (right - (mid+1));
        }
        return count;
    }
    
    void merge(vector<int> &nums, int low, int mid, int high){
        int left = low;
        int right = mid + 1;
        vector<int> temp;
        while(left<=mid && right <= high){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left]);
                left++;
            }else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right <= high){
            temp.push_back(nums[right]);
            right++;
        }
        for(int i = low;i<=high;i++){
            nums[i] =temp[i-low];
        }
        return;
    }

    int merge_sort(vector<int> &nums, int low, int high){
        if(low>=high) return 0;
        int mid = low + (high - low)/2;
        int ans = 0;
        ans += merge_sort(nums,low,mid);
        ans += merge_sort(nums,mid+1,high);
        ans += count_pairs(nums,low,mid,high);
        merge(nums,low,mid,high);
        return ans;
    }
    int reversePairs(vector<int>& nums) {
        return merge_sort(nums,0,nums.size()-1);
    }
};