class MinIdx_Segtree {
public:
    int n;
    const int INF = 1e9;
    vector<int> A;
    vector<int> tree;
    MinIdx_Segtree(int N, vector<int>& a) {
        this->n = N;
        this->A = a;
        while (__builtin_popcount(n) != 1) {
            A.push_back(INF);
            n++;
        }
        tree.resize(2 * n);
        build();
    }

    void build() {
        for (int i = 0; i < n; i++) {
            tree[n + i] = i;
        }
        for (int j = n - 1; j >= 1; j--) {
            int a = tree[j<<1];
            int b = tree[(j<<1) + 1];
            if(A[a]<=A[b])tree[j]=a;
            else tree[j] = b;
        }
    }

    void update(int i, int val) {
        A[i] = val;
        for (int j = (n + i) >> 1; j >= 1; j >>= 1) {
            int a = tree[j<<1];
            int b = tree[(j<<1) + 1];
            if(A[a]<=A[b])tree[j]=a;
            else tree[j] = b;
        }
    }

    int query(int ql, int qh) {
        return query(1, 0, n - 1, ql, qh);
    }

    int query(int node, int l, int h, int ql, int qh) {
        if (ql > h || qh < l) return INF;
        if (l >= ql && h <= qh) return tree[node];
        int a = query(node << 1, l, (l + h) >> 1, ql, qh);
        int b = query((node << 1) + 1, ((l + h) >> 1) + 1, h, ql, qh);
        if(a==INF)return b;
        if(b==INF)return a;
        return A[a]<=A[b]?a:b;
    }
};

class Solution {
public:
    int getMaxArea(vector<int>& heights, int l, int r, MinIdx_Segtree& st) {
        if (l > r) return 0;
        if (l == r) return heights[l];

        int minIdx = st.query(l, r);
        return max(max(getMaxArea(heights, l, minIdx - 1, st),
                   getMaxArea(heights, minIdx + 1, r, st)),
                   (r - l + 1) * heights[minIdx]);
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        MinIdx_Segtree st(n, heights);
        return getMaxArea(heights, 0, n - 1, st);
    }
};