#include "Episodio.h"

Episodio::Episodio(const std::string& titulo, int temporada, float duracion)
    : titulo(titulo), temporada(temporada), duracion(duracion) {}

void Episodio::agregarCalificacion(int calificacion) {
    calificaciones.push_back(calificacion);
}

float Episodio::calcularCalificacionPromedio() const {
    if (calificaciones.empty()) {
        return 0.0;
    }
    return std::accumulate(calificaciones.begin(), calificaciones.end(), 0.0) / calificaciones.size();
}

void Episodio::mostrar() const {
    std::cout << "Título: " << titulo << ", Temporada: " << temporada << ", Duración: " << duracion 
              << ", Calificación Promedio: " << calcularCalificacionPromedio() << std::endl;
}

const std::string& Episodio::getTitulo() const {
    return titulo;
}
