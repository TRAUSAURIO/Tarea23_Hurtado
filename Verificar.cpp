///Autor:Ronald Elian Hurtado Jama
///Fecha:01/08/2024
///Tema:Verificacion de cedula

#include <iostream>
using namespace std;

bool CedulaCorrecta(int cedula[], int total)
{
    int sumapar=0, sumaimpar=0;
for (int k=0; k<total ; k++)//INICIO
    {
        //multiplicar posiciones pares por 2
        int num=0;
        if(k % 2 == 0)
        {
            num = cedula[k]*2;//si el resultado es >=9, se resta 9
            if(num>=9)
            num=num-9;
            sumapar+=num;
        }
        else{///se suma las posiciones impares
            sumaimpar+=cedula[k];
        }
    }//FIN

    int suma = sumapar + sumaimpar;
    //aplicamos modulo 10
    int resto = suma % 10;
    int resultado = 10 - resto;
    if(resultado == 10)
    resultado=0;

    //validamos si el digito concide con el ultimo numero de la cedula
    if(resultado == cedula[total-1])
        return true;
    else
        return false;
    
}

int main()
{
    int cedula[] = {0, 8, 5, 0, 2, 9, 9, 8, 9, 2};
    int total = sizeof(cedula) / sizeof(cedula[0]);
    //cout<<end<<"Tamaño el vector: " <<total;

    if (CedulaCorrecta(cedula, total))
    cout<<endl<<"La cedula es correcta";
    else
    cout<<endl<<"La cedula no es correcta";
    return 0;
    
}