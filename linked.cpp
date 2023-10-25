#include <ctime>
#include <string>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <cstdlib>
#include <iostream>

#include "linked.h"
#include "node.h"

using namespace std;


//Link default un-paramaterized constructor, sets the member variable unsigned int length to zero, sets the Node *head to nullptr
Linked::Linked()
{
    length = 0;
    head = nullptr;
}

//Link copy constructor, never used. Sets the value of the second link to the length of the orginal Link
Linked::Linked(const Linked &linked2)
{
    length = linked2.length;
}

//Link destructor, does nothing because all memory is feed in clear()
Linked::~Linked()
{
    //delete [] head;
}

//Returns the Link class data member int length. In case needed in main(), only used for testing
int Linked::get_length()
{
    return length;
}

//Print function for the linked list. Creates a node pointer and sets it to the *head member variable. Then loops through the *next members of node untill it finds the end (when current_node->next is a nullptr). All the while it couts the val member variable of the current node
void Linked::print()
{
    cout << "\n\nYour linked list: ";
    Node *current_node = head;

    while(current_node != nullptr)
    {
        cout << current_node->val << " ";
        current_node = current_node->next;
    }
    //cout << endl;
}

//Push back function for the linked list. It first checks the edge case where head is a nullptr. If it finds that it is a nullptr. It then sets the head pointer as a newly contructed node passing x in to the node constructor for val. In all other cases, it loops through all the nodes, starting at head, and checks for a nullptr in the *next, when it finds the nullptr (the end), it sets that nodes->next as a new Node(x) which constructs a node setting val to x.
//It does this by creating a *current_node, and setting it to head, if it doesnt find a nullptr in current_node->next, it the sets current_node to current_node->next, meaning it the cycles through next node and checks again
unsigned int Linked::push_back(int x)
{
    if (head == nullptr)
    {
        head = new Node(x);
        //cout << head->val << " ";
    }
    else
    {
        Node *current_node;
        current_node = head;

        int end_found = 0;
        while(!end_found)
        {
            if (current_node->next == nullptr)
            {
                  current_node->next = new Node(x);
                  //cout << current_node->val << " ";
                  end_found = 1;
            }
            else
            {
                  //cout << current_node->val << " ";
                  current_node = current_node->next;
            }
        }
    }
    length ++;
    return length;
}

//Push front function for the linked list. It first checks the edge case where head is a nullptr. If it finds that it is a nullptr. It then sets the head pointer as a newly contructed node passing x in to the node constructor for val. In all other cases. It will create a new Node(x) giving that nodes val the value of x, and sets that nodes *next value as head, and setting head to the new node, meaning it becomes the new head and its next value is the old head.
unsigned int Linked::push_front(int x)
{
    if (head == nullptr)
    {
        head = new Node(x);
    }
    else
    {
        Node *current_node = new Node(x);
        current_node->next = head;
        head = current_node;
    }
    length ++;
    return length;
}

//The insert function for the linked list. It first checks the edge case where head is a nullptr. If it finds that it is a nullptr. It then sets the head pointer as a newly contructed node passing x in to the node constructor for val. It the checks the other edge case where the index is 1 (really means zero). In the case it will just call the push_front() function. In all other cases, it creates a current_node and a next_node nod pointer. It sets current as head. It then loops through the *next
//values of the current_node, until it gets to the correct index. There it sets next node as a newly contructed node. It sets its next value as the next value of current node, and current_node's next value as it. Effectively inserting itself in the list at the index
unsigned int Linked::insert(int x, unsigned int index)
{
    if (head == nullptr)
    {
        head = new Node(x);
    }
    else if (index == 1)
    {
        push_front(x);
    }
    else
    {
        Node *current_node;
        Node *next_node;
        current_node = head;

        unsigned int i = 0;
        while(i <= (index - 2))
        {
            if (i == (index - 2))
            {
                next_node = new Node(x);
                next_node->next = current_node->next;
                current_node->next = next_node;
            }
            else
            {
                current_node = current_node->next;
            }
            i++;
        }
    }
    length ++;
    return length;
}

