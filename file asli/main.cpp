#include "function.h"
using namespace std;

int main() {
	int hasil, pilihan1, login;
	char pilihan2, ulang, kembali_admin, logout, logout2, ulangi_buku, kembali_lihat, kembali_daftar, kembali_login, loginAs, pilihanKet;
	string Nim, pass, username;

	do
	{
		ulang = 'n';
		system("cls");
		cout << "Selamat datang di Perpustakaan Kelas C for Cakep" << endl;
		cout << "1. Tampilkan Buku \n2. Login \n3. Daftar" << endl;
		cout << "Masukkan pilihan anda (isikan pilihan anda dengan memasukkan angka 1/2/3) : ";
		cin >> pilihan1;
		cin.ignore();
		switch (pilihan1)
		{
		case 1:
			do
			{
				kembali_lihat = 'y', 'Y';
				system("cls");
				cetakSemuaBuku();
				cout << "Apakah anda ingin kembali? y / n : ";
				cin >> kembali_lihat;
			} while (kembali_lihat == 'n' || kembali_lihat == 'N');
			if (kembali_lihat == 'y' || kembali_lihat == 'Y')
			{
				ulang = 'y';
			}
			break;
		case 2:
			system("cls");
			cout << "Login sebagai \n1. Mahasiswa \n2. Admin \nIsikan dengan angka : ";
			cin >> loginAs;
			switch (loginAs)
			{
			case '1':
			do
			{
				system("cls");
                kembali_login = 'n';
                login = 100;
				cout << "Login" << endl;
				cout << "Masukkan NIM anda     : ";
				cin >> Nim;
				cout << "Masukkan password anda : ";
				cin >> pass;

				bool data_valid = false; // Cek validitas data
				for (int i = 0; i < max; i++) {
					if (Nim == user[i][1] && pass == user[i][4]) {
						pengguna = i;
						login = 1;
						data_valid = true;
					}
				}

				if (!data_valid) {
					cout << "Nim atau Password Salah!!!\nAtau anda belum mendaftar" << endl;
					cout << "Apakah anda ingin login ulang? y / n : ";
					cin >> kembali_login;
				} else {
					kembali_login = 'n';
				}
				if (kembali_login == 'n')
				{
					ulang = 'y';
				}
				
			} while (kembali_login == 'y');
				break;
			case '2':
			do
			{
				system("cls");
                kembali_login = 'n';
                login = 100;
				cout << "Login" << endl;
				cout << "Masukkan username anda     : ";
				cin >> username;
				cout << "Masukkan password anda : ";
				cin >> password;

				bool data_valid = false; // Cek validitas data
				for (int i = 0; i < 99; i++) {
					if (username == "admin" && password == "123") {
						login = 2;
						data_valid = true;
					}
				}

				if (!data_valid) {
					cout << "Nim atau Password Salah!!!\nAtau anda belum mendaftar" << endl;
					cout << "Apakah anda ingin login ulang? y / n : ";
					cin >> kembali_login;
				} else {
					kembali_login = 'n';
				}
			} while (kembali_login == 'y');
				break;
			}
			switch (login)
			{
			case 1:
				do
				{
					kembali_anggota = 'n','N';
					system("cls");
					cout << "Selamat datang" << user[pengguna][0] << endl;
					cout << "1. Tampilkan Buku \n2. Pinjam Buku \n3. Kembalikan Buku \n4. Keterangan anda \n5. Logout" << endl;
					cout << "Masukkan pilihan anda (isikan pilihan anda dengan memasukkan angka 1/2/3/4/5) : ";
					cin >> pilihan2;
					switch (pilihan2)
					{
					case '1':
						do
						{
							system("cls");
							cetakSemuaBuku();
							cout << "Apakah anda ingin kembali? y / n : ";
							cin >> kembali_anggota;
						} while (kembali_anggota == 'n' || kembali_anggota == 'N');
						break;
					case '2':
						do
						{
							system("cls");
							pinjam();
							cout << "Apakah anda ingin kembali? y / n : ";
							cin >> kembali_anggota;
						} while (kembali_anggota == 'n' || kembali_anggota == 'N');
						break;
					case '3':
						do
						{
							system("cls");
							cout << "kembalikan" << endl;
							cout << "Apakah anda ingin kembali? y / n : ";
							cin >> kembali_anggota;
						} while (kembali_anggota == 'n' || kembali_anggota == 'N');
						break;
					case '4':
						do
						{
							system("cls");
							cout << "1. Lihat data \n2. Baca buku \nMasukkan Pilihan Anda : ";
							cin >> pilihanKet;
							switch (pilihanKet)
							{
							case '1':
								ketAnggota();
								break;
							case '2':
								bacaBuku();
								break;
							default:
								break;
							}
							cout << "Apakah anda ingin kembali? y / n : ";
							cin >> kembali_anggota;
						} while (kembali_anggota == 'n' || kembali_anggota == 'N');
						break;
					case '5':
						logout2 = 'n';
						system("cls");
						cout << "Apakah anda yakin ingin logout? y / n : ";
						cin >> logout;
						if (logout == 'y' || logout == 'Y')
						{
							ulang = 'y';
						}
						else {
							kembali_anggota = 'y';
						}
						break;
					default:
						kembali_anggota = 'y';
						break;
					}
				} while (kembali_anggota == 'y' || kembali_anggota == 'Y');
				break;
			case 2:
				do
				{
					kembali_admin = 'n', 'N';
					system("cls");
					cout << "1. Tampilkan Data Peminjam \n2. Tambah Data Peminjam \n3. Ubah Data Peminjam \n4. Hapus Data Peminjam \n5. Log Out" << endl;
					cout << "Pilihan : ";
					cin >> pilihan2;

					switch (pilihan2) {
					case '1':
						do
						{
							system("cls");
							cout << "Tampilkan Peminjam" << endl;
							cout << "Apakah anda ingin kembali? y / n : ";
							cin >> kembali_admin;
						} while (kembali_admin == 'n' || kembali_admin == 'N');
						break;

					case '2':
						do
						{
							system("cls");
							cout << "Tambah data peminjam" << endl;
							cout << "Apakah anda ingin kembali? y / n : ";
							cin >> kembali_admin;
						} while (kembali_admin == 'n' || kembali_admin == 'N');
						break;

					case '3':
						do
						{
							system("cls");
							cout << "Ubah data peminjam" << endl;
							cout << "Apakah anda ingin kembali? y / n : ";
							cin >> kembali_admin;
						} while (kembali_admin == 'n' || kembali_admin == 'N');
						break;

					case '4':
						system("cls");
						cout << "Hapus data peminjam" << endl;
						cout << "Apakah anda ingin kembali? y / n : ";
						cin >> kembali_admin;
						break;

					case '5':
						logout2 = 'n';
						system("cls");
						cout << "Apakah anda yakin ingin logout? y / n : ";
						cin >> logout;
						if (logout == 'y' || logout == 'Y')
						{
							ulang = 'y';
						}
						else
						{
							kembali_admin = 'y';
						}
						break;

					default:
						kembali_admin = 'y';
						break;
					}
				} while (kembali_admin == 'y');
				break;
			}
			break;

		case 3:
			do
			{
				kembali_daftar = 'y', 'Y';
				daftar();
				cout << "Apakah anda yakin ingin kembali? y / n : ";
				cin >> kembali_daftar;
				cin.ignore();
			} while (kembali_daftar == 'n' || kembali_daftar == 'N');
			if (kembali_daftar != 'n' || kembali_daftar != 'N')
			{
				ulang = 'y';
			}
			break;
		default:
			cout << "Pilihan tidak valid. Silahkan coba lagi!" << endl;
			cout << "Apakah anda ingin memilih ulang? y / n : ";
			cin >> ulang;
			break;
		}
	} while (ulang == 'y');
}