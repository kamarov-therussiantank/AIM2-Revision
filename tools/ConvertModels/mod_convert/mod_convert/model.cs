using System;
using System.Globalization;
using System.IO;
using System.Collections.Generic;
//using System.Linq; //Зачем это оно?
using System.Text;

namespace mod_convert
{
    class model
    { 
        struct meh_node
        {
            public float vX; //-
            public float vZ; //-
            public float vY; //+

            public float nX; //-
            public float nZ; //-
            public float nY; //+

            public float t1; //+
            public float t2; //1-t2
        }
        struct meh_triangle
        {
            public ushort v1;
            public ushort v3;
            public ushort v2;
        }

        uint mehvertex_count;
        uint triangles_count;
        bool transform_wind;
        meh_node[] meh_nodeArray;
        meh_triangle[] meh_TriangleArray, obj_IndexArray;

        public model (string s)//Конструктор класса читает всю информацию о модели. Больше файл не понадобится.
        {
            uint i;

            FileStream modfile = File.OpenRead(s);
            BinaryReader r = new BinaryReader(modfile);

            try
            {
                //Читаем инфу об трансформации-ветре
                modfile.Seek(0x90, SeekOrigin.Begin);
                transform_wind = (0x12 == r.ReadInt32()) ? false : true;
                //Читаем количество меховских вершин
                modfile.Seek(0x94, SeekOrigin.Begin);
                mehvertex_count = r.ReadUInt32();
                //Читаем количество треугольников
                triangles_count = r.ReadUInt32() / 3;

                //Заполняем массив значенриями из файла
                meh_nodeArray = new meh_node[mehvertex_count];
                for (i = 0; i < mehvertex_count; ++i)
                {
                    meh_nodeArray[i].vX = r.ReadSingle();
                    meh_nodeArray[i].vZ = r.ReadSingle();
                    meh_nodeArray[i].vY = r.ReadSingle();
                    if (transform_wind)   r.ReadSingle();
                    meh_nodeArray[i].nX = r.ReadSingle();
                    meh_nodeArray[i].nZ = r.ReadSingle();
                    meh_nodeArray[i].nY = r.ReadSingle();
                    meh_nodeArray[i].t1 = r.ReadSingle();
                    meh_nodeArray[i].t2 = r.ReadSingle();
                }

                //Заполняем массив треугольников
                meh_TriangleArray = new meh_triangle[triangles_count];
                for (i = 0; i < triangles_count; ++i)
                {
                    meh_TriangleArray[i].v1 = r.ReadUInt16();
                    meh_TriangleArray[i].v3 = r.ReadUInt16();
                    meh_TriangleArray[i].v2 = r.ReadUInt16();
                }
            }
            catch
            {
                Console.WriteLine("Произошел сбой во время чтения '{0}'", s.Substring(s.LastIndexOf('\\') + 1));
                r.Close();
                throw (new System.Exception());
            }
            r.Close();
        }

        private StreamWriter WriteToObjPrepare(string s)
        {
            StreamWriter objfile = File.CreateText(s);//Открываем файл
            //Пишем шапку
            objfile.WriteLine("# Artificial Intelligence Machine(A.I.M.) *.mod exporter v1.0 by Razum");
            objfile.WriteLine("# File created: " + DateTime.Now.ToString());
            objfile.WriteLine();
            objfile.WriteLine('#');
            objfile.WriteLine("# Object {0}", s.Substring(s.LastIndexOf('\\') + 1, s.LastIndexOf('.') - s.LastIndexOf('\\') - 1));
            objfile.WriteLine('#');
            objfile.WriteLine();
            return objfile;
        }

