/**
 * Name: dynamic_memory.cpp
 * Purpose: dynamic memory usage
 * Author: joeldevel
 * Date: 06/2020
 * Version: 0.0
 * Compile: g++ dynamic_memory.cpp -o dynamic_memory
 * Usage: ./dynamic_memory
 */

#include<iostream>
using namespace std;

typedef int node_entry;

struct node
{
  node_entry data;
  node* next;
  node() {
    this->data = 0;
    this->next = nullptr;
  }
  node(node_entry data) {
    this->data = data;
    this->next = nullptr;
  }
  node(node_entry data, node& next) {
    this->data = data;
    this->next = &next;
  }
};

int main(){

  // Create a pointer to a node that points to a node in the heap
  node* first_node = new node;
  cout << "node data: " << first_node->data << endl;
  cout << "node next: " <<first_node->next << endl;

  // Create another node and attach it to the previous one
  node* another_node = new node(77);

  first_node->next = another_node;

  cout << "first_node next data: " << first_node->next->data << endl;

  // Create some nodes to make a list
   node* beta = new node(17);
   node* alpha = new node(13, *beta);
   another_node->next = alpha;
  
   // The list should be like this at this point
  
  // |first_node| -->  |another_node| --> |alpha| --> |beta| -->nullptr
  // |  0       |      |  77        |     | 17  |     | 13 |  

  // Traverse the list
  node* aux = first_node;
  
  while(aux) {  // While aux not nullptr
    cout << "Mem. Address: " << aux << " Data in node: " << aux->data << endl;
    aux = aux->next; // Move to the next node
  }

  // Free the memory
  delete first_node;
  delete another_node;
  delete alpha;
  delete beta;

  return 0;
}
