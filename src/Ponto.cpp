#include "Ponto.h"

Ponto::Ponto(int in_x, int in_y)
{
    x = in_x;
    y = in_y;
}

Ponto::~Ponto()
{
    //destructor
}

double Ponto::distancia(Ponto a)
{
    // Não faz a raiz quadrada no final por ser lento
    int xi = x - a.getX();
    int yi = y - a.getY();
    return xi * xi + yi * yi;
}

int Ponto::getX()
{
    return x;
}

int Ponto::getY()
{
    return y;
}
