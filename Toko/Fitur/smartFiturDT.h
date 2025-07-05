#ifndef SMARTFITURDT_H
#define SMARTFITURDT_H

void menuTerlaris(Array1Ddinamis<Menu> &Menu){
  int ambangBatasStok = 15;
  bool adaMenuTerlaris = false;

  for (int i = 0; i < Menu.Size(); ++i) {
    if (Menu[i].stok < ambangBatasStok) {
      cout << i + 1 << ". " << Menu[i].namaMenu << " - Rp. "
           << Menu[i].harga -
                (Menu[i].harga * Menu[i].diskon)
         << endl;
      adaMenuTerlaris = true;
    }
  }

  if (!adaMenuTerlaris) {
    cout << "Tidak ada menu terlaris pada saat ini."
         << endl;
  }
}

void menuDiskon (Array1Ddinamis<Menu> &Menu){
  for (int i = 0; i < Menu.Size(); ++i) {
    if (Menu[i].diskon > 0) {
      cout << i + 1 << ". " << Menu[i].namaMenu
           << " - Harga Diskon: "
           << Menu[i].harga -
                  (Menu[i].harga * Menu[i].diskon)
           << endl;
    }
  }
}
#endif