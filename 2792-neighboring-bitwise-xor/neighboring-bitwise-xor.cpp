class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int result=0;
  
        for(int i=0;i<derived.size();i++){
            result^=derived[i];
        }
        return (bool)(!result);

    }
};