        public void WriteToObjFast(string s, uint precision)
        {
            uint i;
            StreamWriter objfile = WriteToObjPrepare(s);
            string format = "f" + precision.ToString();

            //Пишем вершины модели
            for (i = 0; i < mehvertex_count; ++i)
            {
                objfile.WriteLine("v  {0} {1} {2}", (-(meh_nodeArray[i].vX)).ToString(format, CultureInfo.InvariantCulture), (meh_nodeArray[i].vY).ToString(format, CultureInfo.InvariantCulture), (-(meh_nodeArray[i].vZ)).ToString(format, CultureInfo.InvariantCulture));
            }
            objfile.WriteLine("# " + mehvertex_count + " vertices");
            objfile.WriteLine();
            //Пишем нормали модели
            for (i = 0; i < mehvertex_count; ++i)
            {
                objfile.WriteLine("vn {0} {1} {2}", (-(meh_nodeArray[i].nX)).ToString(format, CultureInfo.InvariantCulture), (meh_nodeArray[i].nY).ToString(format, CultureInfo.InvariantCulture), (-(meh_nodeArray[i].nZ)).ToString(format, CultureInfo.InvariantCulture));
            }
            objfile.WriteLine("# " + mehvertex_count + " vertex normals");
            objfile.WriteLine();
            //Пишем текстурные координаты
            for (i = 0; i < mehvertex_count; ++i)
            {
                objfile.WriteLine("vt {0} {1} {2}", (meh_nodeArray[i].t1).ToString(format, CultureInfo.InvariantCulture), (1-(meh_nodeArray[i].t2)).ToString(format, CultureInfo.InvariantCulture), ((float)0).ToString(format, CultureInfo.InvariantCulture));
            }
            objfile.WriteLine("# {0} texture coords", mehvertex_count);
            objfile.WriteLine();
            objfile.WriteLine("g {0}", s.Substring(s.LastIndexOf('\\') + 1, s.LastIndexOf('.') - s.LastIndexOf('\\') - 1));
            objfile.WriteLine("s off");
            //Пишем треугольники
            for (i = 0; i < triangles_count; ++i)
            {
                objfile.WriteLine("f " + (meh_TriangleArray[i].v1 + 1).ToString() + "/"
                                       + (meh_TriangleArray[i].v1 + 1).ToString() + "/"
                                       + (meh_TriangleArray[i].v1 + 1).ToString() + " "
                                       + (meh_TriangleArray[i].v2 + 1).ToString() + "/"
                                       + (meh_TriangleArray[i].v2 + 1).ToString() + "/"
                                       + (meh_TriangleArray[i].v2 + 1).ToString() + " "
                                       + (meh_TriangleArray[i].v3 + 1).ToString() + "/"
                                       + (meh_TriangleArray[i].v3 + 1).ToString() + "/"
                                       + (meh_TriangleArray[i].v3 + 1).ToString() + " ");
            }
            objfile.WriteLine("# {0} faces", triangles_count);
            objfile.WriteLine();
            //Все, завершаем писанину.
            objfile.Close();
            Console.WriteLine("{0} готов!", s);
            ++Program.done_count;
        }

        private void NodePrepare()
        {
            uint i, j;
            ushort vLastNode = 1;
            ushort nLastNode = 1;
            ushort tLastNode = 1;
            bool swV, swN, swT;

            obj_IndexArray = new meh_triangle[mehvertex_count];
            for (i = 0; i < mehvertex_count; ++i)
            {
                swV = true;
                swN = true;
                swT = true;

                for (j = 0; j < i; ++j)
                {
                    if ((meh_nodeArray[i].vX == meh_nodeArray[j].vX) && (meh_nodeArray[i].vY == meh_nodeArray[j].vY) && (meh_nodeArray[i].vZ == meh_nodeArray[j].vZ))
                    {
                        obj_IndexArray[i].v1 = obj_IndexArray[j].v1;
                        meh_nodeArray[i].vX = float.NaN;
                        swV = false;
                        break;
                    }
                }
                if (swV)
                    obj_IndexArray[i].v1 = vLastNode++;

                for (j = 0; j < i; ++j)
                {
                    if ((meh_nodeArray[i].nX == meh_nodeArray[j].nX) && (meh_nodeArray[i].nY == meh_nodeArray[j].nY) && (meh_nodeArray[i].nZ == meh_nodeArray[j].nZ))
                    {
                        obj_IndexArray[i].v2 = obj_IndexArray[j].v2;
                        meh_nodeArray[i].nX = float.NaN;
                        swN = false;
                        break;
                    }
                }
                if (swN)
                    obj_IndexArray[i].v2 = nLastNode++;

                for (j = 0; j < i; ++j)
                {
                    if ((meh_nodeArray[i].t1 == meh_nodeArray[j].t1) && (meh_nodeArray[i].t2 == meh_nodeArray[j].t2))
                    {
                        obj_IndexArray[i].v3 = obj_IndexArray[j].v3;
                        meh_nodeArray[i].t1 = float.NaN;
                        swT = false;
                        break;
                    }
                }
                if (swT)
                    obj_IndexArray[i].v3 = tLastNode++;
            }
        }

