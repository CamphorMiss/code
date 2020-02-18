class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int ha[26]={0};
        for(int i=0;i<magazine.size();i++)
        {
            ++ha[magazine[i]-97];
        }
        for(int j=0;j<ransomNote.size();j++)
        {
            if(ha[ransomNote[j]-97]==0) return false;
            --ha[ransomNote[j]-97];
        }
        return true;
    }
};
