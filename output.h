#include "Toko/Padang.h"
#include "Toko/Soto.h"
#include "Toko/BakmieJawa.h"
#include "Toko/Kelontong.h"
#include "Toko/MieAyam.h"
#include "Toko/NasiRames.h"
#include "Toko/NasiUduk.h"
#include "Toko/PecelLele.h"
#include "Toko/Steak.h"
#include "Toko/Warmindo.h"
#include "gambar.h"
using namespace std;

string namaToko[10] = {"RM. Padang Uda Adi", "Warung Soto Nusantara", "Mie Ayam Palembang", "Warmindo Gus Fikri","Pecel Lele Neng Shani", "Nasi Uduk Bang Ghani", "Steak The Dims","Warung Nasi Rames BU GM", "Warung kelontong Ganjar", "Bakmie Jawa Bang Aqep"};

string kategoriToko[10][4] = {
    {"Ayam&Bebek", "Ikan", "Sapi", ""}, 
    {"Kuah", "Aneka Nasi", "", ""},  
    {"Mie&Bakso", "", "", ""},       
    {"Aneka Nasi", "Mie&Bakso", "Ayam&Bebek", ""}, 
    {"Ayam&Bebek", "Aneka Nasi", "Gorengan", "Seafood"},
    {"Aneka Nasi", "", "", ""}, 
    {"Sapi", "Mie&Bakso", "", ""},  
    {"Aneka Nasi", "Gorengan", "", ""},
    {"Jajanan", "", "", ""},
    {"Mie&Bakso", "Aneka Nasi", "", ""}
};

string tokoPickUp[10][2] = {
  {"Pick Up","Dine-In"},
  {"Dine-in",""},
  {"Pick Up","Dine-In"},
  {"Pick Up","Dine-In"},
  {"Dine-in",""},
  {"Dine-in",""},
  {"Pick Up","Dine-In"},
  {"Pick Up","Dine-In"},
  {"Dine-in",""},
  {"Dine-in",""},
};

void filterByRating(bstree &avl, nodeptr &root,double targetRating, double tokoRating[], Padang adi, Soto Nusantara, Bakmiejawa BangAqep, Kelontong Ganjar, MieAyam Afui, NasiRames BUGM, NasiUduk BangGhani, Steak theDims, Warmindo GusFikri, PecelLele NengShani) {
    cout << "Toko dengan rating " << targetRating << " dan di atasnya:" << endl;

    for (int i = 0; i < sizeof(namaToko) / sizeof(namaToko[0]); ++i) {
        if (tokoRating[i] >= targetRating) {
            cout << i + 1 << ". " << namaToko[i] << " - Rating: " << tokoRating[i] << endl;
        }
    }

    int pilihresto;
    cout << "Pilih Restoran: ";
    cin >> pilihresto;

  if (pilihresto >= 1 && pilihresto <= 10) {
    if (pilihresto == 1) {
        adi.pilihPeran(avl,root);
    } else if (pilihresto == 2) {
        Nusantara.pilihPeran(avl,root);
    } else if (pilihresto == 3) {
        BangAqep.pilihPeran(avl,root);
    } else if (pilihresto == 4) {
        Ganjar.pilihPeran(avl,root);
    } else if (pilihresto == 5) {
        Afui.pilihPeran(avl,root);
    } else if (pilihresto == 6) {
        BUGM.pilihPeran(avl,root);
    } else if (pilihresto == 7) {
        BangGhani.pilihPeran(avl,root);
    } else if (pilihresto == 8) {
        theDims.pilihPeran(avl,root);
    } else if (pilihresto == 9) {
        GusFikri.pilihPeran(avl,root);
    } else if (pilihresto == 10) {
        NengShani.pilihPeran(avl,root);
    }
  }
}