        public void WriteToObjSlow(string s, uint precision)
        {
            uint i, j;
            StreamWriter objfile = WriteToObjPrepare(s);
            string format = "f" + precision.ToString();

            NodePrepare();
            //Пишем вершины модели
            for (i = 0, j = 0; i < mehvertex_count; ++i)
            {
                if (!(meh_nodeArray[i].vX.Equals(float.NaN)))
                {
                    ++j;
                    objfile.WriteLine("v  {0} {1} {2}", (-(meh_nodeArray[i].vX)).ToString(format, CultureInfo.InvariantCulture), (meh_nodeArray[i].vY).ToString(format, CultureInfo.InvariantCulture), (-(meh_nodeArray[i].vZ)).ToString(format, CultureInfo.InvariantCulture));
                }
            }
            objfile.WriteLine("# {0} vertices", j);
            objfile.WriteLine();
            //Пишем нормали модели
            for (i = 0, j = 0; i < mehvertex_count; ++i)
            {
                if (!(meh_nodeArray[i].nX.Equals(float.NaN)))
                {
                    ++j;
                    objfile.WriteLine("vn {0} {1} {2}", (-(meh_nodeArray[i].nX)).ToString(format, CultureInfo.InvariantCulture), (meh_nodeArray[i].nY).ToString(format, CultureInfo.InvariantCulture), (-(meh_nodeArray[i].nZ)).ToString(format, CultureInfo.InvariantCulture));
                }
            }
            objfile.WriteLine("# {0} vertex normals", j);
            objfile.WriteLine();
            //Пишем текстурные координаты
            for (i = 0, j = 0; i < mehvertex_count; ++i)
            {
                if (!(meh_nodeArray[i].t1.Equals(float.NaN)))
                {
                    ++j;
                    objfile.WriteLine("vt {0} {1} {2}", (meh_nodeArray[i].t1).ToString(format, CultureInfo.InvariantCulture), (1-(meh_nodeArray[i].t2)).ToString(format, CultureInfo.InvariantCulture), ((float)0).ToString(format, CultureInfo.InvariantCulture));
                }
            }
            objfile.WriteLine("# {0} texture coords", j);
            objfile.WriteLine();
            objfile.WriteLine("g {0}", s.Substring(s.LastIndexOf('\\') + 1, s.LastIndexOf('.') - s.LastIndexOf('\\') - 1));
            objfile.WriteLine("s off");
            //Пишем треугольники
            for (i = 0; i < triangles_count; ++i)
            {         
                objfile.WriteLine("f {0}/{1}/{2} {3}/{4}/{5} {6}/{7}/{8} ",
                    obj_IndexArray[meh_TriangleArray[i].v1].v1,
                    obj_IndexArray[meh_TriangleArray[i].v1].v3,
                    obj_IndexArray[meh_TriangleArray[i].v1].v2,
                    obj_IndexArray[meh_TriangleArray[i].v2].v1,
                    obj_IndexArray[meh_TriangleArray[i].v2].v3,
                    obj_IndexArray[meh_TriangleArray[i].v2].v2,
                    obj_IndexArray[meh_TriangleArray[i].v3].v1,
                    obj_IndexArray[meh_TriangleArray[i].v3].v3,
                    obj_IndexArray[meh_TriangleArray[i].v3].v2
                    );
            }
            objfile.WriteLine("# {0} faces", triangles_count);
            objfile.WriteLine();
            //Все, завершаем писанину.
            objfile.Close();
            Console.WriteLine("{0} готов!", s);
            ++Program.done_count;
        }

    }

    //Класс для тестирования.
    /*class model
    {
        public model(string s)
        {
            Console.WriteLine("Выполнен конструктор для класса model.");
            Console.WriteLine("Аргумент :: '{0}'", s);
            Console.ReadLine();
        }
        public void WriteToObjSlow(string s, uint precision)
        {
            Console.WriteLine("Метод записи медленный");
            Console.WriteLine("Аргументы :: '{0}'; {1}", s, precision);
            Console.ReadLine();
        }
        public void WriteToObjFast(string s, uint precision)
        {
            Console.WriteLine("Метод записи быстрый");
            Console.WriteLine("Аргументы :: '{0}'; {1}", s, precision);
            Console.ReadLine();
        }
    }*/
}
