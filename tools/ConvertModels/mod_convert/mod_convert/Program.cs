using System;
using System.Threading;
using System.Windows.Forms;
using System.IO;
using System.Collections.Generic;
//using System.Linq;
using System.Text;

namespace mod_convert
{
    class Program
    {
        static public bool debug = false;
        static public StreamWriter error_log;
        static public int done_count = 0;

        static void error_handler(System.Exception EX, string error_info)
        {
            Console.WriteLine(error_info);
            error_log.WriteLine(DateTime.Now.ToString());
            error_log.WriteLine();
            error_log.WriteLine(error_info);
            if (EX != null)
                error_log.WriteLine(EX.ToString());
            error_log.WriteLine("=====================================");
        }
        static void error_handler(string error_info)
        {
            error_handler(null, error_info);
        }

        static void Main(string[] args)
        {
            bool bugs = false;
            model M;
            options O;
            int i = args.GetLength(0) - 1;
            string outname;
            string[] mod_files = new string[args.GetLength(0)];
            string options_file = null;
            error_log = new StreamWriter(Application.StartupPath + "\\error.log", true, new UTF8Encoding() );

            for (; i >= 0; --i)
            {
                if (File.Exists(args[i]))
                {
                    if (args[i].EndsWith(".mod", StringComparison.OrdinalIgnoreCase))
                    {
                        mod_files[i] = args[i];
                        continue;
                    }
                    if (args[i].EndsWith(".ini", StringComparison.OrdinalIgnoreCase))
                    {
                        options_file = args[i];
                        continue;
                    }
                    error_handler("Файл " + args[i].Substring(args[i].LastIndexOf('\\') + 1) + " обработан не будет.");
                    bugs = true;
                }
                else
                {
                    error_handler("Файла " + args[i].Substring(args[i].LastIndexOf('\\') + 1) + " не существует.");
                    bugs = true;
                }
            }
            if (bugs)
                Thread.Sleep(5000);

            if ((args.GetLength(0) == 1) && (options_file != null))
            {
                debug = true;
            }

            if (options_file == null)
                O = new options(Application.StartupPath + "\\mod_convert.ini");
            else
                O = new options(options_file);

            bugs = false;
            for (i = args.GetLength(0) - 1; i >= 0; --i)
            {
                if (mod_files[i] != null)
                {
                    try
                    {
                        M = new model(mod_files[i]);
                    }
                    catch (System.Exception EX)
                    {
                        error_handler(EX, "Не удалось загрузить '" + mod_files[i].Substring(mod_files[i].LastIndexOf('\\') + 1) + "'; подробности в error.log");
                        bugs = true;
                        continue;
                    }
                    if (O.output == null)
                        outname = mod_files[i];
                    else
                    {
                        try
                        {
                            Directory.CreateDirectory(O.output);
                        }
                        catch (System.Exception EX)
                        {
                            error_handler(EX, "Не удалось создать выходную директорию, подробности в error.log");
                            bugs = true;
                        }
                        outname = O.output + '\\' + mod_files[i].Substring(mod_files[i].LastIndexOf('\\') + 1);
                    }
                    outname = outname.Substring(0, outname.LastIndexOf(".mod", StringComparison.OrdinalIgnoreCase)) + ".obj";
                    try
                    {
                        if (O.method == Method.fast)
                            M.WriteToObjFast(outname, O.precise);
                        else
                            M.WriteToObjSlow(outname, O.precise);
                    }
                    catch (System.Exception EX)
                    {
                        error_handler(EX, "Не удалось выполнить запись " + outname);
                        bugs = true;
                        continue;
                    }
                    if (O.DelAfterConvert)
                        File.Delete(mod_files[i]);
                }
            }
            if (bugs)
                Thread.Sleep(5000);
            error_log.Close();
        }
    }
}
