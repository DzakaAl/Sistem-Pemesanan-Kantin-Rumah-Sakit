#ifndef SORTINGSEARCHING_H
#define SORTINGSEARCHING_H

bool compareByAscendingName(const Menu& menu1, const Menu& menu2) {
    return menu1.namaMenu < menu2.namaMenu;
}

bool compareByDescendingName(const Menu& menu1, const Menu& menu2) {
    return menu1.namaMenu > menu2.namaMenu;
}

bool compareByAscendingPrice(const Menu& menu1, const Menu& menu2) {
    return menu1.harga < menu2.harga;
}

bool compareByDescendingPrice(const Menu& menu1, const Menu& menu2) {
    return menu1.harga > menu2.harga;
}

bool compareByPriceRange(const Menu& menu, const double& lowerBound, const double& upperBound) {
    return menu.harga >= lowerBound && menu.harga <= upperBound;
}

void insertionSortByAscendingName(Array1Ddinamis<Menu>& arr) {
    int n = arr.Size();
    for (int i = 1; i < n; ++i) {
        Menu key = arr[i];
        int j = i - 1;

        while (j >= 0 && compareByAscendingName(arr[j], key)) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void insertionSortByDescendingName(Array1Ddinamis<Menu>& arr) {
    int n = arr.Size();
    for (int i = 1; i < n; ++i) {
        Menu key = arr[i];
        int j = i - 1;

        while (j >= 0 && compareByDescendingName(arr[j], key)) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void insertionSortByAscendingPrice(Array1Ddinamis<Menu>& arr) {
    int n = arr.Size();
    for (int i = 1; i < n; ++i) {
        Menu key = arr[i];
        int j = i - 1;

        while (j >= 0 && compareByAscendingPrice(arr[j], key)) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void insertionSortByDescendingPrice(Array1Ddinamis<Menu>& arr) {
    int n = arr.Size();
    for (int i = 1; i < n; ++i) {
        Menu key = arr[i];
        int j = i - 1;

        while (j >= 0 && compareByDescendingPrice(arr[j], key)) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

bool binarySearchCompareByName(const Menu& menu, const string& kataKunci) {
    return menu.namaMenu < kataKunci;
}

int binarySearchByName(const Array1Ddinamis<Menu>& arr, const string& kataKunci) {
    int low = 0;
    int high = arr.Size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid].namaMenu == kataKunci) {
            return mid;
        }

        if (binarySearchCompareByName(arr[mid], kataKunci)) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1;
}

bool binarySearchCompareByDescendingName(const Menu& menu, const string& kataKunci) {
    return menu.namaMenu > kataKunci;
}

int binarySearchByDescendingName(const Array1Ddinamis<Menu>& arr, const string& kataKunci) {
    int low = 0;
    int high = arr.Size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid].namaMenu == kataKunci) {
            return mid;
        }

        if (binarySearchCompareByDescendingName(arr[mid], kataKunci)) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1;
}

#endif