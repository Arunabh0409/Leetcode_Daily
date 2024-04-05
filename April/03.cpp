// https://leetcode.com/problems/word-search/

class Solution
{
public:
    // mistake : Match the starting letter of WORD initially only ( have a good start always )

    bool check(vector<vector<char>> &board, string word, int x, int y, int index, int r[], int c[], int n, int m, vector<vector<int>> &visited)
    {

        if (index == word.length())
            return true; // got the answer , return true now

        visited[x][y] = 1; // mark the character as true

        for (int i = 0; i < 4; i++)
        {
            int newx = x + r[i];
            int newy = y + c[i];

            if (newx >= 0 && newx < n && newy < m && newy >= 0 && visited[newx][newy] == -1 && board[newx][newy] == word[index])
            {
                // go ahead
                if (check(board, word, newx, newy, index + 1, r, c, n, m, visited))
                    return true;
            }
        }

        visited[x][y] = -1; // backtrack , and explore other paths
        return false;
    }
    bool exist(vector<vector<char>> &board, string word)
    {

        int n = board.size(), m = board[0].size();

        int length = word.length();

        int r[] = {-1, 0, 1, 0};
        int c[] = {0, 1, 0, -1};

        // start from each position in the matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                vector<vector<int>> visited(n, vector<int>(m, -1)); // creating visited 2d array for each point in the matrix
                if (word[0] == board[i][j] && check(board, word, i, j, 1, r, c, n, m, visited))
                    return true;
            }
        }
        return false;
    }
};