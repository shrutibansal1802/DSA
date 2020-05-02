string isBalanced(string s) {
    stack<char> st;
    st.push(1);
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='{' || s[i]=='[' || s[i]=='(')
        st.push(s[i]);

        else if(s[i]==')' && st.top()=='(')
            st.pop();
        else if(s[i]==']' && st.top()=='[')
            st.pop();
        else if(s[i]=='}' && st.top()=='{')
            st.pop();
        else
        st.push(s[i]);
    }
    if(st.top()==1)
    return "YES";
    else
    return "NO";

}
