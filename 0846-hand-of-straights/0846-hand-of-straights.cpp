class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize){
            return false;
        }
        unordered_map<int,int> mp;

        for(int i = 0;i<n;i++){
            mp[hand[i]]++;
        }

        for(int num : hand){
            if(mp[num] == 0){
                //return false;
                continue;
            }
            int start  = num;
            while(mp[start-1]){
                start--;
            }

            while(start<=num){
                while(mp[start]){
                    for(int j = start; j< start + groupSize; j++){
                        if(mp[j]==0){
                            return false;
                        }
                        mp[j]--;
                    }
                }
                start++;     
           }


        }
        return true;
    }
};