#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include <vector>
#include <string>
#include <numeric>

class Video {
protected:
    int id;
    std::string nombre;
    float duracion;
    std::string genero;
    std::vector<int> calificaciones;

public:
    Video(int id, const std::string& nombre, float duracion, const std::string& genero);

    void agregarCalificacion(int calificacion);
    void agregarCalificacion(const std::vector<int>& nuevasCalificaciones); // Sobrecarga de método

    float calcularCalificacionPromedio() const;

    virtual void mostrar() const = 0; // Método virtual puro

    const std::string& getNombre() const;

    const std::string& getGenero() const;

    virtual ~Video() = default;
};

#endif 
