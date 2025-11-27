#include "PutEllipsoid.h"

PutEllipsoid::PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a) {
    this->xcenter = xcenter;
    this->ycenter = ycenter;
    this->zcenter = zcenter;

    this->rx = rx;
    this->ry = ry;
    this->rz = rz;

    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

PutEllipsoid::~PutEllipsoid() {
    // Destrutor vazio, pois não há alocação dinâmica de memória
}

void PutEllipsoid::draw(Sculptor &s) {
    s.setColor(r, g, b, a);

    // Coloca os voxels no elipsoide usando a equação do elipsoide
    for (int x = (xcenter - rx); x <= (xcenter + rx); x++) {
        for (int y = (ycenter - ry); y <= (ycenter + ry); y++) {
            for (int z = (zcenter - rz); z <= (zcenter + rz); z++) {
                if (((x - xcenter) * (x - xcenter)) / (rx * rx) +
                    ((y - ycenter) * (y - ycenter)) / (ry * ry) +
                    ((z - zcenter) * (z - zcenter)) / (rz * rz) <= 1) {
                    s.putVoxel(x, y, z);
                }
            }
        }
    }
}
