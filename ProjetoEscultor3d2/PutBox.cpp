#include "PutBox.h"

PutBox::PutBox(int x0, int x1, int y0, int y1, int z0, int z1, float r, float g, float b, float a) {
    this->x0 = x0;
    this->x1 = x1;

    this->y0 = y0;
    this->y1 = y1;

    this->z0 = z0;
    this->z1 = z1;

    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

PutBox::~PutBox() {};

void PutBox::draw(Sculptor &s) {
    // Define a cor do Sculptor
    s.setColor(r, g, b, a);
    
    // Coloca os voxels na região definida pela caixa
    for (int x = x0; x < x1; x++) {
        for (int y = y0; y < y1; y++) {
            for (int z = z0; z < z1; z++) {
                s.putVoxel(x, y, z);
            }
        }
    }
}
