#ifndef TAMBAHMENU_H
#define TAMBAHMENU_H

void tambahMenuMakanan(Array1Ddinamis<Menu> &Makanan){
  Menu newMenu;
  cout << "Masukkan Nama Menu Minuman: ";
  cin.ignore(); 
  getline(cin, newMenu.namaMenu);
  cout << "Masukkan Harga: ";
  cin >> newMenu.harga;
  cout << "Masukkan Stok: ";
  cin >> newMenu.stok;

  Makanan.ReSize(Makanan.Size() + 1);
  Makanan[Makanan.Size() - 1] = newMenu;
}
void tambahMenuMinuman(Array1Ddinamis<Menu> &Minuman){
  Menu newMenu;
  cout << "Masukkan Nama Menu Minuman: ";
  cin.ignore(); 
  getline(cin, newMenu.namaMenu);
  cout << "Masukkan Harga: ";
  cin >> newMenu.harga;
  cout << "Masukkan Stok: ";
  cin >> newMenu.stok;

  Minuman.ReSize(Minuman.Size() + 1);
  Minuman[Minuman.Size() - 1] = newMenu;
}

#endif