#include "Serie.h"

Serie::Serie(int id, const std::string& nombre, float duracion, const std::string& genero)
    : Video(id, nombre, duracion, genero) {}

void Serie::agregarEpisodio(const Episodio& episodio) {
    episodios.push_back(episodio);
}

void Serie::mostrarEpisodiosConCalificaciones(float calificacion) const {
    for (const auto& episodio : episodios) {
        if (episodio.calcularCalificacionPromedio() >= calificacion) {
            episodio.mostrar();
        }
    }
}

void Serie::mostrar() const {
    std::cout << "Serie -> ID: " << id << ", Nombre: " << nombre << ", Duración: " << duracion 
              << ", Género: " << genero << ", Calificación Promedio: " << calcularCalificacionPromedio() << std::endl;
}

const std::vector<Episodio>& Serie::getEpisodios() const {
    return episodios;
}
