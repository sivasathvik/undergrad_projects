#include<iostream> 
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
using namespace std; 
struct TrNode 
{ 
    struct TrNode *child[26]; 
    bool isEnd; 
}; 
struct TrNode *getNode(void) 
{ 
    struct TrNode *pNode = new TrNode; 
    pNode->isEnd = false; 
    for (int i = 0; i < 26; i++) 
        pNode->child[i] = NULL; 
    return pNode; 
} 
void insert(struct TrNode *root, string key) 
{ 
    struct TrNode *curr = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a';  
        if (!curr->child[index]) 
            curr->child[index] = getNode(); 
  
        curr = curr->child[index]; 
    } 
  

    curr->isEnd = true; 
}
bool search(struct TrNode *root, const string key) 
{ 
    int length = key.length(); 
    struct TrNode *curr = root; 
    for (int i = 0; i < length; i++) 
    { 
        int index = key[i] - 'a';  
        if (!curr->child[index]) 
            return false; 
        curr = curr->child[index]; 
    }  
    return (curr != NULL && curr->isEnd); 
}
bool isLastNode(struct TrNode* root) 
{ 
    for (int i = 0; i < 26; i++) 
        if (root->child[i]) 
            return 0; 
    return 1; 
} 
void suggestionsRec(struct TrNode* root, string currPrefix) 
{ 
    if (root->isEnd) 
    { 
        cout << currPrefix; 
        cout << endl; 
    } 
    if (isLastNode(root)) 
        return; 
    for (int i = 0; i < 26; i++) 
    { 
        if (root->child[i]) 
        {  
            currPrefix.push_back(97 + i); 
            suggestionsRec(root->child[i], currPrefix); 
        } 
    } 
}
int printAutoSuggestions(TrNode* root, const string query) 
{ 
    struct TrNode* curr = root;  
    int n = query.length(); 
    for (int i = 0; i < n; i++) 
    { 
        int index = CHAR_TO_INDEX(query[i]); 
        if (!curr->child[index]) 
            return 0; 
        curr = curr->child[index]; 
    } 
    bool isWord = (curr->isEnd == true);
    bool isLast = isLastNode(curr); 
    if (isWord && isLast) 
    { 
        cout << query << endl; 
        return -1; 
    } 
    if (!isLast) 
    { 
        string prefix = query; 
        suggestionsRec(curr, prefix); 
        return 1; 
    } 
} 
int main() 
{ 
    char output[][32] = {"Not present in trie", "Present in trie"}; 
  string key[] = {"tahe", "a", "tahere", 
     "tar", "tahree", "by", 
     "bye", "taheire", }; 
 int n = sizeof(key)/sizeof(key[0]); ;    
 struct TrNode* root = getNode(); 
 for (int i = 0; i < n; i++) 
  insert(root, key[i]);
 // char S[100];
  //printf("enter the prefix of the word to be searched:") ;
 // scanf("%s",&S);
 printf("The input words are:tahe,a,tahere,tar,tahree,by,bye,taheire\n");
 printf("Words with prefix t:\n");
    int comp = printAutoSuggestions(root, "t"); 
    if (comp == -1) 
        cout << "No other strings found with this prefix\n"; 
 else if (comp == 0) 
        cout << "No string found with this prefix\n"; 
         printf("Words with prefix ta:\n");
         int comp1 = printAutoSuggestions(root, "ta"); 
    if (comp1 == -1) 
        cout << "No other strings found with this prefix\n"; 
 else if (comp1 == 0) 
        cout << "No string found with this prefix\n";
         printf("Words with prefix tah:\n");
         int comp2 = printAutoSuggestions(root, "tah"); 
    if (comp2 == -1) 
        cout << "No other strings found with this prefix\n"; 
 else if (comp2 == 0) 
        cout << "No string found with this prefix\n";
         printf("Words with prefix tahe:\n");
         int comp3 = printAutoSuggestions(root, "tahe"); 
    if (comp3 == -1) 
        cout << "No other strings found with this prefix\n"; 
 else if (comp3 == 0) 
        cout << "No string found with this prefix\n";
         printf("%s --- %s\n", "tahe", output[search(root, "tahe")] ); 
           printf("%s --- %s\n", "taheire", output[search(root, "taheire")] ); 
             printf("%s --- %s\n", "tahere", output[search(root, "tahere")] ); 
			  printf("%s --- %s\n", "tar", output[search(root, "tar")] );
			   printf("Words with prefix b:\n");
    int comp4 = printAutoSuggestions(root, "b"); 
    if (comp4 == -1) 
        cout << "No other strings found with this prefix\n"; 
 else if (comp4 == 0) 
        cout << "No string found with this prefix\n";  
         printf("Words with prefix by:\n");
    int comp5 = printAutoSuggestions(root, "by"); 
    if (comp5 == -1) 
        cout << "No other strings found with this prefix\n"; 
 else if (comp5 == 0) 
        cout << "No string found with this prefix\n";
         printf("Words with prefix bye:\n");
    int comp6 = printAutoSuggestions(root, "bye"); 
    if (comp6 == -1) 
        cout << "No other strings found with this prefix\n"; 
 else if (comp6 == 0) 
        cout << "No string found with this prefix\n";
         printf("%s --- %s\n", "bye", output[search(root, "bye")] ); 
          printf("%s --- %s\n", "by", output[search(root, "by")] ); 
        
			  
            
           
    return 0; 
}
