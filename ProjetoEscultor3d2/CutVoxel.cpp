#include "CutVoxel.h"

CutVoxel::CutVoxel(int x, int y, int z){
    this->x = x;
    this->y = y;
    this->z = z;
}

CutVoxel::~CutVoxel() {
    // Destrutor vazio, pois não há alocação dinâmica de memória
}

void CutVoxel::draw(Sculptor &s){
    s.cutVoxel(x, y, z); // Chama o método cutVoxel da classe Sculptor para remover o voxel
}
