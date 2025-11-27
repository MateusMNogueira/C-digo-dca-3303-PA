#include "FiguraGeometrica.h"
#include "Sculptor.h"

// Classe CutSphere, que herda da classe FiguraGeometrica e representa uma esfera a ser removida do Sculptor.
class CutSphere : public FiguraGeometrica {
    int xcenter, ycenter, zcenter; // Centro da esfera
    int radius; // Raio da esfera
public:
    // Construtor da classe CutSphere, recebe as coordenadas do centro e o raio da esfera.
    CutSphere(int xcenter, int ycenter, int zcenter, int radius);

    // Destrutor da classe CutSphere.
    ~CutSphere(); // Destrutor vazio, pois não há alocação dinâmica de memória

   // Método que remove a esfera representada no construtor do objeto da classe Sculptor. 
    void draw(Sculptor &s); 
    // O método draw é virtual e deve ser implementado para remover a esfera do Sculptor
};
