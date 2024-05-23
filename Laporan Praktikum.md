**BAB 1**

**PENDAHULUAN**

**LATAR BELAKANG**

- **Stack**: Struktur data LIFO (Last In, First Out) di mana elemen terakhir yang dimasukkan adalah yang pertama kali keluar. Operasi utamanya adalah Push (menambahkan) dan Pop (menghapus)[1]. Contoh penerapan meliputi manajemen memori dan evaluasi ekspresi matematika.

- **Queue**: Struktur data FIFO (First In, First Out) di mana elemen pertama yang dimasukkan adalah yang pertama kali keluar. Operasi utamanya adalah Enqueue (menambahkan) dan Dequeue (menghapus). Contoh penerapan meliputi penjadwalan proses dan pengaturan antrian pesan.

**RUMUSAN MASALAH**

a. Bagaimana cara memahami konsep stack dan queue pada struktur data dan algoritma dengan baik?

b. Bagaimana cara mengimplementasikan operasi-operasi dasar pada stack dan queue, seperti Push, Pop, Enqueue, dan Dequeue?

c. Bagaimana cara memecahkan permasalahan menggunakan solusi yang melibatkan penggunaan stack dan queue, seperti manajemen memori, evaluasi ekspresi matematika, penjadwalan proses, atau pengaturan antrian pesan?


**TUJUAN PRAKTIKUM**

a. Mampu memahami konsep stack dan queue pada struktur data dan algoritma
b. Mampu mengimplementasikan operasi-operasi pada stack dan queue
c. Mampu memecahkan permasalahan dengan solusi stack dan queue

**BAB 2**

**PEMBAHASAN**

**DASAR TEORI**

Stack adalah struktur data sederhana yang mengikuti prinsip Last In, First Out (LIFO), yang mirip dengan tumpukan piring di kafetaria. Definisi umumnya menyebutkan bahwa operasi seperti Push (menambah), Pop (menghapus), dan Top (melihat elemen teratas) adalah operasi dasar yang umum dilakukan pada stack. Selain itu, fungsi lain seperti IsEmpty (memeriksa apakah kosong) dan Size (mengembalikan jumlah elemen) juga penting dalam penggunaan stack[2].

Queue adalah struktur data yang mengikuti prinsip First In, First Out (FIFO), mirip dengan konsep antrian dalam kehidupan sehari-hari. Queue dapat diimplementasikan menggunakan array atau linked list, dengan struktur yang terdiri dari dua pointer, yaitu front dan rear[3]. Operasi dasar pada queue meliputi enqueue (menambahkan), dequeue (mengeluarkan), peek (melihat tanpa menghapus), isEmpty (memeriksa apakah kosong), isFull (memeriksa apakah penuh), dan size (menghitung jumlah elemen).

**GUIDED**

**GUIDED 1**

```C++
#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty() {
    return (top == 0);
}

void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] = "";
        top--;
    }
}

void peekArrayBuku(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

int countStack() {
    return top;
}

void changeArrayBuku(int posisi, string data) {
    if (posisi > top) {
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        arrayBuku[index] = data;
    }
}

void destroyArraybuku() {
    for (int i = top; i >= 0; i--) {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main() {
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";
    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;
    peekArrayBuku(2);
    popArrayBuku();
    cout << "Banyaknya data = " << countStack() << endl;
    changeArrayBuku(2, "Bahasa Jerman");
    cout << endl;
    cetakArrayBuku();
    cout << "\n";
    destroyArraybuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;
    cetakArrayBuku();

    return 0;
}
```
**Bagian 1**
```C++
#include<iostream>
#include<string>

using namespace std;
```
Interpretasi :

include iostream : Ini adalah preprocessor directive yang menyertakan pustaka input-output standar C++ ke dalam program. Ini diperlukan untuk menggunakan fungsi-fungsi dasar seperti cout dan cin untuk output dan input data.

include string : Ini adalah preprocessor directive yang menyertakan pustaka string ke dalam program. Pustaka ini memberikan fungsionalitas untuk bekerja dengan tipe data string di C++, seperti deklarasi, manipulasi, dan operasi pada string.

