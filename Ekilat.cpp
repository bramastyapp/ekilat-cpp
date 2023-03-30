#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <string.h>
#define max 10

using namespace std;

struct customer{
	int data[max];
	string pengirim[max];
	string penerima[max];
	string alamat[max];
	int berat[max];
	int jarak[max];
	int head;
	int tail;
} antrian;

void create(){
	antrian.head=antrian.tail=-1;
}

int IsEmpty(){
	if(antrian.tail==-1)
		return 1;
	else
		return 0;
}

int IsFull (){
	if(antrian.tail==max-1)
		return 1;
	else
		return 0;
}

void enqueue(int data, string pengirim, string penerima, string alamat, int berat, int jarak){
	if(IsEmpty()==1){
		antrian.head=antrian.tail=0;
		antrian.data[antrian.tail]=data;
		antrian.pengirim[antrian.tail]=pengirim;
		antrian.penerima[antrian.tail]=penerima;
		antrian.alamat[antrian.tail]=alamat;
		antrian.berat[antrian.tail]=berat;
		antrian.jarak[antrian.tail]=jarak;
		
		cout <<"masuk! no resi       = "<<antrian.data[antrian.tail]<<endl;
		cout <<"masuk! nama pengirim = "<<antrian.pengirim[antrian.tail]<<endl;
		cout <<"masuk! nama penerima = "<<antrian.penerima[antrian.tail]<<endl;
		cout <<"masuk! nama alamat   = "<<antrian.alamat[antrian.tail]<<endl;
		cout <<"masuk! berat         = "<<antrian.berat[antrian.tail]<<endl;
		cout <<"masuk! jarak         = "<<antrian.jarak[antrian.tail]<<endl;
		system("pause");
		
	}else if (IsFull()==0){
		antrian.tail++;
		antrian.data[antrian.tail]=data;
		antrian.pengirim[antrian.tail]=pengirim;
		antrian.penerima[antrian.tail]=penerima;
		antrian.alamat[antrian.tail]=alamat;
		antrian.berat[antrian.tail]=berat;
		antrian.jarak[antrian.tail]=jarak;
		
		cout <<"masuk! no resi       = "<<antrian.data[antrian.tail]<<endl;
		cout <<"masuk! nama pengirim = "<<antrian.pengirim[antrian.tail]<<endl;
		cout <<"masuk! nama penerima = "<<antrian.penerima[antrian.tail]<<endl;
		cout <<"masuk! nama alamat   = "<<antrian.alamat[antrian.tail]<<endl;
		cout <<"masuk! berat         = "<<antrian.berat[antrian.tail]<<endl;
		cout <<"masuk! jarak         = "<<antrian.jarak[antrian.tail]<<endl;
		system("pause");

	}else{
		cout << "Antrian sudah penuh"<<endl;
		system("pause");
	}
}

int dequeue(){
	int i;
	int a = antrian.data[antrian.head];
	for(i=antrian.head;i<=antrian.tail-1;i++){
		antrian.data[i] = antrian.data[i+1];
		antrian.pengirim[i] = antrian.pengirim[i+1];
		antrian.penerima[i] = antrian.penerima[i+1];
		antrian.alamat[i] = antrian.alamat[i+1];
		antrian.berat[i] = antrian.jarak[i+1];
		antrian.jarak[i] = antrian.jarak[i+1];
	}
	cout<<"Antrian terhapus!"<<endl;
	system("pause");
	antrian.tail--;
	return a;

}

void clear(){
	antrian.head=antrian.tail=-1;
	cout<<"data antrian terhapus semua!"<<endl;
	system("pause");
}

void tampil(){
	if (IsEmpty()==0){
		for(int i=antrian.head;i<=antrian.tail;i++){
			cout<<"antrian ke - "<<i+1<<endl;
			cout<<"no resi	  	  = "<<antrian.data[i]<< endl;
			cout<<"Nama	pengirim  = "<<antrian.pengirim[i]<< endl;
			cout<<"Nama	penerima  = "<<antrian.penerima[i]<< endl;
			cout<<"Alamat		  = "<<antrian.alamat[i]<< endl;
			cout<<"Berat		  = "<<antrian.berat[i]<< endl;
			cout<<"Jarak		  = "<<antrian.jarak[i]<< endl;
			cout<<endl;
		}
			system("pause");
	}else{
		cout << "Antrian Kosong!"<<endl;
		system("pause");
	}
}

