#include "FiguraGeometrica.h"
#include "Sculptor.h"

// Classe CutEllipsoid, que herda da classe FiguraGeometrica e representa um elipsoide a ser removido do Sculptor.
class CutEllipsoid : public FiguraGeometrica {
    int xcenter, ycenter, zcenter; // Centro do elipsoide
    int rx, ry, rz; // Raio do elipsoide em cada direção
public:
    // Construtor da classe CutEllipsoid, recebe as coordenadas do centro e raios do elipsoide.
    CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

    // Destrutor da classe CutEllipsoid.
    ~CutEllipsoid();

    // Método que remove o elipsoide representado no construtor do objeto da classe Sculptor.
    void draw(Sculptor &s);
};
