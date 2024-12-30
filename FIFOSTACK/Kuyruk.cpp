#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Node.cpp"

using namespace std;
class Kuyruk {
	private:
		Node *front = NULL;
		Node *rear = NULL;
		int count = 0;
	public:
		void Enqueue(int data) {
			Node *yeni = new Node;
			yeni->next = NULL;
			yeni->data = data;
			
			if(count == 0) {
				front = yeni;
			} else {
				rear->next = yeni;
			}
			
			rear = yeni;
			count++;
		}
		
		int Dequeue() {
			if(count != 0) {
				Node *tmp = front;
				int data = front->data;
				front = front->next;
				
				if(front == NULL) {
					rear = NULL;
				}
				count--;
				delete tmp;
				return data;
				
			} else {
				cout<<"Liste Bos";
			}
			return -1;
		}
		
		int getCount() {
			return count;
		}
};               