using namespace std;: Ini adalah deklarasi yang mengizinkan penggunaan semua simbol dalam namespace std tanpa menuliskan std:: di depannya setiap kali digunakan. Namespace std berisi semua fungsi, tipe data, dan objek yang didefinisikan dalam pustaka standar C++.

**Bagian 2**
```C++
string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty() {
    return (top == 0);
}

void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] = "";
        top--;
    }
}

void peekArrayBuku(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

int countStack() {
    return top;
}

void changeArrayBuku(int posisi, string data) {
    if (posisi > top) {
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        arrayBuku[index] = data;
    }
}

void destroyArraybuku() {
    for (int i = top; i >= 0; i--) {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}
```
Interpretasi : 

Stack adalah struktur data yang mengikuti prinsip Last In First Out (LIFO), yang berarti elemen yang terakhir dimasukkan ke dalam stack akan menjadi yang pertama dikeluarkan. Dalam kode tersebut, terdapat beberapa fungsi yang memungkinkan manipulasi data dalam stack. Fungsi isFull() dan isEmpty() digunakan untuk memeriksa apakah stack sudah penuh atau kosong. Fungsi pushArrayBuku() dan popArrayBuku() digunakan untuk menambahkan dan menghapus data dari stack. Fungsi peekArrayBuku() digunakan untuk melihat data pada posisi tertentu tanpa menghapusnya, sementara countStack() mengembalikan jumlah elemen dalam stack. Fungsi changeArrayBuku() digunakan untuk mengubah data pada posisi tertentu, dan destroyArraybuku() untuk menghapus semua data dalam stack. Terakhir, fungsi cetakArrayBuku() mencetak semua data dalam stack dari atas ke bawah. Semua operasi pada stack diimplementasikan dengan memanipulasi variabel top sebagai penunjuk posisi teratas dalam stack, serta menggunakan array arrayBuku sebagai wadah penyimpanan data.

**Bagian 3**
```C++
int main() {
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";
    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;
    peekArrayBuku(2);
    popArrayBuku();
    cout << "Banyaknya data = " << countStack() << endl;
    changeArrayBuku(2, "Bahasa Jerman");
    cout << endl;
    cetakArrayBuku();
    cout << "\n";
    destroyArraybuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;
    cetakArrayBuku();

    return 0;
}
```
Interpretasi : 

 Tahap awal program memasukkan beberapa judul buku ke dalam tumpukan menggunakan fungsi pushArrayBuku(). Setelah itu, program mencetak seluruh isi tumpukan dengan menggunakan fungsi cetakArrayBuku(). Dilanjutkan dengan memeriksa apakah tumpukan penuh atau kosong menggunakan fungsi isFull() dan isEmpty() serta mencetak hasilnya. Kemudian, program melihat buku yang berada di posisi kedua dari atas tumpukan dengan fungsi peekArrayBuku(), lalu menghapus buku dari atas tumpukan menggunakan fungsi popArrayBuku(). Selanjutnya, program menghitung jumlah buku dalam tumpukan menggunakan fungsi countStack() dan mencetak hasilnya. Setelah itu, program mengganti judul buku yang berada di posisi kedua dari atas tumpukan dengan judul "Bahasa Jerman" menggunakan fungsi changeArrayBuku(). Setelah melakukan perubahan, program kembali mencetak seluruh isi tumpukan. Tahap selanjutnya adalah menghapus semua buku dari tumpukan menggunakan fungsi destroyArraybuku(), lalu mencetak jumlah data yang tersisa setelah tumpukan dikosongkan. Terakhir, program mencetak kembali isi tumpukan yang sudah kosong. Ini semua menunjukkan alur bagaimana program mengelola tumpukan buku dengan berbagai operasi yang dilakukan secara berurutan.

 ## Hasil output
 ```C++
Inggris
Dasar Multimedia
Matematika Diskrit
Struktur Data
Kalkulus

Apakah data stack penuh? 1
Apakah data stack kosong? 0
Posisi ke 2 adalah Dasar Multimedia
Banyaknya data = 4

Dasar Multimedia
Bahasa Jerman
Struktur Data
Kalkulus

Jumlah data setelah dihapus: 0
Tidak ada data yang dicetak

--------------------------------
Process exited after 0.05978 seconds with return value 0
Press any key to continue . . .
```
**GUIDED 2**
```C++
#include <iostream>
using namespace std;

const int maksimalQueue = 5; // Maksimal antrian
int front = 0; // Penanda depan antrian
int back = 0; // Penanda belakang antrian
string queueTeller[5]; // Array untuk menyimpan antrian

bool isFull() { // Pengecekan antrian penuh atau tidak
    if (back == maksimalQueue) {
        return true; // =1
    } else {
        return false;
    }
}

bool isEmpty() { // Antrian kosong atau tidak
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian(string data) { // Menambahkan antrian
    if (isFull()) {
        cout << "Antrian penuh" << endl;
    } else {
        if (isEmpty()) { // Jika antrian kosong
            queueTeller[0] = data;
            front++;
            back++;
        } else { // Jika antrian ada isi
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() { // Mengurangi antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

int countQueue() { // Menghitung jumlah antrian
    return back;
}

void clearQueue() { // Menghapus semua antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue() { // Melihat isi antrian
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```
**Bagian 1**
```C++
#include<iostream>
#include<string>

using namespace std;
```
Interpretasi :

