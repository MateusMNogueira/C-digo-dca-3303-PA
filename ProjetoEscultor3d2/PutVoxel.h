#include "FiguraGeometrica.h"
#include "Sculptor.h"

class PutVoxel : public FiguraGeometrica {
    int x, y, z; // Posição do voxel a ser colocado
public:
    // Construtor da classe PutVoxel, recebe as coordenadas do voxel e a cor.
    PutVoxel(int x, int y, int z, float r, float g, float b, float a);

    //Destrutor da classe PutVoxel.
    ~PutVoxel();

    // Método que desenha o voxel representado no construtor do objeto da classe Sculptor.
    void draw(Sculptor &s);
};
