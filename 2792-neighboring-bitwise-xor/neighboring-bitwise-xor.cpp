class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int result=0;
        int n=derived.size();
        for(int i=0;i<n;i++){
            result^=derived[i];
        }
        if(result==0)
        return true;
        else{return false;}

    }
};