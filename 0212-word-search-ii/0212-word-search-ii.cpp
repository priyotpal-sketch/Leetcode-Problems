// this is my brute force approach idea with a time complexity of O(K*m*n) where k is number of words and space complexity will be O(L) ,where L is size of recursion stack 
// class Solution {
// public:
//     bool solve(vector<vector<char>>& board, string& word,
//                int i, int r, int c) {

//         if (i == word.size()) {
//             return true;
//         }

//         if (r < 0 || c < 0 ||
//             r >= board.size() || c >= board[0].size() ||
//             board[r][c] != word[i]) {
//             return false;
//         }

//         char ch = board[r][c];
//         board[r][c] = '#';

//         bool found = solve(board, word, i + 1, r + 1, c) ||
//                      solve(board, word, i + 1, r - 1, c) ||
//                      solve(board, word, i + 1, r, c + 1) ||
//                      solve(board, word, i + 1, r, c - 1);

//         board[r][c] = ch;

//         return found;
//     }

//     bool exist(vector<vector<char>>& board, string& word) {
//         for (int r = 0; r < board.size(); r++) {
//             for (int c = 0; c < board[0].size(); c++) {
//                 if (solve(board, word, 0, r, c)) {
//                     return true;
//                 }
//             }
//         }

//         return false;
//     }

//     vector<string> findWords(vector<vector<char>>& board,
//                              vector<string>& words) {
//         vector<string> ans;

//         for (int i = 0; i < words.size(); i++) {
//             if (exist(board, words[i])) {
//                 ans.push_back(words[i]);
//             }
//         }

//         return ans;
//     }
// };
// this is gpt solution which used trie concept that I have'nt read yet but I will 
class TrieNode {
public:
    TrieNode* children[26];
    string word;

    TrieNode() {
        word = "";

        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Solution {
public:
    TrieNode* root = new TrieNode();

    // Insert every word into the Trie
    void insert(string& word) {
        TrieNode* node = root;

        for (int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';

            if (node->children[idx] == nullptr) {
                node->children[idx] = new TrieNode();
            }

            node = node->children[idx];
        }

        node->word = word;
    }

    // Search the board using DFS
    void dfs(vector<vector<char>>& board, int r, int c,
             TrieNode* node, vector<string>& ans) {

        if (r < 0 || c < 0 ||
            r >= board.size() || c >= board[0].size()) {
            return;
        }

        if (board[r][c] == '#') {
            return;
        }

        int idx = board[r][c] - 'a';

        if (node->children[idx] == nullptr) {
            return;
        }

        node = node->children[idx];

        // A complete word has been found
        if (node->word != "") {
            ans.push_back(node->word);
            node->word = "";
        }

        char ch = board[r][c];
        board[r][c] = '#';

        dfs(board, r + 1, c, node, ans);
        dfs(board, r - 1, c, node, ans);
        dfs(board, r, c + 1, node, ans);
        dfs(board, r, c - 1, node, ans);

        board[r][c] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        for (int i = 0; i < words.size(); i++) {
            insert(words[i]);
        }

        vector<string> ans;

        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {
                dfs(board, r, c, root, ans);
            }
        }

        return ans;
    }
};
