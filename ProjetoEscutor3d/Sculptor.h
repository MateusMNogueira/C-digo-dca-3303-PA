#ifndef SCULPTOR_H
#define SCULPTOR_H

struct Voxel
{
    float r, g, b, a; // Cores e transparência
    bool show;        // Incluído ou não no desenho
};

class Sculptor
{
private:
    Voxel ***v;       // Matriz 3D de voxels
    int nx, ny, nz;   // Dimensões
    float r, g, b, a; // Cor atual

public:
    // Construtor da classe
    Sculptor(int _nx, int _ny, int _nz);

    // Destrutor da classe
    ~Sculptor();

    // Define a cor atual
    void setColor(float r, float g, float b, float a);

    // Ativa todos os voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1]
    // e atribui a cor atual de desenho
    void putVoxel(int x, int y, int z);

    // Desativa todos os voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1]
    void cutVoxel(int x, int y, int z);

    // Ativa os voxels no intervalo e atribui a cor atual
    void putBox(int x0, int x1, int y0, int y1, int z0, int z1);

    // Desativa os voxels no intervalo
    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);

    // Ativa os voxels de uma esfera e atribui a cor atual
    void putSphere(int xcenter, int ycenter, int zcenter, int radius);

    // Desativa os voxels de uma esfera
    void cutSphere(int xcenter, int ycenter, int zcenter, int radius);

    // Ativa os voxels de uma elipsoide e atribui a cor atual
    void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

    // Desativa os voxels de uma elipsoide
    void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

    // Grava a escultura no formato OFF no arquivo filename
    void writeOFF(const char *filename);
};

#endif
