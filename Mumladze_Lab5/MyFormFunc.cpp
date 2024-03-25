#include "MyForm.h"
#include "DataManager.h"

using namespace MumladzeLab5;

MyForm::MyForm() {
	InitializeComponent();
	// TODO - ��������� ������������� �������� ������� �� DataManager
}

MyForm::~MyForm() {
	if (components) {
		delete components;
	}
}

Void MyForm::ButtonSearchBook_Click(Object^ sender, EventArgs^ e) {
	IsChangeSearchButtonClicked = true;
	TextBoxSearch->Enabled = true;
	TextBoxSearch->Text = L"������� �������� �����";
	ButtonSearchBook->FlatStyle = FlatStyle::Popup;
	ButtonSearchSubject->FlatStyle = FlatStyle::Standard;
}

Void MyForm::ButtonSearchSubject_Click(Object^ sender, EventArgs^ e) {
	IsChangeSearchButtonClicked = true;
	TextBoxSearch->Enabled = true;
	TextBoxSearch->Text = L"������� �������� ����������";
	ButtonSearchBook->FlatStyle = FlatStyle::Standard;
	ButtonSearchSubject->FlatStyle = FlatStyle::Popup;
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

}