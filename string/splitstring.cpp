#include <bits/stdc++.h>
using namespace std;
vector<string> splitString(string &s, char delimeter)
{
    vector<string> ans;
    int start = 0;
    int end = s.find(delimeter, start);
    while (end != string::npos)
    {
        string sub = s.substr(start, end - start);
        ans.push_back(sub);
        start = end + 1;
        end = s.find(delimeter, start);
    }
    string sub = s.substr(start, end - start);
    ans.push_back(sub);
    return ans;
}
int main()
{
    string sentence = "the cattle was rattled by the battery";
    vector<string> words = splitString(sentence, ' ');
    for (auto s : words)
        cout << s << endl;
    return 0;
}