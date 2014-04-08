//
//  trie.cpp
//  suggest
//
//  Created by james porcelli on 2/21/14.
//  Copyright (c) 2014 james porcelli. All rights reserved.
//

#include "trie.h"

#include <stack>

/**
 * Constructs a new trie, where the root corresponds to the empty string.
 *
 * @TODO - Optimize the trie implementation as much as possible
 */
Trie::Trie(): root(new Node(' ')){};

Node* const Trie::getRoot(){
    return root;
}

void Trie::setRoot(Node *p_root){
    root = p_root;
}

/**
 * Insert a string into the Trie.
 *
 * @param s - The string to insert.
 */
void Trie::insert(string s){
    int i = 0;
    int n = int(s.length());
    Node* node = root;
    
    while(i < n){
        Node* next = node->getChild(s[i]);
        if(next){
            node = next;
            i++;
        }else{
            break;
        }
    }
    
    while(i < n){
        node = node->addChild(new Node(s[i], i + 1));
        i++;
    }
    
    //Can update new path end node value at this point
}

/**
 * Search through the trie and return all
 * descendents of the given node.
 *
 * @param node - Pointer to the node in the tree 
 *  representing the prefix from which we
 *  wish to search.
 * @param prefix - The prefix to search on.
 */
vector<string> Trie::preOrder(Node* node, string prefix){
    stack<Node> s;
    vector<string> words;
    
    s.push(*node);
    
    int prev_wrd_lvl = 0;
    
    prefix.pop_back();
    string word = prefix;
    
    bool flag = false;
    
    if(!node){
        return words;
    }else{
        while(!s.empty()){
            Node v = s.top();
            s.pop();
            
            if(flag){
                int k = v.getLevel() - prev_wrd_lvl;
                word = (word.substr(0, word.length() - (k + 1)) += v.getLetter());
                flag = false;
            }else{
                word += v.getLetter();
            }
            
            if(v.getChildCount() == 0){
                words.push_back(word);
                flag = true;
                prev_wrd_lvl = v.getLevel();
            }else{
                for(auto it = v.getChildren().cbegin(); it != v.getChildren().cend(); ++it)
                    s.push(it->second); // the value
            }
        }
        return words;
    }
}

/**
 * Get a result set containing descendents of
 * the node given by the prefix specified by the
 * string parameter.
 *
 * @param s - The prefix to search on.
 */
vector<string> Trie::getDescendents(string prefix){
    int i = 0;
    int n = int(prefix.length());
    Node* node = root;
    vector<string> results;
    
    while(i < n){
        Node* child = node->getChild(prefix[i]);
        if(child){
            node = child;
            i++;
        }else{
            return results; //empty
        }
    }
    return preOrder(node, prefix); //descendents
}


