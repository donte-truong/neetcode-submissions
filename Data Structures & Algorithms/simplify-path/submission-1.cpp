class Solution {
public:
    string simplifyPath(string path) {
        
        vector<string> directories;

        string currDir = "";

        int i = 1;
        while (i < path.size()) {
            
            char c = path[i];

            if (c == '/') {

                if (!directories.empty() && currDir == "..") {
                    directories.pop_back();
                } else if (currDir != ".." && currDir != "." && currDir != "") {
                    directories.push_back(currDir);
                }

                currDir = "";
            } else {
                currDir += path[i];
            }

            i++;
        }

        string ans = "";

        if (!directories.empty() && currDir == "..") {
            directories.pop_back();
        } else if (currDir != ".." && currDir != "." && currDir != "") {
            directories.push_back(currDir);
        }

        for (string dir : directories) {
            ans += "/" + dir;
        }

        return ans != "" ? ans : "/";

    }
};