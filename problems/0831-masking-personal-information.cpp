// problem: 0831 masking personal information
// difficulty: medium
// studysets: dsa-quest
// url: https://leetcode.com/problems/masking-personal-information/
// tags: string, parsing, formatting
#include <string>

using std::string;
class Solution {
private:
    bool isEmail(const string& s) {
        return s.find('@') != string::npos;
    }

    string maskEmail(string s) {
        // lowercase everything
        for (char& c : s)
            c = tolower(static_cast<unsigned char>(c));

        int at = s.find('@');
        string name = s.substr(0, at);
        string domain = s.substr(at);

        // first + 5 stars + last
        return string(1, name[0]) + "*****" + string(1, name.back()) + domain;
    }

    string maskPhone(const string& s) {
        string digits;
        digits.reserve(s.size());
        for (char c : s)
            if (isdigit(c))
                digits.push_back(c);

        string local = digits.substr(digits.size() - 4);
        int country = digits.size() - 10;

        string maskedLocal = "***-***-" + local;

        if (country <= 0)
            return maskedLocal;

        return "+" + string(country, '*') + "-" + maskedLocal;
    }

public:
    string maskPII(string s) {
        return isEmail(s) ? maskEmail(s) : maskPhone(s);
    }
};
