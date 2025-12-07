#include "Poli.h"
#include "Pasien.h"

int main() {
	ListParent LP;
	LP.first = nullptr;
	LP.Last = nullptr;

	int choice = 0;
	while (true) {
		cout << "\n=== MENU ADMIN ===\n";
		cout << "1. Tambah Poli\n";
		cout << "2. Tambah Pasien ke Poli\n";
		cout << "3. Tampilkan Semua Poli dan Pasien\n";
		cout << "4. Total Jumlah Pasien\n";
		cout << "5. Total Kuota Semua Poli\n";
		cout << "6. Keluar\n";
						cout << "Pilih: ";
						cin >> choice;
						if (choice >6 || choice <1) {
								cout << "Input tidak valid.\n";
								continue;
						}

		if (choice == 1) {
			infotypeP p;
			cout << "Nama Poli: ";
			cin >> p.namaPoli;
			cout << "ID Poli (angka): ";
			cin >> p.IDPoli;
			cout << "Nama Dokter: ";
			cin >> p.namaDokter;
			cout << "Kuota Poli: ";
			cin >> p.kuotaPoli;
			p.jumlahPasien = 0;

			addressP newP = createElementParent(p);
			insertLastParent(LP, newP);
			cout << "Poli ditambahkan." << endl;

		} else if (choice == 2) {
			if (isEmptyParent(LP)) {
				cout << "Belum ada poli terdaftar.\n";
				continue;
			}
			int poliID;
			cout << "Masukkan ID Poli tujuan: ";
			cin >> poliID;
			
			addressP target = LP.first;
			while (target != nullptr && target->infoP.IDPoli != poliID) {
				target = target->next;
			}
			if (target == nullptr) {
				cout << "Poli dengan ID tersebut tidak ditemukan.\n";
				continue;
			}

			dataPasien dp;
			cout << "Nama Pasien: ";
			cin >> dp.nama;
			cout << "Umur: ";
			cin >> dp.umur;
			cout << "Penyakit: ";
			cin >> dp.penyakit;
			cout << "ID Pasien (angka unik): ";
			cin >> dp.ID;
			dp.poliTujuan = target->infoP.namaPoli;
			cout << "Tanggal Kunjungan: ";
			cin >> dp.tanggalKunjungan;
			dp.nomorAntrian = 0;
			dp.prioritas = "Normal";
			
			addressC newC = new elmPasien;
			ListChild C;
			newC->info = dp;
			//C.firstC = target;
			newC->nextC = target->firstChild;
			target->firstChild = newC;
			target->infoP.jumlahPasien += 1;
			cout << "Pasien ditambahkan ke poli " << target->infoP.namaPoli << ".\n";

		} else if (choice == 3) {
			printInfoParent(LP);

		} else if (choice == 4) {
			cout << "Total pasien : " << hitungJumlahPasienPoli(LP) << "\n";

		} else if (choice == 5) {
			int total = 0;
			addressP P = LP.first;
			while (P != nullptr) { total += P->infoP.kuotaPoli; P = P->next; }
			cout << "Total kuota semua poli: " << total << "\n";

		} else if (choice == 6) {
			cout << "Keluar.\n";
			break;
		} else {
			cout << "Pilihan tidak valid.\n";
		}
	}

	return 0;
}

