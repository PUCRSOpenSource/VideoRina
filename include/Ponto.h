#ifndef PONTO_H
#define PONTO_H


class Ponto
{
    private:
        int x;
        int y;
    public:

        Ponto(int in_x, int in_y);
        ~Ponto();

        double distancia(Ponto a);

        int getX();

        int getY();
};


#endif // PONTO_H
