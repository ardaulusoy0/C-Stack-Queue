#include <iostream>
#include "Node.cpp"

using namespace std;

class List {
	private:
		Node *head = NULL;
	public:
		
		
		void Listele() {
			// Son -> Ýlk , Son <- Ýlk
			if(head == NULL) {
				cout<<"Liste Bos!"<<endl;
			} else {
				Node *tmp = head;
				do {
					cout<<tmp->data<<"<->";
					tmp = tmp->next;
				} while(tmp != head);
				cout<<endl;
			}
		}
		
		void BasaEkle(int data) {
			Node *yeni = new Node;
			yeni->data = data;
			if(head == NULL)  {
				head = yeni;
				yeni->next = head;
				yeni->prev = head;	
				
			}  else {
				yeni->next = head;
				yeni->prev = head->prev;
				
				head->prev->next = yeni;
				head->prev = yeni;
				
				head = yeni;	
			}
			
		}
		
		void SonaEkle(int data) {
			Node *yeni = new Node;
			yeni->data = data;
			
			
			if(head == NULL) {
				head = yeni;
				yeni->next = head;
				yeni->prev = head;
			} else {
				Node *last = head;
				while(last->next != head) {
					last = last->next;
				}
				
				last->next = yeni;
				yeni->prev = last;
				yeni->next = head;
				head->prev = yeni;
			}
			
		}
		
		void ArayaEkle(int data , int index) {
			if(index < 0 ||index >= ElemanSay()) {
				cout<<"Gecersiz.\n";	
				return;			
			}
			
			Node *yeni = new Node;
			yeni->data = data;
			
			if(index == 0) {
				BasaEkle(data);
				return;
			} else {
				Node *tmp = head;
				for(int i = 0; i < index - 1; i++) {
					if(tmp->next == head) {
						cout << "Geçersiz Pozisyon" <<endl;
						return;
					}
					tmp = tmp->next;
				}
				
				yeni->next = tmp->next;
				yeni->prev = tmp;
				
				if(tmp->next != NULL) {
					tmp->next->prev = yeni;
				}
				tmp->next = yeni;
			}
		}
		
		void Sil(int index) {
			if(head == NULL || index < 0) {
				cout<<"Liste bos ya da gecersiz index"<<endl;
				return;
			}
			
			Node *tmp = head;
			
			if(index == 0) {
				if(head->next == head) {
					delete head;
					head = NULL;
				} else {
					head->prev->next = head->next;
					head->next->prev = head->prev;
					
					head = head->next;
					
					delete tmp;
				}
				return;
			}
			
			for(int i = 0; i < index; i++) {
				tmp = tmp->next;
				if(tmp == head) {
					cout << "Gecersiz Pozisyon"<<endl;
					return;
				}
			}
			
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			
			delete tmp;
		}
		
		int Ara(int data) {
			if(head == NULL) {
				cout<<"Liste Bos"<<endl;
				return -1;
			}
			
			Node *tmp = head;
			int index = 0;
			
			
			do {
				if(tmp->data == data) {
					return index;
				}
				tmp = tmp->next;
				index++;
			} while(tmp != head);
			
			cout<<"Veri Bulunamadi."<<endl;
			return -1;
		}
		
		int ElemanSay() {
			int count = 0;
			if(head == NULL) {
				return 0;
			}
			Node *temp = head;
			do{
				count++;
				temp = temp->next;
			} while(temp != head);
			return count;
		}
		
		void Bosalt() {
			if(head == NULL) {
				cout<<"Liste Bos\n"<<endl;
				return;
			}
			
			Node *tmp = head;
			do {
				Node *tm = tmp->next;
				delete tmp;
				tmp = tm;
			} while(tmp != head);
			
			head = NULL;
		}
};
