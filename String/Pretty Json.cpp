/*

Given a string A representating json object. Return an array of string denoting json object with proper indentaion.

Rules for proper indentaion:

Every inner brace should increase one indentation to the following lines.
Every close brace should decrease one indentation to the same line and the following lines.
The indents can be increased with an additional ‘\t’
Note:

[] and {} are only acceptable braces in this case.

Assume for this problem that space characters can be done away with.




Input Format

The only argument given is the integer array A.
Output Format

Return a list of strings, where each entry corresponds to a single line. The strings should not have "\n" character in them.
For Example

Input 1:
    A = "{A:"B",C:{D:"E",F:{G:"H",I:"J"}}}"
Output 1:
    { 
        A:"B",
        C: 
        { 
            D:"E",
            F: 
            { 
                G:"H",
                I:"J"
            } 
        } 
    }

Input 2:
    A = ["foo", {"bar":["baz",null,1.0,2]}]
Output 2:
   [
        "foo", 
        {
            "bar":
            [
                "baz", 
                null, 
                1.0, 
                2
            ]
        }
    ]
    
*/


vector<string> Solution::prettyJSON(string A) {
    auto r = 0; //vector rows
    vector<string> result(1, "");
    int brace = 1;
    for (auto i = 0; i<A.length(); ++i)
    {
        switch(A[i])
        {
            case ' ':
                continue;
                
            case '{':
            case '[':
                if(brace==1 && r==0)
                    result[r] += A[i];
                else
                {
                    result.push_back("");
                    result[++r] += string(brace, '\t');
                    result[r] += A[i];
                    ++brace;
                }
                result.push_back("");
                result[++r] += string(brace, '\t');
                break;
                
            case '}':
            case ']':
                if (brace>1)
                {
                    result.push_back("");
                    result[++r] += string(brace-1, '\t');
                    result[r] += A[i];
                    --brace;
                }
                else
                {
                    result.push_back("");
                    result[++r] += A[i];
                    --brace;
                }
                break;
                
            case ',':
                result[r] += A[i];
                if (A[i+1]=='{' || A[i+1]=='[')
                    continue;
                else
                {
                    result.push_back("");
                    result[++r] += string(brace, '\t');
                }
                break;
                
            case ':':
                result[r] += A[i];
                if (A[i+1]=='{' || A[i+1]=='[')
                {
                    result.push_back("");
                    result[++r] += string(brace, '\t');
                    result[r] += A[++i];
                    ++brace;
                    if(A[i+1]!='{' && A[i+1]!='[')
                    {
                        result.push_back("");
                        result[++r] += string(brace, '\t');
                        result[r] += A[++i];
                    }
                }
                break;
                
            default:
                result[r] += A[i];
                break;
        }
    }
    return result;
}
