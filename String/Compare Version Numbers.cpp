/*

Compare two version numbers version1 and version2.

If version1 > version2 return 1,
If version1 < version2 return -1,
otherwise return 0.
You may assume that the version strings are non-empty and contain only digits and the . character.

The . character does not represent a decimal point and is used to separate number sequences.

For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 1.13 < 1.13.4

*/

int Solution::compareVersion(string A, string B) {
    string tmpa="",tmpb="";
    int i=0,j=0;
    while(i<A.size() || j<B.size()){
        while(i<A.size() and A[i]!='.'){ 
            tmpa+=A[i];
            i++;
        }
        while(j<B.size() and B[j]!='.'){ 
            tmpb+=B[j];
            j++;
        }
        int l1=0,l2=0;
        while(l1<tmpa.size() and tmpa[l1]=='0') l1++;
        tmpa.erase(0,l1);
        while(l2<tmpb.size() and tmpb[l2]=='0') l2++;
        tmpb.erase(0,l2);
        // if(A[i]=='.' and B[j]=='.''){
            if(tmpa.size()>tmpb.size()) return 1;
            else if(tmpb.size()>tmpa.size()) return -1;
            else{
                if(tmpa>tmpb) return 1;
                else if(tmpb>tmpa) return -1;
            }
            tmpa=""; tmpb="";
            i++;j++;
        // }
    }
    if(j==B.size()) return 1;
    else if(i==A.size()) return -1;
    return 0;  
}
