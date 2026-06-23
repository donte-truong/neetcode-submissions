class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> operands;

        int total = 0;

        for (string operation : operations) {
            if (operation == "+") {
                int top = operands.top();
                operands.pop();
                int secondTop = operands.top();
                operands.push(top); operands.push(top + secondTop);
                total += operands.top();
            }
            else if (operation == "C") {
                total -= operands.top();
                operands.pop();
            }
            else if (operation == "D") {
                operands.push(operands.top() * 2);
                total += operands.top();
            }
            else {
                operands.push(stoi(operation));
                total += operands.top();
            }
        }
        
        return total;
    }
};