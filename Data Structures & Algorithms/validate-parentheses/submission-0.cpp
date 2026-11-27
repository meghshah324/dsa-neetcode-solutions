class Solution {
public:
    bool isValid(string st) {
         int n=st.size();
           stack<char>s;
           for(int i=0;i<n;i++){
                 
                 if(st[i]=='(' || st[i]=='[' || st[i]=='{'){
                       s.push(st[i]);
                 }else{
                       if(s.empty()){
                              return false;
                       }
                       if(st[i]==')'){
                            if(s.top()=='('){
                                 s.pop();
                            }else{
                                  return false;

                            }
                       }else if(st[i]==']'){
                                if(s.top()=='['){
                                 s.pop();
                            }else{
                                  return false;

                            }
                       }else if(st[i]=='}'){
                            if(s.top()=='{'){
                                 s.pop();
                            } else{
                              
                            return false;
                       }
                            
                      
                 }
                 }
           }
           if(s.empty()){
                return true;
           }else{
                return false;
           }
           
        
    }
};