//The clear function for the linked list. It starts off by creating two node pointers. It sets the current_node to point to the head. It the loops until it finds that the current_node is a nullptr. It will first se the next_node to the current_node->next, that way it stores the next node without losing it. Then it deletes the current_node, freeing its memory. Then it sets the current_node node as the next_node, allowing it to loop through all the nodes. Lastly, it sets the head as a nullptr
void Linked::clear()
{
    Node *current_node, *next_node;
    current_node = head;

    while (current_node != nullptr)
    {
        next_node = current_node->next;
        delete current_node;
        current_node = next_node;
    }

    head = nullptr;
    length = 0;
}

//Sort ascending function. Calls the MergeSort() function passing in head.
void Linked::sort_ascending()
{
    MergeSort(&head);
}

//Sort descending function. Calls the MergeSort() function passing in head. It then calls the flip_order() function. Allowing it do be decsending isntead of ascending
void Linked::sort_descending()
{
    MergeSort(&head);
    flip_order();
}

//Print number of prime numbers in the linked list. Loops through all of the nodes and their *next to like the other functions, it then checks if the val of that node is <= 1. Since 0 1 and negative numbers are not considered prime in this program. If not, it then checks if the val can be divided by all whole numbers from one to val without getting a remainder. If it finds a number it can be divided by without a remainder. It knows its not a prime.
//If no values are found for that node, it adds to the counter and loops to the next. If a value is found that can be divided, it loops to the next without doing anything. When it finds the end (nullptr), it prints out the counter value which is the number of prime numbers.
void Linked::print_num_of_primes()
{
    Node *current_node = head;
    int prime_count = 0;

    while(current_node != nullptr)
    {
        bool isPrime = true;
        if (current_node->val <= 1)
        {
            isPrime = false;
        }
        else
        {
            for (int j = 2; j <= current_node->val / 2; ++j) {
                if (current_node->val % j == 0)
                {
                    isPrime = false;
                    break;
                }
            }
        }
        if(isPrime == true)
        {
            prime_count ++;
        }
        current_node = current_node->next;
    }
    cout << "\nYou have " << prime_count << " prime number(s) in your list.\n\n";
}

//The merge function for the Linked list. Does the actually comparisins of each nodes val and returns which node to swich. recieves two heads because the linked list is split in two before. Sorts in ascending.
Node* Linked::Merge(Node* head1, Node* head2)
{
	Node *temp1;
	Node *temp2;
	Node *temp;

	if(head1 == nullptr)
  {
		return head2;
  }

	if(head2 == nullptr)
  {
		return head1;
  }

	temp1 = head1;
	while (head2 != nullptr)
	{
		temp2 = head2;
		head2 = head2->next;
		temp2->next = nullptr;

		if(head1->val > temp2->val)
		{
			temp2->next = head1;
			head1 = temp2;
			temp1 = head1;
			continue;
		}

		flag:
		if(temp1->next == nullptr)
		{
			temp1->next = temp2;
			temp1 = temp1->next;
		}
		else if((temp1->next)->val <= temp2->val)
		{
			temp1 = temp1->next;
			goto flag;
		}
		else
		{
			temp = temp1->next;
			temp1->next = temp2;
			temp2->next = temp;
		}
	}

	return head1;
}

//Merge sort main function. Creates three temporary nodes. Two to split and one for the final merge. Merges in ascending order. Calls itself recursively while looping through nodes
void Linked::MergeSort(Node **head)
{
	Node *first;
	Node *second;
	Node *temp;
	first = *head;
	temp = *head;

	if(first == nullptr || first->next == nullptr)
	{
		return;
	}
	else
	{
		while(first->next != nullptr)
		{
			first = first->next;
			if(first->next != nullptr)
			{
				temp = temp->next;
				first = first->next;
			}
		}

		second = temp->next;
		temp->next = nullptr;
		first = *head;
	}

	MergeSort(&first);
	MergeSort(&second);
	*head = Merge(first, second);
}

//Flips the order of the linked list. Loops through the nodes of the linked list and sswitches the pointer values
void Linked::flip_order()
{
    Node *current_node = head;
    Node *previous_node = nullptr;
    Node *next_node = nullptr;

    while (current_node != nullptr)
    {
        next_node = current_node->next;
        current_node->next = previous_node;
        previous_node = current_node;
        current_node = next_node;
    }

    head = previous_node;
}
