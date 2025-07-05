#ifndef MEMBERSHIP_H
#define MEMBERSHIP_H

#include <cctype>
#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct membership {
  string nama;
  string alamat;
  string noTelp;
  int prio;
  string email;
  string pekerjaan;
  membership *left;
  membership *right;
  int height;
};

typedef struct membership *nodeptr;

class bstree {
public:
  void insert(membership memberBaru, nodeptr &p);
  bool find(string &x, nodeptr &p, membership &found);
  void makeempty(nodeptr &p);
  void copy(nodeptr &p, nodeptr &p1);
  nodeptr nodecopy(nodeptr &p);
  void preorder(nodeptr p);
  int bsheight(nodeptr p);
  nodeptr srl(nodeptr &p1);
  nodeptr drl(nodeptr &p1);
  nodeptr srr(nodeptr &p1);
  nodeptr drr(nodeptr &p1);
  int tinggi(int value1, int value2);
  int nonodes(nodeptr p);

  void simpanKeFile(nodeptr &p);
  void bacaDariFile(nodeptr &p);

private:
  void simpan(nodeptr &p, ofstream &file);
};

void bstree::insert(membership memberBaru, nodeptr &p)
{
    if (p == NULL)
    {
        p = new membership;
        p->nama = memberBaru.nama;
        p->alamat = memberBaru.alamat;
        p->noTelp = memberBaru.noTelp;
        p->prio = memberBaru.prio;
        p->email = memberBaru.email;
        p->pekerjaan = memberBaru.pekerjaan;
        p->left = NULL;
        p->right = NULL;
        p->height = 1;
    }
    else
    {
        if (memberBaru.noTelp < p->noTelp)
        {
            insert(memberBaru, p->left);
            if ((bsheight(p->left) - bsheight(p->right)) == 2)
            {
                if (memberBaru.noTelp < p->left->noTelp)
                {
                    p = srl(p);
                }
                else
                {
                    p = drl(p);
                }
            }
        }
        else if (memberBaru.noTelp > p->noTelp)
        {
            insert(memberBaru, p->right);
            if ((bsheight(p->right) - bsheight(p->left)) == 2)
            {
                if (memberBaru.noTelp > p->right->noTelp)
                {
                    p = srr(p);
                }
                else
                {
                    p = drr(p);
                }
            }
        }
        else
        {
            cout << "Data membership sudah ada" << endl;
        }
    }
    int m, n, d;
    m = bsheight(p->left);
    n = bsheight(p->right);
    d = tinggi(m, n);
    p->height = d + 1;
}

bool bstree::find(string &x, nodeptr &p, membership &found) {
  if (p == NULL) {
    cout << "Maaf Nomor anda tidak ditemukan\n" << endl;
    return false;
  } else {
    if (x < p->noTelp) {
      return find(x, p->left, found);
    } else if (x > p->noTelp) {
      return find(x, p->right, found);
    } else {
      cout << "Nomor Telepon ditemukan" << endl;
      found = *p;
      return true;
    }
  }
}

void bstree::makeempty(nodeptr &p) {
  nodeptr d;
  if (p != NULL) {
    makeempty(p->left);
    makeempty(p->right);
    d = p;
    free(d);
    p = NULL;
  }
}

nodeptr bstree::nodecopy(nodeptr &p) {
  nodeptr temp;
  if (p == NULL) {
    return p;
  } else {
    temp = new membership;
    temp->noTelp = p->noTelp;
    temp->left = nodecopy(p->left);
    temp->right = nodecopy(p->right);
    return temp;
  }
}

void bstree::copy(nodeptr &p, nodeptr &p1) {
  makeempty(p1);
  p1 = nodecopy(p);
}

void bstree::preorder(nodeptr p) {
  if (p != NULL) {
    cout << p->noTelp << "\t";
    preorder(p->left);
    preorder(p->right);
  }
}

int bstree::bsheight(nodeptr p) {
  int t;
  if (p == NULL) {
    return 0;
  } else {
    t = p->height;
    return t;
  }
}

nodeptr bstree::srl(nodeptr &p1) {
  nodeptr p2;
  p2 = p1->left;
  p1->left = p2->right;
  p2->right = p1;
  p1->height = tinggi(bsheight(p1->left), bsheight(p1->right)) + 1;
  p2->height = tinggi(bsheight(p2->left), p1->height) + 1;
  return p2;
}

nodeptr bstree::drl(nodeptr &p1) {
  p1->left = srr(p1->left);
  return srl(p1);
}

nodeptr bstree::srr(nodeptr &p1) {
  nodeptr p2;
  p2 = p1->right;
  p1->right = p2->left;
  p2->left = p1;
  p1->height = tinggi(bsheight(p1->left), bsheight(p1->right)) + 1;
  p2->height = tinggi(p1->height, bsheight(p2->right)) + 1;
  return p2;
}

nodeptr bstree::drr(nodeptr &p1) {
  p1->right = srl(p1->right);
  return srr(p1);
}

int bstree::tinggi(int value1, int value2) {
  return ((value1 > value2) ? value1 : value2);
}

int bstree::nonodes(nodeptr p) {
  int count = 0;
  if (p != NULL) {
    nonodes(p->left);
    nonodes(p->right);
    count++;
  }
  return count;
}

void bstree::simpan(nodeptr &p, ofstream &file) {
  if (p != NULL) {
    file << p->nama << endl;
    file << p->alamat << endl;
    file << p->noTelp << endl;
    file << p->prio << endl;
    file << p->email << endl;
    file << p->pekerjaan << endl;
    simpan(p->left, file);
    simpan(p->right, file);
  }
}

void bstree::simpanKeFile(nodeptr &p) {
  ofstream file("membership_data.txt", ios::out);
  if (file.is_open()) {
    simpan(p, file);
    file.close();
  } else {
    cout << "Tidak dapat membuka file." << endl;
  }
}

void bstree::bacaDariFile(nodeptr &p) {
  ifstream file("membership_data.txt");
  if (file.is_open()) {
    makeempty(p);
    while (!file.eof()) {
      membership newMember;
      getline(file, newMember.nama);
      getline(file, newMember.alamat);
      getline(file, newMember.noTelp);
      file >> newMember.prio;
      file.ignore();
      getline(file, newMember.email);
      getline(file, newMember.pekerjaan);
      insert(newMember, p);
    }
    file.close();
  } else {
    cout << "Unable to open file." << endl;
  }
}

#endif
