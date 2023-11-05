using System;
using System.Threading.Tasks;

namespace ConsoleApp3
{
    class Program
    {
        static void Main(string[] args)
        {
            int numPuntos = 10000000; // Número de puntos a generar
            int numHilos = 1; // Número de hilos

            double piAproximado = CalcularPi(numPuntos, numHilos);
            Console.WriteLine($"Valor aproximado de PI: {piAproximado}");
        }
        static double CalcularPi(int numPuntos, int numHilos)
        {
            int puntosEnCirculo = 0;
            object lockObj = new object();

            Parallel.For(0, numHilos, i =>
            {
                int puntosEnHilo = 0;
                Random rand = new Random();

                for (int j = 0; j < numPuntos / numHilos; j++)
                {
                    double x = rand.NextDouble();
                    double y = rand.NextDouble();

                    if (x * x + y * y <= 1)
                    {
                        puntosEnHilo++;
                    }
                }

                lock (lockObj)
                {
                    puntosEnCirculo += puntosEnHilo;
                }
            });

            // Calcula el valor de PI
            double pi = 4.0 * puntosEnCirculo / numPuntos;
            return pi;
        }
    }
}
