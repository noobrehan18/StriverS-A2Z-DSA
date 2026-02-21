void dfs(vector<vector<int>> img, vector<vector<int>> &vis, int row, int col, int ncolor, int iniColor)
{
    vis[row][col] = ncolor;
    int n = img.size();
    int m = img[0].size();
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] != ncolor && img[nrow][ncol] == iniColor)
        {
            dfs(img, vis, nrow, ncol, ncolor, iniColor);
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>> &img, int sr, int sc, int ncolor)
{
    int iniColor = img[sr][sc];
    vector<vector<int>> vis = img;
    dfs(img, vis, sr, sc, ncolor, iniColor);
    return vis;
}