void filterByCategoryForAllStores(bstree &avl, nodeptr &root, string category, Padang adi, Soto Nusantara, Bakmiejawa BangAqep, Kelontong Ganjar, MieAyam Afui, NasiRames BUGM, NasiUduk BangGhani, Steak theDims, Warmindo GusFikri, PecelLele NengShani) {
    cout << "Toko dengan kategori '" << category << "':" << endl;

    for (int i = 0; i < sizeof(namaToko) / sizeof(namaToko[0]); ++i) {
        for (int j = 0; j < sizeof(kategoriToko[0]) / sizeof(kategoriToko[0][0]); ++j) {
            if (!kategoriToko[i][j].empty() && kategoriToko[i][j] == category) {
                cout << i + 1 << ". " << namaToko[i] << " - Kategori: " << kategoriToko[i][j] << endl;
            }
        }
    }
    int pilihresto;
    cout << "Pilih Restoran: ";
    cin >> pilihresto;
  if (pilihresto >= 1 && pilihresto <= 10) {
    if (pilihresto == 1) {
        adi.pilihPeran(avl,root);
    } else if (pilihresto == 2) {
        Nusantara.pilihPeran(avl,root);
    } else if (pilihresto == 3) {
        BangAqep.pilihPeran(avl,root);
    } else if (pilihresto == 4) {
        Ganjar.pilihPeran(avl,root);
    } else if (pilihresto == 5) {
        Afui.pilihPeran(avl,root);
    } else if (pilihresto == 6) {
        BUGM.pilihPeran(avl,root);
    } else if (pilihresto == 7) {
        BangGhani.pilihPeran(avl,root);
    } else if (pilihresto == 8) {
        theDims.pilihPeran(avl,root);
    } else if (pilihresto == 9) {
        GusFikri.pilihPeran(avl,root);
    } else if (pilihresto == 10) {
        NengShani.pilihPeran(avl,root);
    }
  }
}

void filterByPickupDineIn(bstree &avl, nodeptr &root, string pickupDineIn, Padang adi, Soto Nusantara, Bakmiejawa BangAqep, Kelontong Ganjar, MieAyam Afui, NasiRames BUGM, NasiUduk BangGhani, Steak theDims, Warmindo GusFikri, PecelLele NengShani) {
    cout << "Toko dengan opsi '" << pickupDineIn << "':" << endl;

  for (int i = 0; i < sizeof(namaToko) / sizeof(namaToko[0]); ++i) {
      for (int j = 0; j < sizeof(tokoPickUp[0]) / sizeof(tokoPickUp[0][0]); ++j) {
          if (!tokoPickUp[i][j].empty() && tokoPickUp[i][j] == pickupDineIn) {
              cout << i + 1 << ". " << namaToko[i] << endl;
          }
      }
  }
    int pilihresto;
    cout << "Pilih Restoran: ";
    cin >> pilihresto;

    if (pilihresto >= 1 && pilihresto <= 10) {
      if (pilihresto == 1) {
          adi.pilihPeran(avl,root);
      } else if (pilihresto == 2) {
          Nusantara.pilihPeran(avl,root);
      } else if (pilihresto == 3) {
          BangAqep.pilihPeran(avl,root);
      } else if (pilihresto == 4) {
          Ganjar.pilihPeran(avl,root);
      } else if (pilihresto == 5) {
          Afui.pilihPeran(avl,root);
      } else if (pilihresto == 6) {
          BUGM.pilihPeran(avl,root);
      } else if (pilihresto == 7) {
          BangGhani.pilihPeran(avl,root);
      } else if (pilihresto == 8) {
          theDims.pilihPeran(avl,root);
      } else if (pilihresto == 9) {
          GusFikri.pilihPeran(avl,root);
      } else if (pilihresto == 10) {
          NengShani.pilihPeran(avl,root);
      }
    }
}

