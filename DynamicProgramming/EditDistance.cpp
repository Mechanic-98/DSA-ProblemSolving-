#include <cstring>
#include <iostream>
using namespace std;

int editDistance(string s1, string s2)
{
    if (s1.size() == 0 || s2.size() == 0)
        return max(s1.size(), s2.size());

    if (s1[0] == s2[0])
        return editDistance(s1.substr(1), s2.substr(1));

    int deletion = editDistance(s1, s2.substr(1)) + 1;
    int replacement = editDistance(s1.substr(1), s2.substr(1)) + 1;
    int insertion = editDistance(s1.substr(1), s2) + 1;

    return min(deletion, min(replacement, insertion));
}

int editDistanceMem(string s1, string s2, int **output)
{
    int m = s1.size();
    int n = s2.size();

    if (m == 0 || n == 0)
        return max(m, n);

    if (output[m][n] != -1)
        return output[m][n];

    int ans;

    if (s1[0] == s2[0])
        ans = editDistance(s1.substr(1), s2.substr(1));
    else
    {
        int deletion = editDistance(s1, s2.substr(1)) + 1;
        int replacement = editDistance(s1.substr(1), s2.substr(1)) + 1;
        int insertion = editDistance(s1.substr(1), s2) + 1;

        ans = min(deletion, min(replacement, insertion));
    }

    output[m][n] = ans;

    return output[m][n];
}

int main()
{
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << editDistance(s1, s2);
}