void tampiltotal(int b){
	
		int tanda=-1;
		for(int i=antrian.head;i<antrian.tail+1;i++)
		{
			if (b == antrian.data[i]){
				tanda=i;
				break;
			}
		}
		
	if (tanda!=-1){
		int i = tanda;
			int *ptr;
			ptr= &antrian.data[i];
			cout<<endl;
			cout<<"No. struk pembayran = "<< ptr <<endl;
			cout<<"no resi	  	  = "<<antrian.data[i]<< endl;
			cout<<"Nama	pengirim  = "<<antrian.pengirim[i]<< endl;
			cout<<"Nama	penerima  = "<<antrian.penerima[i]<< endl;
			cout<<"Alamat		  = "<<antrian.alamat[i]<< endl;
			cout<<"Berat		  = "<<antrian.berat[i]<< endl;
			cout<<"Jarak		  = "<<antrian.jarak[i]<< endl;
			int total = (antrian.berat[i]*2000)+(antrian.jarak[i]*3000);
			cout<<"Total bayar       = "<<total<<endl;
			}else{
			cout << "\nResi tidak ada!"<<endl;
			}			
			system("pause");
}

void tampilresi(){
	if (IsEmpty()==0){
		cout<<"no resi	  	  = ";
		for(int i=antrian.head;i<=antrian.tail;i++){
			cout<<antrian.data[i]<<"   ";
		}
			cout<<endl;
	}else{
		cout << "Antrian Kosong!"<<endl;
		system("pause");
}
}

void sortingA(){
	
	int temp1,  temp5, temp6, b;
	string temp2, temp3, temp4;
	for(int i=antrian.head; i<antrian.tail+1;i++){
	 	for(int j = i+1; j<antrian.tail+1; j++)
	 	{
	 	if(antrian.data[i]>antrian.data[j])
	 		{
	 			temp1 = antrian.data[i]; 
				antrian.data[i] = antrian.data[j];
				antrian.data[j] = temp1;
				
				temp2 = antrian.pengirim[i]; 
				antrian.pengirim[i] = antrian.pengirim[j];
				antrian.pengirim[j] = temp2;
				
				temp3 = antrian.penerima[i]; 
				antrian.penerima[i] = antrian.penerima[j];
				antrian.penerima[j] = temp3;
				
				temp4 = antrian.alamat[i]; 
				antrian.alamat[i] = antrian.alamat[j];
				antrian.alamat[j] = temp4;
				
				temp5 = antrian.berat[i]; 
				antrian.berat[i] = antrian.berat[j];
				antrian.berat[j] = temp5;
				
				temp6 = antrian.jarak[i]; 
				antrian.jarak[i] = antrian.jarak[j];
				antrian.jarak[j] = temp6;
				
			 }
	 	}
	  }
	  for (int i=antrian.head; i<antrian.tail+1;i++){
	  	cout << antrian.data[i]<<" ";
	  }
	  system("pause");
	
}

void sortingD(){
	
	int temp1,  temp5, temp6, b;
	string temp2, temp3, temp4;
	for(int i=antrian.head; i<antrian.tail+1;i++){
	 	for(int j = i+1; j<antrian.tail+1; j++)
	 	{
	 	if(antrian.data[i]<antrian.data[j])
	 		{
	 			temp1 = antrian.data[i]; 
				antrian.data[i] = antrian.data[j];
				antrian.data[j] = temp1;
				
				temp2 = antrian.pengirim[i]; 
				antrian.pengirim[i] = antrian.pengirim[j];
				antrian.pengirim[j] = temp2;
				
				temp3 = antrian.penerima[i]; 
				antrian.penerima[i] = antrian.penerima[j];
				antrian.penerima[j] = temp3;
				
				temp4 = antrian.alamat[i]; 
				antrian.alamat[i] = antrian.alamat[j];
				antrian.alamat[j] = temp4;
				
				temp5 = antrian.berat[i]; 
				antrian.berat[i] = antrian.berat[j];
				antrian.berat[j] = temp5;
				
				temp6 = antrian.jarak[i]; 
				antrian.jarak[i] = antrian.jarak[j];
				antrian.jarak[j] = temp6;
				
			 }
	 	}
	  }
	  for (int i=antrian.head; i<antrian.tail+1;i++){
	  	cout << antrian.data[i]<<" ";
	  }
	  system("pause");
	
}

