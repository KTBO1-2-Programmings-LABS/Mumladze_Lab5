#include "MyForm.h"
#include "DataManager.h"

using namespace MumladzeLab5;

MyForm::MyForm() {
	InitializeComponent();
	this->dm = gcnew DataManager();
}

MyForm::~MyForm() {
	if (components) {
		delete components;
	}
	if (!dm) {
		this->dm->WriteDataFiles();
		delete this->dm;
		dm = nullptr;
	}
}

Void MyForm::initializationData() {
	try {
		this->dm->ReadDataFiles();
		this->IsDataInitialized = true;
	}
	catch (Exception^ e) {
		MessageBox::Show("Ошибка, не найдены файлы данных для чтения. Проверьте, что рядом "
			"с программой находится папка Data с тремя текстовыми файлами данных.", 
			"Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		this->Close();
	}
}

Void MyForm::buttonSearchLink_Click(System::Object^ sender, System::EventArgs^ e) {
	IsChangeSearchButtonClicked = true;
	textBoxSearch->Enabled = true;
	buttonSearchStart->Enabled = true;
	buttonAddNode->Enabled = true;
	textBoxInputData1->Enabled = true;
	textBoxInputData2->Enabled = true;
	textBoxInputData3->Enabled = false;
	buttonSearchLink->FlatStyle = FlatStyle::Popup;
	buttonSearchBook->FlatStyle = FlatStyle::Standard;
	buttonSearchSubject->FlatStyle = FlatStyle::Standard;
	searchStatus = S_LINK;
	textBoxSearch->Text = L"";
	labelInputData1->Text = L"ISBN книги";
	labelInputData2->Text = L"Код дисциплины";
	labelInputData3->Text = L"";
	labelSearch->Text = L"Введите информацию о связи";
	listViewData1->Items->Clear();
	columnHeader1->Text = "ISBN";
	columnHeader1->Width = 220;
	columnHeader2->Text = "Название книги";
	columnHeader2->Width = 220;
	columnHeader3->Text = "";
	columnHeader3->Width = 0;
}

Void MyForm::buttonSearchBook_Click(Object^ sender, EventArgs^ e) {
	IsChangeSearchButtonClicked = true;
	textBoxSearch->Enabled = true;
	buttonSearchStart->Enabled = true;
	buttonAddNode->Enabled = true;
	textBoxInputData1->Enabled = true;
	textBoxInputData2->Enabled = true;
	textBoxInputData3->Enabled = true;
	buttonSearchLink->FlatStyle = FlatStyle::Standard;
	buttonSearchBook->FlatStyle = FlatStyle::Popup;
	buttonSearchSubject->FlatStyle = FlatStyle::Standard;
	searchStatus = S_BOOK;
	textBoxSearch->Text = L"";
	labelInputData1->Text = L"ISBN книги";
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
	textBoxInputData1->Enabled = true;
	textBoxInputData2->Enabled = true;
	textBoxInputData3->Enabled = true;
	buttonSearchLink->FlatStyle = FlatStyle::Standard;
	buttonSearchBook->FlatStyle = FlatStyle::Standard;
	buttonSearchSubject->FlatStyle = FlatStyle::Popup;
	searchStatus = S_SUBJECT;
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
	List<Object^>^ finded = nullptr;
	String^ text = textBoxSearch->Text->ToLower();

	switch (searchStatus) {
	case S_LINK:
		finded = dm->FindNodes(T_LINK, text);
		for each (Link^ link in finded) {
			ListViewItem^ item = gcnew ListViewItem();
			item->Text = link->ISBN;
			item->SubItems->Add(link->dis_code);
			listViewData1->Items->Add(item);
		}
		break;
	case S_BOOK:
		finded = dm->FindNodes(T_BOOK, text);
		for each (Book^ book in finded) {
			ListViewItem^ item = gcnew ListViewItem();
			item->Text = book->ISBN;
			item->SubItems->Add(book->title);
			item->SubItems->Add(book->author);
			listViewData1->Items->Add(item);
		}
		break;
	case S_SUBJECT:
		finded = dm->FindNodes(T_SUBJECT, text);
		for each (Subject^ subject in finded) {
			ListViewItem^ item = gcnew ListViewItem();
			item->Text = subject->dis_code;
			item->SubItems->Add(subject->name);
			item->SubItems->Add(subject->description);
			listViewData1->Items->Add(item);
		}
		break;
	default:
		MessageBox::Show("Ошибка - не выбрана категория поиска", "Ошибка",
			MessageBoxButtons::OK, MessageBoxIcon::Error);
		break;
	}
	listViewData1->Scrollable = true;
}

Void MyForm::buttonAddNode_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ text1 = textBoxInputData1->Text;
	String^ text2 = textBoxInputData2->Text;
	String^ text3 = textBoxInputData3->Text;

	if (String::IsNullOrWhiteSpace(text1) || String::IsNullOrWhiteSpace(text2)) {
		MessageBox::Show("Ошибка. Вы ввели не все данные, необходимые для записи в список.",
						 "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
	else {
		ListViewItem^ item = gcnew ListViewItem();
		item->Text = text1;
		item->SubItems->Add(text2);
		Link^ link = gcnew Link();
		Book^ book = gcnew Book();
		Subject^ subject = gcnew Subject();
		Object^ node = nullptr;
		switch (searchStatus) {
		case S_LINK:
			link->ISBN = text1;
			link->dis_code = text2;
			node = link;
			dm->AddNode(T_LINK, node);
			break;
		case S_BOOK:
			if (String::IsNullOrWhiteSpace(text3)) {
				MessageBox::Show("Ошибка. Вы ввели не все данные, необходимые для записи в список.",
								 "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
			else {
				book->ISBN = text1;
				book->title = text2;
				book->author = text3;
				node = book;
				dm->AddNode(T_BOOK, node);
				item->SubItems->Add(text3);
			}
			break;
		case S_SUBJECT:
			if (String::IsNullOrWhiteSpace(text3)) {
				MessageBox::Show("Ошибка. Вы ввели не все данные, необходимые для записи в список.",
								 "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
			else {
				subject->dis_code = text1;
				subject->name = text2;
				subject->description = text3;
				node = subject;
				dm->AddNode(T_SUBJECT, node);
				item->SubItems->Add(text3);
			}
			break;
		default:
			MessageBox::Show("Ошибка - не выбрана категория записи", "Ошибка", 
							 MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		if (node) {
			listViewData1->Items->Add(item);
			textBoxInputData1->Text = "";
			textBoxInputData2->Text = "";
			textBoxInputData3->Text = "";
		}
	}
}

Void MyForm::listViewData1_ItemSelectionChanged(Object^ sender, ListViewItemSelectionChangedEventArgs^ e) {
	buttonRemoveNode->Enabled = listViewData1->SelectedItems->Count > 0;
}

Void MyForm::buttonRemoveNode_Click(System::Object^ sender, System::EventArgs^ e) {
	if (listViewData1->SelectedItems->Count > 0) {
		Link^ link = gcnew Link();
		Book^ book = gcnew Book();
		Subject^ subject = gcnew Subject();
		Object^ node = nullptr;
		List<ListViewItem^>^ itemsToRemove = gcnew List<ListViewItem^>();

		for each (ListViewItem^ item in listViewData1->SelectedItems) {
			itemsToRemove->Add(item);
		}
		for each (ListViewItem^ item in itemsToRemove) {
			listViewData1->Items->Remove(item);
			switch (searchStatus) {
			case S_LINK:
				link->ISBN = item->Text;
				link->dis_code = item->SubItems[0]->Text;
				node = link;
				dm->DeleteNode(T_LINK, node);
				break;
			case S_BOOK:
				book->ISBN = item->Text;
				node = book;
				dm->DeleteNode(T_BOOK, node);
				break;
			case S_SUBJECT:
				subject->dis_code = item->Text;
				node = book;
				dm->DeleteNode(T_BOOK, node);
				break;
			default:
				MessageBox::Show("Ошибка - не выбрана категория удаления", "Ошибка",
								 MessageBoxButtons::OK, MessageBoxIcon::Error);
				break;
			}
		}
	}
	buttonRemoveNode->Enabled = false;
}