class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
      int  n=pref.size();
        int count=0;
        
        for(int i=0;i<words.size();i++)
        {    int counter =n;
            if(n<=words[i].size()){
            for(int j=0;j<n;j++)
            {  
                if(words[i][j]==pref[j])
                counter--;

            }
            }if(counter ==0)
            count++;
        }return count;
    }
};