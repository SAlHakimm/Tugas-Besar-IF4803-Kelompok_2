#include "Poli.h"
#include "Pasien.h"

// We'll avoid adding extra helper functions here. Instead we'll inline
// list initialization and searches directly in main using only cin/cout.

int main() {
	ListParent LP;
	// initialize list (inline, no helper function)
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
						if (!(cin >> choice)) {
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								cout << "Input tidak valid.\n";
								continue;
						}
						// consume remaining newline so getline works later
						cin >> ws;

		if (choice == 1) {
			infotypeP p;
			cout << "Nama Poli: ";
			getline(cin, p.namaPoli);
			cout << "ID Poli (angka): ";
			cin >> p.IDPoli;
			cin >> ws;
			cout << "Nama Dokter: ";
			getline(cin, p.namaDokter);
			cout << "Kuota Poli: ";
			cin >> p.kuotaPoli;
			cin >> ws;
			p.jumlahPasien = 0;

			addressP newP = createElementParent(p);
			insertLastParent(LP, newP);
			cout << "Poli ditambahkan.\n";

		} else if (choice == 2) {
			if (isEmptyParent(LP)) {
				cout << "Belum ada poli terdaftar.\n";
				continue;
			}
			int poliID;
			cout << "Masukkan ID Poli tujuan: ";
			if (!(cin >> poliID)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "ID tidak valid.\n";
				continue;
			}
			cin >> ws;
			// find parent inline
			addressP target = LP.first;
			while (target != nullptr && target->infoP.IDPoli != poliID) target = target->next;
			if (target == nullptr) {
				cout << "Poli dengan ID tersebut tidak ditemukan.\n";
				continue;
			}

			dataPasien dp;
			cout << "Nama Pasien: ";
			getline(cin, dp.nama);
			cout << "Umur: ";
			cin >> dp.umur;
			cin >> ws;
			cout << "Penyakit: ";
			getline(cin, dp.penyakit);
			cout << "ID Pasien (angka unik): ";
			cin >> dp.ID;
			cin >> ws;
			dp.poliTujuan = target->infoP.namaPoli;
			cout << "Tanggal Kunjungan: ";
			getline(cin, dp.tanggalKunjungan);
			dp.nomorAntrian = 0;
			dp.prioritas = "Normal";
			// create child node inline (no helper function)
			addressC newC = new elmPasien;
			newC->infotype = dp;
			newC->firstP = target;
			newC->nextC = target->firstChild;
			target->firstChild = newC;
			target->infoP.jumlahPasien += 1;
			cout << "Pasien ditambahkan ke poli " << target->infoP.namaPoli << ".\n";

		} else if (choice == 3) {
			printInfoParent(LP);

		} else if (choice == 4) {
			cout << "Total pasien (sum poli): " << hitungJumlahPasienPoli(LP) << "\n";

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

