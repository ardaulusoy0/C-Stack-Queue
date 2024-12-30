#include <iostream>
#include <cstdlib>
#include "Node.cpp"

using namespace std;
class Stack {
	private: 
		Node *head = NULL;
		int count = 0;
	public:
		void Push(int data) {
		
			Node *yeni = new Node;
			yeni->data = data;
			yeni->next = head;
			head = yeni;
			count++;
		}
		
		int Pop() {
			int data = 0;
			if(head != NULL) {
				Node *tmp = head;
				data = tmp->data;
				head = tmp->next;
				delete tmp;
				count--;
			} else {
				cout<< "Liste Bos";
			}
			return data;
		}
		
		int GetCount() {
			return count;
		}
};
