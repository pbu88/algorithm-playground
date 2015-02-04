using System;

namespace Prob1004
{
    class Program
    {
        static void Main(string[] args)
        {
            int t = int.Parse(Console.ReadLine());
            for (int i = 0; i < t; i++)
            {
                string s = Console.ReadLine();
                Console.WriteLine(grid(int.Parse(s.Split(' ')[0]), int.Parse(s.Split(' ')[1])));
            }
        }

        static string grid(int n, int m)
        {
            return n == Math.Min(n, m) ? n % 2 == 1 ? "R" : "L" : m % 2 == 1 ? "D" : "U";
        }
    }
}