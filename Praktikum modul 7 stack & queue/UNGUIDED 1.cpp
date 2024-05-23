#include <iostream>
#include <stack>
#include <string>
#include <cctype> // Untuk isalnum()
#include <locale> // Untuk tolower()
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

