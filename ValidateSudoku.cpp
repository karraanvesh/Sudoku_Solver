// Time Complexity : O(2 * (n * n))
// Space Complexity : O(2 * n * n)
// where n = size of the grid i.e., 9

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();

        vector<vector<int>> row(9 , vector<int>(10 , 0)) , col(9 , vector<int>(10,0));

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - '0';

                    if(row[i][num] or col[j][num]) return false;

                    row[i][num] = col[j][num] = 1;
                }
            }
        }

        int boxRow , boxCol;
        boxRow = boxCol = 0;

        while(boxRow <= 6)
        {
            int n = boxRow + 2;
            int m = boxCol + 2;

            vector<int> box(10 , 0);

            for(int i = boxRow ; i <= n ; i++)
            {
                for(int j = boxCol ; j <= m ; j++)
                {
                    if(board[i][j] != '.')
                    {
                        int num = board[i][j] - '0';

                        if(box[num] == 1) return false;

                        box[num] = 1;
                    }
                }
            }

            boxCol = (boxCol + 3)%9;

            if(boxCol == 0)
            boxRow += 3;
        }

        return true;

    }
};


int main(){
    vector<vector<char>> board(9);

    for(int i = 0 ; i < 9 ; i++){
        for(int j = 0 ; j < 9 ; j++){
            char ch;
            cin >> ch;
            board[i].push_back(ch);
        }
    }

    Solution obj;
    cout << obj.isValidSudoku(board) << endl;

    return 0;
}