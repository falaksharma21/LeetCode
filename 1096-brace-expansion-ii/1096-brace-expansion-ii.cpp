class Solution {
public:
    set<string> parse(string &expression, int &i) {
        set<string> result;

        while (i < expression.size() && expression[i] != '}') {
            set<string> current;

            if (expression[i] == '{') {
                i++;
                current = parse(expression, i);
                i++;
            } 
            else {
                current.insert(string(1, expression[i]));
                i++;
            }

            if (result.empty()) {
                result = current;
            } 
            else {
                set<string> temp;

                for (string a : result) {
                    for (string b : current) {
                        temp.insert(a + b);
                    }
                }

                result = temp;
            }

            if (i < expression.size() && expression[i] == ',') {
                i++;

                set<string> next = parse(expression, i);

                result.insert(next.begin(), next.end());
            }
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;

        set<string> result = parse(expression, i);

        return vector<string>(result.begin(), result.end());
    }
};