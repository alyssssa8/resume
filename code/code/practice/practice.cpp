

#include <string>
#include <iostream>


using namespace std;

const int ALPHABET_SIZE = 26;
// trie node 
struct trieNode {
    trieNode *children[ALPHABET_SIZE];
    bool EndOfString;
    int val;
};

// Returns new trie node (initialized to NULLs) 

struct trieNode* getNode(void) {
    trieNode *pNode = new trieNode;
    pNode->EndOfString = false;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        pNode->children[i] = nullptr;
    }
    return pNode;

}

// If not present, inserts key into trie 
// If the key is prefix of trie node, just 
// marks leaf node 

void insert(trieNode *root, string key, int i) {
    trieNode *temp = root;
    for (int i = 0; i < key.size(); i++) {
        int index = key[i] - 'a';
        if (!temp->children[index]) {
            temp->children[index] = getNode();
        }
        temp = temp->children[index];
    }
    temp->EndOfString = true;
    temp->val = i;
}


// Returns true if key presents in trie, else 
// false 
bool search(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return false;

        pCrawl = pCrawl->children[index];
    }

    return (pCrawl != NULL && pCrawl->isEndOfWord);
}

// Driver 
int main()
{
    // Input keys (use only 'a' through 'z' 
    // and lower case) 
    string keys[] = { "the", "a", "there",
                    "answer", "any", "by",
                    "bye", "their" };
    int n = sizeof(keys) / sizeof(keys[0]);

    struct TrieNode *root = getNode();

    // Construct trie 
    for (int i = 0; i < n; i++)
        insert(root, keys[i], i);

    // Search for different keys 
    search(root, "the") ? cout << "Yes\n" :
        cout << "No\n";
    search(root, "these") ? cout << "Yes\n" :
        cout << "No\n";
    return 0;
}
