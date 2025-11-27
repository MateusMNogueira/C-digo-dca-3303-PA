#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "Sculptor.h"

 // Classe abstrata que representa uma figura geométrica 3D.
 // Herda da classe Sculptor e define a interface para figuras geométricas.

class FiguraGeometrica {
protected:
    float r,g,b,a; // Cores e transparência
public:
    // Construtor padrão da classe FiguraGeometrica.
    FiguraGeometrica();
    // Destrutor virtual da classe FiguraGeometrica.
    virtual ~FiguraGeometrica();

    //Método virtual puro (força o programa a executar os métodos das subclasses).
    virtual void draw(Sculptor &s) = 0;
};

#endif // FIGURAGEOMETRICA_H
