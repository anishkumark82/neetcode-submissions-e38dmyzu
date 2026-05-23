class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        // 0 and 1
        queue<int> sQ(students.begin(), students.end());
        int top = 0;
        int prev = -1;
        while(!sQ.empty() && prev != top)
        {
            prev = top;
            int qSize = sQ.size();
            for(auto i = 0; i < qSize; ++i)
            {
                int f = sQ.front();
                sQ.pop();
                if(f == sandwiches[top])
                    top++;
                else
                    sQ.push(f);
            }
        }
        return sQ.size();
    }
};