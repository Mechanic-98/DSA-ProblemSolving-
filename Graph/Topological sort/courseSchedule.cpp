#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        // form graph and store it in adjList
        vector<int> adjList[numCourses]; // an array of vector
        for (vector<int> dependencyList : prerequisites)
        {
            adjList[dependencyList[1]].push_back(dependencyList[0]);
        }

        // int indegreeList[numCourses] = {0}; // initializing all the members of the array with 0.
        vector<int> indegreeList(numCourses, 0);
        queue<int> pendingNodes;
        int count = 0;

        // filling indegreeList
        for (int i = 0; i < numCourses; i++)
        {
            for (int adjNode : adjList[i])
            {
                indegreeList[adjNode]++;
            }
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (indegreeList[i] == 0)
            {
                pendingNodes.push(i);
            }
        }

        while (!pendingNodes.empty())
        {
            int frontNode = pendingNodes.front();
            pendingNodes.pop();
            count++;

            for (int adjNode : adjList[frontNode])
            {
                indegreeList[adjNode]--;
                if (indegreeList[adjNode] == 0)
                    pendingNodes.push(adjNode);
            }
        }

        return (count == numCourses);
    }
};