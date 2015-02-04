using System;
using System.Collections;
using System.Collections.Generic;

namespace acm.blackout
{
    public class EdgeComparer : IComparer
    {
        public int Compare(object x, object y)
        {
            Edge e1 = (Edge)x;
            Edge e2 = (Edge)y;
            if (e1.w < e2.w)
                return -1;
            else if (e1.w > e2.w)
                return 1;
            else return 0;
        }
    }

    struct Edge
    {
        public int x, y, w;
    }

    public class TreeNode
    {
        public int value;
        public int rank;
        public TreeNode p;
    }

    class Program
    {
        static void Main(string[] args)
        {
            int t = int.Parse(Console.ReadLine());
            for (int k = 0; k < t; k++)
            {
                string[] g = Console.ReadLine().Split(' ');
                TreeNode[] nodes = new TreeNode[int.Parse(g[0])];
                Edge[] edges = new Edge[int.Parse(g[1])];
                int[,] graph = new int[nodes.Length, nodes.Length];
                for (int i = 0; i < edges.Length; i++)
                {                    
                    string[] edge = Console.ReadLine().Split(' ');
                    edges[i] = new Edge();
                    edges[i].x = int.Parse(edge[0]) - 1;
                    edges[i].y = int.Parse(edge[1]) - 1;
                    edges[i].w = int.Parse(edge[2]);
                    graph[edges[i].x, edges[i].y] = graph[edges[i].y, edges[i].x] = edges[i].w;
                    if (nodes[edges[i].x] == null)
                    {
                        nodes[edges[i].x] = new TreeNode();
                        nodes[edges[i].x].value = edges[i].x;
                        nodes[edges[i].x].rank = 0;
                        nodes[edges[i].x].p = nodes[edges[i].x];
                    }
                    if (nodes[edges[i].y] == null)
                    {
                        nodes[edges[i].y] = new TreeNode();
                        nodes[edges[i].y].value = edges[i].y;
                        nodes[edges[i].y].rank = 0;
                        nodes[edges[i].y].p = nodes[edges[i].y];
                    }
                }
                List<Edge> tree = new List<Edge>();
                int ans1 = kruskal(nodes, edges, tree);
                int ans2 = second_mst(graph, tree, ans1);
                if(edges.Length != nodes.Length - 1)
                    Console.WriteLine("{0} {1}", ans1, ans2);
                else
                    Console.WriteLine(ans1);
            }

        }

        private static int second_mst(int[,] graph, List<Edge> tree, int weight)
        {
            int n = graph.GetLength(0);
            int[,] paths = new int[n,n];
            int res = int.MaxValue;
            for (int i = 0; i < n; i++)
            {
                int aux = dfs(i, i, tree, paths, int.MinValue, new bool[n], graph, 1);
                res = res > aux ? aux : res;
            }
            return weight + res;
        }

        static int dfs(int root, int current, List<Edge> tree, int[,] paths, int max, bool[] visited, int[,] graph, int depth)
        {
            visited[current] = true;
            int res = int.MaxValue;
            for (int i = 0; i < tree.Count; i++)
            {
                if (current == tree[i].x || current == tree[i].y)
                {
                    int adj = tree[i].x + tree[i].y - current;
                    if (visited[adj] != false)
                        continue;
                    max = max < tree[i].w ? tree[i].w : max;
                    paths[root, adj] = paths[adj, root] = max;
                    if (depth > 1 && graph[root, adj] != 0)
                        res = res > graph[root, adj] - max ? graph[root, adj] - max : res;
                    int aux = dfs(root, adj, tree, paths, max, visited, graph, depth + 1);
                    res = res > aux ? aux : res;
                }
            }
            return res;
        }

        static int kruskal(TreeNode[] nodes, Edge[] edges, List<Edge> tree)
        {
            int res = 0;
            Array.Sort(edges, new EdgeComparer());
            for (int i = 0; i < edges.Length; i++)
            {
                if (find_set(nodes, edges[i].x) != find_set(nodes, edges[i].y))
                {
                    res += edges[i].w;
                    tree.Add(edges[i]);
                    union(nodes, edges[i].x, edges[i].y);
                    if (tree.Count == nodes.Length - 1)
                        break;
                }
            }
            return res;
        }

        static void union(TreeNode[] nodes, int x, int y)
        {
            link(find_set(nodes, x), find_set(nodes, y));
        }

        private static void link(TreeNode x, TreeNode y)
        {
            if (x.rank > y.rank)
                y.p = x;
            else
            {
                x.p = y;
                if (x.rank == y.rank)
                    y.rank++;
            }
        }

        static TreeNode find_set(TreeNode[] nodes, int x)
        {
            if (nodes[x].p != nodes[x])
                nodes[x].p = find_set(nodes, nodes[x].p.value);
            return nodes[x].p;
        }        
    }
}
