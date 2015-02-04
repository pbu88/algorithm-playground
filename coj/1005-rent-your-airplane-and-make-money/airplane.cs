using System;
using System.Collections.Generic;
using System.Collections;

namespace airplane
{

    public class Order : IComparable
    {
        public int Start;
        public int Duration;
        public int Profit;

        public int CompareTo(object order)
        {
            return Start - ((Order)order).Start;
        }
    }

    public class OrderComparer : IComparer<Order>
    {
        public int Compare(Order x, Order y)
        {
            return x.Start - y.Start;
        }
    }

    class Program
    { 

        static void Main(string[] args)
        {
            int t = int.Parse(Console.ReadLine());
            for (int i = 0; i < t; i++)
            {
                int n = int.Parse(Console.ReadLine());
                List<Order> orders = new List<Order>();                
                for (int j = 0; j < n; j++)
                {
                    Order order = new Order();
                    string[] s = Console.ReadLine().Split(' ');
                    order.Start = int.Parse(s[0]);
                    order.Duration = int.Parse(s[1]);
                    order.Profit = int.Parse(s[2]);
                    orders.Add(order);
                }
                Console.WriteLine(airplane(orders));
            }
        }

        static string airplane(List<Order> orders)
        {
            orders.Sort();
            int[] solution = new int[orders.Count + 1];
            solution[solution.Length - 1] = 0;
            for (int i = orders.Count - 1; i >= 0; i--)
            {
                Order aux = new Order();
                aux.Start = orders[i].Start + orders[i].Duration;
                int index = orders.BinarySearch(i + 1, orders.Count - i - 1, aux, new OrderComparer());
                if (index < 0) index = 0 - index - 1;
                solution[i] = Math.Max(solution[i + 1], orders[i].Profit + solution[index]);                
            }
            return solution[0].ToString();
        }
    }
}
