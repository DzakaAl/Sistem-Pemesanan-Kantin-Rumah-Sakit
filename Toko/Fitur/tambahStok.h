#ifndef TAMBAHSTOK_H
#define TAMBAHSTOK_H

void tambahStokMakanan(Array1Ddinamis<Menu> &Makanan, int menuIndex, int jumlah) {
  if (menuIndex >= 0 && menuIndex < Makanan.Size()) {
    Makanan[menuIndex].stok += jumlah;
    cout << "Stok menu makanan " << menuIndex + 1 << " ditambahkan sebanyak " << jumlah << endl;
  } else {
    cout << "Menu makanan tidak valid." << endl;
  }
}

void tambahStokMinuman(Array1Ddinamis<Menu> &Minuman, int menuIndex, int jumlah) {
  if (menuIndex >= 0 && menuIndex < Minuman.Size()) {
    Minuman[menuIndex].stok += jumlah;
    cout << "Stok menu minuman " << menuIndex + 1 << " ditambahkan sebanyak " << jumlah << endl;
  } else {
    cout << "Menu minuman tidak valid." << endl;
  }
}

#endif