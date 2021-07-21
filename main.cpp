#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//Diseñe una funcion que utilizando multiplicaciones sucesivas por 10, devuelva el total de cifras que tiene un numero
//b. segunda solucion, usando bucle while (multiplicaciones *10)
int cuentaCifras(int num)
{
    int i=1, cont=0;
    if(num<0) num=num*-1;
    while(i<= num )
    {
        i=i*10;
        cont++;
    }
    return cont;

}
//Diseñe la funcion recursiva que sume los n primeros numeros primos
bool primo(int num)
{
    bool esPrimo=true;
    int i=2;
    while(i<num/2 && esPrimo==true){
        if(num%i==0)
            esPrimo=false;
        i++;
    }
    return esPrimo;
}

int sumaprimos(int n)
{
    int i=0;int cont=1;
    int sum=0;
    while(i<=n){
        cont++;
        if(primo(cont))
        {
          sum+=cont;
          i++;
        }
    }
    return sum;
}

int sumaprimosrecursivo(int limite, int n)
{
    if(limite > 0){
        if(primo(n))
            return sumaprimosrecursivo(limite-1, n+1) + n;
        else
            return sumaprimosrecursivo(limite, n+1);
    }
    else
        return 0;
}

void adivinaElnumero(int oportunidades)
{
    srand(time(NULL));
    //Numeros aleatorios entre 0 y 50
    int num=1+ (rand()%51);

    //int num=15;
    bool adivinaste= false;
    int n;
    cout<<endl<<"Adivina el numero entre 1 y 50: ";

    int i=1;
    while(i<= oportunidades && adivinaste== false){
        cout<<endl<<"OPORTUNIDAD N°: "<<oportunidades;
        cout<<endl<<"Ingresa tu numero: ";
        cin>>n;
    if(n > num)
        cout<<endl<<"DEBES INGRESAR UN NUMERO MAS BAJO..";
    else if(n < num)
        cout<<endl<<"DEBES INGRESAR UN NUMERO MAS ALTO..";
    else{
        cout<<endl<<"FELICIDADES GANASTE UN PASAJE A GALAPAGOS!!!";
        adivinaste= true;
    }
    i++;
    }
    if(adivinaste)
        cout<<endl<<"ERES EL CAMPEON";
    else
        cout<<endl<<"PERDISTE, VUELVE A INTENTARLO..";

}
//FUNCION QUE SIMULE EL LANZAMIENTO DE DOS DADOS. CADA DADO DEBE GENERAR UN NUMERO ENTRE 1 Y 6. SE PIDE USAR NUMEROS ALEATORIOS
//EL USUARIO TIENE ENTRE 2 O 3 OPORTUNIDADES. EL USUARIO GANA CUANDO LOS NUMERO DE AMBOS LADOS COINCIDEN O SI SACA UN 11, ES DECIR GANA SI SACA PAR
// DE UNOS(1 Y 1) PAR DE DOS(2 Y 2), O PAR DE SEIS (6 Y 6) O SI TAMBIEN SACA UN 11(5 Y 6)
int lanzadordedados(void){

    int primerdado;
    int segundodado;
    int sumadados;

    primerdado=1+rand() % 6;
    segundodado=1+rand() & 6;
    sumadados= primerdado + segundodado;
    cout<<"TIRASTE "<<primerdado<<" + "<<segundodado<<" = "<<sumadados<<endl;

    return sumadados;
}

int main() {
    int num=8909;
    cout<<"El numero"<<num<<"tiene "<<cuentaCifras(num)<<"cifras";

    cout<<endl;
    num=11;
    if(primo(num))
        cout<<num<<"Es primo ";
    else
        cout<<num<<"No es primo ";
    cout<<endl;
    cout<<"LA SUMA DE LOS 4 PRIMEROS PRIMOS ES: (2+3+5+7): "<<sumaprimos(4);

    cout<<endl<<"LA SUMA DE LOS 4 PRIMEROS PRIMOS ES: (2+3+5+7): "<<sumaprimosrecursivo(4,2);

    srand(time(NULL));
    //Numeros aleatorios entre 0 y 50
    num=rand()%51;
    cout<<endl<<"Aleatorios: "<<num;
    int opcion;
    bool salir=false;
    while(true){
        cout<<endl<<endl<<"MENU PRINCIPAL - ADIVINA EL NUMERO ";
        cout<<endl<<endl<<"1. Jugar";
        cout<<endl<<endl<<"2. Salir";
        cout<<endl<<endl<<"CUAL ES TU OPCION: ";
        cin>>opcion;
        switch (opcion) {
            case 1:
                adivinaElnumero(5);
                break;
            case 2:
                salir=true;
                break;
            default:
                cout<<endl<<"OPCION NO VALIDA";
        }
        if(salir)
            break;
    }


    enum Status (CONTINUA, GANADOR, PERDEDOR);
    int suma;
    int punto;

    Status estadodeljuego;

    srand(time(0));
    suma=lanzadordedados();
    switch (suma) {
        case 7: case 11:
            estadodeljuego= GANADOR;
            break;
        case 2: case 3: case 12:
            estadodeljuego= PERDEDOR;
        default:
            estadodeljuego = CONTINUA;
            punto=suma;
            cout<<"EL PUNTO ES "<<punto<<endl;
            break;
    }
    while (estadodeljuego == CONTINUA){
            suma=lanzadordedados();
            if(suma==punto)
                estadodeljuego=GANADOR;
            else
                if(suma== 7)
                    estadodeljuego=PERDEDOR;
    }
    if(estadodeljuego==GANADOR)
        cout<<"GANASTE!!"<<endl;
    else
        cout<<"PERDISTE :("<<endl;
    return 0;
}
