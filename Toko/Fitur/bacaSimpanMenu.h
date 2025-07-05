#ifndef BACASIMPANMENU_H
#define BACASIMPANMENU_H

void bacaMenu(Array1Ddinamis<Menu> &Menulist, string namaFile) {
  ifstream file(namaFile);
  if (file.is_open()) {
    Menu MenuBaru;
    while (getline(file, MenuBaru.namaMenu)) {
      file >> MenuBaru.harga;
      file >> MenuBaru.stok;
      file >> MenuBaru.diskon;
      Menulist.ReSize(Menulist.Size() + 1);
      Menulist[Menulist.Size() - 1] = MenuBaru;
      file.ignore();
    }
    file.close();
  }
}

void simpanMenu(const Array1Ddinamis<Menu> &menuList, string namaFile) {
    ofstream file(namaFile, ios::out);

    if (file.is_open()) {
      for (int i = 0; i < menuList.Size(); i++) {
          file << menuList[i].namaMenu << endl;
          file << menuList[i].harga << endl;
          file << menuList[i].stok << endl;
          file << menuList[i].diskon << endl;
      }
        file.close();
    }
}


// Fungsi untuk mengupdate diskon pada menu makanan
void updateDiskonMakanan(Array1Ddinamis<Menu>& makananList,string namafile) {
    cout << "Daftar Makanan yang tersedia:" << endl;
    for (int i = 0; i < makananList.Size(); i++) {
        cout << i + 1 << ". " << makananList[i].namaMenu << endl;
    }

    int menuIndex;
    double diskonBaru;

    cout << "Pilih Makanan untuk diupdate diskon (1-" << makananList.Size() << "): ";
    cin >> menuIndex;

    if (menuIndex >= 1 && menuIndex <= makananList.Size()) {
        cout << "Masukkan diskon baru: ";
        cin >> diskonBaru;

        // Validasi diskon (harus antara 0 dan 1)
        if (diskonBaru >= 0 && diskonBaru <= 1) {
            makananList[menuIndex - 1].diskon = diskonBaru;
            cout << "Diskon pada Makanan berhasil diupdate." << endl;
            // Simpan perubahan ke file
            simpanMenu(makananList, namafile);
        } else {
            cout << "Diskon harus dalam rentang antara 0 dan 1." << endl;
        }
    } else {
        cout << "Pilihan Makanan tidak valid." << endl;
    }
}

// Fungsi untuk mengupdate diskon pada menu minuman
void updateDiskonMinuman(Array1Ddinamis<Menu>& minumanList,string namafile) {
    cout << "Daftar Minuman yang tersedia:" << endl;
    for (int i = 0; i < minumanList.Size(); i++) {
        cout << i + 1 << ". " << minumanList[i].namaMenu << endl;
    }

    int menuIndex;
    double diskonBaru;

    cout << "Pilih Minuman untuk diupdate diskon (1-" << minumanList.Size() << "): ";
    cin >> menuIndex;

    if (menuIndex >= 1 && menuIndex <= minumanList.Size()) {
        cout << "Masukkan diskon baru: ";
        cin >> diskonBaru;

        // Validasi diskon (harus antara 0 dan 1)
        if (diskonBaru >= 0 && diskonBaru <= 1) {
            minumanList[menuIndex - 1].diskon = diskonBaru;
            cout << "Diskon pada Minuman berhasil diupdate." << endl;
            // Simpan perubahan ke file
            simpanMenu(minumanList, namafile);
        } else {
            cout << "Diskon harus dalam rentang antara 0 dan 1." << endl;
        }
    } else {
        cout << "Pilihan Minuman tidak valid." << endl;
    }
}

#endif