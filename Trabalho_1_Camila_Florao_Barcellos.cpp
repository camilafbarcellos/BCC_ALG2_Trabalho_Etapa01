#include <iostream>

//Camila Flor�o Barcellos
//Trabalho pr�tico 6
/*
    1 � Em uma granja de engorda
    de frangos o propriet�rio necessita saber quantos dias ser�o necess�rios para
    que o lote de N frangos seja entregue com uma m�dia de peso de 4 KG, sabendo
    que cada frango chega na granja pesando 45 gramas e engordam 10% do seu peso
    por dia. Para auxiliar nesta demanda voc� foi contratado para implementar um
    sistema informatizado que receba a quantidade de frangos no lote e calcule com
    uma fun��o recursiva quantos dias ser�o necess�rios alimentar os frangos
    para atingir a m�dia pretendida.
*/

using namespace std;
int calcDias(int quant, float peso=0.045, int dias=0); //peso incial de 45g e dias zerados

int main ()
{
    setlocale (LC_ALL, "Portuguese");

    cout << "----------------------------------------------------------------------" << endl;
    cout << "                       -- TRABALHO PR�TICO 6 --                       " << endl;
    cout << "----------------------------------------------------------------------" << endl;
    cout << "            -- C�LCULO DE PESO M�DIO DO LOTE DE FRANGOS --            " << endl;
    int quant;
    do
    {
        cout << "\nInforme a quantidade de frangos no lote: ";
        cin >> quant;

        if(quant<=0)
            cout << "\n<< QUANTIDADE INV�LIDA >>" << endl;
    }while(quant<=0);

    cout << "\nDias de alimenta��o at� o lote de " << quant << " frangos atingir 4Kg de m�dia: " << calcDias(quant) << endl;
    cout << "----------------------------------------------------------------------" << endl;
}

/*
    -- M�dia do peso dos frangos --
    M = m�dia
    s = soma de pesos (quantidade*peso)
    t = total de frangos
    Eq. geral: M = s/t

    Exemplo: 10 frangos de 5Kg
    M = (10*5)/10 = 5Kg

    Logo, como o peso dos frangos inicia
    igual (0,045Kg) e cresce na mesma medida (10%),
    a m�dia de peso do lote � igual ao peso individual
*/

int calcDias(int quant, float peso, int dias)
{
    // M�dia = soma/quantidade  -->  cada frango tem cerca de 4Kg
    if((quant*peso)/quant>=4) //peso m�dio sendo maior ou igual a 4Kg porque, SEM ARREDONDAR VALORES, o peso no 47� dia ser� 3,96Kg e no 48� atingir� 4,36Kg
        return dias; //retorna os dias necess�rios
    else
    {
        dias++; //aumento de dias devido peso abaixo de 4Kg
        return calcDias(quant, peso+(peso*0.1), dias); //recursividade da fun��o com peso 10% maior (devido passagem de 1 dia)
    }
}
