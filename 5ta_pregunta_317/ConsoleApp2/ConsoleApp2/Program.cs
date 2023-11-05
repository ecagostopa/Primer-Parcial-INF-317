using System;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = 14;  // Número de términos en la serie
            int numHilos = 4;  // Número de hilos

            int aux1 = 0;
            int aux = -1;
            double[] serie = new double[n];
            int inicio = 0;
            int fin = n / numHilos;
            int p_p = n / numHilos;
            int cont = 0;
            int p_i = n % numHilos;

            Parallel.For(0, numHilos, i =>
            {
                cont++;
                if (n % numHilos == 0)
                {
                    for (int j = inicio; j < fin; j++)
                    {
                        if (j % 2 == 0)
                        {
                            aux1 = j - aux;
                            serie[j] = (aux1 * aux1) + 1;
                            aux++;
                        }
                        else
                        {
                            serie[j] = j + 1;
                        }
                    }
                    inicio = inicio + p_p;
                    fin = fin + p_p;
                }
                else
                {
                    if (cont == numHilos)
                    {
                        fin = fin + p_i;
                        for (int j = inicio; j < fin; j++)
                        {
                            if (j % 2 == 0)
                            {
                                aux1 = j - aux;
                                serie[j] = (aux1 * aux1) + 1;
                                aux++;
                            }
                            else
                            {
                                serie[j] = j + 1;
                            }
                        }

                    }
                    else
                    {
                        for (int j = inicio; j < fin; j++)
                        {
                            if (j % 2 == 0)
                            {
                                aux1 = j - aux;
                                serie[j] = (aux1 * aux1) + 1;
                                aux++;
                            }
                            else
                            {
                                serie[j] = j + 1;
                            }
                        }
                        inicio = inicio + p_p;
                        fin = fin + p_p;
                    }
                }
            });
            Console.WriteLine("Serie: " + string.Join(", ", serie));
        }
    }
}
