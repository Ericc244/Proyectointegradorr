#ifndef PELICULA_H
#define PELICULA_H

#include "Video.h"

class Pelicula : public Video {
public:
    Pelicula(int id, const std::string& nombre, float duracion, const std::string& genero);

    void mostrar() const override;

    
    bool operator==(const Pelicula& other) const {
        return this->nombre == other.nombre && this->duracion == other.duracion;
    }
};

#endif
