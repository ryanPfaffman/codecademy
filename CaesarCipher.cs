using System;

//project from codecademy. I like the time-wasting FixCases method :)

namespace CaesarCipher
{
  class Program
  {
    static char[] ShiftBack(char[] charArr)
    {
      char[] alphabet = new char[] {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

      char[] rtnArr = new char[charArr.Length];
      for (int x = 0; x < charArr.Length; x++)
      {
        int indexOf = Array.IndexOf(alphabet, charArr[x]);
        if (indexOf == -1)
        {
          rtnArr[x] = charArr[x];
        } else 
        {
          rtnArr[x] = alphabet[(indexOf - 3) % alphabet.Length];
        }
      }

      return rtnArr;
    }

    static char[] ShiftForward(char[] charArr)
    {
      char[] rtnArr = new char[charArr.Length];

      char[] alphabet = new char[] {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
      
      int i = 0;

      foreach (char l in charArr)
      {
        int indexL = Array.IndexOf(alphabet, l);
        if (indexL == -1)
        {
          rtnArr[i] = charArr[i];
        } else 
        {
          rtnArr[i] = alphabet[(indexL + 3) % alphabet.Length];
        }
        i++;
      }
      return rtnArr;
    }

    static int UpperOrLower(char l)
    {
      string alphabet = "abcdefghijklmnopqrstuvwxyz";
      string alphabetUpper = "ABCEDFGHIJKLMNOPQRSTUVWXYZ";

      if (alphabet.Contains(l.ToString()))
      {
        return 1;
      } else if (alphabetUpper.Contains(l.ToString()))
      {
        return 2;
      } else {
        return 3;
      }
    }

    static string FixCases(char[] arr, int[] lowerOrUpper)
    {
      for (int x = 0; x < arr.Length; x++)
      {
        if (lowerOrUpper[x] == 1)
        {
          //do nothing
        } else if (lowerOrUpper[x] == 2)
        {
          arr[x] = Convert.ToChar(arr[x].ToString().ToUpper());
        } else
        {
          //do nothing
        }
      }

      return String.Join("", arr);
    }
    static void Main(string[] args)
    {
      
      Console.WriteLine("Enter message to encrypt");
      string msg = Console.ReadLine();
      int[] lowerOrUpper = new int[msg.Length];
      int k = 0;
      foreach (char l in msg)
      {
        lowerOrUpper[k] = UpperOrLower(l);
        k++;
      }

      msg = msg.ToLower();

      Console.WriteLine(String.Join("",lowerOrUpper));

      char[] firstChange = ShiftForward(msg.ToCharArray());

      Console.WriteLine($"FixCasesTest: {FixCases(firstChange, lowerOrUpper)}");
      

      string firstChangeS = String.Join("", firstChange);

      Console.WriteLine($"First Change: {firstChangeS}");

      string changeBack = FixCases(ShiftBack(firstChangeS.ToLower().ToCharArray()), lowerOrUpper);

      Console.WriteLine($"Seconds Change: {changeBack}");
    }
  }
}
