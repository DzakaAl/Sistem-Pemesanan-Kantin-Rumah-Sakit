#ifndef QUEUEPESANAN_H
#define QUEUEPESANAN_H
#include <string>
const int MAX_SIZE = 100;

struct Antrian
{
    string atasNama;
    string pesanan;
};

class Queue{
private:
    Antrian list[MAX_SIZE];
    int rear;
    int front;

public:
    Queue() : rear(-1), front(-1) {}

    bool isEmpty() const
    {
        return rear == -1 && front == -1;
    }

    bool isFull() const
    {
        return (rear + 1) % MAX_SIZE == front;
    }

    void enqueue(const Antrian &item)
    {
        if (isFull())
        {
            cout << "Antrian penuh, tidak bisa menambahkan pesanan baru.\n";
            return;
        }

        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX_SIZE;
        }

        list[rear] = item;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Antrian pesanan kosong.\n";
            return;
        }


        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX_SIZE;
        }
    }

    void display() const
    {
        if (isEmpty())
        {
            cout << "Antrian pesanan kosong.\n";
            return;
        }

        cout << "Daftar Pesanan:\n";
        int i = front;
        do
        {
            cout << i - front + 1 << ". " << list[i].atasNama << " - " << list[i].pesanan << endl;
            i = (i + 1) % MAX_SIZE;
        } while (i != (rear + 1) % MAX_SIZE);
    }
    void simpanAntrian(const string &namaFile)
    {
        ofstream file(namaFile, ios::out);
        if (file.is_open())
        {
            if (!isEmpty())
            {
                int i = front;
                do
                {
                    file << list[i].atasNama << endl;
                    file << list[i].pesanan << endl;
                    i = (i + 1) % MAX_SIZE;
                } while (i != (rear + 1) % MAX_SIZE);
            }
            file.close();
        }
    }

    void bacaAntrian(const string &namaFile)
    {
        ifstream file(namaFile);
        if (file.is_open())
        {
            Antrian pesanan;
            while (getline(file, pesanan.atasNama) && getline(file, pesanan.pesanan))
            {
                enqueue(pesanan);
            }
            file.close();
        }
    }
};

#endif