#ifndef LINKED_H
#define LINKED_H

#include <ctime>
#include <string>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <iostream>

#include "node.h"

using namespace std;

class Linked
{
private:
    int length;
    Node *head;
public:
    Linked();
    Linked(const Linked &linked2);
    ~Linked();

   int get_length();

   void print();
   void clear();

   unsigned int push_back(int x);
   unsigned int push_front(int x);
   unsigned int insert(int x, unsigned int index);

   void sort_ascending();
   void sort_descending();

   void print_num_of_primes();

   Node* Merge(Node* h1, Node* h2);
   void MergeSort(Node **head);

   void flip_order();

};

#endif
