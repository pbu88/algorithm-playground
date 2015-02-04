using System;

namespace coj.uci.cu
{
    class Program
    {
        static void Main(string[] args)
        {
            //Console.WriteLine(Math.Pow(2,31) == 2147483648);
            //pthpower(2147483648);
            while (true)
            {
                string s = Console.ReadLine();
                if (s == "0")
                    break;
                long n = long.Parse(s);
                pthpower(n);
            }
        }

        static void pthpower(long n)
        {            
            bool less = false;
            if (n < 0)
            {
                less = true;
            }
            n = Math.Abs(n);
            int cota = (int)Math.Sqrt(n);
            for (long i = 2; i <= cota + 1; i++)
            {
                decimal x = (decimal)Math.Log(n, i);
                if (x / (int)x == 1)
                {
                    if (less)
                    {
                        if (x % 2 == 1)
                        {
                            Console.WriteLine((int)x);
                            return;
                        }
                    }
                    else
                    {
                        Console.WriteLine((int)x);
                        return;
                    }
                }
            }
            Console.WriteLine("1");
        }
    }
}
