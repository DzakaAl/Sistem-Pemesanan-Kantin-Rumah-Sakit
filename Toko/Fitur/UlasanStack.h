#ifndef ULASANSTACK_H
#define ULASANSTACK_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_ULASAN = 100;

struct Ulasan
{
  string namaPembeli;
  int rating;
  string isiUlasan;
};

class UlasanPembeli
{
private:
  Ulasan ulasanArray[MAX_ULASAN];
  int top;

public:
  UlasanPembeli() : top(-1) {}

  void push(const Ulasan &ulasan)
  {
    if (top < MAX_ULASAN - 1)
    {
      top++;
      ulasanArray[top] = ulasan;
      cout << "Ulasan berhasil ditambahkan!\n";
    }
    else
    {
      cout << "Stack ulasan penuh, tidak dapat menambahkan ulasan baru.\n";
    }
  }

  void pop()
  {
    if (top == -1)
    {
      cout << "Tidak ada ulasan untuk dihapus.\n";
    }
    else
    {
      top--;
      cout << "Ulasan saat ini berhasil dihapus.\n";
    }
  }

  void TampilkanSemuaUlasan()
  {
    if (top == -1)
    {
      cout << "Tidak ada ulasan saat ini.\n";
    }
    else
    {
      cout << "Daftar Ulasan:\n";
      for (int i = top; i >= 0; i--)
      {
        Ulasan ulasan = ulasanArray[i];
        cout << "Nama Pembeli: " << ulasan.namaPembeli << "\n";
        if (ulasan.rating == 1)
        {
          cout << "Rating: " << ulasan.rating << " ⭐\n";
        }
        else if (ulasan.rating == 2)
        {
          cout << "Rating: " << ulasan.rating << " ⭐⭐\n";
        }
        else if (ulasan.rating == 3)
        {
          cout << "Rating: " << ulasan.rating << " ⭐⭐⭐\n";
        }
        else if (ulasan.rating == 4)
        {
          cout << "Rating: " << ulasan.rating << " ⭐⭐⭐⭐\n";
        }
        else if (ulasan.rating == 5)
        {
          cout << "Rating: " << ulasan.rating << " ⭐⭐⭐⭐⭐\n";
        }
        cout << "Isi Ulasan: " << ulasan.isiUlasan << "\n\n";
      }
    }
  }

  void TambahUlasan()
  {
    Ulasan ulasan;
    cout << "Masukkan Nama Pembeli: ";
    cin >> ulasan.namaPembeli;
    cout << "1.⭐\n2.⭐⭐\n3.⭐⭐⭐\n4.⭐⭐⭐⭐\n5.⭐⭐⭐⭐⭐\n";
    cout << "Pilih Rating: ";
    cin >> ulasan.rating;
    cout << "Masukkan Isi Ulasan: ";
    cin.ignore(); // Ignore newline character left in the buffer
    getline(cin, ulasan.isiUlasan);

    push(ulasan);
  }

  void DeleteUlasan()
  {
    pop();
  }

  void SimpanKeFile(string namaFile)
  {
    ofstream outFile(namaFile, ios::out);

    if (!outFile)
    {
      return;
    }

    for (int i = top; i >= 0; i--)
    {
      Ulasan ulasan = ulasanArray[i];
      outFile << ulasan.namaPembeli << "\n";
      outFile << ulasan.rating << "\n";
      outFile << ulasan.isiUlasan << "\n\n";
    }

    outFile.close();
  }

  void BacaDariFile(string namaFile)
  {
    ifstream inFile(namaFile);

    if (!inFile)
    {
      return;
    }

    top = -1;
    Ulasan ulasan;
    while (inFile >> ulasan.namaPembeli >> ulasan.rating)
    {
      inFile.ignore();
      getline(inFile, ulasan.isiUlasan);
      if (top < MAX_ULASAN - 1)
      {
        top++;
        ulasanArray[top] = ulasan;
      }
      else
      {
        cerr << "Stack ulasan penuh, tidak dapat membaca lebih banyak ulasan dari file.\n";
        break;
      }
    }

    inFile.close();
  }

  double HitungRataRataRating()
  {
    if (top == -1)
    {
      return 0.0;
    }

    double totalRating = 0.0;
    for (int i = top; i >= 0; i--)
    {
      totalRating += ulasanArray[i].rating;
    }

    return totalRating / (top + 1);
  }

};

#endif