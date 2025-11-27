#include "CutEllipsoid.h"

CutEllipsoid::CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) {
    this->xcenter = xcenter;
    this->ycenter = ycenter;
    this->zcenter = zcenter;

    this->rx = rx;
    this->ry = ry;
    this->rz = rz;
}

CutEllipsoid::~CutEllipsoid(){};

void CutEllipsoid::draw(Sculptor &s) {
    // Remove os voxels dentro do elipsoide definido pelo centro e raios
    for (int x = (xcenter - rx); x <= (xcenter + rx); x++) {
        for (int y = (ycenter - ry); y <= (ycenter + ry); y++) {
            for (int z = (zcenter - rz); z <= (zcenter + rz); z++) {
                if (((x - xcenter) * (x - xcenter)) / (rx * rx) +
                    ((y - ycenter) * (y - ycenter)) / (ry * ry) +
                    ((z - zcenter) * (z - zcenter)) / (rz * rz) <= 1) {
                    s.cutVoxel(x, y, z);
                }
            }
        }
    }
}
