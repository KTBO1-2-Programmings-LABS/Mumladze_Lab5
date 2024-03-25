#pragma once

#include "DataManager.h"

enum SearchStatus {
	S_Nothing = 0,
	S_Book = 1,
	S_Subject = 2
};

namespace MumladzeLab5 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class MyForm : public System::Windows::Forms::Form {
	
	public: MyForm(void);
	protected: ~MyForm();

	private: LinkManager^ lm;
		     BookManager^ bm;
		     SubjectManager^ sm;

	private: System::Windows::Forms::Button^ ButtonSearchBook;
	private: System::Windows::Forms::Button^ ButtonSearchSubject;
	private: System::Windows::Forms::TextBox^ TextBoxSearch;
	private: System::Windows::Forms::Button^ ButtonSearchStart;
	private: System::Windows::Forms::ListView^ ListViewData1;

	/// <summary>
	/// Обязательная переменная конструктора.
	/// </summary>
	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void) {
			this->ButtonSearchBook = (gcnew System::Windows::Forms::Button());
			this->ButtonSearchSubject = (gcnew System::Windows::Forms::Button());
			this->TextBoxSearch = (gcnew System::Windows::Forms::TextBox());
			this->ButtonSearchStart = (gcnew System::Windows::Forms::Button());
			this->ListViewData1 = (gcnew System::Windows::Forms::ListView());
			this->SuspendLayout();
			// 
			// ButtonSearchBook
			// 
			this->ButtonSearchBook->Location = System::Drawing::Point(40, 20);
			this->ButtonSearchBook->Name = L"ButtonSearchBook";
			this->ButtonSearchBook->Size = System::Drawing::Size(150, 45);
			this->ButtonSearchBook->TabIndex = 0;
			this->ButtonSearchBook->Text = L"Книги";
			this->ButtonSearchBook->UseVisualStyleBackColor = true;
			this->ButtonSearchBook->Click += gcnew System::EventHandler(this, &MyForm::ButtonSearchBook_Click);
			// 
			// ButtonSearchSubject
			// 
			this->ButtonSearchSubject->Location = System::Drawing::Point(230, 20);
			this->ButtonSearchSubject->Name = L"ButtonSearchSubject";
			this->ButtonSearchSubject->Size = System::Drawing::Size(150, 45);
			this->ButtonSearchSubject->TabIndex = 1;
			this->ButtonSearchSubject->Text = L"Дисциплины";
			this->ButtonSearchSubject->UseVisualStyleBackColor = true;
			this->ButtonSearchSubject->Click += gcnew System::EventHandler(this, &MyForm::ButtonSearchSubject_Click);
			// 
			// TextBoxSearch
			// 
			this->TextBoxSearch->Location = System::Drawing::Point(40, 90);
			this->TextBoxSearch->Name = L"TextBoxSearch";
			this->TextBoxSearch->Size = System::Drawing::Size(240, 20);
			this->TextBoxSearch->TabIndex = 2;
			this->TextBoxSearch->Text = L"Поиск";
			this->TextBoxSearch->Enabled = false;
			this->TextBoxSearch->TextChanged += gcnew System::EventHandler(this, &MyForm::TextBoxSearch_TextChanged);
			// 
			// ButtonSearchStart
			// 
			this->ButtonSearchStart->Location = System::Drawing::Point(300, 80);
			this->ButtonSearchStart->Name = L"ButtonSearchStart";
			this->ButtonSearchStart->Size = System::Drawing::Size(75, 40);
			this->ButtonSearchStart->TabIndex = 3;
			this->ButtonSearchStart->Text = L"Поиск";
			this->ButtonSearchStart->UseVisualStyleBackColor = true;
			this->ButtonSearchStart->Enabled = false;
			this->ButtonSearchStart->Click += gcnew System::EventHandler(this, &MyForm::ButtonSearchStart_Click);
			// 
			// ListViewData1
			// 
			this->ListViewData1->HideSelection = false;
			this->ListViewData1->Location = System::Drawing::Point(40, 135);
			this->ListViewData1->Name = L"ListViewData1";
			this->ListViewData1->Size = System::Drawing::Size(330, 250);
			this->ListViewData1->TabIndex = 4;
			this->ListViewData1->UseCompatibleStateImageBehavior = false;
			// 
			// MyForm
			// 
			this->ClientSize = System::Drawing::Size(900, 400);
			this->Controls->Add(this->ListViewData1);
			this->Controls->Add(this->ButtonSearchStart);
			this->Controls->Add(this->TextBoxSearch);
			this->Controls->Add(this->ButtonSearchSubject);
			this->Controls->Add(this->ButtonSearchBook);
			this->Name = L"MyForm";
			this->Text = L"Библиотечная картотека";
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
	private: bool IsChangeSearchButtonClicked = false;
		     SearchStatus searchStatus = S_Nothing;

	private: Void ButtonSearchBook_Click(Object^ sender, EventArgs^ e);
	private: Void ButtonSearchSubject_Click(Object^ sender, EventArgs^ e);
	private: Void TextBoxSearch_TextChanged(Object^ sender, EventArgs^ e);
	private: Void ButtonSearchStart_Click(System::Object^ sender, System::EventArgs^ e);

};
}