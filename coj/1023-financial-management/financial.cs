using System;
using System.Collections;

namespace financial
{
    class Program
    {
        static void Main(string[] args)
        {
            double sum = 0;
            for (int i = 0; i < 12; i++)
			{
                sum+= double.Parse(Console.ReadLine());
			}
            Console.WriteLine("$"+Math.Round(sum/12.0,2));
            
        }
    }
}