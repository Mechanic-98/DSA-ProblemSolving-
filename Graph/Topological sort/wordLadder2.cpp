/*
https://practice.geeksforgeeks.org/problems/word-ladder-ii/1
*/

#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_set>
#include <string>

using namespace std;

class Solution
{
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> currentWordList(wordList.begin(), wordList.end());
        queue<vector<string>> wordTransformationSequence;
        wordTransformationSequence.push({beginWord});
        vector<string> usedOnLevel;
        useOnLevel.push_back(beginWord);
        int level = 0;

        vector<vector<string>> ans;

        while (!wordTransformationSequence.empty())
        {
            vector<string> frontList = wordTransformationSequence.front();
            wordTransformationSequence.pop();

            /*
            erase all words that has been used in the previous
            levels to transform
            */

            if (frontList.size() > level)
            {
                level++;
                for (auto ele : usedOnLevel)
                {
                    currentWordList.erase(ele);
                }
                usedOnLevel.clear();
            }

            string word = frontList.back();
            if (word == endWord)
            {
                if (ans.size() == 0)
                    ans.push_back(frontList);
                else if (ans[0].size() == frontList.size())
                {
                    ans.push_back(frontList);
                }
            }
            for (int i = 0; i < word.size(); i++)
            {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (currentWordList.count(word) > 0)
                    {
                        frontList.push_back(word);
                        wordTransformationSequence.push(frontList);
                        // mark visited on the level
                        usedOnLevel.push_back(word);
                        frontList.pop_back()
                    }
                }
                word[i] = original;
            }
        }

        return ans;
    }
};