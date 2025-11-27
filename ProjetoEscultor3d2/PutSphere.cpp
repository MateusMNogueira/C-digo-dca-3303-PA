#include "PutSphere.h"

PutSphere::PutSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a) {
    this->xcenter = xcenter;
    this->ycenter = ycenter;
    this->zcenter = zcenter;
    this->radius = radius;

    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

PutSphere::~PutSphere() {
    // Destrutor vazio, pois não há alocação dinâmica de memória
}

void PutSphere::draw(Sculptor &s){

    s.setColor(r, g, b, a);

    // Coloca os voxels na esfera usando a equação da esfera
    for (int x = (xcenter - radius); x <= (xcenter + radius); x++) {
        for (int y = (ycenter - radius); y <= (ycenter + radius); y++) {
            for (int z = (zcenter - radius); z <= (zcenter + radius); z++) {
                if ((x - xcenter) * (x - xcenter) +
                    (y - ycenter) * (y - ycenter) +
                    (z - zcenter) * (z - zcenter) <= radius * radius) {
                    s.putVoxel(x, y, z);
                }
            }
        }
    }
}
