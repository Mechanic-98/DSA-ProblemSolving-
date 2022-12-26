/*
https://practice.geeksforgeeks.org/problems/word-ladder/1
*/

#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    // T.C: O(wordList.length() * word.length() * log(wordList.length()) * 26)
    int wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
    {
        queue<pair<string, int>> wordTransformationQueue;
        wordTransformationQueue.push({startWord, 1});
        unordered_set<string> currentWordSet(wordList.begin(), wordList.end());
        currentWordSet.erase(startWord);

        while (!wordTransformationQueue.empty())
        {
            string word = wordTransformationQueue.front().first;
            int steps = wordTransformationQueue.front().second;
            wordTransformationQueue.pop();

            if (word == targetWord)
                return steps;

            for (int i = 0; i < word.size(); i++)
            {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (currentWordSet.find(word) != currentWordSet.end())
                    {
                        currentWordSet.erase(word);
                        wordTransformationQueue.push({word, steps + 1});
                    }
                }
                word[i] = original;
            }
        }

        return 0;
    }
};