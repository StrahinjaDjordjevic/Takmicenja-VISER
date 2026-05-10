#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

string ShortestSubsequenceForStability(const string& s);
int FindMax(const vector<int>& array);

int main() {
    cout << "Unesite string: ";
    string unos;
    getline(cin, unos);

    vector<string> brojeviNiz(unos.length());
    for (size_t i = 0; i < unos.length(); ++i) {
        brojeviNiz[i] = to_string((int)unos[i]);
        while (brojeviNiz[i].length() < 3) {
            brojeviNiz[i] = "0" + brojeviNiz[i];
        }
    }

    for (size_t i = 0; i < unos.length(); i += 2) {
        double suma = 0;
        for (char c : brojeviNiz[i]) {
            suma += c - '0';
        }
        double sr = ceil(suma / brojeviNiz[i].length());
        brojeviNiz[i] = "" + string(1, brojeviNiz[i][0]) + to_string((int)sr) + string(1, brojeviNiz[i][1]) + to_string((int)sr) + string(1, brojeviNiz[i][2]);
    }

    cout << "***************Izlaz 2.1.***************" << endl;
    for (size_t i = 0; i < unos.length(); i += 2) {
        cout << brojeviNiz[i] << endl;
    }

    int mapa[256] = {0};
    for (char c : unos) {
        mapa[(unsigned char)c]++;
    }

    vector<int> countCounts;
    for (int i = 0; i < 256; ++i) {
        if (mapa[i] > 0) {
            if (countCounts.size() <= mapa[i]) {
                countCounts.resize(mapa[i] + 1, 0);
            }
            countCounts[mapa[i]]++;
        }
    }

    cout << "***************Izlaz 2.2.***************" << endl;
    int nonzeroCountCounts = count(countCounts.begin(), countCounts.end(), 1);
    if (nonzeroCountCounts == 1) {
        cout << "String je ispravan." << endl;
    } else if (nonzeroCountCounts == 2) {
        vector<int> counts;
        for (size_t i = 0; i < countCounts.size(); ++i) {
            if (countCounts[i] > 0) {
                counts.push_back(i);
            }
        }
        if (abs(counts[0] - counts[1]) < 2) {
            cout << "String je ispravan." << endl;
        } else {
            cout << "String nije ispravan." << endl;
        }
    } else {
        cout << "String nije ispravan." << endl;
    }

    string s2;
    for (char c : unos) {
        c = toupper(c);
        if (c == 'A' || c == 'C' || c == 'T' || c == 'G') {
            s2 += c;
        }
    }

    cout << "***************Izlaz 2.3.***************" << endl;
    cout << "s2: " << s2 << endl;

    cout << "***************Izlaz 2.4.***************" << endl;
    int charCounts[4] = {0};
    for (char c : s2) {
        switch (c) {
            case 'A':
                charCounts[0]++;
                break;
            case 'C':
                charCounts[1]++;
                break;
            case 'G':
                charCounts[2]++;
                break;
            case 'T':
                charCounts[3]++;
                break;
        }
    }

    if (s2.length() % 4 != 0) {
        cout << "s2 nije stabilan!" << endl;
    } else {
        bool provera = true;
        int requiredCount = s2.length() / 4;
        for (int count : charCounts) {
            if (count != requiredCount) {
                cout << "s2 nije stabilan!" << endl;
                provera = false;
                break;
            }
        }
        if (provera) {
            cout << "s2 je stabilan!" << endl;
        }
    }

    cout << "Ucestalost pojavljivanja svakog slova: " << endl;
    const char letters[] = {'A', 'C', 'G', 'T'};
    for (int i = 0; i < 4; ++i) {
        cout << "Slovo: " << letters[i] << ", ucestalost: " << charCounts[i] << endl;
    }

    cout << "***************Izlaz 2.5.***************" << endl;
    cout << ShortestSubsequenceForStability(s2) << endl;

    return 0;
}

string ShortestSubsequenceForStability(const string& s) {
    int charCounts[4] = {0};
    for (char c : s) {
        switch (c) {
            case 'A':
                charCounts[0]++;
                break;
            case 'C':
                charCounts[1]++;
                break;
            case 'G':
                charCounts[2]++;
                break;
            case 'T':
                charCounts[3]++;
                break;
        }
    }

    vector<int> counts;
    for (int count : charCounts) {
        counts.push_back(count);
    }

    int max = FindMax(counts);

    string shortestSubsequence;
    for (int i = 0; i < 4; ++i) {
        shortestSubsequence.append(max - charCounts[i], letters[i]);
    }

    return shortestSubsequence;
}

int FindMax(const vector<int>& array) {
    return *max_element(array.begin(), array.end());
}