include iostream : Ini adalah preprocessor directive yang menyertakan pustaka input-output standar C++ ke dalam program. Ini diperlukan untuk menggunakan fungsi-fungsi dasar seperti cout dan cin untuk output dan input data.

include string : Ini adalah preprocessor directive yang menyertakan pustaka string ke dalam program. Pustaka ini memberikan fungsionalitas untuk bekerja dengan tipe data string di C++, seperti deklarasi, manipulasi, dan operasi pada string.

using namespace std;: Ini adalah deklarasi yang mengizinkan penggunaan semua simbol dalam namespace std tanpa menuliskan std:: di depannya setiap kali digunakan. Namespace std berisi semua fungsi, tipe data, dan objek yang didefinisikan dalam pustaka standar C++.

**Bagian 2**
```C++
const int maksimalQueue = 5; // Maksimal antrian
int front = 0; // Penanda depan antrian
int back = 0; // Penanda belakang antrian
string queueTeller[5]; // Array untuk menyimpan antrian

bool isFull() { // Pengecekan antrian penuh atau tidak
    if (back == maksimalQueue) {
        return true; // =1
    } else {
        return false;
    }
}

bool isEmpty() { // Antrian kosong atau tidak
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian(string data) { // Menambahkan antrian
    if (isFull()) {
        cout << "Antrian penuh" << endl;
    } else {
        if (isEmpty()) { // Jika antrian kosong
            queueTeller[0] = data;
            front++;
            back++;
        } else { // Jika antrian ada isi
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() { // Mengurangi antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

int countQueue() { // Menghitung jumlah antrian
    return back;
}

void clearQueue() { // Menghapus semua antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue() { // Melihat isi antrian
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}
```
Interpretasi : 

konstanta maksimalQueue. Fungsi isFull() digunakan untuk memeriksa apakah antrian sudah penuh, sedangkan fungsi isEmpty() untuk memeriksa apakah antrian kosong. Fungsi enqueueAntrian(string data) bertugas menambahkan elemen baru ke dalam antrian, dengan memeriksa apakah antrian penuh sebelum menambahkan. Fungsi dequeueAntrian() menghapus elemen pertama dari antrian, sedangkan countQueue() mengembalikan jumlah elemen dalam antrian. Fungsi clearQueue() digunakan untuk menghapus seluruh elemen dari antrian, dan viewQueue() untuk menampilkan isi antrian. Dengan struktur data antrian ini, pengguna dapat dengan efisien mengatur dan memanipulasi kumpulan data dengan prinsip first-in-first-out (FIFO).

**Bagian 3**
```C++
int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```
Interpretasi : 

