using System;
using System.Collections.Generic;

namespace Prob1026
{

    public class NodeComparer : IComparer<Node>
    {
        public int Compare(Node x, Node y)
        {
            return x.height - y.height;
        }
    }

    public class Node
    {
        public int height;
        public int r;
        public int c;

        public Node(int height, int r, int c)
        {
            this.height = height;
            this.r = r;
            this.c = c;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            int t = int.Parse(Console.ReadLine());
            for (int i = 0; i < t; i++)
            {
                string[] sa = Console.ReadLine().Split(' ');
                string name = sa[0];
                int r = int.Parse(sa[1]);
                int c = int.Parse(sa[2]);
                List<Node> hs = new List<Node>();
                int[,] field = new int[r, c];
                for (int j = 0; j < r; j++)
                {
                    string[] cs = Console.ReadLine().Split(' ');
                    for (int k = 0; k < c; k++)
                    {
                        field[j, k] = int.Parse(cs[k]);
                        hs.Add(new Node(field[j, k], j, k));
                    }
                }
                int res = solve(field, hs, r, c);
                Console.WriteLine("{0}: {1}",name, res);
            }
        }

        static int solve(int[,] field, List<Node> hs, int r, int c)
        {
            int res = 0;
            int[,] d = new int[r, c];
            hs.Sort(new NodeComparer());
            int h = hs[0].height;
            int cursor = 0;
            for (int i = 0; i < hs.Count; i++)
            {
                if (h != hs[i].height)
                {
                    cursor = i;
                    break;
                }
                else
                {
                    d[hs[i].r, hs[i].c] = 1;
                }
            }
            for (int i = cursor; i < hs.Count; i++)
            {
                int aux = 1;
                int h1 = hs[i].height;
                int r1 = hs[i].r;
                int c1 = hs[i].c;
                if (c1 - 1 >= 0 && field[r1, c1 - 1] < h1)
                {
                    aux = 1 + d[r1, c1 - 1];
                }
                if (r1 - 1 >= 0 && field[r1 - 1, c1] < h1)
                {
                    aux = aux > d[r1 - 1, c1] + 1 ? aux : d[r1 - 1, c1] + 1;
                }
                if (c1 + 1 < c && field[r1, c1 + 1] < h1)
                {
                    aux = aux > d[r1, c1 + 1] + 1 ? aux : d[r1, c1 + 1] + 1;
                }
                if (r1 + 1 < r && field[r1 + 1, c1] < h1)
                {
                    aux = aux > d[r1 + 1, c1] + 1 ? aux : d[r1 + 1, c1] + 1;
                }
                res = res < aux ? aux : res;
                d[r1, c1] = aux;
            }
            return res;
        }
    }
}
