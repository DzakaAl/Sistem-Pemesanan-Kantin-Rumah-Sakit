#ifndef NASIUDUK_H
#define NASIUDUK_H
#include "Array1Ddinamis.h"
#include "Struct.h"
#include "Fitur/UlasanStack.h"
#include "Fitur/bacaSimpanMenu.h"
#include "Fitur/riwayatTransaksi.h"
#include "Fitur/pembayaran.h"
#include "Fitur/pesanan.h"
#include "Fitur/sortingSearching.h"
#include "Fitur/tambahMenu.h"
#include "Fitur/tambahStok.h"
#include "Fitur/displayMenu.h"
#include "Fitur/smartFiturDT.h"
#include "Fitur/smartFiturHS.h"
#include <fstream>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

class NasiUduk {
private:
  Array1Ddinamis<Menu> Makanan;
  Array1Ddinamis<Menu> Minuman;
  Pesanan *daftarpesanan;
  Queue antrianPesanan;
  PriorityQueue antrianPesananPrioritas;
  string namaFile1 = "Stock/menuMakananNasiUduk.txt";
  string namaFile2 = "Stock/menuMinumanNasiUduk.txt";
  string namaFile3 = "antrian/antrianNasiUduk.txt";
  string namaFile4 = "ulasan/ulasanNasiUduk.txt";
  string namaFile5 = "antrianMember/antrianMembershipNasiUduk.txt";
  string namaFile6 = "history/riwayatTransaksiNasiUduk.txt";
  UlasanPembeli ulasanPembeli;
  struk pesanan;
  TransactionHistory history;

public:
  NasiUduk() : Makanan(0), Minuman(0) {
    ulasanPembeli.BacaDariFile(namaFile4);
    antrianPesanan.bacaAntrian(namaFile3);
    antrianPesananPrioritas.bacaAntrian(namaFile5);
    bacaMenu(Makanan, namaFile1);
    bacaMenu(Minuman, namaFile2);
    history.bacaDariFile(namaFile6);
  }
  friend void bacaMenu(Array1Ddinamis<Menu> &Menu, string namaFile);
  friend void simpanMenu(const Array1Ddinamis<Menu> &Menu,
                                string namaFile);
  friend void tambahStokMakanan(Array1Ddinamis<Menu> &Makanan, int menuIndex,
                                int jumlah);
  friend void tambahStokMinuman(Array1Ddinamis<Menu> &Minuman, int menuIndex,
                                int jumlah);
  friend void tambahMenuMakanan(Array1Ddinamis<Menu> &Makanan);
  friend void tambahMenuMinuman(Array1Ddinamis<Menu> &Minuman);
  friend void insertionSortByName(Array1Ddinamis<Menu> &arr);
  friend void insertionSortByPrice(Array1Ddinamis<Menu> &arr);
  friend int binarySearchByName(const Array1Ddinamis<Menu> &arr,
                                const string &kataKunci);
  friend void tambahkanPesananLL(Pesanan *&daftarpesanan, string namaMenu,
                                  int jumlahPorsi, double totalHarga);
  friend double tampilkanNotaBelanjaLL(Pesanan *&daftarpesanan);
  friend void pesanLL(int &pesanan, Array1Ddinamis<Menu> &Menu, Pesanan *&daftarpesanan, string &namaFile);
  friend void ubahDaftarPesananKePesananLL(Pesanan *&daftarpesanan, Queue &antrianPesanan, PriorityQueue &antrianPesananPrioritas,bstree &avl, bool membership, nodeptr &root, string namaFile3, string namaFile5, struk &pesanan);
  friend void hapusPesananDenganNomorLL(Pesanan *&daftarpesanan,
                                         int nomorpesanan);
  friend void hapusSemuaDaftarPesananLL(Pesanan *&daftarpesanan);
  friend void prosesPembayaran(double totalHargaNota);
  friend void tampilkanStokMenipis(const Array1Ddinamis<Menu> &menuList,
                                   const string &jenisMenu, int batasStok);
  friend void updateDiskonMakanan(Array1Ddinamis<Menu> &makananList,
                                  string namafile);
  friend void updateDiskonMinuman(Array1Ddinamis<Menu> &minumanList,
                                  string namafile);
  friend void displayMenuMakanan(Array1Ddinamis<Menu> &Makanan);
  friend void displayMenuMakanan(Array1Ddinamis<Menu> &Minuman);
  friend void menuTerlaris(Array1Ddinamis<Menu> &Menu);
  friend void menuDiskon(Array1Ddinamis<Menu> &Menu);
  friend void tampilkanRiwayatTransaksi(Array1Ddinamis<Menu> &menulist);
  friend void prosesPembayaran(double totalHargaNota, struk &pesanan, TransactionHistory &history);
  friend void generateStruk(struk &pesanan);
  
