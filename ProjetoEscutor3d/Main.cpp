#include "sculptor.h"
#include <iostream>

int main() {
    Sculptor senna(120, 120, 120);
    float a = 1.0f;

    // ====== CASCO PRINCIPAL (esférico) ======
    senna.setColor(1.0f, 0.84f, 0.0f, a); // Amarelo Senna
    senna.putEllipsoid(60, 60, 60, 27, 25, 27); // Casco mais redondo

    // ====== INTERIOR OCO ======
    senna.cutEllipsoid(60, 60, 60, 24, 22, 24);

    // ====== BASE PRETA ======
    senna.setColor(0.05f, 0.05f, 0.05f, a);
    senna.putEllipsoid(60, 47, 60, 27, 6, 27);

    // ====== LISTRAS EXTERNAS ======
    float raioFaixa = 27.5f; // ligeiramente maior para aparecer sobre o casco

    // Faixa verde superior
    senna.setColor(0.0f, 0.6f, 0.0f, a);
    senna.putEllipsoid(60, 70, 60, raioFaixa, 2, raioFaixa);

    // Faixa azul central
    senna.setColor(0.0f, 0.0f, 0.5f, a);
    senna.putEllipsoid(60, 66, 60, raioFaixa, 1, raioFaixa);

    // Faixa verde inferior
    senna.setColor(0.0f, 0.6f, 0.0f, a);
    senna.putEllipsoid(60, 62, 60, raioFaixa, 2, raioFaixa);

    // ====== VISOR PRETO CURVO ======
    senna.setColor(0.0f, 0.0f, 0.0f, a);
    senna.putEllipsoid(60, 62, 82, 15, 9, 8);  // frente externa
    senna.cutEllipsoid(60, 62, 80, 14, 8, 7);  // recorte leve

    // ====== REFLEXO DO VISOR ======
    senna.setColor(0.9f, 0.9f, 0.9f, 0.5f);
    senna.putEllipsoid(54, 70, 83, 4, 2, 1);

    // ====== DETALHE: FAIXAS AMARELAS ENTRE AS VERDES ======
    senna.setColor(1.0f, 0.84f, 0.0f, a);
    senna.putEllipsoid(60, 74, 60, raioFaixa, 1, raioFaixa);
    senna.putEllipsoid(60, 58, 60, raioFaixa, 1, raioFaixa);

    // ====== EXPORTAÇÃO ======
    senna.writeOFF("capacete_senna.off");

    std::cout << "Capacete do Ayrton Senna gerado!" << std::endl;
    return 0;
}
