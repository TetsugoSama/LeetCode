/*****************************************************************
 * 问题：
 * 你这个学期必须选修numCourse门课程，记为 0 到 numCourse-1 。在选修
 * 某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成
 * 课程 1 ，我们用一个数组来表示他们：{0,1}。给定课程总量以及它们的先决
 * 条件，请你判断是否可能完成所有课程的学习？
 *
 * 解决思路：
 * 构建入度表，存放每一门课需要预先修的课程数量。构建邻接表（二维数组），
 * 存放学习第i门课程后可以学习的课程。创建一个队列，将所有入度为0的课程
 * 放入队列，访问修完它们可以学习的课程，并将该课程的入度减1；若某课程
 * 入度为0，则放入队列。若所有的课程最后的入度都为0（或这是所有的课程都
 * 放入过队列），则表明可以修完所有的课（图没有闭环）。
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        queue<int> q;
        int all = 0;
        for (int i = 0; i < prerequisites.size(); i++) {
            indegree[prerequisites[i][0]]++;
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }       
        }
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            ++all;
            for (int i = 0; i < graph[course].size(); i++) {
                int next = graph[course][i];
                indegree[next]--;
                if (indegree[next] == 0)
                    q.push(next);
            }
        }
        return all == numCourses;
    }
};