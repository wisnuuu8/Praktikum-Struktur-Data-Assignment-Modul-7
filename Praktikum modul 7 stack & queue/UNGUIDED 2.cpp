#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Tampilkan isi dari queue
void displayQueue(queue<string> q) {
    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }
}

int main() {
    queue<string> myQueue;
    int choice;
    string data;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue (Tambah data)\n";
        cout << "2. Dequeue (Hapus data)\n";
        cout << "3. Tampilkan Data\n";
        cout << "4. Exit\n";
        cout << "Pilih: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan data: ";
                cin >> data;
                myQueue.push(data);
                break;
            case 2:
                if (!myQueue.empty()) {
                    cout << "Data yang dihapus: " << myQueue.front() << endl;
                    myQueue.pop();
                } else {
                    cout << "Queue kosong. Tidak ada data untuk dihapus." << endl;
                }
                break;
            case 3:
                if (!myQueue.empty()) {
                    cout << "Isi dari Queue:" << endl;
                    displayQueue(myQueue);
                } else {
                    cout << "Queue kosong." << endl;
                }
                break;
            case 4:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan masukkan pilihan yang benar." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}

