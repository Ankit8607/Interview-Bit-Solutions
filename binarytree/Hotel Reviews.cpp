// https://www.interviewbit.com/problems/hotel-reviews/

/*

Problem Description
 
 

Given a set of reviews provided by the customers for different hotels and a string containing Good Words, you need to sort the reviews in descending order according to their Goodness Value (Higher goodness value first). We define the Goodness Value of a string as the number of Good Words in that string.

NOTE: Sorting should be stable. If review i and review j have the same Goodness Value then their original order would be preserved.

You are expected to use Trie in an Interview for such problems



Problem Constraints
1 <= No.of reviews <= 200
1 <= No. of words in a review <= 1000
1 <= Length of an individual review <= 10,000
1 <= Number of Good Words <= 10,000
1 <= Length of an individual Good Word <= 4
All the alphabets are lower case (a - z)


Input Format
First argument is a string A containing "Good Words" separated by "_" character

Second argument is a vector B of strings containing Hotel Reviews. Review strings are also separated by "_" character.



Output Format
Return a vector of integers which contain the original indexes of the reviews in the sorted order of reviews.



Example Input
Input 1:

 A = "coolicewifi"
 B = ["wateriscool", "coldicedrink", "coolwifispeed"]


Example Output
Output 1:

 [2, 0, 1]


Example Explanation
Explanation 1:

 sorted reviews are ["coolwifispeed", "wateriscool", "coldicedrink"]
 
 */


struct trie
{
    int isLeaf;
    trie *child[26];
};

trie *getNode()
{
    trie *node = new trie();
    for(int i=0; i<26; i++)
        node->child[i] = NULL;
    node->isLeaf = 0;
    
    return node;
}

void insert(trie *A, string s)
{
    trie *curr = A;
    
    for(int i=0; i<s.size(); i++)
    {
        int idx = int(s[i] - 'a');
        if(!curr->child[idx])
            curr->child[idx] = getNode();
        
        curr = curr->child[idx];
    }
    curr->isLeaf = 1; 
}

int search(trie *A, string s)
{
    trie *curr = A;
    
    for(int i=0; i<s.size(); i++)
    {
        int idx = int(s[i] - 'a');
        if(!curr->child[idx])
            return 0;
        
        curr = curr->child[idx];
    }
    return (curr && curr->isLeaf);
}

void convert(string &str)
{
    //Convert _ to spaces
    for(int i=0; i<str.size(); i++)	 
    {
	if(str[i] == '_')	
	     str[i] = ' ';
    }
    return;
}

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
    if(a.first == b.first) 
        return a.second < b.second;
    
    return a.first > b.first;	
}

vector<int> Solution::solve(string A, vector<string> &B)
{
    vector<int > v;
    vector<pair<int, int>> v1;

    trie *root = getNode();
    
    convert(A);
    
    string word;

    stringstream ss;

    ss<<A;

    while(ss>>word)	
        insert(root, word);
	
    int cnt;
    for(int i=0; i<B.size(); i++)
    {
	convert(B[i]);
	ss.clear();

	ss<<B[i];

	cnt = 0;
	while(ss>>word)	
	{
	    if(search(root, word))	
		cnt++;
	}
	v1.push_back({cnt, i});
    }
    
    sort(v1.begin(), v1.end(), cmp);
    
    for(int i=0; i<B.size(); i++)
        v.push_back(v1[i].second);
    
    return v;
    
}
