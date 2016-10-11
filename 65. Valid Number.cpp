class Solution {
public:
    bool isNumber(string str) {
        enum InputType {
            INVALID, SPACE, SIGN, DOT, E, DIGIT, LEN
        };
        int trans[][LEN] = {
            {-1,  0,  1,  2, -1,  3},
            {-1, -1, -1,  2, -1,  3},
            {-1, -1, -1, -1, -1,  4},
            {-1,  5, -1,  4,  6,  3},
            {-1,  5, -1, -1,  6,  4},
            {-1,  5, -1, -1, -1, -1},
            {-1, -1,  7, -1, -1,  8},
            {-1, -1, -1, -1, -1,  8},
            {-1,  5, -1, -1, -1,  8}
        };
        int state = 0;
        int i = 0;
        while (i < str.size()) 
        {
            char s = str[i];
            InputType input;
            if (isspace(s)) {
                input = SPACE;
            } else if (s == '+' || s == '-') {
                input = SIGN;
            } else if (s == '.') {
                input = DOT;
            } else if (s == 'e' || s == 'E') {
                input = E;
            } else if (isdigit(s)) {
                input = DIGIT;
            } else {
                input = INVALID;
            }
            state = trans[state][input];
            if (state == -1) {
                return false;
            }
            i++;
        }
        return state == 3 || state == 4 || state == 5 || state == 8;
    }
};