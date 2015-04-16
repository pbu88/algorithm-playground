using System;

namespace Prob1191
{
    class Program
    {
        static void Main(string[] args)
        {
            char[] sep = { ' ' };
            string[] sa;
            string word1;
            string word2;
            int k;
            int w;
            int res;
            int t = int.Parse(Console.ReadLine());
            for (int tc = 0; tc < t; tc++)
            {
                sa = Console.ReadLine().Split(sep, StringSplitOptions.RemoveEmptyEntries);
                k = int.Parse(sa[0]);
                w = int.Parse(sa[1]);
                word1 = Console.ReadLine();
                res = k;
                for (int i = 1; i < w; i++)
                {
                    word2 = Console.ReadLine();
                    int aux = 0;
                    for (; aux < word1.Length; aux++)
                    {
                        if (word2.StartsWith(word1.Substring(aux)))
                        {                            
                            break;
                        }
                    }
                    res += word2.Length - (word2.Length - aux);
                    word1 = word2;
                }
                Console.WriteLine(res);
            }
        }
    }
}
