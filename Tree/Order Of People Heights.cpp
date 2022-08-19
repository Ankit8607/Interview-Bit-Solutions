// https://www.interviewbit.com/problems/order-of-people-heights/

/*

You are given the following :

A positive number N
Heights : A list of heights of N persons standing in a queue
Infronts : A list of numbers corresponding to each person (P) that gives the number of persons who are taller than P and standing in front of P
You need to return  list of actual order of persons’s height

Consider that heights will be unique

Example

Input : 
Heights: 5 3 2 6 1 4
InFronts: 0 1 2 0 3 2
Output : 
actual order is: 5 3 2 1 6 4 
So, you can see that for the person with height 5, there is no one taller than him who is in front of him, and hence Infronts has 0 for him.

For person with height 3, there is 1 person ( Height : 5 ) in front of him who is taller than him.

You can do similar inference for other people in the list.

*/


int t[400010];
void build(int idx,int l,int r){
    if(l==r){
        t[idx]=1;
        return;
    }
    
    int mid=(l+r)/2;
    build(2*idx,l,mid);
    build(2*idx+1,mid+1,r);
    t[idx]=t[2*idx]+t[2*idx+1];
}

int query(int idx,int l,int r,int pos){
    if(l==r){ 
        t[idx]=0;
        return l;
    }
    t[idx]--;
    int mid=(l+r)/2;
    if(t[2*idx]<pos) return query(2*idx+1,mid+1,r,pos-t[2*idx]);
    return query(2*idx,l,mid,pos);
}

vector<int> Solution::order(vector<int> &A, vector<int> &B) {
    int n=A.size();
    vector<int>res(n);
    map<int,int>longer;
    for(int i=0;i<n;i++){
        longer[A[i]]=B[i];
    }
    build(1,0,n-1);
    for(auto i:longer){
        int index=query(1,0,n-1,i.second+1);
        res[index]=i.first;
    }
    return res;
}
