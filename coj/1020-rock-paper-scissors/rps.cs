using System;

namespace Prob1020
{

    public struct Player
    {
        public double win;
        public double loose;
    }

    class Program
    {
        static void Main(string[] args)
        {
            while (true)
            {
                string s = Console.ReadLine();
                if (s == "0")
                    break;
                string[] sa = s.Split(' ');
                int n = int.Parse(sa[0]);
                int k = int.Parse(sa[1]);
                int length = k*n*(n-1)/2;
                Player[] players = new Player[n];
                for (int i = 0; i < length; i++)
                {
                    
                    string[] input = Console.ReadLine().Split(' ');
                    int p1 = int.Parse(input[0]) - 1;
                    int p2 = int.Parse(input[2]) - 1;
                    if (input[1] == "rock" && input[3] == "paper")
                    {
                        players[p2].win++;
                        players[p1].loose++;
                    }
                    if (input[1] == "rock" && input[3] == "scissors")
                        {
                        players[p2].loose++;
                        players[p1].win++;
                    }
                    if (input[1] == "paper" && input[3] == "rock")
                        {
                        players[p2].loose++;
                        players[p1].win++;
                    }
                    if (input[1] == "paper" && input[3] == "scissors")
                        {
                        players[p2].win++;
                        players[p1].loose++;
                    }
                    if (input[1] == "scissors" && input[3] == "rock")
                        {
                        players[p2].win++;
                        players[p1].loose++;
                    }
                    if (input[1] == "scissors" && input[3] == "paper")
                    {
                        players[p2].loose++;
                        players[p1].win++;
                    }
                }
                for (int i = 0; i < players.Length; i++)
                {
                    if (players[i].win == 0 && players[i].loose == 0)
                        Console.WriteLine("-");
                    else
                    {
                        double x = Math.Round(players[i].win / (players[i].win + players[i].loose), 3);
                        string res = x.ToString();
                        if (res.Length == 1)
                            res += ".000";
                        else if (res.Length == 3)
                            res += "00";
                        else if (res.Length == 4)
                            res += "0";
                        Console.WriteLine(res);
                    }
                }
                Console.WriteLine();
            }
        }
    }
}
