#include "buku.h"
#define max 100

// user[][] = {nama ,nim, fakultas, email, password, buku 1, buku 2, buku 3}

string user[max][8];
string nama ,nim, fakultas, password, email, fakul, genreBuku, negaraBuku, pass;
char ulang, kembali_anggota;
int login, pengguna = 0, daftaruser=0, jmlBuku;

int hitungJumlahBuku(){
	jmlBuku = 0;
	for (int i = 0; i < 100; i++)
	{
		if (!buku[i][0].empty())
		{
			jmlBuku++;
		}
	}
	return jmlBuku;
}

void daftar(){
	system("cls");
	char ulang;
	cout << "Masukkan Nama                            : ";
	getline(cin, nama);
	cout << "Masukkan NIM                             : ";
	cin >> nim;
	cout << "Masukkan Fakultas (FTI/FEB/FISIP/FTM/FP) : ";
	cin >> fakul;
	do {
        if (ulang == 'y') {
            cout << "Email yang anda masukkan bukan email kampus.\nGunakan email kampus yang terdapat @student.upnyk.ac.id" << endl;
        }
        ulang = 'n';
        cout << "Masukkan Email Kampus                    : ";
        cin >> email;
        cin.ignore();
        // Cek apakah email mengandung @kampus.ac
        if (email.size() >= 20 && email.substr(email.size() - 20) == "@student.upnyk.ac.id") {
            ulang = 'n';
        } else {
            ulang = 'y';
        }
    } while (ulang == 'y');
	do
	{
		if (ulang == 'y') {
            cout << "Isikan password minimal 8 karakter!!" << endl;
        }
        ulang = 'n';
		cout << "Masukkan Password Bebas                  : ";
		getline(cin,pass);
		if (pass.length() > 8)
		{
			user[daftaruser][0] = nama;
			user[daftaruser][1] = nim;
			user[daftaruser][2] = fakul;
			user[daftaruser][3] = email;
			user[daftaruser][4] = pass;
			daftaruser++;
		} else {
			ulang = 'y';
		}
	} while (ulang == 'y');
}

void pinjam(){
	system("cls");
	char konfirmasi, pinjamLagi;
	bool konfirmasiPinjam;
	int pilihan, indeksBuku = 5;
	string nim;
	if (user[pengguna][7].empty())
	{
		cout << "Selamat datang di Perpustakaan IF-C" << endl;
		do
			{
				konfirmasi = 'n', ulang = 'n';
				pinjamLagi = 'n';
				for (int i = 0; i < maxBuku; i++)
				{
					cout << i+1 <<" "<< buku[i][0] << " Keterangan Buku : " << buku[i][6] << endl;
				}
				cout << "Masukkan nomor dari judul buku yang ingin anda pinjam : ";
				cin >> pilihan;
				if (buku[pilihan-1][6] == "Tersedia")
				{
					system("cls");
					cout << "Judul        : " << buku[pilihan-1][0] << endl;
					cout << "Penulis      : " << buku[pilihan-1][1] << endl;
					cout << "Penerbit     : " << buku[pilihan-1][2] << endl;
					cout << "Tahun terbit : " << buku[pilihan-1][3] << endl;
					cout << "Genre        : " << buku[pilihan-1][4] << endl;
					cout << "Asal         : " << buku[pilihan-1][5] << endl;
					cout << "Apakah anda yakin ingin meminjam buku " << buku[pilihan-1][0] << " y/n : ";
					cin >> konfirmasi;
					if (konfirmasi == 'y')
					{
						for (int i = 5; i < 8; i++)
						{
							if (!user[pengguna][i].empty())
							{
								indeksBuku = indeksBuku + 1;
							}
						}
						user[pengguna][indeksBuku] = buku[pilihan-1][0];
						buku[pilihan-1][6] = "Dipinjam";
					} else {
						cout << "Apakah anda ingin meminjam buku yang lain? y/n : ";
						cin >> ulang;
					}
				} else {
					cout << "Buku " << buku[pilihan-1][0] << " telah dipinjam. \nSilahkan pinjam buku yang lain!" << endl;
					system("pause");
					pinjamLagi = 'y';
				}
				if (pinjamLagi == 'y')
				{
					indeksBuku = 5;
				}
				
			} while (ulang == 'y' || pinjamLagi == 'y');
	} else {
		cout << "Anda telah memenuhi batasan peminjaman. \nSilahkan kembalikan buku yang anda pinjam untuk meminjam buku lainnya!" << endl;
	}
}

