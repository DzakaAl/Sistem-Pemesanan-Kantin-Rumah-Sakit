#ifndef RIWAYATTRANSAKSI_H
#define RIWAYATTRANSAKSI_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

struct struk {
  string nama;
  string pembelian;
  int total;
  int pembayaran;
  int kembalian;
  struk *left;
  struk *right;

  struk()
      : nama(""), pembelian(""), total(0), kembalian(0),
        left(nullptr), right(nullptr) {}

  struk(string name, string purchase, double amount, double change)
      : nama(name), pembelian(purchase), total(amount),
        kembalian(change), left(nullptr), right(nullptr) {}
};

class TransactionHistory {
private:
  struk *root;

  struk *addTransaction(struk *node, const struk &transaction) {
    if (node == nullptr) {
      return new struk(transaction.nama,
                       transaction.pembelian, transaction.total,
                       transaction.kembalian);
    }

    if (transaction.nama < node->nama) {
      node->left = addTransaction(node->left, transaction);
    } else {
      node->right = addTransaction(node->right, transaction);
    }

    return node;
  }

  void printInOrder(struk *node) {
    if (node != nullptr) {
      printInOrder(node->left);
      cout << "=====================================" << endl;
      cout << "           Struk Pembelian           " << endl;
      cout << "             Kantin Maki             " << endl;
      cout << "=====================================" << endl;
      cout << "Nama      : " << node->nama << endl;
      cout << "Pembelian : " << endl;

      stringstream ss(node->pembelian);
      string item;
      while (getline(ss, item, '.')) {
        cout << "           - " << item << endl;
      }
      cout << "Total     : " << node->total << endl;
      cout << "Bayar     : " << node->pembayaran << endl;
      cout << "Kembalian : " << node->kembalian << endl;
      cout << "=====================================" << endl << endl;
      printInOrder(node->right);
    }
  }

  void simpanKeFiletxt(struk *node, ofstream &file) {
    if (node != nullptr) {
      simpanKeFiletxt(node->left, file);
      file << node->nama << endl;
      file << node->pembelian << endl;
      file << node->total << endl;
      file << node->pembayaran << endl;
      file << node->kembalian << endl;
      simpanKeFiletxt(node->right, file);
    }
  }

  struk *bacaDariFiletxt(ifstream &file) {
    struk *node = new struk();

    if (getline(file, node->nama) &&
        getline(file, node->pembelian) && (file >> node->total) && (file >> node->pembayaran) && (file >> node->kembalian)) {
      file.ignore();

      node->left = bacaDariFiletxt(file);
      node->right = bacaDariFiletxt(file);

      return node;
    }

    delete node;
    return nullptr;
  }

public:
  TransactionHistory() : root(nullptr) {}

  void addTransaction(const struk &transaction) {
    root = addTransaction(root, transaction);
  }

  void printHistory() {
    cout << "Transaction History:" << endl;
    printInOrder(root);
  }

  void simpanKeFile(const string &filename) {
    ofstream file(filename, ios::out);

    if (file.is_open()) {
      simpanKeFiletxt(root, file);
      file.close();
    } 
  }

  void bacaDariFile(const string &filename) {
    ifstream file(filename, ios::out);

    if (file.is_open()) {
      root = bacaDariFiletxt(file);
      file.close();
    } 
  }
};

#endif