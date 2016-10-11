class Solution {
public:
    void find_all_neighbor_lands(vector<vector<char>>& grid/*, vector<vector<bool>>& flags*/, const int x, const int y)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        if (grid[x][y] == '0' || grid[x][y] == '2')
            return;
        else
        {
            grid[x][y] = '2';
            if (x-1 >= 0)
                find_all_neighbor_lands(grid, x-1, y);
            if (x+1 < rows)
                find_all_neighbor_lands(grid, x+1, y);
            if (y-1 >= 0)
                find_all_neighbor_lands(grid, x, y-1);
            if (y+1 < cols)
                find_all_neighbor_lands(grid, x, y+1);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        int res = 0;
        if (grid.size() == 0)
            return res;
        
        int rows = grid.size();
        int cols = grid[0].size();
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == '0' || grid[i][j] == '2')
                    continue;
                else
                {
                    find_all_neighbor_lands(grid, i, j);
                    res++;
                }
            }
        }
        
        return res;
    }
};