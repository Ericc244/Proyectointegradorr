#include "Video.h"
#include "Pelicula.h"
#include "Serie.h"
#include "FuncionesAuxiliares.h"
#include <limits>

int main() {
    std::vector<Video*> videos;
    std::vector<Serie*> series;
    int opcion = -1;

    while (opcion != 0) {
        std::cout << "Menu:\n"
                  << "1. Cargar archivo de datos\n"
                  << "2. Mostrar los videos en general con una cierta calificación o de un cierto género\n"
                  << "3. Mostrar los episodios de una determinada serie con una calificación determinada\n"
                  << "4. Mostrar las películas con cierta calificación\n"
                  << "5. Calificar un video\n"
                  << "0. Salir\n"
                  << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                std::string archivo;
                std::cout << "Ingrese el nombre del archivo: ";
                std::cin >> archivo;
                if (cargarDatos(archivo, videos, series)) {
                    std::cout << "Datos cargados exitosamente.\n";
                } else {
                    std::cerr << "Error al cargar los datos.\n";
                }
                break;
            }
            case 2: {
                float calificacion = 0.0;
                std::string genero;
                std::cout << "Ingrese la calificación mínima (0 para ignorar): ";
                std::cin >> calificacion;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // limpiar el buffer
                std::cout << "Ingrese el género (presione Enter para ignorar): ";
                std::getline(std::cin, genero);
                mostrarVideosConCriterio(videos, calificacion, genero);
                break;
            }
            case 3: {
                std::string nombreSerie;
                float calificacion = 0.0;
                std::cout << "Ingrese el nombre de la serie: ";
                std::cin.ignore();
                std::getline(std::cin, nombreSerie);
                std::cout << "Ingrese la calificación mínima: ";
                std::cin >> calificacion;
                mostrarEpisodiosConCalificacion(series, nombreSerie, calificacion);
                break;
            }
            case 4: {
                float calificacion = 0.0;
                std::cout << "Ingrese la calificación mínima: ";
                std::cin >> calificacion;
                mostrarPeliculasConCalificacion(videos, calificacion);
                break;
            }
            case 5: {
                std::string nombre;
                int calificacion;
                std::cout << "Ingrese el nombre del video a calificar: ";
                std::cin.ignore();
                std::getline(std::cin, nombre);
                std::cout << "Ingrese la calificación (1-5): ";
                std::cin >> calificacion;
                if (calificacion < 1 || calificacion > 5) {
                    std::cerr << "Calificación no válida. Debe ser entre 1 y 5.\n";
                } else {
                    calificarVideo(videos, nombre, calificacion);
                }
                break;
            }
            case 0:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cerr << "Opción no válida. Intente nuevamente.\n";
                break;
        }
    }

    // Liberar memoria
    for (auto& video : videos) {
        delete video;
    }

    return 0;
}
