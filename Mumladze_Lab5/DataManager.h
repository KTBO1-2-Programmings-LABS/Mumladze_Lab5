using namespace System;
using namespace System::IO;
using namespace System::Collections;
using namespace System::Collections::Generic;

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

// �����, ����������� ����������� � ������ {�����, ����������}
ref class LinkManager {
private:
	// ��� ����� � ������� � ������
	String^ fileName;
	// ������ ������ {�����, ����������}
	List<Object^>^ links;
public:
	// ����������� ������
	LinkManager();
	// ������ ������ ������ �� �����
	void ReadLinkListFromFile(void);
	// ������ ������ ������ � ����
	void WriteLinkListToFile(void);
	// �������� ����� � ������
	void AddLinkToList(String^);
	// ������� ����� �� ISBN � dis_code
	void RemoveLinkFromList(String^, String^);
	// ������� ��� ����� �� ����� (����� ������ BookManager ��� ��������)
	void RemoveAllLinksByBook(String^);
	// ������� ��� ����� �� ���������� (����� ������ SubjectManager ��� ��������)
	void RemoveAllLinksBySubject(String^);
	// ����� ����� �� �����
	List<Object^>^ FindSubjectsByBook(String^);
	// ����� ����� �� ����������
	List<Object^>^ FindBooksBySubject(String^);
};

// �����, ����������� ����������� � ������
ref class BookManager {
private:
	// ��� ����� � ������� � ������
	String^ fileName;
	// ������ ����
	List<Object^>^ books;
	// ��������� �� ������ ������ LinkManager
	LinkManager^ lm;
public:
	// ����������� ������
	BookManager(LinkManager^);
	// ������ ������ ���� �� �����
	void ReadBookListFromFile(void);
	// ������ ������ ���� � ����
	void WriteBookListToFile(void);
	// ���������� ����� � ������ (������ ���� �� �������)
	void AddBookToList(String^);
	// �������� ����� �� ������ (�� ISBN ����)
	void RemoveBookFromList(String^);
	// �������� ISBN ��� ����� �� �� ��������
	String^ FindISBNByName(String^);
};

// �����, ����������� ����������� � �����������
ref class SubjectManager {
private:
	// ��� ����� � ������� � ������
	String^ fileName;
	// ������ ���������
	List<Object^>^ subjects;
	// ��������� �� ������ ������ LinkManager
	LinkManager^ lm;
public:
	// ����������� ������
	SubjectManager(LinkManager^);
	// ������ ������ ��������� �� �����
	void ReadSubjectListFromFile(void);
	// ������ ������ � ����
	void WriteSubjectListToFile(void);
	// ���������� ����� � ������
	void AddSubjectToList(String^);
	// �������� ����� �� ������ (�� ���� ����������)
	void RemoveSubjectFromList(String^);
	// �������� ��� ���������� �� �� ��������
	String^ FindDisCodeByName(String^);
};