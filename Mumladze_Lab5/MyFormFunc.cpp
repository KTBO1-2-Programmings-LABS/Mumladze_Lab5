#include "MyForm.h"
#include "DataManager.h"

using namespace MumladzeLab5;

MyForm::MyForm() {
	InitializeComponent();
	this->lm = gcnew LinkManager();
	this->bm = gcnew BookManager(lm);
	this->sm = gcnew SubjectManager(lm);
}

MyForm::~MyForm() {
	if (components) {
		delete components;
	}
	this->lm->WriteLinkListToFile();
	this->bm->WriteBookListToFile();
	this->sm->WriteSubjectListToFile();
	delete this->lm;
	delete this->bm;
	delete this->sm;
}

Void MyForm::initializationData() {
	try {
		this->lm->ReadLinkListFromFile();
		this->bm->ReadBookListFromFile();
		this->sm->ReadSubjectListFromFile();
		this->IsDataInitialized = true;
	}
	catch (Exception^ e) {
		MessageBox::Show("Ошибка, не найдены файлы данных для чтения. Проверьте, что рядом "
			"с программой находится папка Data с тремя текстовыми файлами данных.", 
			"Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		this->Close();
	}
}

Void MyForm::buttonSearchBook_Click(Object^ sender, EventArgs^ e) {
	IsChangeSearchButtonClicked = true;
	textBoxSearch->Enabled = true;
	buttonSearchStart->Enabled = true;
	buttonAddNode->Enabled = true;
	buttonSearchBook->FlatStyle = FlatStyle::Popup;
	searchStatus = S_Book;
	textBoxSearch->Text = L"";
	labelInputData1->Text = L"ISBN";
	labelInputData2->Text = L"Название книги";
	labelInputData3->Text = L"Автор";
	labelSearch->Text = L"Введите информацию о книге";
	listViewData1->Items->Clear();
	columnHeader1->Text = "ISBN";
	columnHeader1->Width = 100;
	columnHeader2->Text = "Название книги";
	columnHeader2->Width = 230;
	columnHeader3->Text = "Автор";
	columnHeader3->Width = 115;
}

Void MyForm::buttonSearchSubject_Click(Object^ sender, EventArgs^ e) {
	IsChangeSearchButtonClicked = true;
	textBoxSearch->Enabled = true;
	buttonSearchStart->Enabled = true;
	buttonAddNode->Enabled = true;
	buttonSearchBook->FlatStyle = FlatStyle::Standard;
	buttonSearchSubject->FlatStyle = FlatStyle::Popup;
	searchStatus = S_Subject;
	textBoxSearch->Text = L"";
	labelInputData1->Text = L"Код дисциплины";
	labelInputData2->Text = L"Название дисциплины";
	labelInputData3->Text = L"Описание дисциплины";
	labelSearch->Text = L"Введите информацию о дисциплине";
	listViewData1->Items->Clear();
	columnHeader1->Text = "Код";
	columnHeader1->Width = 75;
	columnHeader2->Text = "Название дисциплины";
	columnHeader2->Width = 145;
	columnHeader3->Text = "Описание";
	columnHeader3->Width = 225;
}

Void MyForm::buttonSearchStart_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!IsDataInitialized) {
		initializationData();
		IsDataInitialized = true;
	}
	listViewData1->Items->Clear();
	String^ text = textBoxSearch->Text->ToLower();
	if (searchStatus == S_Book) {
		for each (Object^ obj in bm->books) {
			Book^ book = dynamic_cast<Book^>(obj);
			if (book != nullptr && (book->ISBN->ToLower()->Contains(text) || book->title->ToLower()->Contains(text) || book->author->ToLower()->Contains(text))) {
				ListViewItem^ item = gcnew ListViewItem();
				item->Text = book->ISBN;
				item->SubItems->Add(book->title);
				item->SubItems->Add(book->author);
				listViewData1->Items->Add(item);
			}
		}
	}
	else if (searchStatus == S_Subject) {
		for each (Object ^ obj in sm->subjects) {
			Subject^ subject = dynamic_cast<Subject^>(obj);
			if (subject != nullptr && (subject->dis_code->ToLower()->Contains(text) || subject->name->ToLower()->Contains(text) || subject->description->ToLower()->Contains(text))) {
				ListViewItem^ item = gcnew ListViewItem();
				item->Text = subject->dis_code;
				item->SubItems->Add(subject->name);
				item->SubItems->Add(subject->description);
				listViewData1->Items->Add(item);
			}
		}
	}
	else {
		MessageBox::Show("Ошибка - не выбрана категория поиска", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	listViewData1->Scrollable = true;
}

Void MyForm::buttonAddNode_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ text1 = textBoxInputData1->Text;
	String^ text2 = textBoxInputData2->Text;
	String^ text3 = textBoxInputData3->Text;
	if (!String::IsNullOrWhiteSpace(text1) && !String::IsNullOrWhiteSpace(text2) && !String::IsNullOrWhiteSpace(text3)) {
		ListViewItem^ item = gcnew ListViewItem();
		if (searchStatus == S_Book) {
			bm->AddBookToList(String::Format("{0}; {1}; {2}", text1, text2, text3));
		}
		else if (searchStatus == S_Subject) {
			sm->AddSubjectToList(String::Format("{0}; {1}; {2}", text1, text2, text3));
		}
		else {
			MessageBox::Show("Ошибка - не выбрана категория записи", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		item->Text = text1;
		item->SubItems->Add(text2);
		item->SubItems->Add(text3);
		listViewData1->Items->Add(item);
		textBoxInputData1->Text = "";
		textBoxInputData2->Text = "";
		textBoxInputData3->Text = "";
	}
	else {
		MessageBox::Show("Ошибка. Вы ввели не все данные, необходимые для записи в список.",
			"Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

Void MyForm::listViewData1_ItemSelectionChanged(Object^ sender, ListViewItemSelectionChangedEventArgs^ e) {
	buttonRemoveNode->Enabled = listViewData1->SelectedItems->Count > 0;
}

Void MyForm::buttonRemoveNode_Click(System::Object^ sender, System::EventArgs^ e) {
	if (listViewData1->SelectedItems->Count > 0) {
		List<ListViewItem^>^ itemsToRemove = gcnew List<ListViewItem^>();
		for each (ListViewItem^ item in listViewData1->SelectedItems) {
			itemsToRemove->Add(item);
		}
		for each (ListViewItem^ item in itemsToRemove) {
			listViewData1->Items->Remove(item);
			if (searchStatus == S_Book) {
				bm->RemoveBookFromList(item->SubItems[0]->Text);
			}
			else if (searchStatus == S_Subject) {
				sm->RemoveSubjectFromList(item->SubItems[0]->Text);
			}
		}
	}
	buttonRemoveNode->Enabled = false;
}