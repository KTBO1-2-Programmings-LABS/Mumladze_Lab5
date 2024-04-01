#pragma once

using namespace System;
using namespace System::IO;
using namespace System::Collections;
using namespace System::Collections::Generic;

// Перечислений форматов данных (связь, книга, дисциплина)
enum DataType {
	T_LINK = 0,
	T_BOOK = 1,
	T_SUBJECT = 2
};

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

// Класс, управляющий данными о книгах, дисциплинах и их связях
ref class DataManager {
private:
	// Путь до файла Links.txt
	String^ fileLinkPath;
	// Путь до файла Books.txt
	String^ fileBookPath;
	// Путь до файла Subjects.txt
	String^ fileSubjectPath;
	// Список объектов Link
	List<Object^>^ listLinks;
	// Список объектов Book
	List<Object^>^ listBooks;
	// Список объектов Subject
	List<Object^>^ listSubjects;

public:
	// Конструктор класса
	DataManager();
	// Прочитать данные из файлов в списки
	void ReadDataFiles();
	// Записать данные из списков в файлы
	void WriteDataFiles();
	// Преобразовать строку данных в Object
	Object^ MakeNode(DataType, String^);
	// Добавить запись в список
	void AddNode(DataType, Object^);
	// Удалить запись из списка
	void DeleteNode(DataType, Object^);
	// Найти запись в списке
	List<Object^>^ FindNodes(DataType, String^);
};