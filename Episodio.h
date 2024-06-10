#ifndef EPISODIO_H
#define EPISODIO_H

#include <iostream>
#include <vector>
#include <string>
#include <numeric>

class Episodio {
    std::string titulo;
    int temporada;
    float duracion;
    std::vector<int> calificaciones;

public:
    Episodio(const std::string& titulo, int temporada, float duracion);

    void agregarCalificacion(int calificacion);

    float calcularCalificacionPromedio() const;

    void mostrar() const;

    const std::string& getTitulo() const;
};

#endif // EPISODIO_H
