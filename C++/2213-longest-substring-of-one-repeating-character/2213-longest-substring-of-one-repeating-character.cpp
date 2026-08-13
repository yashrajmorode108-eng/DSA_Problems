class Solution {
    struct Node {
        int len = 0;
        int prefix = 0;
        int suffix = 0;
        int best = 0;
        char leftChar = 0;
        char rightChar = 0;
    };

    vector<Node> tree;

    Node mergeNodes(const Node& left, const Node& right) {
        if (left.len == 0) return right;
        if (right.len == 0) return left;

        Node res;

        res.len = left.len + right.len;
        res.leftChar = left.leftChar;
        res.rightChar = right.rightChar;

        res.prefix = left.prefix;
        res.suffix = right.suffix;
        res.best = max(left.best, right.best);

        if (left.rightChar == right.leftChar) {
            res.best = max(res.best, left.suffix + right.prefix);

            if (left.prefix == left.len)
                res.prefix = left.len + right.prefix;

            if (right.suffix == right.len)
                res.suffix = right.len + left.suffix;
        }

        return res;
    }

    void build(int node, int start, int end, const string& s) {
        if (start == end) {
            tree[node] = {1, 1, 1, 1, s[start], s[start]};
            return;
        }

        int mid = start + (end - start) / 2;

        build(2 * node, start, mid, s);
        build(2 * node + 1, mid + 1, end, s);

        tree[node] = mergeNodes(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int index, char ch) {
        if (start == end) {
            tree[node] = {1, 1, 1, 1, ch, ch};
            return;
        }

        int mid = start + (end - start) / 2;

        if (index <= mid)
            update(2 * node, start, mid, index, ch);
        else
            update(2 * node + 1, mid + 1, end, index, ch);

        tree[node] = mergeNodes(tree[2 * node], tree[2 * node + 1]);
    }

public:
    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        int n = s.size();
        int q = queryIndices.size();

        tree.resize(4 * n);
        build(1, 0, n - 1, s);

        vector<int> ans;
        ans.reserve(q);

        for (int i = 0; i < q; i++) {
            int index = queryIndices[i];
            char ch = queryCharacters[i];

            if (s[index] != ch) {
                s[index] = ch;
                update(1, 0, n - 1, index, ch);
            }

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};