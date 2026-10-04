class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;

        string currentString = "";
        int count = 0;

        for (char ch : s) {

            if (isdigit(ch)) {
                count = count * 10 + (ch - '0');
            }

            else if (ch == '[') {
                countStack.push(count);
                stringStack.push(currentString);

                count = 0;
                currentString = "";
            }

            else if (ch == ']') {

                int repeatCount = countStack.top();
                countStack.pop();

                string previousString = stringStack.top();
                stringStack.pop();

                string expandedString = "";

                for (int i = 0; i < repeatCount; i++) {
                    expandedString += currentString;
                }

                currentString = previousString + expandedString;
            }

            else {
                currentString += ch;
            }
        }

        return currentString;
    }
};