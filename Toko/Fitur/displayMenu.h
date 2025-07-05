#ifndef DISPLAYMENU_H
#define DISPLAYMENU_H

void displayMenuMakanan(Array1Ddinamis<Menu> &Menu) {
  for (int i = 0; i < Menu.Size(); ++i) {
      cout << i + 1 << ". " << Menu[i].namaMenu
           << " - Harga Diskon: "
           << Menu[i].harga -
                  (Menu[i].harga * Menu[i].diskon)
           << endl;
  }
}

void displayMenuMinuman(Array1Ddinamis<Menu> &Minuman) {
  for (int i = 0; i < Minuman.Size(); i++) {
    cout << i + 1 << ". " << Minuman[i].namaMenu << " - Rp. "
         << Minuman[i].harga << " - Stok: " << Minuman[i].stok
         << endl;
  }
}
#endif