void daftarPinjam(){
	for (int i = 5; i < 8; i++)
	{
		if (!user[pengguna][i].empty())
		{
			cout << i - 4 << ". " << user[pengguna][i] << endl;
		}
	}
}

void ketAnggota(){
	system("cls");
	cout << "Selamat datang " << user[pengguna][0] << endl;
	cout << endl;
	cout << endl;
	cout << "Nama anda     : " << user[pengguna][0] << endl;
	cout << "Nim anda      : " << user[pengguna][1] << endl;
	cout << "Fakultas anda : " << user[pengguna][2] << endl;
	cout << "Email anda    : " << user[pengguna][3] << endl;
	cout << "Password anda : " << user[pengguna][4] << endl << endl;
	cout << "Buku yang anda pinjam" << endl;
	daftarPinjam();
}

void bacaBuku(){
	char noBaca,bacaBukuLain, ulangBaca;
	do
	{
		bacaBukuLain = 'n';
			system("cls");
			cout << "Semua buku yang telah anda pinjam" << endl << endl;
			for (int i = 5; i < 8; i++)
			{
				if (!user[pengguna][i].empty())
				{
					cout << i - 4 << ". " << user[pengguna][i] << endl;
				} else {
					cout << i - 4 << ". Kosong" << endl;
				}
			}
			cout << "4. Kembali" << endl;
			cout << "Masukkan no buku yang ingin anda baca : ";
			cin >> noBaca;
			switch (noBaca)
			{
			case '1':
			system("cls");
					do
					{
							for (int i = 0; i < maxBuku; i++)
							{
									if (user[pengguna][5] == buku[i][0])
									{
											cout << buku[i][7] << endl;
									}
							}
							cout << "Apakah anda ingin membaca buku yang lain? y / n : ";
							cin >> ulangBaca;
							if (ulangBaca == 'y')
							{
								bacaBukuLain = 'y';
							}
					} while (ulangBaca == 'n');
					break;
			case '2':
			system("cls");
					do
					{
							for (int i = 0; i < maxBuku; i++)
							{
									if (user[pengguna][6] == buku[i][0])
									{
											cout << buku[i][7] << endl;
									}
							}
							cout << "Apakah anda ingin membaca buku yang lain? y / n : ";
							cin >> ulangBaca;
							if (ulangBaca == 'y')
							{
								bacaBukuLain = 'y';
							}
					} while (ulangBaca == 'n');
					break;
			case '3':
			system("cls");
					do
					{
							for (int i = 0; i < maxBuku; i++)
							{
									if (user[pengguna][7] == buku[i][0])
									{
											cout << buku[i][7] << endl;
									}
							}
							cout << "Apakah anda ingin membaca buku yang lain? y / n : ";
							cin >> ulangBaca;
							if (ulangBaca == 'y')
							{
								bacaBukuLain = 'y';
							}
					} while (ulangBaca == 'n');
					break;
			case '4':
			kembali_anggota = 'y';
					break;
			
			default:
					break;
			}
	} while (bacaBukuLain == 'y');
}

void cetakSemuaBuku(){
	char kembali;
	do
	{
		kembali = 'n';
		system("cls");
		cout << "Daftar buku-buku yang terdapat di Perpustakaan IF-C" << endl;
		cout << setw(123) << setfill('=') << "" << endl;
		cout << setfill(' ');
		cout << "NO |  Judul Buku                                             | Tahun   | Genre                | Negara        | Tersedia  |" << endl;
		cout << setw(124) << setfill('-') << "-" << endl;  
		cout << setfill(' ');
		for (int i = 0; i < hitungJumlahBuku(); i++)
		{      
				cout <<setw(2)<<setfill(' ') << i + 1 << " | "
							<< setw(55) << left << buku[i][0] << " | "
							<< setw(7) << left << buku[i][3] << " | " 
							<< setw(20) << left << buku[i][4] << " | " 
							<< setw(13) << left << buku[i][5] << " | " 
							<< setw(9) << left << buku[i][6] << " | " << endl;
				cout << setw(124) << setfill('-') << "-" << endl;
				cout << setfill(' ');
		}
		cout << "Tekan y untuk keluar : ";
		cin >> kembali;
	} while (kembali == 'n' || kembali == 'N');
}

