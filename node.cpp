//
//  node.cpp
//  suggest
//
//  Created by james porcelli on 2/21/14.
//  Copyright (c) 2014 james porcelli. All rights reserved.
//

#include "node.h"

/**
 * Constructs a new node for a prefix tree.
 *
 * @param c - The letter corresponding to the node in the
 *  prefix tree.
 */
Node::Node(char c):letter(c), childCount(0), value(-1){};

/**
 * Constructs a new node for a prefix tree
 *
 * @param c - The letter corresponding to the node in the prefix tree.
 * @param l - The level in the tree of this node.
 */
Node::Node(char c, int l):letter(c), childCount(0), value(-1), level(l){}

/**
 * Add a child to this node.
 *
 * @param child - The child node to add to this nodes children.
 *
 * @return The new child added to this node.
 */
Node* Node::addChild(Node* child){
    childCount++;
    return &(children[child->letter] = *child);
}

/**
 * Retrieves the data structure holding the children for
 * this node.
 */
unordered_map<char, Node> const Node::getChildren(){
    return children;
}

/**
 * Retrieves a child with the specified letter from
 * this node.
 *
 * @param letter - The letter of the desired child of the node.
 *
 * @return The child of this node with the specified letter, or
 *  NULL if no child exists for this node.
 */
Node* const Node::getChild(char letter){
    try{
       return &(children.at(letter));
    }catch(out_of_range){
        return NULL;
    }
}

//Accessors/Mutators 

char const Node::getLetter(){
    return letter;
}

void Node::setLetter(char p_letter){
    letter = p_letter;
}

int const Node::getChildCount(){
    return childCount;
}

void Node::setChildCount(int p_childCount){
    childCount = p_childCount;
}

int const Node::getValue(){
    return value;
}

void Node::setValue(int p_value){
    value = p_value;
}

int const Node::getLevel(){
    return level;
}

void Node::setLevel(int p_level){
    level = p_level;
}








