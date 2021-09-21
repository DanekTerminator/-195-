using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Исключения
{
    class Program
    {
        static void Main(string[] args)
        {
            double a, b;
            try
            {
                Console.WriteLine("Введите первое число: ");
                a = Convert.ToDouble(Console.ReadLine());

                Console.WriteLine("Введите второе число: ");
                b = Convert.ToDouble(Console.ReadLine());

                if (b == 0)
                    Console.WriteLine("Вы не можете делить на ноль!!! ");
                else
                    Console.WriteLine("Результат:" + " " + a / b);

            }
            catch
            {
                Console.WriteLine("Ошибка");
            }
            
           
        }
    }

}

