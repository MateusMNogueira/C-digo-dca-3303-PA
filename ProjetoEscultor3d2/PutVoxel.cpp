#include "PutVoxel.h"

PutVoxel::PutVoxel(int x, int y, int z, float r, float g, float b, float a) {
    this->x = x;
    this->y = y;
    this->z = z;

    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

PutVoxel::~PutVoxel() {
    // Destrutor vazio, pois não há alocação dinâmica de memória
}

void PutVoxel::draw(Sculptor &s) {
    // Define a cor do Sculptor
    s.setColor(r, g, b, a);
    // Coloca o voxel na posição especificada
    s.putVoxel(x, y, z);
}
