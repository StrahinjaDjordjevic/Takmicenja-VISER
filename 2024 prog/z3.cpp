#include <iostream>
#include <vector>
#include <iomanip>

const int rows = 10;
const int cols = 20;

char** InitializeMall() {
    char** mall = new char*[rows];
    for (int i = 0; i < rows; ++i) {
        mall[i] = new char[cols];
        for (int j = 0; j < cols; ++j) {
            if (j == 0 || j == cols - 1) {
                if (i == rows - 1) {
                    mall[i][j] = 'E'; 
                } else {
                    mall[i][j] = 'S';
                }
            } else {
                mall[i][j] = 'R'; 
            }
        }
    }
    return mall;
}

void PrintMall(char** mall) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << mall[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void MoveThief(char** mall, int& Xl, int& Yl) {
    if (mall[Xl][Yl] == 'R') {
        mall[Xl][Yl] = '-';
    }

    if (Yl < cols - 2 && mall[Xl][Yl + 1] == 'R') {
        Yl++;
    } else if (Yl > 1 && mall[Xl][Yl - 1] == 'R') {
        Yl--;
    } else if ((Yl == 0 || Yl == cols - 1)) {
        if (Xl < rows - 1 && mall[Xl + 1][Yl] == 'S') {
            Xl++;
        } else if (Xl > 0 && mall[Xl - 1][Yl] == 'S') {
            Xl--;
        }
    } else {
        if (Yl == 1 && mall[Xl][0] == 'S') {
            Yl = 0;
        } else if (Yl == cols - 2 && mall[Xl][cols - 1] == 'S') {
            Yl = cols - 1;
        } else {
            if (Yl < cols / 2) {
                Yl--;
            } else {
                Yl++;
            }
        }
    }
}

void MovePolice(char** mall, int& Xp, int& Yp, int Xl, int Yl) {
    if (Xp == Xl) {
        if (Yp < Yl) Yp += 2;
        else if (Yp > Yl) Yp -= 2;
    } else {
        if (Yp != 0 && Yp != cols - 1) {
            if (Yp < cols / 2) Yp = 0;
            else Yp = cols - 1;
        } else {
            if (Xp < Xl) Xp++;
            else if (Xp > Xl) Xp--;
        }
    }
}

bool AllShopsRobbed(char** mall) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 1; j < cols - 1; ++j) {
            if (mall[i][j] == 'R') return false;
        }
    }
    return true;
}

int CountRobbedShops(char** mall) {
    int count = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 1; j < cols - 1; ++j) {
            if (mall[i][j] == '-') count++;
        }
    }
    return count;
}

int main() {
    std::cout << "Unesite početne kordinate policajca u formatu Xp,Yp" << std::endl;
    int Xp, Yp, Xl, Yl;
    std::cin >> Xp;
    std::cin.ignore(1, ',');
    std::cin >> Yp;
    std::cout << "Unesite početne kordinate lopova u formatu Xl,Yl" << std::endl;
    std::cin >> Xl;
    std::cin.ignore(1, ',');
    std::cin >> Yl;

    int Xu = -1;
    int Yu = -1;

    char** mall = InitializeMall();
    std::cout << "***************Izlaz 3.1.***************" << std::endl;
    PrintMall(mall);

    mall[Xp][Yp] = 'P';
    mall[Xl][Yl] = 'L';
    std::cout << "***************Izlaz 3.2.***************" << std::endl;
    PrintMall(mall);

    while (true) {
        MoveThief(mall, Xl, Yl);

        if (AllShopsRobbed(mall)) {
            break;
        }

        MovePolice(mall, Xp, Yp, Xl, Yl);
        if (Xp == Xl && Yp == Yl) {
            mall[Xp][Yp] = 'X';
            Xu = Xp;
            Yu = Yp;
            break;
        }
    }
    std::cout << "***************Izlaz 3.3.***************" << std::endl;
    PrintMall(mall);
    std::cout << "***************Izlaz 3.4.***************" << std::endl;
    if (Xu != -1 && Yu != -1) {
        std::cout << "Policajac je uhvatio lopova na poziciji: " << Xu << ", " << Yu << std::endl;
    } else {
        std::cout << "Lopov je uspeo da opustoši sve radnje i pobegne." << std::endl;
    }
    std::cout << "***************Izlaz 3.5.***************" << std::endl;
    int countRobbed = CountRobbedShops(mall);
    double percente = static_cast<double>(countRobbed) / (rows * (cols - 2)) * 100;
    std::cout << "Uspešnost pljačke je " << std::fixed << std::setprecision(2) << percente << " %" << std::endl;

    // Cleanup dynamic memory
    for (int i = 0; i < rows; ++i) {
        delete[] mall[i];
    }
    delete[] mall;

    return 0;
}
