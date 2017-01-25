// Projekt z informatyki v2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <cstdlib>
#include "Windows.h"
#include <iomanip>



struct book
{
	std::string autor;
	std::string tytul;
	std::string wydawca;
	int rok_wydania;
	int ilosc_stron;
	int id;
	bool czy_wypozyczona=false;
	book *next;
	book *prev;
	
};
struct person
{
	std::string imie;
	std::string nazwisko;
	int rok_urodzenia;
	int id;
	person *next;
	person *prev;
};

void add_to_library(book *&first_book, book *&last_book, int &idbook, int &number_of_book);
void delete_from_library(book *&first_book, book *&last_book);
void search_in_library(book *&first_book, book *&last_book, int &number_of_book);
void show_all_book(book *&first_book, int &number_of_book);

void add_person(person *&first_person, person *&last_person, int &number_of_person, int &idperson);
void deleta_person(person *&first_person, person *&last_person);
void search_personal_data(person *&first_person,person *&last_person, int &number_person);
void show_all_person(person *&first_person, int *&number_of_person);

void show_all_options(void);
bool choose(book *&first_book, book *&last_book, person *&first_person, person *&last_person, int &number_of_person, int &idmax, int &idperson, int &number_of_book);
void wypozyczanie();

int main()
{
	book *first_book= nullptr;
	book *last_book = nullptr;
	person *first_person = nullptr;
	person *last_person = nullptr;
	int number_of_book = 0; 
	int number_of_person = 0;
	int idbook = 0;
	int idperson = 0;
	bool end_program = false;
		while (end_program == false)
		{
			show_all_options();
			end_program = choose(first_book, last_book, first_person, last_person, number_of_person, idbook, idperson, number_of_book);

		}
	
	//wczytaj_liste_ksiazek(first_book, last_book);
	//wczytaj_liste_uzytkownikow(first_person,last_person);
	


	//zapisz_liste_ksiazek(first_book, last_book);
	//zapisz_liste_uzytkownikow(first_person, last_person);

    return 0;
}
void add_to_library(book *&first_book, book *&last_book, int &idbook, int &number_of_book )
{
	book *new_book;
	new_book = new book;

	std::cout << "Wprowadz autora: ";
	getline(std::cin, new_book->autor);
	std::cout << "Wprowadz tytul ksiazki: ";
	getline(std::cin, new_book->tytul);
	std::cout << "Wprowadz wydawce: " ;
	getline(std::cin, new_book->wydawca);
	std::cout << "Wprowadz rok wydania: " ;
	std::cin >> new_book->rok_wydania;
	std::cout << "Wprowadz ilosc stron: " ;
	std::cin >> new_book->ilosc_stron;
	new_book->id = idbook;
	idbook++;

	new_book->prev = last_book;
	if (last_book != nullptr)
	{
		last_book->next = new_book;
	}
	else
		first_book = new_book;
	last_book = new_book;
	number_of_book++;
}
void search_in_library(book *&first_book, book *&last_book, int &number_of_book)
{


}
void delete_from_library(book *&first_book, book *&last_book)
{


}
void add_person(person *&first_person, person *&last_person, int &idperson, int &number_of_person)
{
	person *new_person;
	new_person = new person;

	std::cout << "Podaj imiê: ";
	getline(std::cin, new_person->imie);
	std::cout << "Podaj Nazwisko: ";
	getline(std::cin, new_person->nazwisko);
	std::cout << "Podaj rok urodzenia: ";
	std::cin >> new_person->rok_urodzenia;
	new_person->id = idperson;
	idperson++;
	new_person->prev = last_person;
	if (last_person != nullptr)
	{
		last_person->next = new_person;
	}
	else
		first_person = new_person;
		last_person = new_person;
		number_of_person++;
}
void show_all_book(book *&first_book, int &number_of_book)
{
	if (number_of_book> 0) {
		book * books= first_book;
		std::cout << std::setw(30) << "autor: " << std::setw(30) << "tytul: " << std::setw(30) << "wydawca: " << std::setw(5) <<"rok wydania: " << std::setw(5) << "ilosc stron: " << std::setw(4) << "id: "<< std::endl;
		while (books != nullptr) 
		{
			std::cout <<std::setw(30) << books->autor <<std::setw(30) << books->tytul<< std::setw(30) << books->wydawca << std::setw(5) << books->rok_wydania << std::setw(5) << books->ilosc_stron << std::setw(4) << books->id << std::endl;
			books = books->next;
		}
	}
	else
		std::cout << "Nie ma zadnych ksiazek na liscie." << std::endl;

}
void show_all_person(person *&first_person, int &number_of_person)
{
	if (number_of_person> 0) 
	{
		person *persons = first_person;
		std::cout << std::setw(30) << "imie " << std::setw(30) << "nazwisko " << std::setw(5) << "rok urodzenia: " << std::setw(4) << "id: " << std::endl;
		while (persons != nullptr)
		{
			std::cout << std::setw(30) << persons->imie << std::setw(30) << persons->nazwisko << std::setw(5) << persons->rok_urodzenia << std::setw(4) <<persons->id  << std::endl;
			persons=persons->next;
		}
	}
	else
		std::cout << "Nie ma zadnych ksiazek na liscie." << std::endl;
}
void show_all_options(void)
{
	std::cout << "Wpisz" << std::endl;
	std::cout << "1-wyswietl wszystkie ksiazki w bibliotece" << std::endl;
	std::cout << "2-dodaj ksiazke" << std::endl;
	std::cout << "3-usun ksiazke" << std::endl;
	std::cout << "4-wyszukaj ksiazke" << std::endl;
	std::cout << "5-wyswietl wszystkich uzytkownikow" << std::endl;
	std::cout << "6-dodaj uzytkownika" << std::endl;
	std::cout << "7-usun uzytkownika" << std::endl;
	std::cout << "8-wyszukaj uzytkownika uzytkownika" << std::endl;
	std::cout << "9-zamknij program" << std::endl;

}
bool choose(book *&first_book, book *&last_book, person *&first_person, person *&last_person, int &number_of_person, int &idbook, int &idperson, int &number_of_book)
{
	
	switch
	{
	case 1:
		show_all_book(first_book, number_of_book);
		char back;
		std::cout << "nacisnij 'w' aby wrocic: ";
		std::cin >> back;
		while (back != 'w') 
		{
			std::cout <<"sprobuj ponownie :)" << std::endl;
			std::cin >> back;
		}
		return false;
	case 2:
		add_to_library(first_book, last_book, idbook, number_of_book);
		return false;
	case 3:
		delete_from_library(first_book, last_book);
		return false;
	case 4:
		search_in_library(first_book, last_book, number_of_book);
		return false;
	case 5:
		show_all_person(first_person, number_of_person);
		char back_person;
		std::cout << "nacisnij 'w' aby wrocic: ";
		std::cin >> back_person;
		while (back_person != 'w')
		{
			std::cout << "sprobuj ponownie :)" << std::endl;
			std::cin >> back_person;
		}
		return false;
	case 6:
		add_person(first_person, last_person, idperson, number_of_person);
		return false;
	case 7:
		deleta_person(first_person, last_person);
		return false;
	case 8:
		search_personal_data(first_person, last_person, number_of_person);
		return false;
	case 9:
		return true;
	}

}
