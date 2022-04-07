/*

Find last digit of the number AB.
A and B are large numbers given as strings.


Problem Constraints
1 <= |A| <= 105
1 <= |B| <= 105


Input Format
First argument is a string A.
First argument is a string B.


Output Format
Return an integer.


Example Input
Input 1:
A = 2
B = 10
Input 2:
A = 11
B = 11


Example Output
Output 1:
4
Output 2:
1


Example Explanation
Explanation 1:
210 = 1024, hence last digit is 4.
Explanation 2:
1111 = 285311670611, hence last digit is 1.


*/

// int Solution::solve(string A, string B) {
//     vector<int>present;
//     int digit=A[A.size()-1]-'0';
//     int last=digit;
//     // s.insert(last);
//     // present[digit]=1;
//     present.push_back(digit);
//     for(int i=2;i<10;i++){
//         last=last*digit%10;
//         if(last==present[0]) break;
//         // s.insert(last);
//         // if(present[last]==0) present[last]=i;
//         present.push_back(last);
//     }
//     int sz=present.size();
//     sz=(B[B.size()-1]-'0')%sz;
//     return present[sz];   
// }
int Solution::solve(string A, string B) {
    int k = A.back() - '0';
    vector<int> v(1, k);
    while (true) {
        int x = v.back() * k;
        x %= 10;
        if (x == v[0]) {
            break;
        } else {
            v.push_back(x);
        }
    }
    int n = v.size();
    int b = 0;
    int mul = 1;
    for (int i = B.size() - 1; i >= 0; --i) {
        int x = B[i] - '0';
        b = (b + x * mul) % n;
        mul = (mul * 10) % n;
    }
    b = (b - 1 + n) % n;
    return v[b];
}


// Fastest

int Solution::solve(string A, string B) {
    int x=A[A.size()-1]-'0';
    if(B.size()==1) return ((int)pow(x,(B[0]-'0')))%10;
    int y=B[B.size()-1]-'0';
    int z=B[B.size()-2]-'0';
    int p=z*10+y;
    if(p%4==0) return ((int)pow(x,4))%10;
    return ((int)pow(x,p%4))%10;
}
