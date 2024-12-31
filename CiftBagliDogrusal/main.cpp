#include <iostream>
#include <cstdlib>
#include "List.cpp"
int main(int argc, char** argv) {
	int index, data, iskod;
	List *liste = new List;
	do {
		cout<<"\nIslem Tablosu:\n"<<
		"Listeyi Sil...[0]\n"<<
		"Listele.......[1]\n"<<
		"Ara...........[2]\n"<<
		"Basa Ekle.....[3]\n"<<
		"Sona Ekle.....[4]\n"<<
		"Araya Ekle....[5]\n"<<
		"Sil...........[6]\n"<<
		"Eleman Say....[7]\n"<<
		"Cikis.........[8]\n\n"<<
		"Islem Kodu Giriniz :";
		cin>>iskod;
		
		switch(iskod) {
			case 0:
				liste->Bosalt();
				break;
			case 1:
				liste->Listele();
				cout<<endl;
				break;
			case 2:
				cout<<"Aranacak Sayi: ";
				cin>>data;
				index = liste->Ara(data);
				if(index == -1) {
					cout<<"Aranan sayi dizide yok\n\n";
				} else {
					cout<<"Aranan eleman indexi: "<<index<<"\n\n";
				}
				break;
			case 3:
				cout<<"Eklenecek Sayi: ";
				cin>>data;
				liste->BasaEkle(data);
				break;
			case 4:
				cout<<"Eklenecek Sayi: ";
				cin>>data;
				liste->SonaEkle(data);
				break;
			case 5:
				cout<<"Eklenecek Sayi: ";
				cin>>data;
				cout<<"Index: ";
				cin>>index;
				liste->ArayaEkle(data , index);
				break;
			case 6:
				cout<<"Index: ";
				cin>>index;
				liste->Sil(index);
				break;
			case 7:
				cout<<"Eleman Sayisi: "<<liste->ElemanSay()<<"\n\n";
				break;
			case 8:
				cout<<"Cikis Yapildi."<<endl;
				break;
			default:
				cout<<"Hatali Kod \n";
				break;
		}
		
	} while(iskod != 8);
}
