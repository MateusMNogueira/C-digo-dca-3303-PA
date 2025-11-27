#include "FiguraGeometrica.h"
#include "Sculptor.h"

//Classe CutBox, que herda da classe FiguraGeometrica e representa uma caixa a ser removida do Sculptor.
class CutBox : public FiguraGeometrica {
    int x0, x1, y0, y1, z0, z1; // Coordenadas dos cantos da caixa
public:
    // Construtor da classe CutBox, recebe as coordenadas dos cantos da caixa.
    CutBox(int x0, int x1, int y0, int y1, int z0, int z1);

    // Destrutor da classe CutBox.
    ~CutBox();

    // Método que remove a caixa representada no construtor do objeto da classe Sculptor.
    void draw(Sculptor &s);
};
