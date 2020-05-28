#include <bits/stdc++.h>
using namespace std;

// Function declaration line.
bool matching_char(char a, char b);

// Matching the top of the stack and the upcoming closing parenthesis.
bool matching_char(char a, char b)
{
    if (a == '(' && b == ')')
    {
        return true;
    }

    if (a == '{' && b == '}')
    {
        return true;
    }

    if (a == '[' && b == ']')
    {
        return true;
    }

    return false;
}

// Function to balance the parenthesis.
bool is_balanced(string str)
{
    std::stack<int> s;

    for (int i = 0; i < str.length(); i++)
    {

        // If the upcoming character is opening parenthesis, push it in stack.
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            s.push(str[i]);
        }
        else
        {
            // If the closing parenthesis is closing one and stack is empty
            // Return false.
            if (s.empty() == true)
            {
                return false;
            }

            // If the closing one matches with
            // the upcoming character, then pop.
            if (matching_char(s.top(), str[i]) == true)
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
    }

    if (s.empty() == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string str = "()";
    cout << is_balanced(str);
}
