#ifndef SMARTFITURHS_H
#define SMARTFITURHS_H

void searchMenuByPriceRange(const Array1Ddinamis<Menu> &arr, const double& lowerBound, const double& upperBound) {
    bool found = false;

    cout << "Menu dengan harga antara " << lowerBound << " dan " << upperBound << ":\n";
    for (int i = 0; i < arr.Size(); ++i) {
        if (compareByPriceRange(arr[i], lowerBound, upperBound)) {
            cout << i + 1 << ". " << arr[i].namaMenu << " - Rp. " << arr[i].harga << " - Stok: " << arr[i].stok << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Tidak ada menu dalam rentang harga tersebut.\n";
    }
}

void tampilkanStokMenipis(const Array1Ddinamis<Menu> &menuList, const string& jenisMenu, int batasStok) {
    cout << "Menu " << jenisMenu << " dengan Stok di Bawah " << batasStok << ":" << endl;

    for (int i = 0; i < menuList.Size(); i++) {
        if (menuList[i].stok < batasStok) {
            cout << i + 1 << ". " << menuList[i].namaMenu << " - Rp. "
                << menuList[i].harga << " - Stok: " << menuList[i].stok << endl;
        }
    }
}

#endif