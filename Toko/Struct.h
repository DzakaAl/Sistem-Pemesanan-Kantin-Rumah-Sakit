#ifndef STRUCT_H
#define STRUCT_H

#include <string>
using namespace std;
struct Menu {
  string namaMenu;
  double harga;
  int stok;
  double diskon;
};

struct Pesanan {
  string namaMenu;
  int jumlahPorsi;
  double totalHarga;
  Pesanan *next;
  Pesanan *prev;

  Pesanan(string nama, int porsi, double harga)
      : namaMenu(nama), jumlahPorsi(porsi), totalHarga(harga), next(nullptr), prev(nullptr) {}
};

#endif