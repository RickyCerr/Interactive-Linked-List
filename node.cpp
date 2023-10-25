#include <ctime>
#include <string>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <iostream>

#include "node.h"

using namespace std;


//default constructor for node, never used. Sets member functions int val to zero, *next to nullptr
Node::Node()
{
    val = 0;
    next = nullptr;
}

//paramaterized constructor for node. Sets member functions int val to input of x, *next to nullptr
Node::Node(int x)
{
    val = x;
    next = nullptr;
}

//copy constructor for node. Sets the values of the node (val and *next) equal to the values of the copied node
Node::Node(const Node &node2)
{
    val = node2.val;
    next = node2.next;
}

//node destructor, does not need to delete anything because all memory is freed in the Linked class in clear()
Node::~Node()
{
    //delete [] next;
}

//does not need any other member functions because the data members are all public
