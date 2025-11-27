#include "FiguraGeometrica.h"
#include "Sculptor.h"

// Classe PutEllipsoid, que herda da classe FiguraGeometrica e representa um elipsoide a ser desenhado no Sculptor.
class PutEllipsoid : public FiguraGeometrica {
    int xcenter, ycenter, zcenter; // Centro do elipsoide
    int rx, ry, rz; // Raio do elipsoide em cada direção
    float r, g, b, a; // Atributos de cor e transparência

public:
    // Construtor da classe PutEllipsoide, recebe as coordenadas do centro, raios e cor.
    PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a);

    // Destrutor da classe PutEllipsoide.
    ~PutEllipsoid();

    // Método que desenha o elipsoide representado no construtor do objeto da classe Sculptor.
    void draw(Sculptor &s);
};


