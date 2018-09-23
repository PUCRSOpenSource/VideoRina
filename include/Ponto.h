#ifndef PONTO_H
#define PONTO_H


class Ponto
{
    private:
        int x;
        int y;
        double r;
        double g;
        double b;
    public:

        Ponto();
        Ponto(int in_x, int in_y);
        Ponto(int in_x, int in_y, double in_r, double in_g, double in_b);
        ~Ponto();
        double distancia(Ponto a);
        int getX();
        int getY();
        double getR();
        double getG();
        double getB();
        void setX(int xi);
        void setY(int yi);
};


#endif // PONTO_H
