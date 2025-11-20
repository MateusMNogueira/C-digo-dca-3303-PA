#include "sculptor.h" // inclusão de declaração de classe e funções
#include <iostream>   // inclusão de biblioteca para entrada e saída padrão
#include <fstream>    // inclusão de biblioteca para manipulação de arquivos
#include <cmath>      // inclusão de biblioteca para funções matemáticas
#include <iomanip>    // inclusão de biblioteca para manipulação de formatação de saída

// Constructor da classe Sculptor
Sculptor::Sculptor(int nx, int ny, int nz)
{
    this->nx = nx;
    this->ny = ny;
    this->nz = nz;
    this->r = 0;
    this->g = 0;
    this->b = 0;
    this->a = 0;

    v = new Voxel **[nx]; // 1° DIMENSÃO DA MATRIZ: Aloca nx blocos do tipo Voxel**
    for (int i = 0; i < nx; i++)
    {
        v[i] = new Voxel *[ny]; // 2° DIMENSÃO DA MATRIZ: Aloca ny blocos do tipo Voxel* para cada bloco da 1° dimensão
        for (int j = 0; j < ny; j++)
        {
            v[i][j] = new Voxel[nz]; // 3° DIMENSÃO DA MATRIZ: Aloca nz blocos do tipo Voxel para cada bloco da 2° dimensão
        }
    }

    for (int x = 0; x < nx; x++)
    {
        for (int y = 0; y < ny; y++)
        {
            for (int z = 0; z < nz; z++)
            {
                // inicializa todos os voxels como não visíveis e com cor preta
                v[x][y][z].show = false;
                v[x][y][z].r = 0;
                v[x][y][z].g = 0;
                v[x][y][z].b = 0;
                v[x][y][z].a = 0;
            }
        }
    }
}
// Destructor da classe Sculptor
Sculptor::~Sculptor()
{
    for (int x = 0; x < nx; x++)
    {
        for (int y = 0; y < ny; y++)
        {
            delete[] v[x][y]; // libera a memória alocada para o eio Z
        }
        delete[] v[x]; // libera a memória alocada para o eixo Y
    }
    delete[] v; // libera a memória alocada para o eixo X
}

// Define a cor atual (RGBA) que será usada nos próximos voxels ativados.
void Sculptor::setColor(float r, float g, float b, float a)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

void Sculptor::putVoxel(int x, int y, int z)
{
    // Ativa o voxel na posição (x, y, z) e define sua cor atual
    v[x][y][z].show = true;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
}

void Sculptor::cutVoxel(int ex, int ey, int ez)
{
    // Desativa o voxel na posição (x, y, z)
    v[ex][ey][ez].show = false;
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    // Ativa todos os voxels no intervalo definido e atribui a cor atual
    for (int x = x0; x < x1; x++)
    {
        for (int y = y0; y < y1; y++)
        {
            for (int z = z0; z < z1; z++)
            {
                putVoxel(x, y, z);
            }
        }
    }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    // Desativa todos os voxels no intervalo definido
    for (int x = x0; x < x1; x++)
    {
        for (int y = y0; y < y1; y++)
        {
            for (int z = z0; z < z1; z++)
            {
                cutVoxel(x, y, z);
            }
        }
    }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    // Ativa os voxels dentro de uma esfera e atribui a cor atual
    for (int x = xcenter - radius; x <= xcenter + radius; x++)
    {
        for (int y = ycenter - radius; y <= ycenter + radius; y++)
        {
            for (int z = zcenter - radius; z <= zcenter + radius; z++)
            {
                if ((x - xcenter) * (x - xcenter) +
                        (y - ycenter) * (y - ycenter) +
                        (z - zcenter) * (z - zcenter) <=
                    radius * radius)
                {
                    putVoxel(x, y, z);
                }
            }
        }
    }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    // Desativa os voxels dentro de uma esfera
    for (int x = xcenter - radius; x <= xcenter + radius; x++)
    {
        for (int y = ycenter - radius; y <= ycenter + radius; y++)
        {
            for (int z = zcenter - radius; z <= zcenter + radius; z++)
            {
                if ((x - xcenter) * (x - xcenter) +
                        (y - ycenter) * (y - ycenter) +
                        (z - zcenter) * (z - zcenter) <=
                    radius * radius)
                {
                    cutVoxel(x, y, z);
                }
            }
        }
    }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    // Ativa os voxels dentro de uma elipsoide e atribui a cor atual
    for (int x = xcenter - rx; x <= xcenter + rx; x++)
    {
        for (int y = ycenter - ry; y <= ycenter + ry; y++)
        {
            for (int z = zcenter - rz; z <= zcenter + rz; z++)
            {
                if ((x - xcenter) * (x - xcenter) / (rx * rx) +
                        (y - ycenter) * (y - ycenter) / (ry * ry) +
                        (z - zcenter) * (z - zcenter) / (rz * rz) <=
                    1)
                {
                    putVoxel(x, y, z);
                }
            }
        }
    }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    // Desativa os voxels dentro de uma elipsoide
    for (int x = xcenter - rx; x <= xcenter + rx; x++)
    {
        for (int y = ycenter - ry; y <= ycenter + ry; y++)
        {
            for (int z = zcenter - rz; z <= zcenter + rz; z++)
            {
                if ((x - xcenter) * (x - xcenter) / (rx * rx) +
                        (y - ycenter) * (y - ycenter) / (ry * ry) +
                        (z - zcenter) * (z - zcenter) / (rz * rz) <=
                    1)
                {
                    cutVoxel(x, y, z);
                }
            }
        }
    }
}


