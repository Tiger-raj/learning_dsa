#include <bits/stdc++.h>
using namespace std;

int hamming(string s, string r)
{
    int n = s.length(), cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != r[i])
            cnt++;
    }
    return cnt;
}

vector<string> getSeq(vector<string> &words, vector<int> &groups, int l, int h)
{
    vector<string> ans;
    int i = l, j = l + 1;

    while (j < h)
    {
        if (groups[i] != groups[j]) //&& (words[i].length() == words[j].length())
        {
            if (hamming(words[i], words[j]) == 1)
            {
                if (ans.size() == 0)
                {
                    ans.push_back(words[i]);
                }
                ans.push_back(words[j]);
                i = j;
            }
            j++;
        }
        else
        {
            j++;
        }
        if (ans.size() == 0 && j == words.size())
        {
            i++;
            j = i + 1;
        }
    }
    if (ans.size() == 0)
    {
        ans.push_back(words[0]);
    }
    return ans;
}

void copyV(vector<string> &v1, vector<string> &v2)
{
    for (int i = 0; i < v2.size(); i++)
    {
        if (i <= v1.size() - 1)
        {
            v1[i] = v2[i];
        }
        else
        {
            v1.push_back(v2[i]);
        }
    }
}

vector<string> getWordsInLongestSubsequence(int n, vector<string> &words, vector<int> &groups)
{
    vector<pair<string, int>> temp;
    for (int i = 0; i < n; i++)
    {
        temp.push_back({words[i], groups[i]});
    }

    stable_sort(temp.begin(), temp.end(),
                [](const pair<string, int> &a, const pair<string, int> &b)
                {
                    return a.first.size() < b.first.size();
                });

    for (int i = 0; i < n; i++)
    {
        words[i] = temp[i].first;
        groups[i] = temp[i].second;
    }

    int l = words[0].length();
    int i = 0, n = words.size();
    vector<int> sizes;
    sizes.push_back(-1);
    while (i < n)
    {
        if (words[i].length() != l)
        {
            sizes.push_back(i - 1);
            l = words[i].length();
        }
        i++;
    }
    sizes.push_back(n - 1);
    int i = 1;
    vector<string> ans = getSeq(words, groups, 0, sizes[1]);

    for (; i < sizes.size() - 1; i++)
    {
        vector<string> ans1 = getSeq(words, groups, sizes[i], sizes[i + 1]);
        if (ans.size() < ans1.size())
        {
            copyV(ans, ans1);
        }
    }
    return ans;
}

int main()
{

    return 0;
}
