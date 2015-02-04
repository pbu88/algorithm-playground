using System;

namespace Prob1024
{
    class Program
    {
        static void Main(string[] args)
        {
            while (true)
            {
                string s = Console.ReadLine();
                if (s == "0.00")
                    break;
                double target = double.Parse(s);
                double sum = 0;
                int count = 0;
                for (int i = 2; sum < target; i++)
                {
                    count++;
                    sum += 1.00 / i;
                }
                Console.WriteLine("{0} card(s)",count);
            }
        }
    }
}