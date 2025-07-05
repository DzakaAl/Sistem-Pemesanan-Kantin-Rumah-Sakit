#ifndef PEMBAYARAN_H
#define PEMBAYARAN_H
#include "qrcode.h"
#include <thread>
#include <chrono>
#include <sstream>
#include <string>

void generateStruk(struk& pesanan) {
  cout << "=====================================" << endl;
  cout << "           Struk Pembelian           " << endl;
  cout << "             Kantin Maki             " << endl;
  cout << "=====================================" << endl;
  cout << "Nama      : " << pesanan.nama << endl;
  cout << "Pembelian : " << endl;

  stringstream ss(pesanan.pembelian);
  string item;
  while (getline(ss, item, '.')) {
    cout << "           - " << item << endl;
  }
  cout << "Total     : " << pesanan.total << endl;
  cout << "Bayar     : " << pesanan.pembayaran << endl;
  cout << "Kembalian : " << pesanan.kembalian << endl;
  cout << "=====================================" << endl << endl;
}

void prosesPembayaran(double totalHargaNota, struk& pesanan, TransactionHistory& history) {
  double pembayaran;
  int metodePembayaran;

  cout << "Pilih Metode Pembayaran:" << endl;
  cout << "1. Tunai" << endl;
  cout << "2. QRIS" << endl;
  cout << "Pilih: ";
  cin >> metodePembayaran;

  if (metodePembayaran == 1) {
    cout << "Masukkan jumlah uang yang dibayar: Rp. ";
    cin >> pembayaran;

    if (pembayaran < totalHargaNota) {
      cout << "Jumlah uang yang dibayarkan kurang. Transaksi dibatalkan."
           << endl;
    } else {
      double kembalian = pembayaran - totalHargaNota;
      cout << "Terima kasih! Kembalian Anda: Rp. " << kembalian << endl;
      pesanan.total = totalHargaNota;
      pesanan.kembalian = kembalian;
      pesanan.pembayaran = pembayaran;
      history.addTransaction(pesanan);
      generateStruk(pesanan);
    }
  } else if (metodePembayaran == 2) {
    int kembalian = 0;
    int pembayaran = totalHargaNota;
    cout << "SCAN QR CODE" << endl;

    qrcode();

    this_thread::sleep_for(std::chrono::seconds(30));
    cout << "\033[2J\033[1;1H";
    cout << "Pembayaran berhasil menggunakan QRIS."
         << endl;
    pesanan.total = totalHargaNota;
    pesanan.kembalian = kembalian;
    pesanan.pembayaran = pembayaran;
    history.addTransaction(pesanan);
    generateStruk(pesanan);
  } else {
    cout << "Pilihan metode pembayaran tidak valid. Transaksi dibatalkan."
         << endl;
  }
}

#endif