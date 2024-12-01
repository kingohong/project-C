using System;
using System.IO;
using System.Linq;

namespace StudentManagement
{
    public struct Password
    {
        public string Username { get; set; }
        public int PasswordValue { get; set; }
    }

    public struct Student
    {
        public string FullName { get; set; }
        public string Gender { get; set; }
        public int StudentId { get; set; }
        public DateTime BirthDate { get; set; }
        public string Subject1 { get; set; }
        public string Subject2 { get; set; }
        public string Subject3 { get; set; }
        public float Grade1 { get; set; }
        public float Grade2 { get; set; }
        public float Grade3 { get; set; }
        public float AverageGrade { get; set; }
        public string Hometown { get; set; }
    }

    public class Program
    {
        private static void WriteNewLineToFile(string filePath)
        {
            using (StreamWriter sw = new StreamWriter(filePath, true))
            {
                sw.WriteLine();
            }
        }

        private static void WritePasswordToFile(Password pw)
        {
            using (StreamWriter sw = new StreamWriter("PassWord.txt", true))
            {
                sw.WriteLine($"{pw.Username}-{pw.PasswordValue}");
            }
        }

        private static void WriteStudentCountToFile(int count)
        {
            using (StreamWriter sw = new StreamWriter("StudentCount.txt"))
            {
                sw.WriteLine(count);
            }
        }

        private static int ReadStudentCountFromFile()
        {
            using (StreamReader sr = new StreamReader("StudentCount.txt"))
            {
                return int.Parse(sr.ReadLine());
            }
        }

        private static bool ValidateAscii(string input)
        {
            return input.All(c => char.IsLetter(c) || c == ' ');
        }

        private static void PressEnterToContinue()
        {
            Console.WriteLine("\n\n* Press Enter to continue *");
            Console.ReadLine();
        }

        private static void RegisterPassword(ref Password pw, ref int count)
        {
            Console.WriteLine("      - REGISTER -");
            Console.Write("Enter username: ");
            pw.Username = Console.ReadLine();
            Console.Write("Enter password: ");
            pw.PasswordValue = int.Parse(Console.ReadLine());
        }
    }
}
