#pragma once

using namespace System;
using namespace System::IO;
using namespace System::Collections;
using namespace System::Collections::Generic;

// Структура записи связи {книга, дисциплина}
ref struct Link {
	String^ ISBN;
	String^ dis_code;
};

// Структура записи одной книги
ref struct Book {
	String^ ISBN;
	String^ title;
	String^ author;
};

// Структура записи одной дисциплины
ref struct Subject {
	String^ dis_code;
	String^ name;
	String^ description;
};

// Класс, управляющий информацией о связях {книга, дисциплина}
ref class LinkManager {
public:
	// Имя файла с данными о связях
	String^ fileName;
	// Список связей {книга, дисциплина}
	List<Object^>^ links;
public:
	// Конструктор класса
	LinkManager();
	// Чтение списка связей из файла
	void ReadLinkListFromFile(void);
	// Запись списка связей в файл
	void WriteLinkListToFile(void);
	// Добавить связь в список
	void AddLinkToList(String^);
	// Удалить связь по ISBN и dis_code
	void RemoveLinkFromList(String^, String^);
	// Удалить все связи по книге (через объект BookManager или напрямую)
	void RemoveAllLinksByBook(String^);
	// Удалить все связи по дисциплине (через объект SubjectManager или напрямую)
	void RemoveAllLinksBySubject(String^);
	// Найти связи по книге
	List<Object^>^ FindSubjectsByBook(String^);
	// Найти связи по дисциплине
	List<Object^>^ FindBooksBySubject(String^);
};

// Класс, управляющий информацией о книгах
ref class BookManager {
public:
	// Имя файла с данными о книгах
	String^ fileName;
	// Список книг
	List<Object^>^ books;
	// Указатель на объект класса LinkManager
	LinkManager^ lm;
public:
	// Конструктор класса
	BookManager(LinkManager^);
	// Чтение списка книг из файла
	void ReadBookListFromFile(void);
	// Запись списка книг в файл
	void WriteBookListToFile(void);
	// Добавление книги в список (парсит ввод по запятой)
	void AddBookToList(String^);
	// Удаление книги из списка (по ISBN коду)
	void RemoveBookFromList(String^);
	// Получить ISBN код книги по ее названию
	String^ FindISBNByName(String^);
};

// Класс, управляющий информацией о дисциплинах
ref class SubjectManager {
public:
	// Имя файла с данными о книгах
	String^ fileName;
	// Список дисциплин
	List<Object^>^ subjects;
	// Указатель на объект класса LinkManager
	LinkManager^ lm;
public:
	// Конструктор класса
	SubjectManager(LinkManager^);
	// Чтение списка дисциплин из файла
	void ReadSubjectListFromFile(void);
	// Запись списка в файл
	void WriteSubjectListToFile(void);
	// Добавление книги в список
	void AddSubjectToList(String^);
	// Удаление книги из списка (по коду дисциплины)
	void RemoveSubjectFromList(String^);
	// Получить код дисциплины по ее названию
	String^ FindDisCodeByName(String^);
};