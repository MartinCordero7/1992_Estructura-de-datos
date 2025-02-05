#include <graphics.h>
#include <iostream>

void obtenerResolucion(int &ancho, int &alto) {
    // Inicializar modo gráfico
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, NULL);

    // Obtener dimensiones máximas
    ancho = getmaxx();
    alto = getmaxy();

    // Cerrar modo gráfico temporal
    closegraph();
}

void dibujarResponsivo() {
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, NULL);
    
    int anchoPantalla = getmaxx();
    int altoPantalla = getmaxy();
    
    // Configuración responsiva (ejemplo: 80% del ancho y alto)
    int anchoFigura = anchoPantalla * 0.8;
    int altoFigura = altoPantalla * 0.8;
    int xInicio = (anchoPantalla - anchoFigura) / 2;
    int yInicio = (altoPantalla - altoFigura) / 2;

    // Dibujar un rectángulo responsivo
    rectangle(xInicio, yInicio, xInicio + anchoFigura, yInicio + altoFigura);
    
    getch();
    closegraph();
}

int main() {
    int ancho, alto;
    
    obtenerResolucion(ancho, alto);
    std::cout << "Resolución detectada: " << ancho << "x" << alto << std::endl;
    
    dibujarResponsivo();
    
    return 0;
}