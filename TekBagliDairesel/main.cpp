#include <iostream>
#include "List.cpp"

using namespace std;
int main(int argc, char** argv) {
	int iskod, data, index;
	List *liste = new List();
	do {
		cout << endl;
		cout << "Liste Islemleri: "<<endl;
		cout << "Sil..........[0]" <<endl;
		cout << "Listele......[1]" <<endl;
		cout << "Ara..........[2]" <<endl;
		cout << "Basa Ekle....[3]" <<endl;
		cout << "Sona Ekle....[4]" <<endl;	
		cout << "Araya Ekle...[5]" <<endl;
		cout << "Bosalt.......[6]" <<endl;
		cout << "Eleman Say...[7]" <<endl;
		cout << "Cikis........[8]" <<endl;
		cout << "Islem Kodu:..";
		cin>>iskod;
		cout<<endl;
		
		switch(iskod) {
			case 0:
				cout << "Index: ";
				cin>>index;
				liste->Sil(index);
				break;
			case 1:
				liste->Listele();
				break;
			case 2:
				cout<<"Aranacak Sayi: ";
				cin>>data;
				index = liste->Ara(data);
				if(index == -1) {
					cout << "Aranan sayi bulunamadi."<<endl;
				} else {
					cout << "Aranan sayi indexi: "<<index<<endl;
				}
				break;
			case 3:
				cout << "Eklenecek Sayi: ";
				cin>>data;
				liste->BasaEkle(data);
				break;
			case 4:
				cout << "Eklenecek Sayi: ";
				cin>>data;
				liste->SonaEkle(data);
				break;
			case 5:
				cout << "Eklenecek Sayi: ";
				cin>>data;
				cout << "Index: ";
				cin>>index;
				liste->ArayaEkle(index,data);
				break;
			case 6:
				liste->Bosalt();
				break;
			case 7:
				cout<<"Eleman Sayisi: "<<liste->elemanSay()<<endl;
				break;
			case 8:
				cout <<"Cikis yapildi."<<endl;
				break;
			default:
				cout<<"Gecersiz Kod!."<<endl;
				break;
		} 
		
	}while(iskod != 8);
	return 0;
}