Pertama, program menambahkan dua elemen ke dalam antrian, yakni "Andi" dan "Maya". Setelah itu, program menampilkan isi dari antrian dan jumlah elemennya. Selanjutnya, program menghapus elemen pertama dari antrian, kemudian menampilkan kembali isi antrian dan jumlah elemennya setelah penghapusan. Setelah itu, program membersihkan seluruh isi antrian dan menampilkan jumlah elemen yang tersisa. Dengan demikian, program ini memberikan pemahaman yang jelas tentang cara kerja dari struktur data antrian dan bagaimana mengakses serta memanipulasi elemennya dalam sebuah program.

## Hasil Output
```C++
Data antrian teller:
1. Andi
2. Maya
3. (kosong)
4. (kosong)
5. (kosong)
Jumlah antrian = 2
Data antrian teller:
1. Maya
2. (kosong)
3. (kosong)
4. (kosong)
5. (kosong)
Jumlah antrian = 1
Data antrian teller:
1. (kosong)
2. (kosong)
3. (kosong)
4. (kosong)
5. (kosong)
Jumlah antrian = 0

--------------------------------
Process exited after 0.06908 seconds with return value 0
Press any key to continue . . .
```

**UNGUIDED**

**UNGUIDED 1**
```C++
#include <iostream>
#include <stack>
#include <string>
#include <cctype> 
#include <locale> 
using namespace std;

// Fungsi untuk membersihkan string dari karakter non-alphanumeric dan mengubah huruf menjadi huruf kecil
string preprocess(string s) {
    string result;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (isalnum(c)) { // Memeriksa apakah karakter adalah alphanumeric
            result += tolower(c); // Mengubah huruf menjadi huruf kecil
        }
    }
    return result;
}

// Fungsi untuk menentukan apakah sebuah string adalah palindrom atau tidak
bool isPalindrome(string s) {
    s = preprocess(s);
    stack<char> st;

    // Memasukkan setengah karakter pertama ke dalam stack
    int n = s.length();
    for (int i = 0; i < n / 2; i++) {
        st.push(s[i]);
    }

    // Membandingkan setengah karakter kedua dengan karakter yang ada di stack
    for (int i = (n + 1) / 2; i < n; i++) {
        if (s[i] != st.top()) {
            return false;
        }
        st.pop();
    }
    return true;
}

int main() {
    string input;
    cout << "Masukkan kalimat: ";
    getline(cin, input);

    if (isPalindrome(input)) {
        cout << "Kalimat tersebut adalah palindrom." << endl;
    } else {
        cout << "Kalimat tersebut bukan palindrom." << endl;
    }

    system("pause"); // Menahan layar agar tidak langsung tertutup pada Dev C++
    return 0;
}
```
**Bagian 1**
```C++
#include<iostream>
#include<string>

using namespace std;
```
Interpretasi :

include iostream : Ini adalah preprocessor directive yang menyertakan pustaka input-output standar C++ ke dalam program. Ini diperlukan untuk menggunakan fungsi-fungsi dasar seperti cout dan cin untuk output dan input data.

include string : Ini adalah preprocessor directive yang menyertakan pustaka string ke dalam program. Pustaka ini memberikan fungsionalitas untuk bekerja dengan tipe data string di C++, seperti deklarasi, manipulasi, dan operasi pada string.

using namespace std;: Ini adalah deklarasi yang mengizinkan penggunaan semua simbol dalam namespace std tanpa menuliskan std:: di depannya setiap kali digunakan. Namespace std berisi semua fungsi, tipe data, dan objek yang didefinisikan dalam pustaka standar C++.

<stack> digunakan untuk mengakses dan menggunakan struktur data tumpukan (stack), <cctype> digunakan untuk mengakses fungsi-fungsi yang berkaitan dengan pengolahan karakter, dan <locale> digunakan untuk mengakses fasilitas yang berkaitan dengan lokal atau pengaturan regional dalam pemrosesan teks

