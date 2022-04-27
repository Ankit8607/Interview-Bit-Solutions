/*

Given a string A representing an absolute path for a file (Unix-style).

Return the string A after simplifying the absolute path.

Note:

Absolute path always begin with ’/’ ( root directory ).

Path will not have whitespace characters.




Input Format

The only argument given is string A.
Output Format

Return a string denoting the simplified absolue path for a file (Unix-style).
For Example

Input 1:
    A = "/home/"
Output 1:
    "/home"

Input 2:
    A = "/a/./b/../../c/"
Output 2:
    "/c"
    
*/


string Solution::simplifyPath(string A) {
    vector<string> collection;
    string name = "";
    
    A.push_back('/');   //For path ending with ..
    
    for (auto i = 0; i<A.length(); ++i)
    {
        if (A[i] == '/')
        {
            if (name.size() == 0) continue;
            else if (name == ".") {}
            else if (name == "..")
            {
                if (collection.size() > 0)
                    collection.pop_back();
            }
            else
                collection.emplace_back(name);
            
            name.clear();
        }
        else
            name.push_back(A[i]);
    }
    
    if (collection.empty())
        return "/";
        
    A.clear();
    for (auto j = 0; j<collection.size(); ++j)
        A.append("/" + collection[j]);
        
    return A;
}
