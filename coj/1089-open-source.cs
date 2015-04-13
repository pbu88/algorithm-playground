using System;
using System.Collections.Generic;


namespace Prob1089
{
    public class TrieComparer : IComparer<Trie>
    {
        public int Compare(Trie x, Trie y)
        {
            if(x.count == y.count)
                return x.name.CompareTo(y.name);
            return y.count - x.count;
        }
    }
    public class Node
    {
        public Trie owner;
        public bool erased = false;
        public char value;
        public List<Node> sons;

        public Node(char value, Trie owner)
        {
            this.value = value;
            this.owner = owner;
            sons = new List<Node>();
        }
    }
    public class Trie
    {
        public string name;
        public Node root;
        public int count;

        public Trie(string name)
        {
            this.name = name;
            root = new Node('^', this);
        }

        private Node get_node(Node r, string s, ref int index)
        {
            foreach (Node n in r.sons)
                if (n.value == s[index])
                {
                    index++;
                    return get_node(n, s, ref index);
                }
            return r;
        }

        public void Add(string s, Trie owner)
        {
            s += "$";
            int index = 0;
            Node n = get_node(root, s, ref index);
            for (int i = index; i < s.Length; i++)
            {
                Node n1 = new Node(s[i], owner);
                n.sons.Add(n1);
                n = n1;                
            }
            count++;
        }

        public Node Contains(string s)
        {
            s += "$";
            int index = 0;
            Node n = get_node(root, s, ref index);
            return n.value == '$' ? n : null;
        }

        public void DecreaseCount()
        {
            if (count == 0) return;
            count--;
        }
    }

    public class Program
    {
        static void Main(string[] args)
        {
            while (true)
            {
                string s = Console.ReadLine();
                if (s == "0")
                    break;
                solve_case(s);
            }
        }

        static void solve_case(string s)
        {
            Trie inscripted = new Trie("inscripted");
            List<Trie> trees = new List<Trie>();
            while (true)
            {
                if (s[0] == '1')
                    break;
                else if (char.IsUpper(s[0]))
                {
                    trees.Add(new Trie(s));                   
                }
                else
                {
                    Node ins = inscripted.Contains(s);
                    if (ins != null)
                    {
                        if (ins.owner != trees[trees.Count - 1] && !ins.erased)
                        {
                            ins.erased = true;
                            ins.owner.DecreaseCount();
                        }
                    }
                    else
                    {
                        inscripted.Add(s, trees[trees.Count - 1]);
                        trees[trees.Count - 1].Add(s, trees[trees.Count - 1]);
                    }
                }
                s = Console.ReadLine();
            }
            trees.Sort(new TrieComparer());
            for (int i = 0; i < trees.Count; i++)
            {
                Console.WriteLine("{0} {1}",trees[i].name, trees[i].count);
            }
        }
    }
}
