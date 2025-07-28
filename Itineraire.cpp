#include "Itineraire.h"
#include <iostream>
#include <iomanip>
#include <sstream>

/**
 * @brief Constructeur par défaut.
 */
Itineraire::Itineraire() = default;

/**
 * @brief Constructeur avec initialisation directe d'une liste de points.
 */Itineraire::Itineraire(const std::vector<Point>& points) : points(points) {}

/**
 * @brief Ajoute un point à la fin de l'itinéraire.
 */
void Itineraire::ajouterPoint(const Point& point) {
    points.push_back(point);
}

/**
 * @brief Calcule la longueur totale de l'itinéraire (somme des distances entre les points successifs).
 */
double Itineraire::calculerLongueur() const {
    if (points.size() < 2) return 0.0;

    double longueur = 0.0;
    for (size_t i = 0; i < points.size() - 1; ++i) {
        longueur += points[i].distanceTo(points[i+1]);
    }
    return longueur;
}

/**
 * @brief Affiche les informations détaillées de l'itinéraire : points, distance, représentation graphique.
 */
void Itineraire::afficherDetails() const {
    const std::string separator = "\n----------------------------------------\n";

    std::cout << separator;
    std::cout << "  DÉTAILS DE L'ITINÉRAIRE\n";
    std::cout << separator;

    if (points.empty()) {
        std::cout << "   Aucun point dans cet itinéraire.\n";
        std::cout << separator;
        return;
    }

    // Affichage des points avec formatage amélioré
    std::cout << "   Parcours:\n";
    std::cout << "  • Départ (A): (" << points[0].getX() << ", "
              << points[0].getY() << ", " << points[0].getZ() << ")\n";

    for (size_t j = 1; j < points.size(); ++j) {
        if (j == points.size()-1) {
            std::cout << "  • Arrivée (B): (" << points[j].getX() << ", "
                      << points[j].getY() << ", " << points[j].getZ() << ")\n";
        } else {
            std::cout << "  • Étape P" << j << ": (" << points[j].getX() << ", "
                      << points[j].getY() << ", " << points[j].getZ() << ")\n";
        }
    }

    // Affichage de la longueur avec emoji
    std::cout << "\n   Longueur totale: " << std::fixed << std::setprecision(2)
              << calculerLongueur() << " mètres\n";

    // Visualisation graphique améliorée
    std::cout << "\n   Représentation graphique:\n  ";
    std::cout << "A";
    for (size_t j = 1; j < points.size(); ++j) {
        if (j == points.size()-1) {
            std::cout << "━━━━━━━▶ B";
        } else {
            std::cout << "━━━━━━━▶ P" << j;
        }
    }

    std::cout << separator;
}
/**
 * @brief Renvoie la liste des points de l'itinéraire.
 */
const std::vector<Point>& Itineraire::getPoints() const {
    return points;
}