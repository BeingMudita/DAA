#include<bits/stdc++.h>
using namespace std;

void printboard(const vector<string>& board)
{
    for(const string& row:board)
        cout<<row<<'\n';
            cout<<'\n';
}

bool isSafe(int r,int c,int N,const vector<string>& board)
{
    for(int i=0; i<r; ++i)
        if(board[i][c]=='Q')
             return false;
             
    for(int i=r-1, j=c-1; i>=0 && j>=0; --i, --j)
        if(board[i][j]=='Q')
            return false;
            
    for(int i=r-1, j=c+1; i>=0 && j<N; --i, j++)
        if(board[i][j]=='Q')
            return false;
    return true;
}

void solve_n(int row, int N, vector<string>& board, int &count)
{
    if(row==N)
    {
        ++count;
        printboard(board);
        return;
    }
    
    for(int col=0; col<N; ++col)
    {
        if(isSafe(row, col, N, board))
        {
            board[row][col]='Q';
            solve_n(row+1, N, board, count);
            board[row][col]='.';
        }
    }
}
int main()
{
    int N;
    cout<<"enter N:";
    if(!(cin>>N))
    return 0;
    
    vector<string> board(N,string(N, '.'));
    int solutions=0;
    solve_n(0, N, board, solutions);
    cout<<"total solutions:"<<solutions<<'\n';
    
    return 0;
}
