using System;

namespace Prob1003
{
    class Program
    {
        static void Main(string[] args)
        {
            int t = int.Parse(Console.ReadLine());
            for (int i = 0; i < t; i++)
            {
                string s = Console.ReadLine();
                int n = int.Parse(s.Split(' ')[0]);
                int m = int.Parse(s.Split(' ')[1]);
                long[] candidates = new long[n];
                for (int j = 0; j < m; j++)
                {
                    string s1 = Console.ReadLine();
                    for (int k = 0; k < n; k++)
                    {
                        candidates[k] += int.Parse(s1.Split(' ')[k]);
                    }
                }
                long max = -1;
                int winner = 0;
                for (int j = 0; j < n; j++)
                {
                    if (max < candidates[j])
                    {
                        max = candidates[j];
                        winner = j + 1;
                    }
                }
                Console.WriteLine(winner);
            }
        }
    }
}
