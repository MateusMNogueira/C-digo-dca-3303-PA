#include "Sculptor.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

//Função construtora da classe Sculptor. Recebe as dimensões da matriz tridimensional de Voxels e inicializa os valores de cor e opacidade dos Voxels.
Sculptor::Sculptor(int nx, int ny, int nz) 
{
    this->nx = nx;
    this->ny = ny;
    this->nz = nz;

    v = new Voxel**[nx];
    for (int x = 0; x < nx; x++) {
        v[x] = new Voxel*[ny];
        for (int y = 0; y < ny; y++) {
            v[x][y] = new Voxel[nz];
        }
    }

    for (int x = 0; x < nx; x++) {
        for (int y = 0; y < ny; y++) {
            for (int z = 0; z < nz; z++) {
                v[x][y][z].show = false; // Inicializa todos os voxels como não visíveis
                v[x][y][z].r = 0;
                v[x][y][z].g = 0;
                v[x][y][z].b = 0;
                v[x][y][z].a = 0;
            }
        }
    }
}

// Destructor da classe Sculptor para liberar a memória
Sculptor::~Sculptor()
{
    for (int x = 0; x < nx; x++) {
        for (int y = 0; y < ny; y++) {
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

// Ativa o voxel na posição (x, y, z) com a cor atual.
void Sculptor::putVoxel(int x, int y, int z)
{
    // Ativa o voxel na posição (x, y, z) e define sua cor atual
    v[x][y][z].show = true;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
}

void Sculptor::cutVoxel(int x, int y, int z)
{
    // Desativa o voxel na posição (x, y, z)
    v[x][y][z].show = false;
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
