#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Stack.cpp"

using namespace std;
int main() {
	Stack stack;
	Stack gecici;
	int toplam = 0, count = 0;
	srand(time(0));
	
	for(int i = 0; i<100; i++) {
		int sayi = rand() % 100 + 1;
		if(sayi % 2 != 0) {
			stack.Push(sayi);
		}
	}
	
	cout<<"Sayilar: ";
	while(stack.GetCount() != 0) {
		int sayim = stack.Pop();
		cout << sayim << " | ";
		gecici.Push(sayim);
		
		toplam += sayim;
		count++;
	}
	cout<<endl;
	double ortalama = (count > 0) ? (double)toplam/count : 0;
	cout<<"Toplam: "<< toplam<<endl;
	cout<<"Ortalama: "<< ortalama <<endl;
	
}
