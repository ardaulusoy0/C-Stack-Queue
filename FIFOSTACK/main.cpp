#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Kuyruk.cpp"

using namespace std;

int main() {
	Kuyruk kuyruk;
	Kuyruk gecici;
	int enBuyuk = INT_MIN , enKucuk = INT_MAX;

	srand(time(0));
	
	for(int i = 0; i<100; i++) {
		int sayi = rand() % 100 +1;
		if(sayi % 2 == 0) {
			kuyruk.Enqueue(sayi);
		}
	}
	
	cout<<"Sayilar: ";
	while(kuyruk.getCount()) {
		int sayim = kuyruk.	Dequeue();
		cout << sayim << " | ";
		gecici.Enqueue(sayim);
		
		(sayim > enBuyuk) ? enBuyuk = sayim : enBuyuk;
		(sayim < enKucuk) ? enKucuk = sayim : enKucuk;

	}
	
	cout<<endl;
	cout<<"En Buyuk Sayi: "<< enBuyuk<< endl;
	cout<<"En Kucuk Sayi: "<< enKucuk<< endl;
	
	return 0;
}