void output() {
  Padang adi;
  Soto Nusantara;
  Bakmiejawa BangAqep;
  Kelontong Ganjar;
  MieAyam Afui;
  NasiRames BUGM;
  NasiUduk BangGhani;
  Steak theDims;
  Warmindo GusFikri;
  PecelLele NengShani;
  bstree avl;
  nodeptr root = NULL;
  avl.bacaDariFile(root);

  double tokoRating[10] = {adi.rataRata(), Nusantara.rataRata(), BangAqep.rataRata(), Ganjar.rataRata(), Afui.rataRata(), BUGM.rataRata(), BangGhani.rataRata(), theDims.rataRata(), GusFikri.rataRata(), NengShani.rataRata()};
  int pilihMenu;
  do{
    cout << "1. Daftar Membership\n";
    cout << "2. Daftar Toko\n";
    cout << "3. Keluar\n";
    cout << "Pilih: ";
    cin >> pilihMenu;
    switch (pilihMenu) {
      case 1: {
          membership newMember;
          cin.ignore();
          cout << "+--------------------------------+" << endl;
          cout << "| Daftar Memebership             |" << endl;
          cout << "+--------------------------------+" << endl;
          cout << "| Nama: ";
          getline(cin, newMember.nama);
          cout << "| Alamat: ";
          getline(cin, newMember.alamat);
          cout << "| No. Telp: ";
          cin >> newMember.noTelp;
          newMember.prio = rand() % 100 + 1;
          cout << "| Email: ";
          cin >> newMember.email;
          cin.ignore();
          cout << "| Pekerjaan: ";
          getline(cin, newMember.pekerjaan);
          cout << "+--------------------------------+" << endl; 
          avl.insert(newMember,root);
          avl.simpanKeFile(root);
        break;
      }
      case 2: {
        int pilihToko;
        do{
          kantinMaki();
          cout << "+--------------------------------+" << endl;
          cout << "| Selamat Datang Di kantin Maki  |" << endl;
          cout << "+--------------------------------+" << endl;
          cout << "0. Filter\n";
          cout << "1. RM. Padang Uda Adi\n";
          cout << "2. Warung Soto Nusantara\n";
          cout << "3. Mie Ayam Palembang Afui\n";
          cout << "4. Warmindo Gus Fikri\n";
          cout << "5. Pecel Lele Neng Shani\n";
          cout << "6. Nasi Uduk Bang Ghani\n";
          cout << "7. Steak The Dims\n";
          cout << "8. Warung Nasi Rames BU GM\n";
          cout << "9. Warung kelontong Ganjar\n";
          cout << "10. Bakmie Jawa Bang Aqep\n";
          cout << "11. Keluar\n";
          cout << "Pilihan Restoran: ";
          cin >> pilihToko;
          cout << "\033[2J\033[1;1H";



          switch (pilihToko) {
            case 0: {
              int pilihFilter;
              cout << "1. Filter Kategori\n";
              cout << "2. Filter Rating\n";
              cout << "3. Filter Pickup atau Dine-in\n";
              cout << "Pilih Filter: ";
              cin >> pilihFilter;
              if (pilihFilter == 1) {
                int pilihKategori;
                cout << "1. Aneka Nasi\n";
                cout << "2. Mie&Bakso\n";
                cout << "3. Kuah\n";
                cout << "4. Ayam&Bebek\n";
                cout << "5. Sapi\n";
                cout << "6. Seafood\n";
                cout << "7. Ikan\n";
                cout << "8. Gorengan\n";
                cout << "9. Jajanan\n";
                cout << "Pilih Kategori: ";
                cin >> pilihKategori;
                switch (pilihKategori){
                  case 1: {
                    filterByCategoryForAllStores(avl,root, "Aneka Nasi", adi, Nusantara, BangAqep, Ganjar, Afui, BUGM, BangGhani, theDims, GusFikri, NengShani);
                    break;
                  }
                  case 2: {
                    filterByCategoryForAllStores(avl,root, "Mie&Bakso", adi, Nusantara, BangAqep, Ganjar, Afui, BUGM, BangGhani, theDims, GusFikri, NengShani);
                    break;
                  }
                  case 3: {
                    filterByCategoryForAllStores(avl,root, "Kuah", adi, Nusantara, BangAqep, Ganjar, Afui, BUGM, BangGhani, theDims, GusFikri, NengShani);
                    break;
                  }
                  case 4: {
                    filterByCategoryForAllStores(avl,root, "Ayam&Bebek", adi, Nusantara, BangAqep, Ganjar, Afui, BUGM, BangGhani, theDims, GusFikri, NengShani);
                    break;
                  }
                  case 5: {
                    filterByCategoryForAllStores(avl,root, "Sapi", adi, Nusantara, BangAqep, Ganjar, Afui, BUGM, BangGhani, theDims, GusFikri, NengShani);
                    break;
                  }
                  case 6: {
                    filterByCategoryForAllStores(avl,root, "Seafood", adi, Nusantara, BangAqep, Ganjar, Afui, BUGM, BangGhani, theDims, GusFikri, NengShani);
                    break;
                  }
                  case 7: {
                    filterByCategoryForAllStores(avl,root, "Ikan", adi, Nusantara, BangAqep, Ganjar, Afui, BUGM, BangGhani, theDims, GusFikri, NengShani);
                    break;
                  }
                  case 8: {
                    filterByCategoryForAllStores(avl,root, "Gorengan", adi, Nusantara, BangAqep, Ganjar, Afui, BUGM, BangGhani, theDims, GusFikri, NengShani);
                  }
                  case 9: {
                    filterByCategoryForAllStores(avl,root, "Jajanan", adi, Nusantara, BangAqep, Ganjar, Afui, BUGM, BangGhani, theDims, GusFikri, NengShani);
                  }
                }
              } else if (pilihFilter == 2){
                int pilihRating;
                cout << "1. 5⭐\n";
                cout << "2. 4,5⭐\n";
                cout << "3. 4⭐\n";
                cout << "Pilih Rating: ";
                cin >> pilihRating;

                if (pilihRating == 1) {
                    filterByRating(avl,root, 5.0, tokoRating,adi, Nusantara, BangAqep, Ganjar, Afui, BUGM, BangGhani, theDims, GusFikri, NengShani);
                } else if (pilihRating == 2) {
                    filterByRating(avl,root, 4.5, tokoRating,adi, Nusantara, BangAqep, Ganjar, Afui, BUGM, BangGhani, theDims, GusFikri, NengShani);
                } else if (pilihRating == 3) {
                    filterByRating(avl,root, 4.0, tokoRating,adi, Nusantara, BangAqep, Ganjar, Afui, BUGM, BangGhani, theDims, GusFikri, NengShani);
                }
              } else if (pilihFilter == 3){
                int pilihPickupDineIn;
                cout << "1. Pickup\n";
                cout << "2. Dine-in\n";
                cout << "Pilih Opsi: ";
                cin >> pilihPickupDineIn;

                if (pilihPickupDineIn == 1) {
                    filterByPickupDineIn(avl,root, "Pick Up", adi, Nusantara, BangAqep, Ganjar, Afui, BUGM, BangGhani, theDims, GusFikri, NengShani);
                } else if (pilihPickupDineIn == 2) {
                    filterByPickupDineIn(avl,root, "Dine-in", adi, Nusantara, BangAqep, Ganjar, Afui, BUGM, BangGhani, theDims, GusFikri, NengShani);
                }
              }
              break;
            }
            case 1: {
              cout << "Anda Memasuki RM. Padang Uda Adi" << endl << endl;
              adi.pilihPeran(avl,root);
              break;
            }
            case 2: {
              cout << "Anda Memasuki Warung Soto Nusantara" << endl << endl;
              Nusantara.pilihPeran(avl,root);
              break;
            }
            case 3: {
              cout << "Anda Memasuki Mie Ayam Palembang Afui" << endl << endl;
              Afui.pilihPeran(avl,root);
              break;
            }
            case 4: {
              cout << "Anda Memasuki Warmindo Gus Fikri" << endl << endl;
              GusFikri.pilihPeran(avl,root);
              break;
            }
            case 5: {
              cout << "Anda Memasuki Pecel Lele Neng Shani " << endl << endl;
              NengShani.pilihPeran(avl,root);
              break;
            }
            case 6: {
              cout << "Anda Memasuki Nasi Uduk Bang Ghani" << endl << endl;
              BangGhani.pilihPeran(avl,root);
              break;
            }
            case 7: {
              cout << "Anda Memasuki Steak The Dims " << endl << endl;
              theDims.pilihPeran(avl,root);
              break;
            }
            case 8: {
              cout << "Anda Memasuki Warung Nasi Rames Bu GM" << endl << endl;
              BUGM.pilihPeran(avl,root);
              break;
            }
            case 9: {
              cout << "Anda Memasuki Warung kelontong Cak Ganjar" << endl << endl;
              Ganjar.pilihPeran(avl,root);
              break;
            }
            case 10: {
              cout << "Anda Memasuki Bakmi Jawa Aqep " << endl << endl;
              BangAqep.pilihPeran(avl,root);
              break;
            }
            case 11: {
              cout << "Terimakasih Sudah Mengunjungi Kantin" << endl;
              break;
            }
          }
        }while ( pilihToko != 12);
        break;
      }
    }
  }while (pilihMenu != 3);
}