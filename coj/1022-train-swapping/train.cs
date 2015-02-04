using System;
using System.Collections.Generic;


namespace Prob1022
{
    class Program
    {
        static void Main(string[] args)
        {
            int t = int.Parse(Console.ReadLine());
            for (int i = 0; i < t; i++)
            {
                int l = int.Parse(Console.ReadLine());
                if (l == 0){
                    Console.WriteLine("Optimal train swapping takes 0 swaps.");
                    continue;
                }
                string s = Console.ReadLine();
                string[] sa = s.Split(' ');
                

                List<int> input = new List<int>();
                for (int j = 0; j < l; j++)
                {
                    if (sa[j] != "")
                    {
                        int num = int.Parse(sa[j]);
                        input.Add(num);
                    }
                }
                Console.WriteLine("Optimal train swapping takes {0} swaps.", mergeSort(input.ToArray()));
            }
        }

        static int mergeSort(int[] a)
        {
            return mergeSortP(a, 0, a.Length - 1);
        }

        private static int mergeSortP(int[] a, int p, int q)
        {
            if (p == q)
                return 0;
            int r = (p + q) / 2;
            int inversionsL = mergeSortP(a, p, r);
            int inversionsR = mergeSortP(a, r + 1, q);
            int inversionsC = combine(a, p, r, q);

            return inversionsC + inversionsL + inversionsR;
        }

        private static int combine(int[] a, int p, int r, int q)
        {
            int inversions = 0;
            int sizeL = r - p + 1;
            int sizeR = q - r;
            int[] L = new int[sizeL];
            int[] R = new int[sizeR];
            for (int i = 0; i < sizeL; i++)
            {
                L[i] = a[p + i];
            }
            for (int i = 0; i < sizeR; i++)
            {
                R[i] = a[r + 1 + i];
            }
            int contL = 0;
            int contR = 0;
            for (int i = 0; i < sizeL + sizeR; i++)
            {
                if (contL == sizeL)
                {
                    a[p + i] = R[contR];
                    contR++;
                }
                else if (contR == sizeR)
                {
                    a[p + i] = L[contL];
                    contL++;
                }
                else
                {
                    if (L[contL] > R[contR])
                    {
                        a[p + i] = R[contR++];
                        inversions += L.Length - contL;
                    }
                    else a[p + i] = L[contL++];
                }
            }
            return inversions;
        }
    }
}
