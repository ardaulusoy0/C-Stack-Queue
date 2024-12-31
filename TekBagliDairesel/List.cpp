#include <iostream>
#include <cstdlib>
#include "Node.cpp"

using namespace std;
class List {
	private:
		Node *head = NULL;
	public:
		int elemanSay() {
			int count = 0;
			if(head == NULL) {
				return 0;
			} else {
				Node *tmp = head;
				while(tmp != NULL) {
					count++;
					tmp = tmp->next;
				}
				return count;
			}
		}
		
		void Listele() {
			if(head == NULL) {
				cout << "Liste Bos!"<<endl;
			} else {
				Node *tmp = head;
				
				do {
					cout << tmp->data << "->";
					tmp = tmp->next;
				} while(tmp != NULL);
				cout << "NULL\n";
			}
		}
		
		void BasaEkle(int data) {
			Node *yeni = new Node;
			yeni->next = head;
			yeni->data = data;
			head = yeni;
		}
		
		void SonaEkle(int data) {
			Node *yeni = new Node;
			yeni->data = data;
			yeni->next = NULL;
			
			Node *tmp = head;
			if(tmp == NULL) {
				head = yeni;
			} else {
				while(tmp->next != NULL) {
					tmp = tmp->next;
				}
				tmp->next = yeni;
			}
		}
		
		void ArayaEkle(int index , int data) {
			if(index < 0 || index >= elemanSay()) {
				cout << "\nIndex gecerli degil..\n";
				return;
			}
			
			Node *yeni = new Node;
			yeni->data = data;
			
			Node *tmp = head;
			for(int i = 0; i < index -1 ; i++) {
				tmp = tmp->next;
			} 
			if(index != 0) {
				yeni->next = tmp->next;
				tmp->next = yeni;
			} else {
				yeni->next = tmp;
				head = yeni;
			}
		}
		
		void Bosalt() {
			if(head == NULL) {
				cout << "Liste Bos!"<<endl;
				return;
			}
			
			Node *tmp = head;
			Node *tail = NULL;
			
			do{
				tail = tmp->next;
				delete tmp;
				tmp = tail;
			} while(tmp != NULL);
			
			head = NULL;
			cout << "Liste temizlendi." <<endl;
		}
		
		void Sil(int index) {
			if(index < 0 || index >= elemanSay()) {
				cout << "\nIndex gecerli degil..\n";
			}
			else if(index == 0) {
				Node *sil = head;
				head = head->next;
				delete sil;
			} else {
				Node *tmp = head;
				for(int i = 0; i <index -1; i++) {
					tmp = tmp->next;
				}
				Node *sil = tmp->next;
				tmp->next = tmp->next->next;
				delete sil;
			}
		}
		
		int Ara(int data) {
			int index = 0;;
			Node *tmp = head;
			while(tmp != NULL) {
				if(tmp->data == data) {
					return index;
				}
				tmp = tmp->next;
				index++;
			}
			return -1;
		}
};
