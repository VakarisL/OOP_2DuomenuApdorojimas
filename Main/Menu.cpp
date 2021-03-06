#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <algorithm>

#include "../Main/Headers/Menu.h"
#include "../Main/Headers/MathFunctions.h"


void InitialInfo(std::string& vardas, std::string& pavarde) {
	std::cout << "Iveskite studento varda: " << std::endl;
	std::cin >> vardas;
	std::cout << "Iveskite studento pavarde: " << std::endl;
	std::cin >> pavarde;
}

void MainMenu(int& choice) {
	do {
		std::cout << "Ar norite:" << std::endl;
		std::cout << "1- Irasyti pazymius ranka;" << std::endl;
		std::cout << "2- Generuoti atsitiktinius pazymius;" << std::endl;
		std::cout << "3- Skaityti pazymius is failo;" << std::endl;
		std::cout << "4- Generuoti 10/100/.../100000 irasu ir matuoti veikimo laika;" << std::endl;
		std::cout << "5- Generuoti 10/100/.../100000 irasu ir matuoti veikimo laika naudojant du papildomus konteinerius;" << std::endl;
		std::cout << "6- Generuoti 10/100/.../100000 irasu ir matuoti veikimo laika naudojant viena papildoma konteineri;" << std::endl;
		std::cout << "7- Iseiti..." << std::endl;
		if (!(std::cin >> choice)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		};
	} while (choice < 1 || choice > 7 );
}

void output(studentaiInfo& studentas) {
	studentas.average = 0.4 * darbuVidurkis(studentas.nDarbai) + studentas.egzaminas * 0.6;
	studentas.median = 0.4 * darbuMediana(studentas.nDarbai) + studentas.egzaminas * 0.6;

	std::cout << std::endl;
	std::cout << "Studento info:" << std::endl;
	std::cout << studentas.vardas << " " << studentas.pavarde << std::endl;
	int counter = 0;
	for (auto i : studentas.nDarbai) {
		std::cout << "Namu darbu " << ++counter << " pazymys: " << i << std::endl;
	}
	std::cout << "Egzamino pazymys: " << studentas.egzaminas << std::endl;
	std::cout << "Galutinis balas (naudojant vidurki): " << std::setprecision(2) << std::fixed << studentas.average << std::endl;
	std::cout << "Galutinis balas (naudojant mediana): " << std::setprecision(2) << std::fixed << studentas.median << std::endl;
}

void output(std::vector<studentaiInfo>& studentai) {
	std::sort(studentai.begin(), studentai.end(), compareNames);
	std::cout << std::endl;
	std::cout << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) <<
	          "Galutinis-Vidurkis" << std::setw(20) << "Galutinis-Mediana" << std::endl;
	for (size_t i = 0; i < studentai.size(); i++) {
		std::cout << std::left << std::setw(20) << studentai[i].pavarde << std::setw(20) << studentai[i].vardas <<
		          std::setprecision(2) << std::fixed << std::setw(20) << 0.4 * studentai[i].average + studentai[i].egzaminas * 0.6 <<
		          std::setw(20) << 0.4 * studentai[i].median + studentai[i].egzaminas * 0.6 << std::endl;
	}
}

bool compareNames(const studentaiInfo& a, const studentaiInfo& b) {return a.vardas < b.vardas;}