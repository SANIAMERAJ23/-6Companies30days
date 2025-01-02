class Solution {
public:
    int findTheWinner(int n, int k) {
        
        vector<int> store(n);

        for(int i=0;i<n;i++)
        {
            store[i] = i+1;
        }

        int start = 0;
        int count = 0;

        while(store.size()>0)
        {
          count++;

          if(count==k)
          {
            store.erase(store.begin()+start);
            count = 0;
          }

          else
          {
            start = (start+1)%store.size();
          }
          
        }

        return store[0];
    }
};