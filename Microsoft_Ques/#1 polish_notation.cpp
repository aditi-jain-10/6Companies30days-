class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        int n = tokens.size();
        stack<string> st;
        int i = 0;

        while (i < n)
        {
            if (isoperator(tokens[i]))
            {
                string b = st.top();
                st.pop();
                string a = st.top();
                st.pop();
                string c = calculate(b, a, tokens[i]);
                st.push(c);
            }

            else
                st.push(tokens[i]);

            i++;
        }
        return stoi(st.top());
    }

    bool isoperator(string a)
    {
        if (a == "+" || a == "-" || a == "*" || a == "/")
            return true;
        else
            return false;
    }

    string calculate(string b, string a, string op)
    {
        int num1 = stoi(a);
        int num2 = stoi(b);
        if (op == "+")
            return to_string(num1 + num2);
        else if (op == "-")
            return to_string(num1 - num2);
        else if (op == "*")
            return to_string(num1 * num2);
        else
            return to_string(num1 / num2);
    }
};