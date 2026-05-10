string s1 = Console.ReadLine();
string[] brojeviNiz = new string[s1.Length];

double ar = 0;

for (int i = 0; i < s1.Length; i++)
{
    int brChar = Convert.ToInt32(s1[i]);
    int cj = brChar % 10;
    int cd = brChar % 100 / 10;
    int cs = brChar / 100;
    int s = 0;
    
    ar = Math.Ceiling((double)(cj + cd + cs) / 3);
    
    if (brChar < 100)
    {
        brojeviNiz[i] = "0" + brChar;
    }
    else
    {
        brojeviNiz[i] = (Convert.ToInt32(s1[i])).ToString();
    }
    brojeviNiz[i] = brojeviNiz[i].Substring(0,1)+ar+brojeviNiz[i].Substring(1,2)+ar+brojeviNiz[i].Substring(3);
}

Console.WriteLine("********************************************Izlaz 2.1. **************************************");
for (int i = 0; i < brojeviNiz.Length; i+=2)
{
    Console.WriteLine(brojeviNiz[i]);
}