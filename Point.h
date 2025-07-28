//
// Created by Elishama Vayanza on 22/07/2025.
//

#ifndef ROUTEOPTIMIZATION_POINT_H
#define ROUTEOPTIMIZATION_POINT_H

#include <vector>
/**
 * @class Point
 * @brief Représente un point en 3 dimensions (x, y, z) dans un espace cartésien.
 */
class Point {
private:
    double x, y, z; // Coordonnées en mètres

public:
    /**
     * @brief Constructeur du point.
     * @param x Coordonnée x (par défaut 0).
     * @param y Coordonnée y (par défaut 0).
     * @param z Coordonnée z (par défaut 0).
     */
    Point(double x = 0, double y = 0, double z = 0);

    // === Getters ===
    /**
     * @brief Obtient la coordonnée x du point.
     * @return La coordonnée x.
     */
    double getX() const;

    /**
     * @brief Obtient la coordonnée y du point.
     * @return La coordonnée y.
     */
    double getY() const;

    /**
     * @brief Obtient la coordonnée z du point.
     * @return La coordonnée z.
     */
    double getZ() const;

    // === Setters ===

    /**
     * @brief Modifie la coordonnée x du point.
     * @param newX La nouvelle valeur de x.
     */
    void setX(double newX);

    /**
     * @brief Modifie la coordonnée y du point.
     * @param newY La nouvelle valeur de y.
     */
    void setY(double newY);

    /**
     * @brief Modifie la coordonnée z du point.
     * @param newZ La nouvelle valeur de z.
     */
    void setZ(double newZ);


    /**
     * @brief Calcule la distance entre ce point et un autre.
     * @param other Le point de destination.
     * @return La distance en mètres.
     */
    double distanceTo(const Point& other) const;
};

#endif //ROUTEOPTIMIZATION_POINT_H
