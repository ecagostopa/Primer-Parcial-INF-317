#Pregunta 4 - PRIMER PARCIAL 324

#Importacion de Bibliotecas
from threading import Thread
import os
import winsound
import time

num=17

#Funcion que ejecutara cada proceso
def funcion(numero, limite, inicio, aux1, aux): #2,10,6,3,2
    for n in range(inicio, limite, 1):
        #valor=0
        if n%2==0:
            aux1=n-aux
            valor=(aux1*aux1)+1
            aux=aux+1
        else:
            valor=n+1
        
        print(valor,"-->",numero,"aux1-aux",aux1,aux)
        #winsound.Beep(2500, 100)

def obt_indices(numero, limite, inicio, aux1, aux): #1,14,7

    for n in range(inicio, limite, 1):
        #valor=0
        if n%2==0:
            aux1=n-aux
            aux=aux+1
 
    return aux1, aux 
        
#Para observar la ejecucion debemos de ejecutar en una consola
#Creamos un MAIN para facilitar
if __name__ == '__main__':
    procesos=[] # En la lista guardamos los procesos
    # core=os.cpu_count() Obtenemos la de cores que tiene el cpu
    core=3
    print("Tienes ",core," cores")
    
    #print("Instanciar....")
    # Aca creamos los procesos, uno para cada core que tenemos
    p_par=int(num/core) # 16/4==4
    p_p=int(num/core)
    p_impar=int(num%core) # 
    inicio=0
    aux1=0
    aux=-1
    if num%core==0: 
        for n in range(core):
            proceso=Thread(target=funcion ,args=(n, p_par, inicio, aux1, aux, )) #Asiganamos la funcion a ejecutar con el argumento
            procesos.append(proceso) #Adicionamos el proceso a la lista de procesos
            indices = obt_indices(n, p_par, inicio, aux1, aux )
            aux1, aux = indices
            print("aux1,aux",aux1,aux)  
            inicio=inicio+p_p
            p_par=p_par+p_p
    else:
        for n in range(core):
            if n!=core-1:
                proceso=Thread(target=funcion ,args=(n, p_par, inicio, aux1, aux, )) #Asiganamos la funcion a ejecutar con el argumento
                procesos.append(proceso) #Adicionamos el proceso a la lista de procesos
                indices = obt_indices(n, p_par, inicio, aux1, aux )
                aux1, aux = indices
                print(p_par,inicio)
                print("aux1,aux",aux1,aux)  
                inicio=inicio+p_p
                p_par=p_par+p_p
            else:
                print(p_par,inicio)  
                p_par=p_par+p_impar
                proceso=Thread(target=funcion ,args=(n, p_par, inicio, aux1, aux )) #Asiganamos la funcion a ejecutar con el argumento
                procesos.append(proceso) #Adicionamos el proceso a la lista de procesos
                
    #print("Ejecutar...")
    #Una vez instanciada iniciamos su ejecucion
    for proceso in procesos:
        proceso.start()
    
    #print("Espera...")
    for proceso in procesos:
        proceso.join()
     
    print(procesos)
    print("Regreso a la ejecucion inicial")
    
    time.sleep(100)



