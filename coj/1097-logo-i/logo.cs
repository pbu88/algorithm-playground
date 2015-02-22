using System;

namespace Prob1097
{
    class Program
    {
        static void Main(string[] args)
        {
            char[] sep = { ' ' };
            int t = int.Parse(Console.ReadLine());
            for (int i = 0; i < t; i++)
            {
                int n = int.Parse(Console.ReadLine());
                double x = 0;
                double y = 0;
                double angle = 0;
                for (int j = 0; j < n; j++)
                {
                    string s = Console.ReadLine();
                    string command = s.Split(' ')[0];
                    int value = int.Parse(s.Split(' ')[1]);
                    if (command == "fd")
                    {
                        x += value * Math.Sin(angle * Math.PI / 180);
                        y += value * Math.Cos(angle * Math.PI / 180);
                    }
                    else if (command == "lt")
                    {
                        angle += value;

                    }
                    else if (command == "bk")
                    {
                        x -= value * Math.Sin(angle * Math.PI / 180);
                        y -= value * Math.Cos(angle * Math.PI / 180);
                    }
                    else if (command == "rt")
                    {
                        angle -= value;
                    }
                    else
                    {
                        throw new Exception();
                    }
                }
                Console.WriteLine((int)Math.Round(Math.Sqrt(x * x + y * y)));

            }
        }
    }
}
