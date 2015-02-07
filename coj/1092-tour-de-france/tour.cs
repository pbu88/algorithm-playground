using System;
using System.Collections.Generic;

namespace Prob1092
{
    class Program
    {
        static void Main(string[] args)
        {
            while (true)
            {
                string s = Console.ReadLine();
                if (s == "0")
                    break;
                string[] sa = s.Split(' ');
                int f = int.Parse(sa[0]);
                int r = int.Parse(sa[1]);
                double[] fs = new double[f];
                string[] fsa = Console.ReadLine().Split(' ');
                string[] rsa = Console.ReadLine().Split(' ');
                List<double> ratios = new List<double>();
                for (int i = 0; i < f; i++)
                {
                    fs[i] = double.Parse(fsa[i]);
                }
                for (int i = 0; i < f; i++)
                {
                    for (int j = 0; j < r; j++)
                    {
                        ratios.Add(double.Parse(rsa[j]) / fs[i]);
                    }

                }
                ratios.Sort();
                double res = 0;
                for (int i = 1; i < ratios.Count; i++)
                {
                    double x = ratios[i] / ratios[i - 1];
                    res = res < x ? x : res;
                }
                string ans = Math.Round(res, 2).ToString();
                if(ans.Length == 1)
                    Console.WriteLine("{0}.00",ans);
                else if(ans.Length==3)
                    Console.WriteLine("{0}0",ans);
                else
                    Console.WriteLine(ans);
            }
        }
    }
}
