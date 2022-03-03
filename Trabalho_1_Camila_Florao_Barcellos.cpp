#include <iostream>

//Camila Florão Barcellos
//Trabalho prático 6
/*
    1 – Em uma granja de engorda
    de frangos o proprietário necessita saber quantos dias serão necessários para
    que o lote de N frangos seja entregue com uma média de peso de 4 KG, sabendo
    que cada frango chega na granja pesando 45 gramas e engordam 10% do seu peso
    por dia. Para auxiliar nesta demanda você foi contratado para implementar um
    sistema informatizado que receba a quantidade de frangos no lote e calcule com
    uma função recursiva quantos dias serão necessários alimentar os frangos
    para atingir a média pretendida.
*/

using namespace std;
int calcDias(int quant, float peso=0.045, int dias=0); //peso incial de 45g e dias zerados

int main ()
{
    setlocale (LC_ALL, "Portuguese");

    cout << "----------------------------------------------------------------------" << endl;
    cout << "                       -- TRABALHO PRÁTICO 6 --                       " << endl;
    cout << "----------------------------------------------------------------------" << endl;
    cout << "            -- CÁLCULO DE PESO MÉDIO DO LOTE DE FRANGOS --            " << endl;
    int quant;
    do
    {
        cout << "\nInforme a quantidade de frangos no lote: ";
        cin >> quant;

        if(quant<=0)
            cout << "\n<< QUANTIDADE INVÁLIDA >>" << endl;
    }while(quant<=0);

    cout << "\nDias de alimentação até o lote de " << quant << " frangos atingir 4Kg de média: " << calcDias(quant) << endl;
    cout << "----------------------------------------------------------------------" << endl;
}

/*
    -- Média do peso dos frangos --
    M = média
    s = soma de pesos (quantidade*peso)
    t = total de frangos
    Eq. geral: M = s/t

    Exemplo: 10 frangos de 5Kg
    M = (10*5)/10 = 5Kg

    Logo, como o peso dos frangos inicia
    igual (0,045Kg) e cresce na mesma medida (10%),
    a média de peso do lote é igual ao peso individual
*/

int calcDias(int quant, float peso, int dias)
{
    // Média = soma/quantidade  -->  cada frango tem cerca de 4Kg
    if((quant*peso)/quant>=4) //peso médio sendo maior ou igual a 4Kg porque, SEM ARREDONDAR VALORES, o peso no 47º dia será 3,96Kg e no 48º atingirá 4,36Kg
        return dias; //retorna os dias necessários
    else
    {
        dias++; //aumento de dias devido peso abaixo de 4Kg
        return calcDias(quant, peso+(peso*0.1), dias); //recursividade da função com peso 10% maior (devido passagem de 1 dia)
    }
}
