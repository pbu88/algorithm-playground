using System;
using System.Collections.Generic;


namespace Prob1011
{
    class Program
    {
        static void Main(string[] args)
        {
            int t = int.Parse(Console.ReadLine());
            for (int i = 0; i < t; i++)
            {
                Console.ReadLine();
                string[] s = Console.ReadLine().Split(' ');
                int ng = int.Parse(s[0]);
                int nm = int.Parse(s[1]);
                List<int> ngl = new List<int>();
                List<int> nml = new List<int>();
                string[] g = Console.ReadLine().Split(' ');
                for (int j = 0; j < ng; j++)
                {
                    int x = int.Parse(g[j]);
                    ngl.Add(x);
                }
                string[] m = Console.ReadLine().Split(' ');
                for (int j = 0; j < nm; j++)
                {
                    int x = int.Parse(m[j]);
                    nml.Add(x);
                }
                ngl.Sort();
                nml.Sort();
                int mi = 0;
                int gi = 0;
                while (mi < nml.Count && gi < ngl.Count)
                {
                    if (ngl[gi] < nml[mi])
                        gi++;
                    else
                        mi++;
                }
                Console.WriteLine(gi == ngl.Count ? "MechaGodzilla" : "Godzilla");
            }
        }
    }
}
