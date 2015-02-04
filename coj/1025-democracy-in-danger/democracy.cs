using System;

namespace Prob1025
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] input = new int[n];
            string[] s = Console.ReadLine().Split(' ');
            for (int i = 0; i < n; i++)
            {
                input[i] = int.Parse(s[i]);
            }
            Array.Sort(input);
            int res = 0;
            for (int i = 0; i <= n/2; i++)
            {
                res += input[i] / 2 + 1;
            }
            Console.WriteLine(res);
        }
    }
}
