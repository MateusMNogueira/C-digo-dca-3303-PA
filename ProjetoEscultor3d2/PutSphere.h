#include "FiguraGeometrica.h"
#include "Sculptor.h"

//Classe PutSphere, que herda da classe FiguraGeometrica e representa uma esfera tridimensional a ser desenhada no Sculptor.
class PutSphere : public FiguraGeometrica {
    int xcenter, ycenter, zcenter; // Centro da esfera
    int radius; // Raio da esfera
public:
    // Construtor padrão da classe PutSphere, recebe as coordenadas do centro e o raio da esfera, além das cores.
    PutSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a);

    // Destrutor padrão da classe PutSphere.
    ~PutSphere();

    // Método que desenha a esfera representada no construtor do objeto da classe Sculptor.
    void draw(Sculptor &s);
};
