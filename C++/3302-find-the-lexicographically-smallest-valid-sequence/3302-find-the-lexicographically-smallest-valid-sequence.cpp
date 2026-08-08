class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
       int n = word1.size();
       int m = word2.size();
       int j = m-1;
       vector<int> suffix(m,-1);
       for(int i = n-1;i >=0 && j>=0 ; i--){
        if(word1[i] == word2[j]){
            suffix[j] = i;
            j--;
        }
       }
       bool mismatch = false;
       int  i = 0;
       vector<int> ans;
       for(int k = 0;k<m;k++){
          while(i<n){
            if(word1[i] == word2[k]){
                ans.push_back(i);
                i++;
                break;
            }

            if(!mismatch){
                bool ispossible = (k== m-1) ||(suffix[k+1] != -1 && suffix[k+1]>i);

                if(ispossible){
                    ans.push_back(i);
                    mismatch = true;
                    i++;
                    break;
                }
            }
             i++;

        }
        if((int)ans.size() != k+1){
            return {};
        }
       }
       return ans;
    }
};