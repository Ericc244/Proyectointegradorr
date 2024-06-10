#include "Video.h"

Video::Video(int id, const std::string& nombre, float duracion, const std::string& genero)
    : id(id), nombre(nombre), duracion(duracion), genero(genero) {}

void Video::agregarCalificacion(int calificacion) {
    calificaciones.push_back(calificacion);
}

void Video::agregarCalificacion(const std::vector<int>& nuevasCalificaciones) {
    calificaciones.insert(calificaciones.end(), nuevasCalificaciones.begin(), nuevasCalificaciones.end());
}

float Video::calcularCalificacionPromedio() const {
    if (calificaciones.empty()) {
        return 0.0;
    }
    return std::accumulate(calificaciones.begin(), calificaciones.end(), 0.0) / calificaciones.size();
}

const std::string& Video::getNombre() const {
    return nombre;
}

const std::string& Video::getGenero() const {
    return genero;
}
