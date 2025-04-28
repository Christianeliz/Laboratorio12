#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Función para buscar coincidencias de patrón en una lista
vector<string> buscarCoincidencias(const vector<string>& lista, const string& patron) {
    vector<string> resultados;
    for (const string& item : lista) {
        if (item.find(patron) != string::npos) {
            resultados.push_back(item);
        }
    }
    return resultados;
}

int main() {
    vector<string> nombres = {
        "Alicia", "Roberto", "Alfonso", "Claudia", "Beto", "Albert", "Roberta", "Carla"
    };

    cout << "Ingrese el patron a buscar: ";
    string patron;
    getline(cin, patron);

    vector<string> encontrados = buscarCoincidencias(nombres, patron);

    cout << "\nResultados encontrados:\n";
    for (const string& nombre : encontrados) {
        cout << "- " << nombre << endl;
    }

    if (encontrados.empty()) {
        cout << "No se encontraron coincidencias." << endl;
    }

    return 0;
}