void kembalikanBuku(){
	cout << "Daftar buku yang anda pinjam" << endl;
	daftarPinjam();
	
}

int hitungbuku(){
	int count = 0;
	for (int i = 0; i < maxBuku; i++)
	{
		if (buku[i][0] != "")
		{
			count++;
		}
		else{
			break;
		}
		
	}
	return count;
	
}

void ubahdatabuku(){
    system("cls");
	int jumlahbuku = hitungbuku();
	string bukunew, penulisbaru, penerbitbaru, tahunterbitbaru, genrebaru, asalbaru;
	char inginlihat, kondisi;
	int ubahdata, nobuku, ketersediaan;
    cout << "Data apa yang ingin anda ubah : \n";
    cout << "1. Judul Buku \n"
    << "2. Penulis\n"
	<< "3. Penerbit\n"
	<< "4. Tahun Terbit\n"
	<< "5. Genre\n"
	<< "6. Asal\n"
	<< "7. Tambah daftar buku\n"
	<< "8. Hapus Buku \n"
	<< "Masukan nomor yang anda inginkan : ";cin >>ubahdata;

    switch(ubahdata){
		case 1 : 		 
		cout << "Apakah anda ingin melihat daftar buku ? (y/n)\n" <<"pil : ";cin>>inginlihat;
		cin.ignore();
		if (inginlihat == 'y' || inginlihat == 'Y')
		{
			cetakSemuaBuku();
			cout << "\nNo buku berapa yang ingin anda ubah : ";cin>>nobuku;
			cout << "Apakah ini judul buku yang ingin anda ubah : "<<buku[nobuku-1][0];
			cout << "\nJika ya tekan y ";cin>>kondisi;
			cin.ignore();
			if (kondisi == 'y' || kondisi == 'Y')
			{
			cout <<	"Masukan judul buku baru yang ingin : ";getline(cin, bukunew);
				buku[nobuku-1][0] = bukunew;
			}
			else{

			}
			
			
		}
		break;

		case 2 : 		 
		cout << "Apakah anda ingin melihat daftar buku ? (y/n)\n" <<"pil : ";cin>>inginlihat;
		if (inginlihat == 'y' || inginlihat == 'Y')
		{
			cetakSemuaBuku();
			cout << "\nNo buku berapa yang ingin anda ubah : ";cin>>nobuku;
			cout << "Apakah ini nama penulis buku yang ingin anda ubah : "<<buku[nobuku-1][1];
			cout << "\nJika ya tekan y ";cin>>kondisi;
			cin.ignore();
			if (kondisi == 'y' || kondisi == 'Y')
			{
			cout<< "Masukan Penulis buku baru yang ingin : ";getline(cin, penulisbaru);
			buku[nobuku-1][1] = bukunew;
			}
			else{

			}

		}
		break;

		case 3: 		 
		cout << "Apakah anda ingin melihat daftar buku ? (y/n)\n" <<"pil : ";cin>>inginlihat;
		if (inginlihat == 'y' || inginlihat == 'Y')
		{
			cetakSemuaBuku();
			cout << "\nNo buku berapa yang ingin anda ubah : ";cin>>nobuku;
			cout << "Apakah ini nama penerbit buku yang ingin anda ubah : "<<buku[nobuku-1][2];
			cout << "\nJika ya tekan y ";cin>>kondisi;
			cin.ignore();
			if (kondisi == 'y' || kondisi == 'Y')
			{
			cout<< "Masukan Penerbit buku baru yang ingin : ";getline(cin, penerbitbaru);
			buku[nobuku-1][2] = bukunew;
			}
			else{

			}

		}
		break;

		case 4 : 		 
		cout << "Apakah anda ingin melihat daftar buku ? (y/n)\n" <<"pil : ";cin>>inginlihat;
		if (inginlihat == 'y' || inginlihat == 'Y')
		{
			cetakSemuaBuku();
			cout << "\nNo buku berapa yang ingin anda ubah : ";cin>>nobuku;
			cout << "Apakah ini tahun terbit buku yang ingin anda ubah : "<<buku[nobuku-1][3];
			cout << "\nJika ya tekan y ";cin>>kondisi;
			cin.ignore();
			if (kondisi == 'y' || kondisi == 'Y')
			{
			cout<< "Masukan tahun terbit buku baru yang ingin : ";getline(cin, tahunterbitbaru);
			buku[nobuku-1][3] = bukunew;
			}
			else{

			}

		}
		break;

		case 5 : 		 
		cout << "Apakah anda ingin melihat daftar buku ? (y/n)\n" <<"pil : ";cin>>inginlihat;
		if (inginlihat == 'y' || inginlihat == 'Y')
		{
			cetakSemuaBuku();
			cout << "\nNo buku berapa yang ingin anda ubah : ";cin>>nobuku;
			cout << "Apakah ini genre buku yang ingin anda ubah : "<<buku[nobuku-1][4];
			cout << "\nJika ya tekan y ";cin>>kondisi;
			cin.ignore();
			if (kondisi == 'y' || kondisi == 'Y')
			{
			cout<< "Masukan genre buku baru yang ingin : ";getline(cin, genrebaru);
			buku[nobuku-1][4] = bukunew;
			}
			else{

			}

		}
		break;

		case 6 : 		 
		cout << "Apakah anda ingin melihat daftar buku ? (y/n)\n" <<"pil : ";cin>>inginlihat;
		if (inginlihat == 'y' || inginlihat == 'Y')
		{
			cetakSemuaBuku();
			cout << "\nNo buku berapa yang ingin anda ubah : ";cin>>nobuku;
			cout << "Apakah ini asal buku yang ingin anda ubah : "<<buku[nobuku-1][5];
			cout << "\nJika ya tekan y ";cin>>kondisi;
			cin.ignore();
			if (kondisi == 'y' || kondisi == 'Y')
			{
			cout<< "Masukan Asal buku baru yang ingin : ";getline(cin, asalbaru);
			buku[nobuku-1][5] = bukunew;
			}
			else{
				system("cls");
			}
		}
		break;

		case 7 :
		system("cls");
		if (jumlahbuku>=maxBuku )
		{
			cout << "Rak anda penuh";
		}
		else{
		cout << "Apakah anda ingin menambah daftar buku : "
		<<"\nJika ya tekan y ";cin>>kondisi;
		cin.ignore();
		cin.ignore();
		
		if (kondisi == 'y' || kondisi == 'Y')
			{
			system("cls");
			cout<< "Masukan judul buku baru yang ingin anda buat: ";getline(cin, bukunew);
			buku[jumlahbuku][0] = bukunew;
			
			cout<< "\nMasukan Penulis buku baru yang ingin anda buat: ";getline(cin, penulisbaru);
			buku[jumlahbuku][1] = penulisbaru;
			
			cout<< "\nMasukan Penerbit buku baru yang ingin anda buat: ";getline(cin, penerbitbaru);
			buku[jumlahbuku][2] = penerbitbaru;
			
			cout<< "\nMasukan Tahun terbit buku baru yang ingin anda buat: ";getline(cin, tahunterbitbaru);
			buku[jumlahbuku][3] = tahunterbitbaru;
			
			cout<< "\nMasukan Genre buku baru yang ingin anda buat: ";getline(cin, genrebaru);
			buku[jumlahbuku][4] = genrebaru;
			
			cout<< "\nMasukan Asal buku baru yang ingin anda buat: ";getline(cin, asalbaru);
			buku[jumlahbuku][5] = asalbaru;

			cout<< "\nMasukan apakah buku tersedia(1) atau tidak(2) : ";cin>>ketersediaan;
			if (ketersediaan = 1)
			{
				buku[jumlahbuku][6] = "Tersedia";
			}
			else if (ketersediaan = 2)
			{
				buku[jumlahbuku][6] = "Tidak Tersedia";
			}
			else{
				cout << "Masukan yang benar ";
			}
			
			nobuku++;
			}
			else{
			
			}

		break;

		case 8 :
		cout << "Apakah anda ingin melihat daftar buku ? (y/n)\n" <<"pil : ";cin>>inginlihat;
		if (inginlihat == 'y' || inginlihat == 'Y')
		{
			cetakSemuaBuku();
			cout << "\nNo buku berapa yang ingin anda ubah : ";cin>>nobuku;
			cout << "Apakah ini buku yang ingin anda hapus : "<<buku[nobuku-1][0];
			cout << "\nJika ya tekan y ";cin>>kondisi;
			cin.ignore();
			if (kondisi == 'y' || kondisi == 'Y')
			{
				for (int i = 0; i < 9; i++)
				{
					buku[nobuku-1][i] = "";
				}
				
			}
			else{
				system("cls");
			}
		}
		break;
		

		}}
}
	
