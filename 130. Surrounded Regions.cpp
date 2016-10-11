class Solution {
public:
    void process(int i,int j,vector<vector<char> >& board)  //BFS search  
    {  
        int m=board.size();  
        int n=board[0].size();  
  
        typedef pair<int,int> point;  
        queue<point> Q;  
        Q.push(point(i,j));  
        board[i][j]='E';  
        while(!Q.empty())  
        {  
            point tmp=Q.front();  
            Q.pop();  
              
            int x=tmp.first,y=tmp.second;  
  
            //extending  
            if (x!=0 && board[x-1][y]=='O')  
            {  
                Q.push(point(x-1,y));  
                board[x-1][y]='E';   //extended;  
            }  
            if (x!=m-1 && board[x+1][y]=='O')  
            {  
                Q.push(point(x+1,y));  
                board[x+1][y]='E';   //extended;  
            }  
            if (y!=0 && board[x][y-1]=='O')  
            {  
                Q.push(point(x,y-1));  
                board[x][y-1]='E';   //extended;  
            }  
            if (y!=n-1 && board[x][y+1]=='O')  
            {  
                Q.push(point(x,y+1));  
                board[x][y+1]='E';   //extended;  
            }  
        }  
    }  
    void solve(vector<vector<char>>& board) 
    {
        if (board.size() == 0)
            return;
        int m=board.size();  
        int n=board[0].size();
        for (int i = 0; i < m; i++)
        {
            if (board[i][0] == 'O')
                process(i, 0, board);
            
            if (board[i][n-1] == 'O')
                process(i, n-1, board);
        }
        
        for (int i = 0; i < n; i++)
        {
            if (board[0][i] == 'O')
                process(0, i, board);
                
            if (board[m-1][i] == 'O')
                process(m-1, i, board);
        }
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'E')
                    board[i][j] = 'O';
            }
        }
    }
};