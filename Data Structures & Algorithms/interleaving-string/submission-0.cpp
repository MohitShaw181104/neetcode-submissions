class Solution {
public:   
    bool check(string& s1, string& s2, string& s3) {
        int m = s1.length();
        int n = s2.length();
        int N = s3.length();
        if(m + n != N)
            return false;
        
        bool t[n+1];
        
        
        for(int i = 0; i<m+1; i++) {
            for(int j = 0; j<n+1; j++) {
                if(i == 0 && j == 0) {
                    t[j] = true;
                } else if(i == 0) {
                    t[j] = t[j-1] && s2[j-1]==s3[i+j-1];
                } else if (j == 0) {
                    t[j] = t[j] && s1[i-1]==s3[i+j-1];
                } else {
                    t[j] = (t[j-1] && s2[j-1]==s3[i+j-1]) || (t[j] && s1[i-1]==s3[i+j-1]);
                }
            }
        }
        
        return t[n];
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        return check(s1, s2, s3);
    }
};