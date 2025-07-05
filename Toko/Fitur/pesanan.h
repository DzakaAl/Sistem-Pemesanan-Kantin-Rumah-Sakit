#ifndef PESANAN_H
#define PESANAN_H

#include "pesananDLL.h"
#include "pesananLL.h"

void pesanLL(int &pesanan, Array1Ddinamis<Menu> &Menu, Pesanan*& daftarpesanan, string &namaFile){
  if (pesanan >= 1 && pesanan <= Menu.Size()) {
    // Proses pembelian
    int jumlahPorsi;
    cout << "Masukkan jumlah porsi yang ingin dibeli: ";
    cin >> jumlahPorsi;

    if (Menu[pesanan - 1].stok >= jumlahPorsi) {
      double harga_diskon = Menu[pesanan-1].harga - (Menu[pesanan-1].harga * Menu[pesanan-1].diskon);
      double totalHarga = harga_diskon * jumlahPorsi;
      cout << "Anda memesan: " << Menu[pesanan - 1].namaMenu
           << " - Rp. " << harga_diskon << " per porsi - "
           << jumlahPorsi << " porsi" << endl;

      tambahkanPesananLL(daftarpesanan, Menu[pesanan - 1].namaMenu,
                          jumlahPorsi, totalHarga);

      Menu[pesanan - 1].stok -= jumlahPorsi;
      simpanMenu(Menu, namaFile);
    } else {
      cout << "Maaf, stok tidak mencukupi untuk jumlah porsi yang "
              "diminta."
           << endl;
    }
  } else {
    cout << "Pilihan tidak valid. Silakan pilih lagi." << endl;
  }
}

void pesanDLL(int &pesanan, Array1Ddinamis<Menu> &Menu, Pesanan*& daftarpesanan, string &namaFile){
  if (pesanan >= 1 && pesanan <= Menu.Size()) {
    // Proses pembelian
    int jumlahPorsi;
    cout << "Masukkan jumlah porsi yang ingin dibeli: ";
    cin >> jumlahPorsi;

    if (Menu[pesanan - 1].stok >= jumlahPorsi) {
      double harga_diskon = Menu[pesanan-1].harga - (Menu[pesanan-1].harga * Menu[pesanan-1].diskon);
      double totalHarga = harga_diskon * jumlahPorsi;
      cout << "Anda memesan: " << Menu[pesanan - 1].namaMenu
           << " - Rp. " << harga_diskon << " per porsi - "
           << jumlahPorsi << " porsi" << endl;

      tambahkanPesananDLL(daftarpesanan, Menu[pesanan - 1].namaMenu,
                          jumlahPorsi, totalHarga);

      Menu[pesanan - 1].stok -= jumlahPorsi;
      simpanMenu(Menu, namaFile);
    } else {
      cout << "Maaf, stok tidak mencukupi untuk jumlah porsi yang "
              "diminta."
           << endl;
    }
  } else {
    cout << "Pilihan tidak valid. Silakan pilih lagi." << endl;
  }
}

#endif 