using System;
using System.Collections;

namespace a.plus.b
{
    class Program
    {
        static void Main(string[] args)
        {
            ArrayList a = new ArrayList();
            while (true)
            {
                string input = Console.ReadLine();
                if (input == null || input == "")
                    break;
                string[] s = input.Split(' ');
                a.Add((int.Parse(s[0]) + int.Parse(s[1])).ToString());
            }
            for (int i = 0; i < a.Count; i++)
            {
                Console.WriteLine(a[i]);
            }
        }
    }
}