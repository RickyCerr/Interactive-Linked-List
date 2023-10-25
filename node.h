#ifndef NODE_H
#define NODE_H

#include <string>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <iostream>

using namespace std;

class Node
{
private:
public:
    int val;
    Node *next;
    Node();
    Node(int x);
    Node(const Node &node);
    ~Node();

    //int get_val();
    //Node* get_next();
    //void set_val(int x);

   //string getBreed();

   //void setBreed(string breed);

   //string getLifespan();


   //double area() const;

};

#endif
