class Solution {
public:

    struct TrieNode {
        int child[26];
        int bestindex, bestlength;
        TrieNode() {
            memset(child, -1, sizeof(child));
            bestindex = -1;
            bestlength = INT_MAX;
        }
    };

    vector<TrieNode> trie;
    Solution() {
        trie.push_back(TrieNode());
    }

    void update(int node, int idx, int len) {
        if (len < trie[node].bestlength) {
            trie[node].bestlength = len;
            trie[node].bestindex = idx;
        } else if (len == trie[node].bestlength && idx < trie[node].bestindex) {
            trie[node].bestindex = idx;
        }
    }

    void insert(string &s, int idx) {
        int node = 0, len = s.size();
        update(node, idx, len);
        for (int i = len - 1; i >= 0; i--) {
            int c = s[i] - 'a';
            if (trie[node].child[c] == -1) {
                trie[node].child[c] = trie.size();
                trie.push_back(TrieNode());
            }
            node = trie[node].child[c];
            update(node, idx, len);
        }
    }

    int query(string &s) {
        int node = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            int c = s[i] - 'a';
            if (trie[node].child[c] == -1) break;
            node = trie[node].child[c];
        }
        return trie[node].bestindex;
    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        vector<int>ans;
        for(int i=0;i<wordsContainer.size();i++) {
            insert(wordsContainer[i],i);
        }
        for(string &p:wordsQuery) {
            ans.push_back(query(p));
        }
        return ans;
    }
};