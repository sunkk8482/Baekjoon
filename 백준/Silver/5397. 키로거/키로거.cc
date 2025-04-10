#include <iostream>
#include <list>
#include <string>

using namespace std;

int n;

int main() {

    int N;
    string s;

    cin >> N;
  
    list<char> password;

    for (int i = 0; i < N; ++i) {

        cin >> s;

        password.clear();
        auto it = password.begin();


        for (int j = 0; j < s.length(); ++j) {
            if (s[j] == '<') {
                if (it != password.begin()) it--;
            }
            else if (s[j] == '>') {
                if (it != password.end()) it++;
            }
            else if (s[j] == '-') {
                if (it != password.begin()) it = password.erase(--it);
            }
            else {
                it = password.insert(it, s[j]);
                it++;
            }
        }

        for (char x : password) cout << x;
        cout << endl;
    }
    return 0;
}