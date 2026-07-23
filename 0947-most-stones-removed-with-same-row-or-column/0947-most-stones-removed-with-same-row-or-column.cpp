class disjointset{
public: 
  vector<int> parent, size;
  disjointset(int n){
    parent.resize(n);
    size.resize(n);

    for(int i =0;i<n;i++){
        parent[i] = i;
        size[i] = 1;

    }
  }

    int findparent(int a){
        if(a ==parent[a]) return a;
        return parent[a] = findparent(parent[a]);
    }

    void unionbysize(int a, int b){
        int pa = findparent(a);
        int pb = findparent(b);

        if(pa==pb) return;
        if(size[pa]< size[pb]){
            size[pb] += size[pa];
            parent[pa] = pb;
        }else{
            size[pa] += size[pb];
            parent[pb] = pa;
        }
    }
  };
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        //find maxrow and maxcol
        int maxrow = 0;
        int maxcol = 0;
        int n = stones.size();
        for(auto it : stones){
            maxrow = max(maxrow,it[0]);
            maxcol = max(maxcol,it[1]);
        }

        disjointset ds(maxrow + maxcol + 2);
        unordered_map<int,int> stonenodes;

        for(auto it : stones){
            int row = it[0];
            int col = maxrow + it[1] + 1;

            ds.unionbysize(row,col);
            stonenodes[row] = 1;
            stonenodes[col] = 1;
        }
        int cnt = 0;
        for(auto it : stonenodes){
            if(ds.findparent(it.first)== it.first){
                cnt++;
            }
        }
        return n - cnt;
    }
};