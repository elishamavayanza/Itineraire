#include <iostream>
#include <vector>
#include <locale>
#include <clocale>
#include <limits> // Pour std::numeric_limits
#include "Point.h"
#include "Itineraire.h"
#include "RouteOptimizer.h"

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

/**
 * @brief Configure la console pour supporter les caractères UTF-8.
 *
 * Fonction utile pour garantir que les caractères spéciaux s'affichent correctement,
 * notamment sur Windows.
 */
void configurerConsolePourUTF8() {
    // Configuration pour Windows
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    #endif

    // Configuration cross-platform
    try {
        setlocale(LC_ALL, ".UTF-8");
        ios_base::sync_with_stdio(false);
        cin.imbue(locale(".UTF-8"));
        cout.imbue(locale(".UTF-8"));
    } catch (const exception& e) {
        setlocale(LC_ALL, "C");
    }
}

/**
 * @brief Affiche un en-tête stylisé en console.
 */
void afficherEnTete() {
    cout << "==========================================\n";
    cout << "  OPTIMISATION D'ITINÉRAIRE - CALCULATEUR\n";
    cout << "==========================================\n\n";
}

/**
 * @brief Vide le buffer d'entrée pour éviter les erreurs de saisie.
 *
 * Utilisé après une saisie incorrecte pour nettoyer l'entrée standard.
 */
void viderBufferEntree() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/**
 * @brief Demande à l'utilisateur de saisir une coordonnée (x, y ou z).
 *
 * @param prompt Le texte affiché pour guider l'utilisateur.
 * @param coord Référence vers la variable où stocker la valeur saisie.
 * @return true si la saisie est correcte, false sinon (réessaie en boucle).
 */
bool saisirCoordonnee(const string& prompt, double& coord) {
    while (true) {
        cout << prompt;
        if (cin >> coord) {
            return true;
        } else {
            cout << "Erreur: Veuillez entrer un nombre valide.\n";
            viderBufferEntree();
        }
    }
}

/**
 * @brief Saisit les coordonnées d'un point en trois dimensions.
 *
 * @param nomPoint Le nom du point (ex: "Point de départ").
 * @param numeroPoint Un numéro optionnel pour identifier les points intermédiaires.
 * @return Le point saisi par l'utilisateur.
 */
Point saisirPoint(const string& nomPoint, int numeroPoint = 0) {
    double x, y, z;

    if (numeroPoint > 0) {
        cout << "\n  POINT " << numeroPoint << ":\n";
        cout << "  ---------\n";
    } else {
        cout << "\n" << nomPoint << ":\n";
    }

    while (!saisirCoordonnee("  Coordonnée x (m): ", x));
    while (!saisirCoordonnee("  Coordonnée y (m): ", y));
    while (!saisirCoordonnee("  Coordonnée z (m): ", z));

    return Point(x, y, z);
}

/**
 * @brief Permet à l'utilisateur de saisir un itinéraire entre deux points.
 *
 * @param depart Le point de départ.
 * @param arrivee Le point d'arrivée.
 * @param numero Le numéro de l'itinéraire (à des fins d'affichage).
 * @return L'itinéraire complet incluant les points intermédiaires.
 */
Itineraire saisirItineraire(const Point& depart, const Point& arrivee, int numero) {
    Itineraire itineraire;
    itineraire.ajouterPoint(depart);

    cout << "\n═══ Itinéraire " << numero << " ═══\n";

    int nbPoints;
    while (true) {
        cout << "Nombre de points intermédiaires (0 si aucun): ";
        if (cin >> nbPoints && nbPoints >= 0) {
            break;
        }
        cout << "Erreur: Veuillez entrer un nombre entier positif.\n";
        viderBufferEntree();
    }

    for (int j = 1; j <= nbPoints; ++j) {
        Point p = saisirPoint("Coordonnées du point", j);
        itineraire.ajouterPoint(p);
    }

    itineraire.ajouterPoint(arrivee);
    return itineraire;
}

/**
 * @brief Point d'entrée principal de l'application.
 *
 * Ce programme permet à l'utilisateur de saisir plusieurs itinéraires entre deux points
 * et d'afficher les itinéraires les plus courts et les plus longs.
 *
 * @return 0 en cas de succès.
 */
int main() {
    configurerConsolePourUTF8();
    afficherEnTete();

    // Saisie des points de départ et d'arrivée
    cout << "SAISIE DES POINTS EXTREMES\n";
    cout << "--------------------------\n";
    Point depart = saisirPoint("1. Point de départ (A)");
    Point arrivee = saisirPoint("2. Point d'arrivée (B)");

    // Saisie du nombre d'itinéraires
    int nbItineraires;
    while (true) {
        cout << "\nNombre d'itinéraires possibles entre A et B: ";
        if (cin >> nbItineraires && nbItineraires > 0) {
            break;
        }
        cout << "Erreur: Veuillez entrer un nombre entier positif.\n";
        viderBufferEntree();
    }

    // Saisie des itinéraires
    RouteOptimizer optimizer;
    for (int i = 0; i < nbItineraires; ++i) {
        optimizer.ajouterItineraire(saisirItineraire(depart, arrivee, i+1));
    }

    // Affichage des résultats
    cout << "\n══════════ RÉSULTATS ══════════\n";
    optimizer.afficherTousItineraires();

    Itineraire plusCourt, plusLong;
    optimizer.trouverItinerairesExtremes(plusCourt, plusLong);

    cout << "\n★ Itinéraire le plus court:\n";
    plusCourt.afficherDetails();

    cout << "\n★ Itinéraire le plus long:\n";
    plusLong.afficherDetails();

    cout << "\n═══════════════════════════════\n";
    cout << "Merci d'avoir utilisé notre système d'optimisation d'itinéraires!\n";

    return 0;
}