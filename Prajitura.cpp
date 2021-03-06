#include "Prajitura.h"

Prajitura::Prajitura() {
	this->id = 0;
	this->nume = NULL;
	this->ingrediente = NULL;
	this->pret = 0.0;
}

Prajitura::Prajitura(int id,  char* nume,  char* ingrediente, double pret) {
	this->id = id;
	this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, strlen(nume) + 1, nume);
	this->ingrediente = new char[strlen(ingrediente) + 1];
	strcpy_s(this->ingrediente, strlen(ingrediente) + 1, ingrediente);
	this->pret = pret;
}

Prajitura::Prajitura(const Prajitura& p) {
	this->id = p.id;
	this->nume = new char[strlen(p.nume) + 1];
	strcpy_s(this->nume, strlen(p.nume) + 1, p.nume);
	this->ingrediente = new char[strlen(p.ingrediente) + 1];
	strcpy_s(this->ingrediente, strlen(p.ingrediente) + 1, p.ingrediente);
	this->pret = p.pret;
}

Prajitura::~Prajitura() {
	this->id = 0;
	this->ingrediente = NULL;
	this->nume = NULL;
	this->pret = 0.0;
}


int Prajitura::getId() {
	return this->id;
}

char* Prajitura::getNume() {
	return this->nume;
}

char* Prajitura::getIngrediente() {
	return this->ingrediente;
}

double Prajitura::getPret() {
	return this->pret;
}


void Prajitura::setId(int id) {
	this->id = id;
}

void Prajitura::setNume( char* nume) {
	if (this->nume) {
		delete[] this->nume;
	}
	this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, strlen(nume) + 1, nume);
}

void Prajitura::setIngrediente( char* ingrediente) {
	if (this->ingrediente) {
		delete[] this->ingrediente;
	}
	this->ingrediente = new char[strlen(ingrediente) + 1];
	strcpy_s(this->ingrediente, strlen(ingrediente) + 1, ingrediente);
}

void Prajitura::setPret(double pret) {
	this->pret = pret;
}

/*void Prajitura::toString(string info) {
	int info1 = info.length() - 1;
	int info2 = info.length() - 1;
	while (info[info1] != '|')
		info1--;
	this->setPret(stod(info.substr(info1 + 1, info2 - info1 + 1)));
	info1--;
	info2 = info1;
	while (info[info1] != '|')
		info1--;
	this->setIngrediente(info.substr(info1 + 1, info2 - info1).c_str());

}*/

bool Prajitura::operator==(const Prajitura& p) {
	return (this->id == p.id) && (strcmp(this->nume, p.nume)==0) && (strcmp(this->ingrediente, p.ingrediente)==0) && (abs(this->pret-p.pret)<0.0001);
}

Prajitura& Prajitura::operator=(const Prajitura& p) {
	this->setId(p.id);
	this->setNume(p.nume);
	this->setIngrediente(p.ingrediente);
	this->setPret(p.pret);
	return *this;
}

bool Prajitura::operator!=(const Prajitura& p) {
	return !(Prajitura::operator==(p));
}

ostream& operator<<(ostream& os, const Prajitura& p) {
	os << p.id <<" "<< p.nume <<" "<< p.ingrediente <<" " <<p.pret << endl;
	return os;
}

istream& operator>>(istream& is, Prajitura& p) {
	if (p.nume == NULL)
		p.nume = new char[30];

	if (p.ingrediente == NULL)
		p.ingrediente = new char[40];

	is >> p.id >> p.nume >> p.ingrediente >> p.pret;

	return is;
}