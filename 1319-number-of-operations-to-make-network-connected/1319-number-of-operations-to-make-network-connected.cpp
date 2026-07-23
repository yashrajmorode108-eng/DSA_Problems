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
        if(a == parent[a]) return a;
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        disjointset ds(n);
        int extra = 0;
        int nc = 0;
        for(auto it : connections){
            int u = it[0];
            int v = it[1];

            if(ds.findparent(u) == ds.findparent(v) ){
                extra++;
            }else{
                ds.unionbysize(u,v);
            }

        }

        for(int i = 0;i<n;i++){
            if(ds.parent[i] == i){
                nc++;
            }
        }
        int ans = nc -1;
        if(extra >= ans) return ans;
        return -1;
    }
};