void sequential(int cari){
	int tanda=-1;
		for(int i=antrian.head;i<antrian.tail+1;i++)
		{
			if (cari == antrian.data[i]){
				tanda=i;
				break;
			}
		}
		
	if (tanda!=-1){
		cout << "\n \n Data "<<antrian.data[tanda] <<" ditemukan!";
		cout<<endl;
		system("pause");
	}
	else {
		cout << "\n \n Data tidak ditemukan!";
		cout<<endl;
		system("pause");
	}
}

void judul () {
	cout << "===================================="<<endl;
    cout << "     Jasa Pengiriman Barang"<<endl;
    cout << "              E-Kilat"<<endl;
    cout << "    'Barang aman, Anda senang' "<<endl;
    cout << "===================================="<<endl;
};

int main ()
{
	int pilihan, no, berat, jarak, cari, bayar;
	string pengirim, penerima, alamat, user, pass;
	char login;
	create();
	
	salah:
	judul();
	cout << "Username : ";
	cin >> user;
	cout << "Password : ";
	cin >> pass;
	cout <<endl;	
	
if (user == "admin" && pass == "admin"){
		cout << "Anda berhasil login.\n";
		system("pause");
	do
	{
		system("cls");
		judul();
		cout<<"1. Tambah data baru"<<endl;
		cout<<"2. Hapus data"<<endl;
		cout<<"3. Tampilkan semua data"<<endl;
		cout<<"4. Urutkan data secara ascending"<<endl;
		cout<<"5. Urutkan data secara descending"<<endl;
		cout<<"6. Cari data berdasarkan no resi"<<endl;
		cout<<"7. Lihat total pembayaran berdasarkan no resi"<<endl;
		cout<<"8. Bersihkan semua data"<<endl;
		cout<<"9. Keluar"<<endl;
		cout<<endl;
		cout<<"Masukkan pilihan : ";
		cin >> pilihan;
		cout<<endl;
		switch(pilihan)
		{
			case 1:
				cout<<"Masukkan no resi         = ";
				cin>>no;
				cout<<"Masukkan nama pengirim   = ";
				cin>>pengirim;
				cout<<"Masukkan nama penerima   = ";
				cin>>penerima;
				cout<<"Masukkan alamat pemerima = ";
				cin>>alamat;
				cout<<"Berapa berat barang(Kg)  = ";
				cin >>berat;
				cout << "Jarak (Km)               = ";
				cin >>jarak;
				cout <<endl;
				enqueue(no, pengirim, penerima, alamat, berat, jarak); 
				break;
			case 2:dequeue(); 
				break;
			case 3:tampil(); 
				break;
			case 4:sortingA();
				break;
			case 5:sortingD();
				break;
			case 6:
				cout<<"Masukkan no resi yang ingin anda cari = ";
				cin>>cari;
				sequential(cari);
				break;
			case 7:
				tampilresi();
				cout<<"Masukkan no resi yang ingin diliat total pembayarannya = ";
				cin>>bayar;
				tampiltotal(bayar);
				break;
			case 8:clear();
				break;
			case 9: cout<<"Terimakasih";
		}
		getchar ();
		cout << endl;
		cout << endl;	
	}while(pilihan!=9);
	
}else{
		cout << "Maaf Username & Password anda masukan salah!\n\n";
		cout << "Login ulang ? (y/t) ";
		cin >> login;
		
		if (login == 'y' || login == 'Y'){  //sistem login
			system ("cls");
			goto salah;	
		}
	}
}
