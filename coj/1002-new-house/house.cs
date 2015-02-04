using System;
using System.Collections;

namespace house
{
	class Program
	{
		static void Main(string[] args)
		{
			ArrayList arr = new ArrayList();
			int t = int.Parse(Console.ReadLine());
			for (int i = 0; i < t; i++)
			{
				int n = int.Parse(Console.ReadLine());
				int[,] area = new int[n, n];
				for (int j = 0; j < n; j++)
				{
					string s = Console.ReadLine();
					for (int k = 0; k < n; k++)
					{
						area[j, k] = s[k] == '.' ? 1 : 0;
					}
				}
				arr.Add(square(n, area));
			}
			for (int i = 0; i < arr.Count; i++)
			{
				Console.WriteLine(arr[i]);
			}
		}

		static int square(int n, int[,] area)
		{
			int[,] a_aux = new int[n, n];
			for (int i = 0; i < n; i++)
			{
				a_aux[i, 0] = area[i, 0] == 1 ? 1 : 0;			 
			}
			
			for (int i = 0; i < n; i++)
			{
				for (int j = 1; j < n; j++)
				{
					a_aux[i, j] = area[i, j] == 1 ? a_aux[i, j - 1] + 1 : 0;
				}
			}
			int aux = 0;
			int res = 0;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (area[i, j] == 1)
					{
						aux = get_square(i, j, area, a_aux);
						if (aux > res) res = aux;
					}

				}
			}
            return res;
		}

		static int get_square(int i, int j, int[,] area, int[,] a_aux)
		{
            int res = 0;
            int lado = a_aux[i, j];
            for (int k = 0; k < lado && i - k >= 0; k++)
            {
                if (area[i - k, j] != 1)
                    break;
                if (i - k - 1 >= 0 && lado > a_aux[i - k - 1, j])
                    lado = a_aux[i - k - 1, j];
                res++;
            }
            return res;
		}
	}
}