**Bagian 2**
```C++

// Fungsi untuk membersihkan string dari karakter non-alphanumeric dan mengubah huruf menjadi huruf kecil
string preprocess(string s) {
    string result;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (isalnum(c)) { // Memeriksa apakah karakter adalah alphanumeric
            result += tolower(c); // Mengubah huruf menjadi huruf kecil
        }
    }
    return result;
}

// Fungsi untuk menentukan apakah sebuah string adalah palindrom atau tidak
bool isPalindrome(string s) {
    s = preprocess(s);
    stack<char> st;

    // Memasukkan setengah karakter pertama ke dalam stack
    int n = s.length();
    for (int i = 0; i < n / 2; i++) {
        st.push(s[i]);
    }

    // Membandingkan setengah karakter kedua dengan karakter yang ada di stack
    for (int i = (n + 1) / 2; i < n; i++) {
        if (s[i] != st.top()) {
            return false;
        }
        st.pop();
    }
    return true;
}
```
Interpretasi : 

Fungsi preprocess() bertujuan untuk membersihkan string input dari karakter non-alphanumeric dan mengubah semua huruf menjadi huruf kecil. Ini dilakukan dengan iterasi setiap karakter dalam string dan memeriksa apakah itu adalah karakter alfanumerik. Jika ya, karakter tersebut diubah menjadi huruf kecil dan ditambahkan ke dalam string hasil. Kemudian, fungsi isPalindrome() menggunakan pendekatan stack untuk memeriksa apakah string yang telah diolah oleh preprocess() adalah palindrom atau tidak. String input diolah terlebih dahulu dengan preprocess(), kemudian setengah karakter pertama dimasukkan ke dalam stack. Setelah itu, setengah karakter kedua dibandingkan dengan karakter-karakter yang diambil dari stack secara terbalik. Jika tidak ada perbedaan, string tersebut dianggap sebagai palindrom dan fungsi mengembalikan true, jika ada perbedaan, maka dikembalikan false. Dengan demikian, dengan menggunakan pendekatan ini, kita dapat memeriksa palindromitas string dengan mengabaikan perbedaan dalam huruf besar dan kecil serta karakter non-alphanumeric.

**Bagian 3**
```C++
int main() {
    string input;
    cout << "Masukkan kalimat: ";
    getline(cin, input);

    if (isPalindrome(input)) {
        cout << "Kalimat tersebut adalah palindrom." << endl;
    } else {
        cout << "Kalimat tersebut bukan palindrom." << endl;
    }

    system("pause"); // Menahan layar agar tidak langsung tertutup pada Dev C++
    return 0;
}
```
Interpretasi : 

Pertama-tama, program meminta pengguna untuk memasukkan sebuah kalimat. Kalimat yang dimasukkan oleh pengguna akan disimpan dalam variabel bernama input.

Selanjutnya, program memanggil fungsi isPalindrome(input) untuk memeriksa apakah kalimat tersebut merupakan palindrom atau tidak. Sayangnya, dalam kode yang diberikan, definisi dari fungsi isPalindrome(input) tidak disertakan. Sehingga, untuk membuat program ini berfungsi sepenuhnya, Anda perlu menambahkan definisi dari fungsi isPalindrome(input) yang dapat melakukan pemeriksaan palindrom.

Setelah memeriksa palindrom, program akan mencetak pesan sesuai dengan hasil pemeriksaan. Jika kalimat yang dimasukkan oleh pengguna merupakan palindrom, program akan mencetak "Kalimat tersebut adalah palindrom.", sedangkan jika tidak, program akan mencetak "Kalimat tersebut bukan palindrom."

Terakhir, program menggunakan system("pause") untuk menahan layar agar tidak langsung tertutup pada Dev C++. Setelah itu, program mengembalikan nilai 0 dan berakhir.

## Hasil output
```C++
Masukkan kalimat: ini
Kalimat tersebut adalah palindrom.
Press any key to continue . . .

Masukkan kalimat: telkom
Kalimat tersebut bukan palindrom.
Press any key to continue . . .
```

**UNGUIDED 2**
```C++
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
```
**Bagian 1**
```C++
#include <iostream>
#include <queue>
#include <string>
using namespace std;
```
Interpretasi : 

include iostream : Ini adalah preprocessor directive yang menyertakan pustaka input-output standar C++ ke dalam program. Ini diperlukan untuk menggunakan fungsi-fungsi dasar seperti cout dan cin untuk output dan input data.

