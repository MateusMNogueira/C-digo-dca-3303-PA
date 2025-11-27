#include "FiguraGeometrica.h"
#include "Sculptor.h"

// Classe CutVoxel, que herda da classe FiguraGeometrica e representa um voxel a ser removido do Sculptor.
class CutVoxel : public FiguraGeometrica {
    int x, y, z; // Posição do voxel a ser removido
public:
    // Construtor da classe CutVoxel, recebe as coordenadas do voxel a ser removido.
    CutVoxel(int x, int y, int z);

    // Destrutor da classe CutVoxel.
    ~CutVoxel();

    // Método que remove o voxel representado no construtor do objeto da classe Sculptor.
    void draw(Sculptor &s);
};
