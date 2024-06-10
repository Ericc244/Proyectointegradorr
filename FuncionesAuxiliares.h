#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

#include <vector>
#include <string>
#include "Video.h"
#include "Pelicula.h"
#include "Serie.h"

std::string readQuotedString(std::istringstream& iss);

bool cargarDatos(const std::string& archivo, std::vector<Video*>& videos, std::vector<Serie*>& series);

void mostrarVideosConCriterio(const std::vector<Video*>& videos, float calificacion, const std::string& genero);

void mostrarEpisodiosConCalificacion(const std::vector<Serie*>& series, const std::string& nombreSerie, float calificacion);

void mostrarPeliculasConCalificacion(const std::vector<Video*>& videos, float calificacion);

void calificarVideo(std::vector<Video*>& videos, const std::string& nombre, int calificacion);

#endif 
