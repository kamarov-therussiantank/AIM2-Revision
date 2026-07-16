using System;
using System.IO;
using System.Collections.Generic;
//using System.Linq;
using System.Text;

namespace mod_convert
{
    enum Method { fast, slow };

    class options
    {
        public Method method;
        public uint precise;
        public string output;
        public bool DelAfterConvert;

        public options(string s)
        {
            StreamReader optfile;

            method = Method.slow;
            precise = 6;
            output = null;
            DelAfterConvert = false;

            int i = 0;
            string temp;
            bool not_success = false;

            try
            {
                optfile = File.OpenText(s);//Открываем файл
            }
            catch (System.Exception)
            {
                Console.WriteLine("Не можно открыть файл опций по неизвестным науке причинам.");
                Console.WriteLine("Работа будет выполнена с опциями по умолчанию:");
                Console.WriteLine("Точность - 6 знаков после запятой.");
                Console.WriteLine("Выходные файлы будут созданы там же, где были и входные.");
                Console.WriteLine("Метод конвертации - медленный.");
                Console.WriteLine("Исходные файлы НЕ будут удалены.");
                Console.WriteLine("Нажмите 'Enter' для продолжения, или CTRL+C для отмены.");
                Console.ReadLine();
                return;
            }
            //Читаем строчечки из файла
            while ((s = optfile.ReadLine()) != null)
            {
                ++i;
                if (s[0] == '#')
                {
                    continue;
                }
                if (s.StartsWith("precision="))
                {
                    temp = s.Substring(10);
                    try
                    {
                        precise = (uint)Convert.ToInt32(temp);
                    }
                    catch (System.Exception)
                    {
                        not_success = true;           
                        if (Program.debug) 
                            Console.WriteLine("Ошибка в строке № " + i + ", точность не распознана.");
                    }
                    continue;
                }
                if (s.StartsWith("delete="))
                {
                    temp = s.Substring(7);
                    if (temp == "y")
                    {
                        DelAfterConvert = true;
                        continue;
                    }
                    if (temp == "n")
                    {
                        DelAfterConvert = false;
                        continue;
                    }
                    not_success = true;
                    if (Program.debug)
                        Console.WriteLine("Ошибка в строке № " + i + ", опция удаления исходного файла не распознана.");
                    continue;
                }
                if (s.StartsWith("method="))
                {
                    temp = s.Substring(7);
                    if (temp == "slow")
                    {
                        method = Method.slow;
                        continue;
                    }
                    if (temp == "fast")
                    {
                        method = Method.fast;
                        continue;
                    }
                    not_success = true;
                    if (Program.debug)
                        Console.WriteLine("Ошибка в строке № " + i + ", метод не распознан.");
                    continue;
                }
                if (s.StartsWith("output="))
                {
                    output = s.Substring(7);
                    continue;
                }
                not_success = true;
                if (Program.debug)
                    Console.WriteLine("Ошибка в строке № " + i + ", вероятно, ошибка в написании ключевого слова.");
            }
            if (!Program.debug && not_success)
            {
                Console.WriteLine("В файле опций содержатся ошибки. Нажмите 'Enter' для продолжения, или CTRL+C для отмены.");
                Console.ReadLine();
            }
            if (Program.debug)
            {
                if (!not_success)
                    Console.WriteLine("Файл опций ошибок не содержит.");
                Console.WriteLine("Будут использованы следующие опции:");
                Console.WriteLine("precision={0}", precise);
                Console.WriteLine("delete={0}", DelAfterConvert);
                Console.WriteLine(output == null ? "Вывод в папку исходного файла" : "Output='" + output + "'");
                Console.WriteLine("method={0}", method);
                Console.ReadLine();
            }
            optfile.Close();
        }
    }
    /*class options  //Для тестирования
    {
        public Method method;
        public uint precise;
        public string output;
        public bool DelAfterConvert;

        public options(string s)
        {
            method = Method.slow;
            precise = 6;
            output = null;
            DelAfterConvert = false;

            Console.WriteLine("Конструктор опций");
            Console.WriteLine("Аргументы :: {0}", s);
            Console.ReadLine();
        }
    }*/
}
