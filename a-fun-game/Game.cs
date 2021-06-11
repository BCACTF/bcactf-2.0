using System;

namespace AFunGame
{
    class Game
    {
        static int points = 0;
        static int pointsNeeded = 1000;

        static void Main(string[] args)
        {
            string chars = "abcdefghijklmnopqrstuvwxyz";
            char letter;
            int num;
            Random rand = new Random();

            Console.WriteLine("Hello!\nWrite the correct letter 1,000 times to get the flag!\nNot that hard, right?\nType '0' to stop.");
            while (points < pointsNeeded)
            {
                num = rand.Next(0, chars.Length - 1);
                letter = chars[num];
                Console.WriteLine(String.Format("Type the letter '{0}': ", letter));
                try
                {
                    char inpt = Console.ReadLine()[0];
                    if (inpt == letter)
                    {
                        points++;
                        Console.WriteLine("Correct! Current points: " + points);
                    }
                    else if (inpt == '0')
                    {
                        goto End;
                    }
                    else
                    {
                        Console.WriteLine("Incorrect. Current Points: " + points);
                    }
                }
                catch
                {
                    Console.WriteLine("Incorrect input.");
                }

            }
            End:
            if (points >= pointsNeeded)
            {
                char[] array = "}sr3tte1_0001_epYt_yl1aUtca_tNd1d_U0y_yl1uf3p0h{ftcacb".ToCharArray();
                Array.Reverse(array);
                Console.WriteLine("Here's your flag: " + new String(array));
            }
            else
            {
                Console.WriteLine("Well, better luck next time!");
            }
            Console.ReadLine();
        }
    }
}