void Sculptor::writeOFF(const char *filename)
{
    std::ofstream sculptorWriter;

    sculptorWriter.open(filename);
    if (!sculptorWriter.is_open())
    {
        std::cerr << "Erro: não foi possível abrir o arquivo " << filename << " para escrita.\n";
    }

    int voxels_ativo = 0;

    for (int i = 0; i < nx; i++)
    {
        for (int j = 0; j < ny; j++)
        {
            for (int k = 0; k < nz; k++)
            {
                if (v[i][j][k].show == true)
                {
                    voxels_ativo++;
                }
            }
        }
    }

    int n_vertices = voxels_ativo * 8;
    int n_faces = voxels_ativo * 6;

    sculptorWriter << "OFF\n";
    sculptorWriter << n_vertices << " " << n_faces << " 0\n";

    // 1. Escreve os vértices
    for (int i = 0; i < nx; i++)
    {
        for (int j = 0; j < ny; j++)
        {
            for (int k = 0; k < nz; k++)
            {
                if (v[i][j][k].show == true)
                {
                    sculptorWriter << std::fixed << std::setprecision(2);
                    sculptorWriter << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << "\n";
                    sculptorWriter << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << "\n";
                    sculptorWriter << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << "\n";
                    sculptorWriter << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << "\n";
                    sculptorWriter << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << "\n";
                    sculptorWriter << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << "\n";
                    sculptorWriter << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << "\n";
                    sculptorWriter << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << "\n";
                }
            }
        }
    }

    // 2. Escreve as faces (usando contador separado)
    int contador_vertices = 0;
    for (int i = 0; i < nx; i++)
    {
        for (int j = 0; j < ny; j++)
        {
            for (int k = 0; k < nz; k++)
            {
                if (v[i][j][k].show == true)
                {
                    sculptorWriter << "4 " << contador_vertices << " " << contador_vertices + 3 << " " << contador_vertices + 2 << " " << contador_vertices + 1 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
                    sculptorWriter << "4 " << contador_vertices + 4 << " " << contador_vertices + 5 << " " << contador_vertices + 6 << " " << contador_vertices + 7 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
                    sculptorWriter << "4 " << contador_vertices << " " << contador_vertices + 1 << " " << contador_vertices + 5 << " " << contador_vertices + 4 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
                    sculptorWriter << "4 " << contador_vertices << " " << contador_vertices + 4 << " " << contador_vertices + 7 << " " << contador_vertices + 3 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
                    sculptorWriter << "4 " << contador_vertices + 3 << " " << contador_vertices + 7 << " " << contador_vertices + 6 << " " << contador_vertices + 2 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
                    sculptorWriter << "4 " << contador_vertices + 1 << " " << contador_vertices + 2 << " " << contador_vertices + 6 << " " << contador_vertices + 5 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";

                    contador_vertices += 8;
                }
            }
        }
    }

    sculptorWriter.close();
}
