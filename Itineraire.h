//
// Created by Elishama Vayanza on 22/07/2025.
//

#ifndef ROUTEOPTIMIZATION_ITINERAIRE_H
#define ROUTEOPTIMIZATION_ITINERAIRE_H

#include "Point.h"
#include <vector>

/**
 * @class Itineraire
 * @brief Représente un itinéraire constitué d'une suite de points dans l'espace 3D.
 *
 * Cette classe permet d'ajouter des points, de calculer la longueur totale du trajet,
 * d'afficher les détails, et d'obtenir la liste complète des points.
 */
class Itineraire {
private:
    std::vector<Point> points; ///< Liste ordonnée des points composant l'itinéraire.

public:
    /**
     * @brief Constructeur par défaut. Crée un itinéraire vide.
     */
    Itineraire();

    /**
     * @brief Constructeur avec liste de points.
     * @param points Vecteur de points représentant l'itinéraire.
     */
    explicit Itineraire(const std::vector<Point>& points);

    /**
     * @brief Ajoute un point à l'itinéraire.
     * @param point Le point à ajouter à la fin du trajet.
     */
    void ajouterPoint(const Point& point);

    /**
     * @brief Calcule la longueur totale de l'itinéraire.
     * @return Distance totale en mètres.
     */
    double calculerLongueur() const;

    /**
     * @brief Affiche les détails de l'itinéraire dans la console.
     * Inclut les coordonnées des points et une représentation graphique.
     */
    void afficherDetails() const;

    /**
     * @brief Accède à la liste complète des points de l'itinéraire.
     * @return Une référence constante vers le vecteur des points.
     */
    const std::vector<Point>& getPoints() const;
};

#endif //ROUTEOPTIMIZATION_ITINERAIRE_H
