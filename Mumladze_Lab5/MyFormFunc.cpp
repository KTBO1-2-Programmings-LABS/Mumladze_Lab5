#include "MyForm.h"
#include "DataManager.h"

using namespace MumladzeLab5;

MyForm::MyForm() {
	this->lm = gcnew LinkManager();
	this->bm = gcnew BookManager(lm);
	this->sm = gcnew SubjectManager(lm);
	lm->ReadLinkListFromFile();
	bm->ReadBookListFromFile();
	sm->ReadSubjectListFromFile();
	InitializeComponent();
}

MyForm::~MyForm() {
	if (components) {
		delete components;
	}
	delete this->lm;
	delete this->bm;
	delete this->sm;
}

Void MyForm::ButtonSearchBook_Click(Object^ sender, EventArgs^ e) {
	IsChangeSearchButtonClicked = true;
	TextBoxSearch->Enabled = true;
	ButtonSearchStart->Enabled = true;
	TextBoxSearch->Text = L"������� �������� �����";
	ButtonSearchBook->FlatStyle = FlatStyle::Popup;
	searchStatus = S_Book;
}

Void MyForm::ButtonSearchSubject_Click(Object^ sender, EventArgs^ e) {
	IsChangeSearchButtonClicked = true;
	TextBoxSearch->Enabled = true;
	ButtonSearchStart->Enabled = true;
	TextBoxSearch->Text = L"������� �������� ����������";
	ButtonSearchBook->FlatStyle = FlatStyle::Standard;
	ButtonSearchSubject->FlatStyle = FlatStyle::Popup;
	searchStatus = S_Subject;
}

Void MyForm::TextBoxSearch_TextChanged(Object^ sender, EventArgs^ e) {
	String^ text = TextBoxSearch->Text;
	if (IsChangeSearchButtonClicked) {
		IsChangeSearchButtonClicked = false;
	}
	else if (text->StartsWith("������� �������� �����") || text->StartsWith("������� �������� ����������")) {
		text = text->Substring(text->Length - 1);
		TextBoxSearch->Text = text;
		TextBoxSearch->Select(TextBoxSearch->Text->Length, 1);
	}
}

Void MyForm::ButtonSearchStart_Click(System::Object^ sender, System::EventArgs^ e) {
	ListViewData1->Items->Clear();
	String^ searched_data = TextBoxSearch->Text;
	if (searchStatus == S_Book) {
		/*
		ListViewData1->Columns->Add("ISBN", 75);
		ListViewData1->Columns->Add("��������", 200);
		ListViewData1->Columns->Add("�����", 150);
		for each (Object^ obj in bm->books) {
			Book^ book = dynamic_cast<Book^>(obj);
			if (book != nullptr) {
				ListViewItem^ item = gcnew ListViewItem();
				item->Text = book->ISBN;
				item->SubItems->Add(book->title);
				item->SubItems->Add(book->author);
				ListViewData1->Items->Add(item);
			}
		}
		*/
		// TODO - ListView �� ���������� ��������� ��������� ��������
	}
	else if (searchStatus == S_Subject) {

	}
	else {
		// TODO - �������� ��� ������������ ��������� ������ ������ �� "������"
	}
	ListViewData1->Scrollable = true;
}