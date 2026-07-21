class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int>Q(students.begin(), students.end());
        int k = 0;
        bool change = true;
        while(!Q.empty() && change)
        {
            int qSize = Q.size();
            for(auto i = 0; i < qSize; ++i)
            {
                int f = Q.front();
                Q.pop();
                if(f == sandwiches[k])
                    k++;
                else
                    Q.push(f);
            }
            change = qSize != Q.size();
        }
        return Q.size();
    }
};