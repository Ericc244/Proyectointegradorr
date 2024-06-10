#ifndef SERIE_H
#define SERIE_H

#include "Video.h"
#include "Episodio.h"
#include <vector>

class Serie : public Video {
    std::vector<Episodio> episodios;

public:
    Serie(int id, const std::string& nombre, float duracion, const std::string& genero);

    void agregarEpisodio(const Episodio& episodio);

    void mostrarEpisodiosConCalificaciones(float calificacion) const;

    void mostrar() const override;

    const std::vector<Episodio>& getEpisodios() const;
};

#endif 
