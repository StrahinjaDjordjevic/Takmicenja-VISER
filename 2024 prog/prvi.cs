using System.Data;

Console.WriteLine("PRVI ZADATAK");

string naredba;
int s = 0;
int prvi, drugi, treci, cetvrti, peti, sesti;

Console.WriteLine("Unesite N");
int n = Convert.ToInt32(Console.ReadLine());
if (n >= 20 || n < 1) return 1;

int[,,] pomeranje = new int[n, n, n];
int[,,] mat = new int[n, n, n];
Unos(mat);


Console.WriteLine("************************************** naredba 1.1 ***********************************************");
Ispis(mat);


do
{
    Console.WriteLine("Naredba:");
    naredba = Console.ReadLine();
    naredba = naredba.ToLower();

    string[] pom = naredba.Split(' ');
    // update
    if (pom[0] == "update")
    {
        string[] koordinate = pom[1].Split(',');
        int[] kordinatice = { Convert.ToInt32(koordinate[0]), Convert.ToInt32(koordinate[1]), Convert.ToInt32(koordinate[2]) };
        int broj = Convert.ToInt32(pom[2]);
        
        mat[kordinatice[0], kordinatice[1], kordinatice[2]] = broj;
        
        Console.WriteLine("************************************** naredba 1.2 ***********************************************");
        Ispis(mat);
    }
    // suma
    if (pom[0] == "sum")
    {
        string[] prveK = pom[1].Split(',');
        int[] x = { Convert.ToInt32(prveK[0]), Convert.ToInt32(prveK[1]), Convert.ToInt32(prveK[2]) };
        
        string[] drugeK = pom[2].Split(',');
        int[] y = { Convert.ToInt32(drugeK[0]), Convert.ToInt32(drugeK[1]), Convert.ToInt32(drugeK[2]) };

        for (int i = x[0]; i <= y[0]; i++)
        {
            for (int j = x[1]; j <= y[1]; j++)
            {
                for (int k = x[2]; k <= y[2]; k++)
                {
                    s+=mat[i,j,k];
                }
            }
        }
        
        Console.WriteLine("********************************************Izlaz 1.3***********************************");
        Console.WriteLine($"Suma je: {s}");
    }

    if (pom[0] == "new")
    {
        int[,,] newMat = new int[mat.GetLength(0), mat.GetLength(1), mat.GetLength(2)];
        for (int i = 0; i < newMat.GetLength(0); i++)
        {
            for (int j = 0; j < newMat.GetLength(1); j++)
            {
                for (int k = 0; k < mat.GetLength(2); k++)
                {
                    if (i == 0) prvi = mat[n - 1, j, k];
                    else prvi = mat[i-1, j, k];
                    if (i == n - 1) drugi = mat[0, j, k];
                    else drugi = mat[i+1, j, k];
                    if (j == 0) treci = mat[i, n - 1, k];
                    else treci = mat[i, j - 1,k];
                    if (j == n - 1) cetvrti = mat[i, 0, k];
                    else cetvrti = mat[i, j + 1, k];
                    if (k == 0) peti = mat[i, j, n - 1];
                    else peti = mat[i, j, k - 1];
                    if (k == n - 1) sesti = mat[i, j, 0];
                    else sesti = mat[i, j, k + 1];
                    newMat[i, j, k] = prvi + drugi + treci + cetvrti + peti + sesti;
                }
            }
        }
        Console.WriteLine("******************************IZLAZ 1.4 *****************************************");
        Ispis(newMat);
    }

    if (pom[0] == "move")
    {
        string[] koordinate = pom[1].Split(',');
        int[] kordinatice = { Convert.ToInt32(koordinate[0]), Convert.ToInt32(koordinate[1]), Convert.ToInt32(koordinate[2]) };

        string[] pomeraj = pom[2].Split(',');
        int[] koliko = { Convert.ToInt32(koordinate[0]), Convert.ToInt32(koordinate[1]), Convert.ToInt32(koordinate[2]) };
        koliko[0] = koliko[0] % n;
        koliko[1] = koliko[1] % n;
        koliko[2] = koliko[2] % n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    pomeranje[(i + koliko[0]) % n, (j + koliko[1]) % n, (k + koliko[2]) % n] = mat[i,j,k];
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    mat[i, j, k] = pomeranje[i, j, k];
                }
            }
        }
        Console.WriteLine("*********************************************** Izlaz 1.5 *******************************************");
        Ispis(mat);
    }
        
} while (naredba != "quit");

return 0;


void Unos(int[,,] mat)
{
    for (int i = 0; i < mat.GetLength(0); i++)
    {
        for (int j = 0; j < mat.GetLength(1); j++)
        {
            for (int k = 0; k < mat.GetLength(2); k++)
            {
                mat[i, j, k] = i+j+k;
            }
        }
    }
}

void Ispis(int[,,] mat)
{
    for (int i = 0; i < mat.GetLength(0); i++)
    {
        for (int j = 0; j < mat.GetLength(1); j++)
        {
            for (int k = 0; k < mat.GetLength(2); k++)
            {
                Console.Write(mat[i,j,k]+" ");
            }
            Console.WriteLine();
        }
        Console.WriteLine();
    }
}