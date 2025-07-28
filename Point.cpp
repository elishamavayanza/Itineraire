//
// Created by Elishama Vayanza on 22/07/2025.
//

#include "Point.h"
#include <cmath>

/**
 * @brief Implémentation du constructeur de la classe Point.
 */
Point::Point(double x, double y, double z) : x(x), y(y), z(z) {}

/**
 * @brief Retourne la coordonnée x.
 */
double Point::getX() const { return x; }

/**
 * @brief Retourne la coordonnée y.
 */
double Point::getY() const { return y; }

/**
 * @brief Retourne la coordonnée z.
 */
double Point::getZ() const { return z; }

/**
 * @brief Définit une nouvelle valeur pour x.
 */
void Point::setX(double newX) { x = newX; }

/**
 * @brief Définit une nouvelle valeur pour y.
 */
void Point::setY(double newY) { y = newY; }

/**
 * @brief Définit une nouvelle valeur pour z.
 */
void Point::setZ(double newZ) { z = newZ; }

/**
 * @brief Calcule la distance euclidienne entre ce point et un autre.
 */
double Point::distanceTo(const Point& other) const {
    return sqrt(pow(other.x - x, 2) + pow(other.y - y, 2) + pow(other.z - z, 2));
}