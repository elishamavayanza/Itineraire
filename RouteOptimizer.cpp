//
// Created by Elishama Vayanza on 22/07/2025.
//

#include "RouteOptimizer.h"

#include <iostream>
#include <limits>


/**
 * @brief Ajoute un itinéraire à la liste.
 */
void RouteOptimizer::ajouterItineraire(const Itineraire& itineraire) {
    itineraires.push_back(itineraire);
}

/**
 * @brief Trouve les itinéraires extrêmes (plus court et plus long).
 *
 * Utilise la longueur totale de chaque itinéraire pour déterminer ceux ayant la distance
 * minimale et maximale.
 */
void RouteOptimizer::trouverItinerairesExtremes(Itineraire& plusCourt, Itineraire& plusLong) const {
    if (itineraires.empty()) return;

    double minLongueur = std::numeric_limits<double>::max();
    double maxLongueur = std::numeric_limits<double>::min();
    size_t indexCourt = 0, indexLong = 0;

    for (size_t i = 0; i < itineraires.size(); ++i) {
        double longueur = itineraires[i].calculerLongueur();
        if (longueur < minLongueur) {
            minLongueur = longueur;
            indexCourt = i;
        }
        if (longueur > maxLongueur) {
            maxLongueur = longueur;
            indexLong = i;
        }
    }

    plusCourt = itineraires[indexCourt];
    plusLong = itineraires[indexLong];
}

/**
 * @brief Affiche chaque itinéraire avec ses détails.
 */
void RouteOptimizer::afficherTousItineraires() const {
    for (size_t i = 0; i < itineraires.size(); ++i) {
        std::cout << "Itinéraire " << i+1 << ":\n";
        itineraires[i].afficherDetails();
    }
}