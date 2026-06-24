class Solution {
public:
    string decodeString(string s) {
        
        vector<string> operands;

        string num = "";

        for (char c : s) {

            if (isdigit(static_cast<unsigned char>(c))) {
                num += c;
            } else if (c == '[') {
                operands.push_back(num);
                operands.push_back("[");
                num.clear();
            } else if (c == ']') {

                string base = "";

                while (operands.back() != "[") {
                    swap(operands.back(), base);
                    base += operands.back();
                    operands.pop_back();
                }

                operands.pop_back();
                int multiplicity = stoi(operands.back());
                operands.pop_back();

                string newBase = "";
                newBase.reserve(base.size() * multiplicity);
                for (int i = 0; i < multiplicity; i++) {
                    newBase += base;
                }

                operands.push_back(newBase);
            } else {
                operands.push_back(string(1, c));
            }

        }

        string ans = "";
        for (string operand : operands) {
            ans += operand;
        }
        return ans;

    }
};