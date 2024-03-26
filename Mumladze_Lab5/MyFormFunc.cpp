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
	TextBoxSearch->Text = L"Введите название книги";
	ButtonSearchBook->FlatStyle = FlatStyle::Popup;
	searchStatus = S_Book;
	ListViewData1->Items->Clear();
	columnHeader1->Text = "ISBN";
	columnHeader1->Width = 100;
	columnHeader2->Text = "Название книги";
	columnHeader2->Width = 230;
	columnHeader3->Text = "Автор";
	columnHeader3->Width = 115;
}

Void MyForm::ButtonSearchSubject_Click(Object^ sender, EventArgs^ e) {
	IsChangeSearchButtonClicked = true;
	TextBoxSearch->Enabled = true;
	ButtonSearchStart->Enabled = true;
	TextBoxSearch->Text = L"Введите название дисциплины";
	ButtonSearchBook->FlatStyle = FlatStyle::Standard;
	ButtonSearchSubject->FlatStyle = FlatStyle::Popup;
	searchStatus = S_Subject;
	ListViewData1->Items->Clear();
	columnHeader1->Text = "Код";
	columnHeader1->Width = 75;
	columnHeader2->Text = "Название дисциплины";
	columnHeader2->Width = 115;
	columnHeader3->Text = "Описание";
	columnHeader3->Width = 225;
}

Void MyForm::TextBoxSearch_TextChanged(Object^ sender, EventArgs^ e) {
	String^ text = TextBoxSearch->Text;
	if (IsChangeSearchButtonClicked) {
		IsChangeSearchButtonClicked = false;
	}
	else if (text->StartsWith("Введите название книги") || text->StartsWith("Введите название дисциплины")) {
		text = text->Substring(text->Length - 1);
		TextBoxSearch->Text = text;
		TextBoxSearch->Select(TextBoxSearch->Text->Length, 1);
	}
}

Void MyForm::ButtonSearchStart_Click(System::Object^ sender, System::EventArgs^ e) {
	ListViewData1->Items->Clear();
	String^ text = TextBoxSearch->Text;
	if (searchStatus == S_Book) {
		for each (Object^ obj in bm->books) {
			Book^ book = dynamic_cast<Book^>(obj);
			if (book != nullptr && (book->ISBN->Contains(text) || book->title->Contains(text) || book->author->Contains(text))) {
				ListViewItem^ item = gcnew ListViewItem();
				item->Text = book->ISBN;
				item->SubItems->Add(book->title);
				item->SubItems->Add(book->author);
				ListViewData1->Items->Add(item);
			}
		}
	}
	else if (searchStatus == S_Subject) {
		for each (Object ^ obj in sm->subjects) {
			Subject^ subject = dynamic_cast<Subject^>(obj);
			if (subject != nullptr && (subject->dis_code->Contains(text) || subject->name->Contains(text) || subject->description->Contains(text))) {
				ListViewItem^ item = gcnew ListViewItem();
				item->Text = subject->dis_code;
				item->SubItems->Add(subject->name);
				item->SubItems->Add(subject->description);
				ListViewData1->Items->Add(item);
			}
		}
	}
	else {
		MessageBox::Show("Ошибка - не выбрана категория поиска", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	ListViewData1->Scrollable = true;
}