include string : Ini adalah preprocessor directive yang menyertakan pustaka string ke dalam program. Pustaka ini memberikan fungsionalitas untuk bekerja dengan tipe data string di C++, seperti deklarasi, manipulasi, dan operasi pada string.

using namespace std;: Ini adalah deklarasi yang mengizinkan penggunaan semua simbol dalam namespace std tanpa menuliskan std:: di depannya setiap kali digunakan. Namespace std berisi semua fungsi, tipe data, dan objek yang didefinisikan dalam pustaka standar C++.

**Bagian 2**
```C++
// Tampilkan isi dari queue
void displayQueue(queue<string> q) {
    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }
}
```
Interpretasi : 

Fungsi `displayQueue` merupakan sebuah implementasi dalam bahasa C++ yang bertujuan untuk menampilkan isi dari sebuah queue yang berisi elemen bertipe string. Dalam algoritma yang dibangun, fungsi ini menerima satu parameter, yaitu sebuah queue yang berisi string. Melalui sebuah perulangan, fungsi secara berurutan mengambil elemen yang berada di depan queue, menampilkannya ke layar, dan kemudian menghapusnya dari queue. Proses ini terus berlanjut hingga tidak ada elemen lagi dalam queue. Dengan demikian, fungsi ini memastikan bahwa setiap elemen yang ada dalam queue akan ditampilkan sekali, sehingga pengguna dapat melihat dengan jelas urutan dan isi dari queue tersebut. Dengan kejelasan dan runtutnya proses yang dilakukan oleh fungsi ini, pengguna dapat dengan mudah memahami dan memanfaatkannya dalam pengembangan program yang memerlukan manipulasi data berbasis queue.

**Bagian 3**
```C++
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
```
Interpretasi : 

Pada awalnya, program mendeklarasikan variabel dan objek yang diperlukan, termasuk objek antrian myQueue, variabel choice untuk menyimpan pilihan pengguna, dan variabel data untuk menyimpan data yang akan dimasukkan ke dalam antrian.

Selanjutnya, program memberikan beberapa opsi kepada pengguna melalui sebuah loop do-while. Pengguna dapat memilih untuk menambahkan data baru ke dalam antrian, menghapus elemen pertama dari antrian, menampilkan isi antrian, atau keluar dari program.

Penggunaan struktur switch-case digunakan untuk menangani setiap pilihan yang dimasukkan oleh pengguna. Jika pengguna memilih untuk menambahkan data baru, program akan meminta pengguna untuk memasukkan data yang kemudian ditambahkan ke dalam antrian menggunakan myQueue.push(data). Sedangkan jika pengguna memilih untuk menghapus data, program akan menghapus elemen pertama dari antrian menggunakan myQueue.pop() jika antrian tidak kosong. Untuk menampilkan isi dari antrian, program memanggil fungsi displayQueue(), meskipun implementasi dari fungsi tersebut tidak terlihat dalam potongan kode yang diberikan. Terakhir, jika pengguna memilih untuk keluar dari program, program akan selesai.

Jika pengguna memasukkan pilihan yang tidak valid, program akan memberikan pesan kesalahan dan meminta pengguna untuk memasukkan pilihan yang benar. Dengan demikian, program ini menyediakan antarmuka sederhana untuk memanipulasi sebuah antrian dengan operasi dasar seperti menambahkan, menghapus, dan menampilkan data.

## Hasil output
```C++
Menu:
1. Enqueue (Tambah data)
2. Dequeue (Hapus data)
3. Tampilkan Data
4. Exit
Pilih:
```

**DAFTAR PUSTAKA**

Selamet, R. (2016). Implementasi Struktur Data List, Queue Dan Stack Dalam Java. Media Informatika, 15(3), 18–25.

Aliyanto, A., Utomo, S., & Santosa, S. (2011). Sistem Pembelajaran Algoritma Stack Dan Queue Dengan Pendekatan Program Based Learning. Jurnal Teknologi Informasi, 7(1), 17–18.

Sihombing, J. (2019). Penerapan Stack Dan Queue Pada Array Dan Linked List Dalam Java. Jurnal Ilmiah Infokom, 7(2), 15–24.

