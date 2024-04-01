#pragma once

using namespace System;
using namespace System::IO;
using namespace System::Collections;
using namespace System::Collections::Generic;

// ������������ �������� ������ (�����, �����, ����������)
enum DataType {
	T_LINK = 0,
	T_BOOK = 1,
	T_SUBJECT = 2
};

// ��������� ������ ����� {�����, ����������}
ref struct Link {
	String^ ISBN;
	String^ dis_code;
};

// ��������� ������ ����� �����
ref struct Book {
	String^ ISBN;
	String^ title;
	String^ author;
};

// ��������� ������ ����� ����������
ref struct Subject {
	String^ dis_code;
	String^ name;
	String^ description;
};

// �����, ����������� ������� � ������, ����������� � �� ������
ref class DataManager {
private:
	// ���� �� ����� Links.txt
	String^ fileLinkPath;
	// ���� �� ����� Books.txt
	String^ fileBookPath;
	// ���� �� ����� Subjects.txt
	String^ fileSubjectPath;
	// ������ �������� Link
	List<Object^>^ listLinks;
	// ������ �������� Book
	List<Object^>^ listBooks;
	// ������ �������� Subject
	List<Object^>^ listSubjects;

public:
	// ����������� ������
	DataManager();
	// ��������� ������ �� ������ � ������
	void ReadDataFiles();
	// �������� ������ �� ������� � �����
	void WriteDataFiles();
	// ������������� ������ ������ � Object
	Object^ MakeNode(DataType, String^);
	// �������� ������ � ������
	void AddNode(DataType, Object^);
	// ������� ������ �� ������
	void DeleteNode(DataType, Object^);
	// ����� ������ � ������
	List<Object^>^ FindNodes(DataType, String^);
};