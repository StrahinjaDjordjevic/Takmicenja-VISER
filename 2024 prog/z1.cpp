#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <sstream>

using namespace std;

int sumaX(int x, int y, int z, int*** matrica, int n);
int sumaY(int x, int y, int z, int*** matrica, int n);
int sumaZ(int x, int y, int z, int*** matrica, int n);
void moveX(int x, int y, int z, int pomeraj, int*** matrica, int n);
void moveY(int x, int y, int z, int pomeraj, int*** matrica, int n);
void moveZ(int x, int y, int z, int pomeraj, int*** matrica, int n);

int main() {
    int n;
    cout << "Unesite N" << endl;
    cin >> n;

    int*** matrica = new int**[n];
    for (int i = 0; i < n; ++i) {
        matrica[i] = new int*[n];
        for (int j = 0; j < n; ++j) {
            matrica[i][j] = new int[n];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                matrica[i][j][k] = i + j + k;
            }
        }
    }

    cout << "***************Izlaz 1.1.***************" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cout << matrica[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    string naredba;
    while (true) {
        cout << "Naredba: " << endl;
        cin.ignore();
        getline(cin, naredba);

        string nazivNaredbe = naredba.substr(0, naredba.find(' '));
        transform(nazivNaredbe.begin(), nazivNaredbe.end(), nazivNaredbe.begin(), ::toupper);

        if (nazivNaredbe == "UPDATE") {
            int x, y, z, vrednost;
            sscanf(naredba.c_str(), "UPDATE %d,%d,%d %d", &x, &y, &z, &vrednost);
            matrica[x][y][z] = vrednost;

            cout << "***************Izlaz 1.2.***************" << endl;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < n; k++) {
                        cout << matrica[i][j][k] << " ";
                    }
                    cout << endl;
                }
                cout << endl;
            }
        } else if (nazivNaredbe == "SUM") {
            int suma = 0, x, y, z, x1, y1, z1;
            sscanf(naredba.c_str(), "SUM %d,%d,%d %d,%d,%d", &x, &y, &z, &x1, &y1, &z1);
            for (int i = x; i <= x1; i++) {
                for (int j = y; j <= y1; j++) {
                    for (int k = z; k <= z1; k++) {
                        suma += matrica[i][j][k];
                    }
                }
            }
            cout << "***************Izlaz 1.3.***************" << endl;
            cout << "Suma je: " << suma << endl;
        } else if (nazivNaredbe == "NEW") {
            int*** nova = new int**[n];
            for (int i = 0; i < n; ++i) {
                nova[i] = new int*[n];
                for (int j = 0; j < n; ++j) {
                    nova[i][j] = new int[n];
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < n; k++) {
                        nova[i][j][k] = sumaX(i, j, k, matrica, n) + sumaY(i, j, k, matrica, n) + sumaZ(i, j, k, matrica, n);
                    }
                }
            }

            cout << "***************Izlaz 1.4.***************" << endl;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < n; k++) {
                        cout << nova[i][j][k] << " ";
                    }
                    cout << endl;
                }
                cout << endl;
            }

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    delete[] nova[i][j];
                }
                delete[] nova[i];
            }
            delete[] nova;
        } else if (nazivNaredbe == "MOVE") {
            int x, y, z, x1, y1, z1;
            sscanf(naredba.c_str(), "MOVE %d,%d,%d %d,%d,%d", &x, &y, &z, &x1, &y1, &z1);
            moveX(x, y, z, x1, matrica, n);
            moveY(x, y, z, y1, matrica, n);
            moveZ(x, y, z, z1, matrica, n);

            cout << "***************Izlaz 1.5.***************" << endl;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < n; k++) {
                        cout << matrica[i][j][k] << " ";
                    }
                    cout << endl;
                }
                cout << endl;
            }
        } else if (nazivNaredbe == "QUIT") {
            break;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            delete[] matrica[i][j];
        }
        delete[] matrica[i];
    }
    delete[] matrica;

    return 0;
}

int sumaX(int x, int y, int z, int*** matrica, int n) {
    int suma = 0;
    if (x == 0) {
        suma += matrica[n - 1][y][z];
        suma += matrica[x + 1][y][z];
    } else if (x == n - 1) {
        suma += matrica[x - 1][y][z];
        suma += matrica[0][y][z];
    } else {
        suma += matrica[x + 1][y][z];
        suma += matrica[x - 1][y][z];
    }
    return suma;
}

int sumaY(int x, int y, int z, int*** matrica, int n) {
    int suma = 0;
    if (y == 0) {
        suma += matrica[x][n - 1][z];
        suma += matrica[x][y + 1][z];
    } else if (y == n - 1) {
        suma += matrica[x][y - 1][z];
        suma += matrica[x][0][z];
    } else {
        suma += matrica[x][y + 1][z];
        suma += matrica[x][y - 1][z];
    }
    return suma;
}

int sumaZ(int x, int y, int z, int*** matrica, int n) {
    int suma = 0;
    if (z == 0) {
        suma += matrica[x][y][n - 1];
        suma += matrica[x][y][z + 1];
    } else if (z == n - 1) {
        suma += matrica[x][y][z - 1];
        suma += matrica[x][y][0];
    } else {
        suma += matrica[x][y][z + 1];
        suma += matrica[x][y][z - 1];
    }
    return suma;
}

void moveX(int x, int y, int z, int pomeraj, int*** matrica, int n) {
    if (pomeraj < 0) {
        for (int p = 0; p < -pomeraj; p++) {
            int tmp = matrica[0][y][z];
            for (int i = 0; i < n - 1; i++) {
                matrica[i][y][z] = matrica[i + 1][y][z];
            }
            matrica[n - 1][y][z] = tmp;
        }
    } else {
        for (int p = 0; p < pomeraj; p++) {
            int tmp = matrica[n - 1][y][z];
            for (int i = n - 1; i > 0; i--) {
                matrica[i][y][z] = matrica[i - 1][y][z];
            }
            matrica[0][y][z] = tmp;
        }
    }
}

void moveY(int x, int y, int z, int pomeraj, int*** matrica, int n) {
    if (pomeraj < 0) {
        for (int p = 0; p < -pomeraj; p++) {
            int tmp = matrica[x][0][z];
            for (int i = 0; i < n - 1; i++) {
                matrica[x][i][z] = matrica[x][i + 1][z];
            }
            matrica[x][n - 1][z] = tmp;
        }
    } else {
        for (int p = 0; p < pomeraj; p++) {
            int tmp = matrica[x][n - 1][z];
            for (int i = n - 1; i > 0; i--) {
                matrica[x][i][z] = matrica[x][i - 1][z];
            }
            matrica[x][0][z] = tmp;
        }
    }
}

void moveZ(int x, int y, int z, int pomeraj, int*** matrica, int n) {
    if (pomeraj < 0) {
        for (int p = 0; p < -pomeraj; p++) {
            int tmp = matrica[x][y][0];
            for (int i = 0; i < n - 1; i++) {
                matrica[x][y][i] = matrica[x][y][i + 1];
            }
            matrica[x][y][n - 1] = tmp;
        }
    } else {
        for (int p = 0; p < pomeraj; p++) {
            int tmp = matrica[x][y][n - 1];
            for (int i = n - 1; i > 0; i--) {
                matrica[x][y][i] = matrica[x][y][i - 1];
            }
            matrica[x][y][0] = tmp;
        }
    }
}
