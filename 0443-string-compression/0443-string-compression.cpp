class Solution {
public:
    int compress(vector<char>& chars) {
        int idx=0;
        for(int i=0;i<chars.size();i++){
            int count=0;
            char ch=chars[i];
            while(i<chars.size() && chars[i]==ch){
                i++;
                count++;
            }
            if(count==1){
                chars[idx]=ch;
                idx++;
            }
            else{
                chars[idx]=ch;
                idx++;
                string s=to_string(count);
                for(int j=0;j<s.size();j++){
                    chars[idx]=s[j];
                    idx++;
                }
            }
            i--;
        }
        chars.resize(idx);
        
        return idx;
    }
    
};