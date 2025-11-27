#ifndef SCULPTOR_H
#define SCULPTOR_H

/**
 * Struct usada para servir como "pixel" da imagem 3D a ser feita.\n
 * Guarda a cor, opacidade e decisao se o pixel sera desenhado ou nao.
 */
struct Voxel {
    float r, g, b; // Color components
    float a;       // Transparency
    bool show;     // Voxel state (on/off)
};
/**
 * Classe que representa um escultor 3D, capaz de criar e manipular uma matriz tridimensional de Voxels.
 */
class Sculptor 
{
protected:
    Voxel ***v; // Ponteiro para a matriz tridimensional de Voxels
    int nx, ny, nz; // Dimensions da matriz 3d
    float r, g, b, a; // Atributos de cor e transparencia

public:
    //Construtor padrão
    Sculptor(int nx, int ny, int nz);

    // Destrutor padrão
    ~Sculptor();

    void setColor(float r, float g, float b, float a);

    void putVoxel(int x, int y, int z);

    void cutVoxel(int x, int y, int z);

    void writeOFF(const char *filename);

};

#endif // SCULPTOR_H
