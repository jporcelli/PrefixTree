//
//  node.h
//  suggest
//
//  Created by james porcelli on 2/21/14.
//  Copyright (c) 2014 james porcelli. All rights reserved.
//

#ifndef suggest_node_h
#define suggest_node_h

#include <unordered_map>

using namespace std;

/**
 * Represents a node in a prefix tree.
 *
 * Node{
 *  letter: The letter for this node in the prefix tree,
 *  childCount: The number of children for this node,
 *  children: The data structure holding the child nodes
 *      of this node,
 *  value: The value representing the end of a word (path) in the tree,
 *  level: The height of this node in the tree (Root is level 0)
 * }
 */
class Node{
    
public:
    Node(char);
    Node(char, int);
    
    Node* addChild(Node*);
    Node* const getChild(char);
    
    char const getLetter();
    void setLetter(char);
    
    int const getChildCount();
    void setChildCount(int);
    
    int const getValue();
    void setValue(int);
    
    int const getLevel();
    void setLevel(int);
    
    unordered_map<char, Node> const getChildren();
    
private:
    char letter;
    int childCount;
    int value;
    int level;
    unordered_map<char, Node> children;
};


#endif
