class Solution {
public:
	bool isValid(string s) {
		stack<char> stk;
		char ch,ch2;
		for (auto i = s.begin(); i != s.end(); i++) {
			ch = *i;
			if (ch != '(' && ch != ')' && ch != '[' && ch != ']' && ch != '{' && ch != '}') exit(-1);
			else if (ch == '(' || ch == '[' || ch == '{') {
				stk.push(ch);
			}
			else {
				switch (ch){
				case ')':
					if (stk.empty())return false;
					ch2 = stk.top();
					stk.pop();
					if (ch2 != '(') return false;
					break;
				case ']':
					if (stk.empty())return false;
					ch2 = stk.top();
					stk.pop();
					if (ch2 != '[') return false;
					break;
				case '}':
					if (stk.empty())return false;
					ch2 = stk.top();
					stk.pop();
					if (ch2 != '{') return false;
					break;
				}
			}
			
		}
		if (stk.empty())return true;
		else return false;
	}
};

class Solution_By_Bigwig {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n % 2 == 1) {
            return false;
        } 
    unordered_map<char, char> pairs = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };
    stack<char> stk;
    for (char ch: s) {
        if (pairs.count(ch)) {
            if (stk.empty() || stk.top() != pairs[ch]) {
                return false;
            }
            stk.pop();
        }
        else {
            stk.push(ch);
        }
    }
    return stk.empty();
}
};

int main() {
	string temp;
	cin >> temp;
	Solution a;
	if (a.isValid(temp)) cout << "ok";
	else cout << "fuck";
	return 0;
}
