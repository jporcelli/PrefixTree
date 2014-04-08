//
//  trie.h
//  suggest
//
//  Created by james porcelli on 2/21/14.
//  Copyright (c) 2014 james porcelli. All rights reserved.
//

#ifndef suggest_trie_h
#define suggest_trie_h

#include "node.h"

#include <vector>
#include <string>

using namespace std;

/**
 * Represents a prefix tree, a Trie.
 *
 * Trie{
 *  root: The root of the tree
 * }
 */
class Trie{
    
public:
    Trie();
    
    void insert(string);
    
    vector<string> getDescendents(string);
    
    vector<string> preOrder(Node*, string);
    
    Node* const getRoot();
    void setRoot(Node*);
    
private:
    Node* root;
};

#endif
