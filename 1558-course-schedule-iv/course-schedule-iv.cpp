class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // Step 1: Create a 2D grid (matrix) to store which courses are prerequisites of other courses
        // Size: numCourses × numCourses, initially all false
        vector<vector<bool>> isPrerequisite(numCourses, vector<bool>(numCourses, false));
        
        // Step 2: Mark direct prerequisites
        // For each prerequisite pair [course1, course2]:
        // course1 is a prerequisite of course2
        for (const auto& prereq : prerequisites) {
            int course1 = prereq[0];    // This is the prerequisite course
            int course2 = prereq[1];    // This is the course that needs the prerequisite
            isPrerequisite[course1][course2] = true;
        }
        
        // Step 3: Find all indirect prerequisites
        // Example: if A is prerequisite of B, and B is prerequisite of C
        // then A is also prerequisite of C
        for (int through = 0; through < numCourses; through++) {
            for (int start = 0; start < numCourses; start++) {
                for (int end = 0; end < numCourses; end++) {
                    // If 'start' is prerequisite of 'through' AND
                    // 'through' is prerequisite of 'end'
                    // Then 'start' is also prerequisite of 'end'
                    if (isPrerequisite[start][through] && 
                        isPrerequisite[through][end]) {
                        isPrerequisite[start][end] = true;
                    }
                }
            }
        }
        
        // Step 4: Answer each query
        vector<bool> answers;
        for (const auto& query : queries) {
            int course1 = query[0];     // Is this course...
            int course2 = query[1];     // ...a prerequisite of this course?
            answers.push_back(isPrerequisite[course1][course2]);
        }
        
        return answers;
    }
};