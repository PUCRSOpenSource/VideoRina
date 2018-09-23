#include "Ponto.h"

Ponto::Ponto()
{
    //construtor
}

Ponto::Ponto(int in_x, int in_y)
{
    x = in_x;
    y = in_y;
}

Ponto::Ponto(int in_x, int in_y, double in_r, double in_g, double in_b)
{
    x = in_x;
    y = in_y;
    r = in_r;
    g = in_g;
    b = in_b;
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

double Ponto::getR()
{
    return r;
}

double Ponto::getG()
{
    return g;
}

double Ponto::getB()
{
    return b;
}

void Ponto::setX(int xi)
{
    x = xi;
}

void Ponto::setY(int yi)
{
    y = yi;
}
