#include<bits/stdc++.h>
using namespace std;

class Solution {
    private :
    bool checkDiagonal(int i , int j , int n , vector<vector<char>> &board , int num)
    {
        map<pair<int,int> , pair<int,int>> arr;

        arr.insert({{0,0} , {2,2}});
        arr.insert({{0,3} , {2,5}});
        arr.insert({{0,6} , {2,8}});
        arr.insert({{3,0} , {5,2}});
        arr.insert({{3,3} , {5,5}});
        arr.insert({{3,6} , {5,8}});
        arr.insert({{6,0} , {8,2}});
        arr.insert({{6,3} , {8,5}});
        arr.insert({{6,6} , {8,8}});

        map<pair<int,int> , pair<int,int>> :: iterator itr;

        for(itr = arr.begin() ; itr != arr.end() ; itr++)
        {
            pair<int,int> p1 , p2;
            p1 = itr->first;
            p2 = itr->second;

            int r1 , c1 , r2 , c2;
            r1 = p1.first;
            c1 = p1.second;
            r2 = p2.first;
            c2 = p2.second;

            if(i >= r1 and i <= r2 and j >= c1 and j <= c2)
            {
                for(int a = r1 ; a <= r2 ; a++)
                {
                    for(int b = c1 ; b <= c2 ; b++)
                    {
                        if(board[a][b] - '0' == num)
                        return false;
                    }
                }
                break;
            }
        }

        return true;
        
    }
    bool isValid(int i , int j , int n , vector<vector<char>> &board , vector<vector<bool>> &row , vector<vector<bool>> &col , int num)
    {
        return (row[i][num] == false and col[j][num] == false and checkDiagonal(i , j , n , board , num));
    }
    bool solve(int i , int j , int n , vector<vector<char>> &board , vector<vector<bool>> &row , vector<vector<bool>> &col)
    {
        if(i == n)
        {
            return true;
        }

        if(board[i][j] != '.'){
            int new_row = i;
            int new_col = (j + 1)%9;

            if(new_col == 0)
            new_row++;

            return solve(new_row , new_col , n , board , row , col);
        }

        for(int num = 1 ; num <= 9 ; num++)
        {
            if(isValid(i , j , n , board , row , col , num))
            {
                board[i][j] = '0' + num;
                row[i][num] = true;
                col[j][num] = true;

                int new_row = i;
                int new_col = (j + 1)%9;

                if(new_col == 0)
                new_row++;

                if(solve(new_row , new_col , n , board , row , col))
                return true;

                board[i][j] = '.';
                col[j][num] = false;
                row[i][num] = false;
            }
        }

        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();

        vector<vector<bool>> row(9 , vector<bool>(10 , false)) , col(9 , vector<bool>(10 , false));

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(board[i][j] == '.')
                continue;

                int ch = board[i][j] - '0';
                row[i][ch] = true;
                col[j][ch] = true;
            }
        }

        bool b = solve(0 , 0 , n , board , row , col);

        return ;
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
    obj.solveSudoku(board);
    
    for(int i = 0 ; i < 9 ; i++){
        for(int j = 0 ; j < 9 ; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}