#include "Prajitura.h"

Prajitura::Prajitura() {
	this->id = 0;
	this->nume = NULL;
	this->ingrediente = NULL;
	this->pret = 0.0;
}

Prajitura::Prajitura(int id, char* nume, char* ingrediente, double pret) {
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
	if (this->nume != NULL) {
		delete[] this->nume;
		this->nume = NULL;
	}
	if (this->ingrediente != NULL) {
		delete[] this->ingrediente;
		this->ingrediente = NULL;
	}
	this->id = 0;
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

void Prajitura::setNume(char* nume) {
	if (this->nume != NULL)
		delete[] this->nume;
	if (nume != NULL) {
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
	}
	else
		this->nume = NULL;
}

void Prajitura::setIngrediente(char* ingrediente) {
	if (this->ingrediente != NULL)
		delete[] this->ingrediente;
	if (ingrediente != NULL) {
		this->ingrediente = new char[strlen(ingrediente) + 1];
		strcpy_s(this->ingrediente, strlen(ingrediente) + 1, ingrediente);
	}
	else
		this->ingrediente = NULL;
}

void Prajitura::setPret(double pret) {
	this->pret = pret;
}

bool Prajitura::operator==(const Prajitura& p) {
	return (this->id == id) && (strcmp(this->nume, p.nume) == 0) && (strcmp(this->ingrediente, p.ingrediente)==0) && (this->pret == pret);
}

Prajitura& Prajitura::operator=(const Prajitura& p) {
	this->setId(p.id);
	this->setNume(p.nume);
	this->setIngrediente(p.ingrediente);
	this->setPret(p.pret);
	return *this;
}

ostream& operator<<(ostream& os, const Prajitura& p) {
	os << "Id: " << p.id << ", nume: " << p.nume << ", ingredinte: " << p.ingrediente << ", pret: " << p.pret << endl;
	return os;
}

istream& operator>>(istream& is, Prajitura& p) {
	if (p.nume == NULL)
		p.nume = new char[20];
	if (p.ingrediente == NULL)
		p.ingrediente = new char[30];
	is >> p.id >> p.nume >> p.ingrediente >> p.pret;
	return is;
}