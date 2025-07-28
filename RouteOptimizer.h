//
// Created by Elishama Vayanza on 22/07/2025.
//

#ifndef ROUTEOPTIMIZATION_ROUTEOPTIMIZER_H
#define ROUTEOPTIMIZATION_ROUTEOPTIMIZER_H

#include "Itineraire.h"
#include <vector>

/**
 * @class RouteOptimizer
 * @brief Classe utilitaire pour gérer une collection d'itinéraires et effectuer des analyses.
 *
 * Cette classe permet d'ajouter des itinéraires, d'afficher tous les itinéraires
 * enregistrés, et de déterminer les itinéraires les plus courts et les plus longs.
 */
class RouteOptimizer {
private:
    std::vector<Itineraire> itineraires; ///< Liste des itinéraires enregistrés.

public:
    /**
     * @brief Ajoute un itinéraire à la collection.
     * @param itineraire L'itinéraire à ajouter.
     */
    void ajouterItineraire(const Itineraire& itineraire);

    /**
     * @brief Trouve les itinéraires le plus court et le plus long parmi ceux enregistrés.
     * @param plusCourt Référence de sortie vers l'itinéraire le plus court.
     * @param plusLong Référence de sortie vers l'itinéraire le plus long.
     */
    void trouverItinerairesExtremes(Itineraire& plusCourt, Itineraire& plusLong) const;

    /**
     * @brief Affiche les détails de tous les itinéraires dans la console.
     */
    void afficherTousItineraires() const;
};

#endif //ROUTEOPTIMIZATION_ROUTEOPTIMIZER_H
