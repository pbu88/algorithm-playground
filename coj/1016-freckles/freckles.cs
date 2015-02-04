using System;
using System.Collections;

namespace freckles
{

    public struct Point{
        public double x;
        public double y;
    }

    class Program
    {
        static void Main(string[] args)
        {
            int t = int.Parse(Console.ReadLine());
            Point[] v = new Point[t];
            for (int i = 0; i < t; i++)
            {
                string[] s = Console.ReadLine().Split(' ');
                double x = double.Parse(s[0]);
                double y = double.Parse(s[1]);
                v[i].x = x;
                v[i].y = y;
            }
            Console.WriteLine(prim(v));
        }

        static double prim(Point[] v)
        {
            double res = 0;
            int v_in_tree = 1;
            bool[] tree = new bool[v.Length];
            tree[0] = true;
            double[,] edges = new double[v.Length, v.Length];
            while (v_in_tree != v.Length)
            {
                double safe_edge = double.MaxValue;
                int safe_vertex = -1;
                for (int i = 0; i < v.Length; i++)
                {                    
                    if (tree[i])
                    {
                        for (int j = 0; j < v.Length; j++)
                        {
                            if (!tree[j])
                            {
                                if (edges[i, j] == 0)
                                {
                                    edges[i, j] = Math.Sqrt(Math.Pow(v[i].x - v[j].x, 2) + Math.Pow(v[i].y - v[j].y, 2));
                                    edges[j, i] = edges[i, j];
                                }
                                if (safe_edge > edges[i, j])
                                {
                                    safe_edge = edges[i, j];
                                    safe_vertex = j;
                                }
                            }
                        }                        
                    }
                }
                v_in_tree++;
                tree[safe_vertex] = true;
                res += safe_edge;
            }
            return Math.Round(res, 2);
        }
    }
}
