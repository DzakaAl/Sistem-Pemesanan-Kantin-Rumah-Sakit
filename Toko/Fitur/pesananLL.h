#ifndef PESANANLL_H
#define PESANANLL_H
#include <iomanip>
#include "queuePesanan.h"
#include "priorityQueue.h"
#include "../../membership.h"

void tambahkanPesananLL(Pesanan*& daftarpesanan, string namaMenu, int jumlahPorsi, double totalHarga) {
    Pesanan* pesananBaru = new Pesanan{namaMenu, jumlahPorsi, totalHarga};
    if (daftarpesanan == nullptr) {
        daftarpesanan = pesananBaru;
    } else {
        Pesanan* temp = daftarpesanan;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = pesananBaru;
    }
}

double tampilkanNotaBelanjaLL(Pesanan*& daftarpesanan) {
    if (daftarpesanan == nullptr) {
        cout << "Belum ada pesanan yang ditempatkan." << endl;
        return 0;
    }

    Pesanan* temp = daftarpesanan;
    int nomorPesanan = 1;
    double totalHargaNota = 0.0;

    cout << "Nota Belanja:" << endl;
    while (temp != nullptr) {
        cout << nomorPesanan << ". " << temp->namaMenu << " - "
             << temp->jumlahPorsi << " porsi - Rp. " << temp->totalHarga << endl;
        totalHargaNota += temp->totalHarga;
        nomorPesanan++;
        temp = temp->next;
    }
    cout << "Total Harga: Rp. " << totalHargaNota << endl;
    return totalHargaNota;
}

void ubahDaftarPesananKePesananLL(Pesanan*& daftarpesanan, Queue &antrianPesanan, PriorityQueue &antrianPesananPriority, bstree &avl, bool anggota, nodeptr &root, string namaFile3, string namaFile5, struk& pesanan) {
  if (daftarpesanan == nullptr) {
    cout << "Belum ada pesanan yang ditempatkan." << endl;
  }

  Pesanan *temp = daftarpesanan;
  if (anggota == true){
    string nomor;
    cout << "Masukkan Nomor Telepon yang Terdaftar: ";
    cin >> nomor;
    membership found;
    if (avl.find(nomor, root, found))
    {
      Priority data;
      data.prioritas = found.prio;
      data.atasNama = found.nama;
      data.pesanan = " ";
      while (temp != nullptr) {
          data.pesanan += temp->namaMenu + " - " + to_string(temp->jumlahPorsi) + " Porsi, ";
          temp = temp->next;
      }
      delete temp;
      antrianPesananPriority.enqueue(data);
      antrianPesananPriority.simpanAntrian(namaFile5);
      cout << "Atas Nama: " << data.atasNama << endl;
      pesanan.nama = data.atasNama;

      temp = daftarpesanan;
      while (temp != nullptr) {
          ostringstream stream;
          stream << fixed << setprecision(0) << temp->totalHarga; 
          pesanan.pembelian += temp->namaMenu + " - " + to_string(temp->jumlahPorsi) + " - " + stream.str();
          if (temp->next != nullptr) {
              pesanan.pembelian += ".";
          }
          temp = temp->next;
      }
    }
    else
    {
        cout << "Nomor Telepon tidak ditemukan." << endl;
        anggota = false;
        ubahDaftarPesananKePesananLL(daftarpesanan, antrianPesanan, antrianPesananPriority, avl, anggota, root, namaFile3, namaFile5, pesanan);
    }

  } else {
    Antrian list;
    cin.ignore();
    cout << "Masukkan Nama: ";
    getline(cin, list.atasNama);
    list.pesanan = " ";
    while (temp != nullptr) {
        list.pesanan += temp->namaMenu + " - " + to_string(temp->jumlahPorsi) + " Porsi, ";
        temp = temp->next;
    }
    delete temp;
    antrianPesanan.enqueue(list);
    antrianPesanan.simpanAntrian(namaFile3);
    cout << "Atas Nama: " << list.atasNama << endl;
    pesanan.nama = list.atasNama;

    temp = daftarpesanan;
    while (temp != nullptr) {
        ostringstream stream;
        stream << fixed << setprecision(0) << temp->totalHarga;  // Menampilkan tanpa desimal
        pesanan.pembelian += temp->namaMenu + " - " + to_string(temp->jumlahPorsi) + " - " + stream.str();
        if (temp->next != nullptr) {
            pesanan.pembelian += ".";
        }
        temp = temp->next;
    }
  }
}

void hapusPesananDenganNomorLL(Pesanan*& daftarpesanan, int nomorPesanan) {
    if (daftarpesanan == nullptr) {
        cout << "Daftar pesanan kosong." << endl;
        return;
    }

    if (nomorPesanan == 1) {
        // Menghapus elemen pertama
        Pesanan* temp = daftarpesanan;
        daftarpesanan = daftarpesanan->next;
        delete temp;
    } else {
        Pesanan* temp = daftarpesanan;
        int nomor = 1;
        while (nomor < nomorPesanan - 1 && temp->next != nullptr) {
            temp = temp->next;
            nomor++;
        }

        if (nomor == nomorPesanan - 1 && temp->next != nullptr) {
            Pesanan* hapus = temp->next;
            temp->next = temp->next->next;
            delete hapus;
        }
    }
}

void hapusSemuaDaftarPesananLL(Pesanan*& daftarpesanan) {
    while (daftarpesanan != nullptr) {
        Pesanan* temp = daftarpesanan;
        daftarpesanan = daftarpesanan->next;
        delete temp;
    }
}

#endif