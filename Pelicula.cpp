#include "Pelicula.h"

Pelicula::Pelicula(int id, const std::string& nombre, float duracion, const std::string& genero)
    : Video(id, nombre, duracion, genero) {}

void Pelicula::mostrar() const {
    std::cout << "Película -> ID: " << id << ", Nombre: " << nombre << ", Duración: " << duracion 
              << ", Género: " << genero << ", Calificación Promedio: " << calcularCalificacionPromedio() << std::endl;
}
