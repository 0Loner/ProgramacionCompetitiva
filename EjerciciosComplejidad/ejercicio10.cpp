#include <iostream>
#include <regex>

int main() {
    std::string s = "línea: a70 y z72 serán sustituidas, aa24 y a872 no";
    std::regex word_regex("[a-z][0-9]{2}"); // Expresión regular para buscar palabras especiales

    // Utilizamos std::regex_replace para reemplazar todas las palabras especiales con "***"
    std::string result = std::regex_replace(s, word_regex, "***");

    std::cout << "Cadena original: " << s << std::endl;
    std::cout << "Cadena transformada: " << result << std::endl;

    return 0;
}

// O(n)