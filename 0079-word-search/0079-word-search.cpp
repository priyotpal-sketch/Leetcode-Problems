// time complexity will be O(m*n) and sapce complexity will be O(L) where L is size  of recursion stack 
class Solution {
public:
    bool solve(vector<vector<char>>& board, string& word,
               int i, int r, int c) {

        if (i == word.size()) {
            return true;
        }

        if (r < 0 || c < 0 ||
            r >= board.size() || c >= board[0].size() ||
            board[r][c] != word[i]) {
            return false;
        }

        char ch = board[r][c];
        board[r][c] = '#';

        bool found = solve(board, word, i + 1, r + 1, c) ||
                     solve(board, word, i + 1, r - 1, c) ||
                     solve(board, word, i + 1, r, c + 1) ||
                     solve(board, word, i + 1, r, c - 1);

        board[r][c] = ch;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {
                if (solve(board, word, 0, r, c)) {
                    return true;
                }
            }
        }

        return false;
    }
};
