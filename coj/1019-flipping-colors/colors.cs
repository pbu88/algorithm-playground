using System;


namespace Prob1019
{
    class Program
    {
        static void Main(string[] args)
        {
            char[] sep = { ' ' };
            int cases = 1;
            while (true)
            {
                string s = Console.ReadLine();
                if (s == "0 0 0 0".Trim())
                    break;
                Console.WriteLine("Case {0}:",cases++);
                string[] sa = s.Split(sep, StringSplitOptions.RemoveEmptyEntries);
                decimal w = decimal.Parse(sa[0]);
                decimal h = decimal.Parse(sa[1]);
                decimal vprop = decimal.Parse(sa[2]);
                decimal hprop = decimal.Parse(sa[3]);
                int ps = int.Parse(Console.ReadLine().Trim());
                for (int i = 0; i < ps; i++)
                {
                    string[] points = Console.ReadLine().Split(sep, StringSplitOptions.RemoveEmptyEntries);
                    decimal px = decimal.Parse(points[0]);
                    decimal py = decimal.Parse(points[1]);
                    bool res = solve(w, h, vprop, hprop, px, py, false);
                    Console.WriteLine(res ? "white" : "black");
                }
            }
            
        }

        static bool solve(decimal w, decimal h, decimal hprop, decimal vprop, decimal pointx, decimal pointy, bool color)
        {
            decimal wm = w * hprop;
            decimal hm = h * vprop;
            if ((pointx < wm && pointy > hm) || (pointx > wm && pointy < hm))
                return color;
            if (pointx < wm && pointy < hm)
            {
                return solve(wm, hm, hprop, vprop, pointx, pointy, !color);
            }
            else if (pointx > wm && pointy > hm)
            {
                return solve(w - wm, h - hm, hprop, vprop, pointx - wm, pointy - hm, !color);
            }
            return false;
        }
    }
}
