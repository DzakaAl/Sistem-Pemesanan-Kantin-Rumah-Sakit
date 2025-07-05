#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

using namespace std;

struct Priority {
  string atasNama;
  string pesanan;
  int prioritas;
  Priority* next;

  Priority() : next(nullptr) {}
};

class PriorityQueue {
private:
  Priority* front;

public:
  PriorityQueue() : front(nullptr) {}

  void enqueue(const Priority& priority) {
    Priority* newNode = new Priority;
    *newNode = priority;

    if (front == nullptr || priority.prioritas < front->prioritas) {
      newNode->next = front;
      front = newNode;
    } else {
      Priority* temp = front;
      while (temp->next != nullptr && temp->next->prioritas < priority.prioritas) {
        temp = temp->next;
      }
      newNode->next = temp->next;
      temp->next = newNode;
    }
  }

  void dequeue() {
    if (front == nullptr) {
      cout << "Antrian kosong. Tidak ada yang dihapus." << endl;
    } else {
      Priority* temp = front;
      front = front->next;
      delete temp;
    }
  }

  void display() {
    Priority* temp = front;
    cout << "Daftar Pesanan: " << endl;
    while (temp != nullptr) {
      cout << "Atas Nama: " << temp->atasNama << ", Pesanan: " << temp->pesanan
           << ", Prioritas: " << temp->prioritas << endl;
      temp = temp->next;
    }
  }

  void simpanAntrian(const string& filename) {
    ofstream file(filename);
    Priority* temp = front;
    while (temp != nullptr) {
      file << temp->atasNama << endl;
      file << temp->pesanan << endl;
      file << temp->prioritas << endl;
      temp = temp->next;
    }
    file.close();
  }

  void bacaAntrian(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
      while (!file.eof()) {
        Priority pesanan;
        getline(file, pesanan.atasNama);
        getline(file, pesanan.pesanan);
        file >> pesanan.prioritas;
        file.ignore(); // Membersihkan karakter newline
        if (file.fail()) break; // Exit loop jika bacaan file gagal
        enqueue(pesanan);
      }
      file.close();
    }
  }
};

#endif