  double rataRata() {
    double rataRata = ulasanPembeli.HitungRataRataRating();
    return rataRata;
  }

void pilihPeran(bstree &avl, nodeptr &root) {
  int peran;
  do {
    cout << "Pilih Peran Anda\n";
    cout << "1. Pembeli\n";
    cout << "2. Penjual\n";
    cout << "3. Kembali Ke Menu Sebelumnya\n";
    cout << "Pilih : ";
    cin >> peran;
    cout << "\033[2J\033[1;1H";

    switch (peran) {
    case 1:
      menuPembeli(avl, root);
      break;
    case 2:
      menuPenjual();
      break;
    case 3:
      cout << "Terima kasih, Selamat tinggal." << endl;
      break;
    default:
      cout << "Pilihan tidak valid. Silakan pilih lagi." << endl;
    }
  } while (peran != 3);
}

void menuPembeli(bstree &avl, nodeptr &root) {
  int pil;
  do {
    cout << "1. Menu \n";
    cout << "2. Ulasan\n";
    cout << "3. Kembali Ke Menu Sebelumnya\n";
    cout << "Pilih Menu: ";
    cin >> pil;
    cout << "\033[2J\033[1;1H";
    switch (pil) {
    case 1: {
      int pilCara;
      cout << "1. Menu Makanan\n";
      cout << "2. Menu Minuman\n";
      cout << "3. Kembali Ke Menu Sebelumnya\n";
      cout << "Pilih Menu: ";
      cin >> pilCara;
      cout << "\033[2J\033[1;1H";
      switch (pilCara) {
      case 1: {
        cout << "Menu Makanan Nasi Uduk Bang Ghani:" << endl;
        cout << "0. Filter Menu\n";
        displayMenuMakanan(Makanan);

        int pesanan;
        cout << "Pilih Menu Makanan (0-" << Makanan.Size() << "): ";
        cin >> pesanan;

        if (pesanan == 0) {
          int pilFilter;
          cout << "1. Menu dari rentang Harga\n";
          cout << "2. Menu terlaris\n";
          cout << "3. Menu yang diskon\n";
          cout << "4. Urutkan Nama Menu ⬆️\n";
          cout << "5. Urutkan Nama Menu ️⬇️\n";
          cout << "6. Urutkan Harga Menu ⬆️\n";
          cout << "7. Urutkan Harga Menu ⬇️\n";
          cout << "Pilih Filter: ";
          cin >> pilFilter;
          cout << "\033[2J\033[1;1H";

          switch (pilFilter) {
          case 1: {
            double lowerBound, upperBound;
            cout << "Masukkan batas harga bawah: ";
            cin >> lowerBound;
            cout << "Masukkan batas harga atas: ";
            cin >> upperBound;
            searchMenuByPriceRange(Makanan, lowerBound, upperBound);

            break;
          }
          case 2: {
            cout << "Menu Makanan Terlaris di Nasi Uduk Bang Ghani:" << endl;
            menuTerlaris(Makanan);
            break;
          }
          case 3: {
            cout << "Menu Makanan yang diskon di Nasi Uduk Bang Ghani:" << endl;
            menuDiskon(Makanan);
            break;
          }
          case 4: {
            cout << "Urutkan Nama Menu ⬆️ di Nasi Uduk Bang Ghani:" << endl;
            insertionSortByAscendingName(Makanan);
            displayMenuMakanan(Makanan);
            break;
          }
          case 5: {
            cout << "Urutkan Nama Menu ️⬇️ di Nasi Uduk Bang Ghani:"
                 << endl;
            insertionSortByDescendingName(Makanan);
            displayMenuMakanan(Makanan);
            break;
          }
          case 6: {
            cout << "Urutkan Harga Menu ⬆️ di Nasi Uduk Bang Ghani:"
                 << endl;
            insertionSortByAscendingPrice(Makanan);
            displayMenuMakanan(Makanan);
            break;
          }
          case 7: {
            cout << "Urutkan Harga Menu ⬇️ di Nasi Uduk Bang Ghani:"
                 << endl;
            insertionSortByDescendingPrice(Makanan);
            displayMenuMakanan(Makanan);
            break;
          }
          }
          cout << "Pilih Menu Makanan (1-" << Makanan.Size() << "): ";
          cin >> pesanan;
        }
        pesanLL(pesanan, Makanan, daftarpesanan, namaFile1);
        daftarPesanan(avl, root);
        cout << "\033[2J\033[1;1H";

        break;
      }
      case 2: {
          cout << "Menu Minuman Nasi Uduk Bang Ghani:" << endl;
          cout << "0. Filter Menu\n";
          displayMenuMinuman(Minuman);

          int pesanan;
          cout << "Pilih Menu Minuman (0-" << Minuman.Size() << "): ";
          cin >> pesanan;

          if (pesanan== 0) {
            int pilFilter;
            cout << "1. Menu dari rentang Harga\n";
            cout << "2. Menu terlaris\n";
            cout << "3. Menu yang diskon\n";
            cout << "4. Urutkan Nama Menu ⬆️\n";
            cout << "5. Urutkan Nama Menu ️⬇️\n";
            cout << "6. Urutkan Harga Menu ⬆️\n";
            cout << "7. Urutkan Harga Menu ⬇️\n";
            cout << "Pilih Filter: ";
            cin >> pilFilter;
            cout << "\033[2J\033[1;1H";

            switch (pilFilter) {
            case 1: {
              double lowerBound, upperBound;
              cout << "Masukkan batas harga bawah: ";
              cin >> lowerBound;
              cout << "Masukkan batas harga atas: ";
              cin >> upperBound;
              searchMenuByPriceRange(Minuman, lowerBound, upperBound);
              break;
            }
            case 2: {
              cout << "Menu Minuman Terlaris di Nasi Uduk Bang Ghani:" << endl;
              menuTerlaris(Minuman);
              break;
            }
            case 3: {
              cout << "Menu Minuman yang diskon di Nasi Uduk Bang Ghani:" << endl;
              menuDiskon(Minuman);
              break;
            }
            case 4: {
              cout << "Urutkan Nama Minuman ⬆️ di Nasi Uduk Bang Ghani:"
                   << endl;
              insertionSortByAscendingName(Minuman);
              displayMenuMinuman(Minuman);
              break;
            }
            case 5: {
              cout << "Urutkan Nama Minuman ️⬇️ di Nasi Uduk Bang Ghani:"
                   << endl;
              insertionSortByDescendingName(Minuman);
              displayMenuMinuman(Minuman);
              break;
            }
            case 6: {
              cout << "Urutkan Harga Minuman ⬆️ di Nasi Uduk Bang Ghani:"
                   << endl;
              insertionSortByAscendingPrice(Minuman);
              displayMenuMinuman(Minuman);
              break;
            }
            case 7: {
              cout << "Urutkan Harga Minuman ⬇️ di Nasi Uduk Bang Ghani:"
                   << endl;
              insertionSortByDescendingPrice(Minuman);
              displayMenuMinuman(Minuman);
              break;
            }
            }
            cout << "Pilih Menu Minuman (1-" << Minuman.Size() << "): ";
            cin >> pesanan;
          } 
          pesanLL(pesanan, Minuman, daftarpesanan, namaFile2);

          daftarPesanan(avl, root);
          cout << "\033[2J\033[1;1H";

        break;
      }
      }

      break;
    }
    case 2: {
      int pil; // Deklarasi variabel pil di sini
      bool lanjutUlasan = true;

      while (lanjutUlasan) {
        cout << "1. Tampilkan Ulasan\n";
        cout << "2. Masukkan Ulasan\n";
        cout << "3. Hapus Ulasan Saat ini\n";
        cout << "4. Kembali\n";
        cout << "Pilih: ";
        cin >> pil;

        switch (pil) {
        case 1:
          ulasanPembeli.TampilkanSemuaUlasan();
          break;
        case 2:
          ulasanPembeli.TambahUlasan();
          ulasanPembeli.SimpanKeFile(namaFile4);
          break;
        case 3:
          ulasanPembeli.DeleteUlasan();
          ulasanPembeli.SimpanKeFile(namaFile4);
          break;
        case 4:
          lanjutUlasan = false;
          break;
        default:
          cout << "Pilihan tidak valid.\n";
          break;
        }
      }

      break;
    }
    default:
      cout << "Pilihan tidak valid.\n";
      break;
    }
  } while (pil != 3);
}

void menuPenjual() {
  int pilihanMenu;
  do {
    cout << "Menu Penjual\n";
    cout << "1. Menambah Menu Makanan\n";
    cout << "2. Menambah Menu Minuman\n";
    cout << "3. Menambah Stok Makanan\n";
    cout << "4. Menambah Stok Minuman\n";
    cout << "5. Tampilkan menu dengan Stock yang mulai menipis\n";
    cout << "6. Tampilkan Antrian Pesanan\n";
    cout << "7. Tampilkan Antrian Pesanan Membership\n";
    cout << "8. Update Diskon Makanan dan Minuman\n";
    cout << "9. Riwayat Transaksi\n";
    cout << "10. Kembali ke Menu Sebelumnya\n";
    cout << "Pilih Menu: ";
    cin >> pilihanMenu;
    cout << "\033[2J\033[1;1H";

    switch (pilihanMenu) {
    case 1: {
      tambahMenuMakanan(Makanan);
      cout << "Menu Makanan berhasil ditambahkan." << endl;
      simpanMenu(Makanan, namaFile1);
      break;
    }
    case 2: {
      tambahMenuMinuman(Minuman);
      cout << "Menu Minuman berhasil ditambahkan." << endl;
      simpanMenu(Minuman, namaFile2);
      break;
    }
    case 3: {
      cout << "Menu Makanan Nasi Uduk Bang Ghani:" << endl;
      for (int i = 0; i < Makanan.Size(); i++) {
        cout << i + 1 << ". " << Makanan[i].namaMenu << " - Rp. "
             << Makanan[i].harga << " - Stok: " << Makanan[i].stok << endl;
      }
      int menuIndex, jumlahStok;
      cout << "Pilih menu makanan untuk menambah stok (1-" << Makanan.Size()
           << "): ";
      cin >> menuIndex;
      if (menuIndex >= 1 && menuIndex <= Makanan.Size()) {
        cout << "Jumlah stok makanan yang akan ditambahkan: ";
        cin >> jumlahStok;
        tambahStokMakanan(Makanan, menuIndex - 1, jumlahStok);
        cout << "Simpan stok ke file..." << endl;
        simpanMenu(Makanan, namaFile1);
      } else {
        cout << "Menu Makanan tidak valid." << endl;
      }
      break;
    }
    case 4: {
      cout << "Menu Minuman Nasi Uduk Bang Ghani:" << endl;
      for (int i = 0; i < Minuman.Size(); i++) {
        cout << i + 1 << ". " << Minuman[i].namaMenu << " - Rp. "
             << Minuman[i].harga << " - Stok: " << Minuman[i].stok << endl;
      }
      int menuIndex, jumlahStok;
      cout << "Pilih menu minuman untuk menambah stok (1-" << Minuman.Size()
           << "): ";
      cin >> menuIndex;
      if (menuIndex >= 1 && menuIndex <= Minuman.Size()) {
        cout << "Jumlah stok minuman yang akan ditambahkan: ";
        cin >> jumlahStok;
        tambahStokMinuman(Minuman, menuIndex - 1, jumlahStok);
        cout << "Simpan stok ke file..." << endl;
        simpanMenu(Minuman, namaFile2);
      } else {
        cout << "Menu minuman tidak valid." << endl;
      }
      break;
    }
    case 5:
      cout << "Makanan dan Minuman dengan Stok Menipis (di bawah 15):"
         << endl;
      tampilkanStokMenipis(Makanan, "Makanan", 15);
      tampilkanStokMenipis(Minuman, "Minuman", 15);
      break;
    case 6:
      bool dilayani;
      antrianPesanan.display();
      cout << "Pesanan nomor 1 sudah dilayani (1 = sudah||0 = belum)? ";
      cin >> dilayani;
      if (dilayani == true) {
        antrianPesanan.dequeue();
        antrianPesanan.simpanAntrian(namaFile3);
      }
      break;
    case 7: {
      bool dilayani;
      antrianPesananPrioritas.display();
      cout << "Pesanan nomor 1 sudah dilayani (1 = sudah||0 = belum)? ";
      cin >> dilayani;
      if (dilayani == true) {
        antrianPesananPrioritas.dequeue();
        antrianPesananPrioritas.simpanAntrian(namaFile5);
      }
      break;
    }
    case 8: {
      // Update diskon makanan dan minuman
      cout << "Update Diskon Makanan dan Minuman" << endl;
      updateDiskonMakanan(Makanan, namaFile1);
      updateDiskonMinuman(Minuman, namaFile2);
      break;
    }
    case 9: {
      history.printHistory();
      break;
    }
    case 10: {
      cout << "Terima kasih. Selamat tinggal." << endl;
      break;
    }
    default:
      cout << "Pilihan tidak valid. Silakan pilih lagi." << endl;
    }
  } while (pilihanMenu != 9);
}

void daftarPesanan(bstree &avl, nodeptr &root){
  if (daftarpesanan != nullptr) {
    tampilkanNotaBelanjaLL(daftarpesanan); // Menampilkan nota belanja

    bool hapusPesanan;
    cout << "Apakah ada pesanan yang ingin dihapus (1 = ya, 0 = "
            "tidak)? ";
    cin >> hapusPesanan;

    if (hapusPesanan) {
      int nomorPesananHapus;
      cout << "Masukkan nomor pesanan yang ingin dihapus: ";
      cin >> nomorPesananHapus;
      hapusPesananDenganNomorLL(daftarpesanan, nomorPesananHapus);

      bool pesanLagi;
      cout << "Apakah Anda ingin memesan lagi (1 = ya, 0 = tidak)? ";
      cin >> pesanLagi;

      if (pesanLagi) {
        menuPembeli(avl,root);
      } else {
        tampilkanNotaBelanjaLL(daftarpesanan);
      }
    } else {
      bool pesanLagi;
      cout << "Apakah Anda ingin memesan lagi (1 = ya, 0 = tidak)? ";
      cin >> pesanLagi;

      if (pesanLagi) {
        menuPembeli(avl,root);
      } else {
        bool membership;
        cout << "Apakah anda mempunyai membership? (1 = yes || 0 = "
                "no) : ";
        cin >> membership;
        ubahDaftarPesananKePesananLL(daftarpesanan, antrianPesanan, antrianPesananPrioritas, avl, membership, root, namaFile3, namaFile5, pesanan);
        double totalHargaNota = tampilkanNotaBelanjaLL(daftarpesanan);
        prosesPembayaran(totalHargaNota, pesanan, history);
        history.simpanKeFile(namaFile6);
      }
    }
  } else {
    cout << "Terimakasih Sudah Mengunjungi Toko Kami" << endl;
  }
}

  ~NasiUduk() {
    while (daftarpesanan != nullptr) {
      Pesanan *temp = daftarpesanan;
      daftarpesanan = daftarpesanan->next;
      delete temp;
    }
  }
};

#endif