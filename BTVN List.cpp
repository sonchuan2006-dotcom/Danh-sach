#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct SinhVien {
    string hoTen;
    string mssv;
    int namSinh;
    float gpa;
    SinhVien *next;
};

// Chèn cuối danh sách
void chenSV(SinhVien **first, string hoTen, string mssv, int namSinh, float gpa) {
    SinhVien *s = new SinhVien;       
    s->hoTen = hoTen;
    s->mssv = mssv;
    s->namSinh = namSinh;
    s->gpa = gpa;
    s->next = nullptr;

    if (*first == nullptr) {
        *first = s;
        return;
    }

    SinhVien *p = *first;
    while (p->next != nullptr)
        p = p->next;

    p->next = s;
}

// In danh sách
void in_DS(SinhVien *first) {
    while (first) {
        cout <<first->hoTen << ' '
             << first->mssv<< ' '
             << first->namSinh<< ' '
             <<  fixed << setprecision(2) << first->gpa<< ' '
             << endl;
        first = first->next;
    }
}

// Đếm số SV
int demDS(SinhVien *first) {
    int d = 0;
    while (first) {
        d++;
        first = first->next;
    }
    return d;
}

// Đếm SV có GPA > 3.2
int SV_Gioi(SinhVien *first) {
    int d = 0;
    while (first) {
        if (first->gpa > 3.2)
            d++;
        first = first->next;
    }
    return d;
}

// Sắp xếp theo GPA tăng dần 
void SapXep(SinhVien *first) {
    for (SinhVien *i = first; i != nullptr; i = i->next) {
        for (SinhVien *j = i->next; j != nullptr; j = j->next) {
            if (i->gpa > j->gpa) {
                // Chỉ hoán đổi dữ liệu, KHÔNG động tới next
                swap(i->hoTen, j->hoTen);
                swap(i->mssv, j->mssv);
                swap(i->namSinh, j->namSinh);
                swap(i->gpa, j->gpa);
            }
        }
    }
}

int main() {
    SinhVien *DS = nullptr;

    chenSV(&DS, "Dat",  "202414345", 2006, 3.1);
    chenSV(&DS, "Son",  "202414346", 2006, 3.4);
    chenSV(&DS, "Minh", "202414347", 2006, 2.9);
    chenSV(&DS, "Tung", "202414348", 2006, 4.0);
    in_DS(DS);cout<<endl;
    cout << "\nSo luong SV: " << demDS(DS) << endl;
    cout << "SV co GPA > 3.2: " << SV_Gioi(DS) << endl;
    SapXep(DS);
    in_DS(DS);cout<<endl;
    chenSV(&DS, "Long", "202414349", 2006, 2.4);
    SapXep(DS);
    in_DS(DS);cout<<endl;
    return 0;
}

