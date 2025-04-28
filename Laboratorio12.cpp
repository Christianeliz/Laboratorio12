#include <iostream>  
#include <fstream>  
#include <string>  
#include <map>  
#include <vector>  
#include <sstream>  
#include <algorithm>  

using namespace std;

// Cargar la base de conocimiento desde un archivo  
map<string, string> cargarBaseDeConocimiento(const string& archivo) {
    map<string, string> baseDeConocimiento;
    ifstream file(archivo);
    string linea;

    while (getline(file, linea)) {
        size_t separador = linea.find('|');
        if (separador != string::npos) {
            string pregunta = linea.substr(0, separador);
            string respuesta = linea.substr(separador + 1);
            baseDeConocimiento[pregunta] = respuesta;
        }
    }

    return baseDeConocimiento;
}

// Búsqueda exacta  
string busquedaExacta(const map<string, string>& baseDeConocimiento, const string& pregunta) {
    auto it = baseDeConocimiento.find(pregunta);
    if (it != baseDeConocimiento.end()) {
        return it->second;
    }
    return "";
}

// Búsqueda por palabras clave  
string busquedaPorPalabrasClave(const map<string, string>& baseDeConocimiento, const string& pregunta) {
    vector<string> palabrasPregunta;
    istringstream stream(pregunta);
    string palabra;

    while (stream >> palabra) {
        palabrasPregunta.push_back(palabra);
    }

    for (const auto& par : baseDeConocimiento) {
        for (const auto& palabra : palabrasPregunta) {
            if (par.first.find(palabra) != string::npos) {
                return par.second;
            }
        }
    }

    return "";
}

int main() {
    string archivo = "conocimiento.txt";
    map<string, string> baseDeConocimiento = cargarBaseDeConocimiento(archivo);

    cout << "Chatbot iniciado. Escribe tu pregunta (escribe 'salir' para terminar):" << endl;
    string pregunta;

    while (true) {
        cout << "> ";
        getline(cin, pregunta);

        if (pregunta == "salir") {
            break;
        }

        string respuesta = busquedaExacta(baseDeConocimiento, pregunta);

        if (respuesta.empty()) {
            respuesta = busquedaPorPalabrasClave(baseDeConocimiento, pregunta);
        }

        if (respuesta.empty()) {
            cout << "Lo siento, no tengo una respuesta para esa pregunta." << endl;
        }
        else {
            cout << respuesta << endl;
        }
    }

    return 0;
}