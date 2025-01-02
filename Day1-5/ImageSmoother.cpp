class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {

        int n = img.size();
        int m = img[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int r=0;r<n;r++)
        {
            for(int c=0;c<m;c++)
          {
            int sum = 0;
            int count = 0;

            for(int i=-1;i<=1;i++)
            {
                for(int j=-1;j<=1;j++)
                {
                    int nr = r+i;
                    int nc = c+j;

                    if(nr>=0 && nr<n && nc>=0 && nc<m)
                    {
                        sum += img[nr][nc];
                        count+=1;
                        
                        
                    }
                }
            }

            vis[r][c] = sum/count;

          }
            
        } 

        return vis;  
    }
};