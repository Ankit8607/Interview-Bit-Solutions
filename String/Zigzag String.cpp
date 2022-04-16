/*

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P.......A........H.......N
..A..P....L....S....I...I....G
....Y.........I........R
And then read line by line: PAHNAPLSIIGYIR

Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"
**Example 2 : **

ABCD, 2 can be written as

A....C
...B....D
and hence the answer would be ACBD.

*/


string Solution::convert(string A, int B) {
    if(B==1) return A;
    string ans="";
    map<int,string>mp;
    int i=0,dir=1,row=1;
    while(i<A.size()){
        if(dir){
            mp[row]+=A[i];
            row++;
            if(row==B) dir=0;
        }
        else{
            mp[row]+=A[i];
            row--;
            if(row==1) dir=1;
        }
        i++;
        // if(row==B)dir=0;
        // if(row==1) dir=1;
    }
    for(auto i:mp) ans+=i.second;
    return ans;
}
