#include "FuncionesAuxiliares.h"
#include "Pelicula.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <iomanip>

std::string readQuotedString(std::istringstream& iss) {
    std::string result;
    char ch;
    iss >> ch; 
    if (ch == '\"') {
        std::getline(iss, result, '\"'); 
    } else {
        iss.putback(ch); 
        iss >> result;
    }
    return result;
}

bool cargarDatos(const std::string& archivo, std::vector<Video*>& videos, std::vector<Serie*>& series) {
    std::ifstream inFile(archivo);
    if (!inFile.is_open()) {
        std::cerr << "Error al abrir el archivo.\n";
        return false;
    }

    std::string linea;
    while (std::getline(inFile, linea)) {
        std::istringstream iss(linea);
        std::string tipo, nombre, genero;
        int id, temporada;
        float duracion;
        tipo = readQuotedString(iss);
        iss >> id;
        nombre = readQuotedString(iss);
        iss >> duracion;
        genero = readQuotedString(iss);

        if (tipo == "Pelicula") {
            videos.push_back(new Pelicula(id, nombre, duracion, genero));
        } else if (tipo == "Serie") {
            auto* serie = new Serie(id, nombre, duracion, genero);
            while (std::getline(inFile, linea)) {
                if (linea.empty()) break;
                std::istringstream issEp(linea);
                std::string titulo;
                issEp >> temporada >> duracion;
                titulo = readQuotedString(issEp);
                Episodio episodio(titulo, temporada, duracion);
                serie->agregarEpisodio(episodio);
            }
            series.push_back(serie);
            videos.push_back(serie);
        }
    }

    inFile.close();
    return true;
}

void mostrarVideosConCriterio(const std::vector<Video*>& videos, float calificacion, const std::string& genero) {
    for (const auto& video : videos) {
        if ((calificacion == 0.0 || video->calcularCalificacionPromedio() >= calificacion) &&
            (genero.empty() || video->getGenero() == genero)) {
            video->mostrar();
        }
    }
}

void mostrarEpisodiosConCalificacion(const std::vector<Serie*>& series, const std::string& nombreSerie, float calificacion) {
    for (const auto& serie : series) {
        if (serie->getNombre() == nombreSerie) {
            serie->mostrarEpisodiosConCalificaciones(calificacion);
        }
    }
}

void mostrarPeliculasConCalificacion(const std::vector<Video*>& videos, float calificacion) {
    for (const auto& video : videos) {
        Pelicula* pelicula = dynamic_cast<Pelicula*>(video);
        if (pelicula && pelicula->calcularCalificacionPromedio() >= calificacion) {
            pelicula->mostrar();
        }
    }
}

void calificarVideo(std::vector<Video*>& videos, const std::string& nombre, int calificacion) {
    for (auto& video : videos) {
        if (video->getNombre() == nombre) {
            video->agregarCalificacion(calificacion);
            std::cout << "Calificación agregada.\n";
            return;
        }
    }
    std::cout << "Video no encontrado.\n";
}
