using System;
using System.Collections.Generic;

namespace FerryLoadingIII
{
    class Program
    {
        static void Main(string[] args)
        {
            int cases = int.Parse(Console.ReadLine());
            for (int z = 0; z < cases; z++)
            {
                string s = Console.ReadLine();
                string[] ss = s.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                int n = int.Parse(ss[0]);
                int t = int.Parse(ss[1]);
                int m = int.Parse(ss[2]);
                List<Arrive> alls = new List<Arrive>();
                List<Arrive> lefts = new List<Arrive>();
                List<Arrive> rights = new List<Arrive>();
                for (int i = 0; i < m; i++)
                {
                    s = Console.ReadLine();
                    ss = s.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                    int num = int.Parse(ss[0]);
                    Arrive arrive = new Arrive();
                    arrive.time = num;
                    arrive.side = ss[1] == "left";
                    alls.Add(arrive);
                    if (arrive.side)
                    {
                        lefts.Add(arrive);                        
                    }
                    else
                    {
                        rights.Add(arrive);
                    }
                }
                lefts.Sort();
                rights.Sort();
                int time = 0;
                bool leftBank = true;
                Queue<Arrive> _lefts = new Queue<Arrive>();
                Queue<Arrive> _rights = new Queue<Arrive>();
                Dictionary<Arrive, int> dict = new Dictionary<Arrive, int>();
                int idxLeft = 0;
                int idxRight = 0;
                int count = m;
                while (count != 0)
                {
                    while (idxLeft < lefts.Count && time >= lefts[idxLeft].time) _lefts.Enqueue(lefts[idxLeft++]);
                    while (idxRight < rights.Count && time >= rights[idxRight].time) _rights.Enqueue(rights[idxRight++]);
                    bool aux = false;
                    if (leftBank)
                    {
                        if (_lefts.Count > 0)
                        {
                            int length = Math.Min(_lefts.Count, n);
                            for (int i = 0; i < length; i++)
                            {
                                count--;
                                Arrive arrive = _lefts.Dequeue();
                                dict.Add(arrive, time + t);
                            }
                            aux = true;
                            leftBank = false;
                        }
                        else if (_rights.Count > 0)
                        {
                            leftBank = false;
                            aux = true;
                        }
                    }
                    else
                    {
                        if (_rights.Count > 0)
                        {
                            int length = Math.Min(_rights.Count, n);
                            for (int i = 0; i < length; i++)
                            {
                                count--;
                                Arrive arrive = _rights.Dequeue();
                                dict.Add(arrive, time + t);
                            }
                            aux = true;
                            leftBank = true;
                        }
                        else if (_lefts.Count > 0)
                        {
                            leftBank = true;
                            aux = true;
                        }
                    }

                    if (aux)
                    {
                        time += t;
                    }
                    else
                    {
                        int min = int.MaxValue;
                        if (idxLeft < lefts.Count)
                        {
                            min = Math.Min(min, lefts[idxLeft].time);
                        }
                        if (idxRight < rights.Count)
                        {
                            min = Math.Min(min, rights[idxRight].time);
                        }
                        time = min;
                    }
                }
                foreach (Arrive item in alls)
                {
                    Console.WriteLine(dict[item]);
                }
                Console.WriteLine();
            }
        }
    }

    class Arrive : IComparable<Arrive>
    {
        public int time;
        public bool side;

        #region IComparable<Arrive> Members

        public int CompareTo(Arrive other)
        {
            return time - other.time;
        }

        #endregion
    }
}