using System;
using System.Collections.Generic;

namespace Prob1021
{
    class Program
    {
        static void Main(string[] args)
        {
            char[] sep = { ' ' };
            string s;
            string[] sa;
            int k;
            int m;
            int catMin;
            int catsDone;
            List<string> courses = new List<string>();
            while (true)
            {
                s = Console.ReadLine();
                if (s == "0")
                    break;
                courses.Clear();
                sa = s.Split(sep, StringSplitOptions.RemoveEmptyEntries);
                k = int.Parse(sa[0]);
                m = int.Parse(sa[1]);
                while (courses.Count != k)
                {
                    sa = Console.ReadLine().Split(sep, StringSplitOptions.RemoveEmptyEntries);
                    foreach (string course in sa)
                    {
                        courses.Add(course);
                    }
                }
                catsDone = 0;
                for (int i = 0; i < m; i++)
                {
                    sa = Console.ReadLine().Split(sep, StringSplitOptions.RemoveEmptyEntries);
                    catMin = int.Parse(sa[1]);
                    for (int j = 2; j < sa.Length; j++)
                    {
                        if(courses.Contains(sa[j]))
                            catMin--;
                    }
                    if (catMin <= 0)
                        catsDone++;
                }
                if(catsDone == m)
                    Console.WriteLine("yes");
                else
                    Console.WriteLine("no");
            }
        }
    }
}
