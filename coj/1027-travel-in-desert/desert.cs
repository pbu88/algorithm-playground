using System;
using System.Collections.Generic;

namespace Prob1027
{
    class Program
    {

        static double[,] data = new double[2, 101];
        static Edge[] edges = new Edge[10001];
        static char[] sep = { ' ' };
        static string s;
        static string[] inp;
        static int n, m, o, d;

        class Edge
        {
            public int x, y;
            public double temp, dist;

            public Edge(int x, int y, double temp, double dist)
            {
                this.x = x;
                this.y = y;
                this.temp = temp;
                this.dist = dist;
            }
        }

        static void Main(string[] args)
        {
            
            while (true)
            {
                s = Console.ReadLine();
                if (s == null)
                    break;
                inp = s.Split(sep, StringSplitOptions.RemoveEmptyEntries);
                n = int.Parse(inp[0]);
                m = int.Parse(inp[1]);
                inp = Console.ReadLine().Split(sep, StringSplitOptions.RemoveEmptyEntries);
                o = int.Parse(inp[0]) - 1;
                d = int.Parse(inp[1]) - 1;
                for (int i = 0; i < m; i++)
                {
                    inp = Console.ReadLine().Split(sep, StringSplitOptions.RemoveEmptyEntries);
                    edges[i] = new Edge(int.Parse(inp[0]) - 1, int.Parse(inp[1]) - 1, double.Parse(inp[2]), double.Parse(inp[3]));
                }
                bellman_ford(o, n, m, -1);
                double temp = data[0, d];
                bellman_ford(o, n, m, temp);
                LinkedList<int> path = Path(o, d);
                LinkedListNode<int> aux = path.First;
                while (aux != path.Last)
                {
                    Console.Write(aux.Value + 1 + " ");
                    aux = aux.Next;
                }
                Console.WriteLine(aux.Value + 1);
                Console.WriteLine("{0} {1}", data[0, d].ToString(".0"), temp.ToString(".0"));
            }
        }

        static LinkedList<int> Path(int s, int d)
        {
            LinkedList<int> res = new LinkedList<int>();
            while (d != s)
            {
                res.AddFirst(d);
                d = (int)data[1, d];
            }
            res.AddFirst(s);
            return res;
        }

        private static void bellman_ford(int o, int n, int m, double temps)
        {
            init(o);
            for (int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    if (temps < 0)
                    {
                        relax_temp(edges[j].x, edges[j].y, edges[j].temp);
                        relax_temp(edges[j].y, edges[j].x, edges[j].temp);
                    }
                    else
                    {
                        if (edges[j].temp <= temps)
                        {
                            relax_dist(edges[j].x, edges[j].y, edges[j].dist);
                            relax_dist(edges[j].y, edges[j].x, edges[j].dist);
                        }
                    }
                }
            }
        }

        static void relax_dist(int u, int v, double w)
        {
            if (data[0, u] + w < data[0, v])
            {
                data[0, v] = data[0, u] + w;
                data[1, v] = u;
            }
        }

        static void relax_temp(int u, int v, double w)
        {
            if (Math.Max(w, data[0, u]) < data[0, v])
            {
                data[0, v] = Math.Max(w, data[0, u]);
                data[1, v] = u;
            }
        }

        static void init(int source)
        {
            for (int i = 0; i < n; i++)
            {
                data[0, i] = long.MaxValue;
            }
            data[0, source] = 0;
        }
    }
}
