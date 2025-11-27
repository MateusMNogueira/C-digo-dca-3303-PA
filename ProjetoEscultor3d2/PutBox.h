#include "FiguraGeometrica.h"
#include "Sculptor.h"

//Classe PutBox, que herda da classe FiguraGeometrica e representa uma caixa tridimensional a ser desenhada no Sculptor.
class PutBox : public FiguraGeometrica
{
    //Coordenadas da região da caixa a ser desenhada
    int x0, x1, y0, y1, z0, z1;
public:
    // Construtor padrão da classe PutBox
    PutBox(int x0, int x1, int y0, int y1, int z0, int z1, float r, float g, float b, float a);

    // Destrutor padrão da classe PutBox.
    ~PutBox();

    // Método que desenha a caixa representada no construtor do objeto da classe Sculptor.
    void draw(Sculptor &s);
};
