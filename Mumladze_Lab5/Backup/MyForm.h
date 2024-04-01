#pragma once

#include "DataManager.h"

enum SearchStatus {
	S_NOTHING = -1,
	S_LINK = 0,
	S_BOOK = 1,
	S_SUBJECT = 2
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

	private: DataManager^ dm;

	private: System::Windows::Forms::Button^ buttonSearchBook;
	private: System::Windows::Forms::Button^ buttonSearchSubject;
	private: System::Windows::Forms::TextBox^ textBoxSearch;
	private: System::Windows::Forms::Button^ buttonSearchStart;
	private: System::Windows::Forms::ListView^ listViewData1;
	private: System::Windows::Forms::ColumnHeader^ columnHeader1;
	private: System::Windows::Forms::ColumnHeader^ columnHeader2;
	private: System::Windows::Forms::ColumnHeader^ columnHeader3;
	private: System::Windows::Forms::Label^ labelSearch;
	private: System::Windows::Forms::TextBox^ textBoxInputData1;
	private: System::Windows::Forms::Label^ labelInputData1;
	private: System::Windows::Forms::TextBox^ textBoxInputData2;
	private: System::Windows::Forms::Label^ labelInputData2;
	private: System::Windows::Forms::TextBox^ textBoxInputData3;
	private: System::Windows::Forms::Label^ labelInputData3;
	private: System::Windows::Forms::Button^ buttonRemoveNode;
	private: System::Windows::Forms::Button^ buttonAddNode;
	private: System::Windows::Forms::Button^ buttonSearchLink;



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
			this->buttonSearchLink = (gcnew System::Windows::Forms::Button());
			this->buttonSearchBook = (gcnew System::Windows::Forms::Button());
			this->buttonSearchSubject = (gcnew System::Windows::Forms::Button());
			this->textBoxSearch = (gcnew System::Windows::Forms::TextBox());
			this->buttonSearchStart = (gcnew System::Windows::Forms::Button());
			this->listViewData1 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->labelSearch = (gcnew System::Windows::Forms::Label());
			this->textBoxInputData1 = (gcnew System::Windows::Forms::TextBox());
			this->labelInputData1 = (gcnew System::Windows::Forms::Label());
			this->textBoxInputData2 = (gcnew System::Windows::Forms::TextBox());
			this->labelInputData2 = (gcnew System::Windows::Forms::Label());
			this->textBoxInputData3 = (gcnew System::Windows::Forms::TextBox());
			this->labelInputData3 = (gcnew System::Windows::Forms::Label());
			this->buttonRemoveNode = (gcnew System::Windows::Forms::Button());
			this->buttonAddNode = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// buttonSearchLink
			// 
			this->buttonSearchLink->Location = System::Drawing::Point(260, 20);
			this->buttonSearchLink->Name = L"buttonSearchLink";
			this->buttonSearchLink->Size = System::Drawing::Size(100, 45);
			this->buttonSearchLink->TabIndex = 2;
			this->buttonSearchLink->Text = L"Связи";
			this->buttonSearchLink->UseVisualStyleBackColor = true;
			this->buttonSearchLink->Click += gcnew System::EventHandler(this, &MyForm::buttonSearchLink_Click);
			// 
			// buttonSearchBook
			// 
			this->buttonSearchBook->Location = System::Drawing::Point(40, 20);
			this->buttonSearchBook->Name = L"buttonSearchBook";
			this->buttonSearchBook->Size = System::Drawing::Size(100, 45);
			this->buttonSearchBook->TabIndex = 0;
			this->buttonSearchBook->Text = L"Книги";
			this->buttonSearchBook->UseVisualStyleBackColor = true;
			this->buttonSearchBook->Click += gcnew System::EventHandler(this, &MyForm::buttonSearchBook_Click);
			// 
			// buttonSearchSubject
			// 
			this->buttonSearchSubject->Location = System::Drawing::Point(150, 20);
			this->buttonSearchSubject->Name = L"buttonSearchSubject";
			this->buttonSearchSubject->Size = System::Drawing::Size(100, 45);
			this->buttonSearchSubject->TabIndex = 1;
			this->buttonSearchSubject->Text = L"Дисциплины";
			this->buttonSearchSubject->UseVisualStyleBackColor = true;
			this->buttonSearchSubject->Click += gcnew System::EventHandler(this, &MyForm::buttonSearchSubject_Click);
			// 
			// textBoxSearch
			// 
			this->textBoxSearch->Enabled = false;
			this->textBoxSearch->Location = System::Drawing::Point(40, 80);
			this->textBoxSearch->Name = L"textBoxSearch";
			this->textBoxSearch->Size = System::Drawing::Size(450, 22);
			this->textBoxSearch->TabIndex = 3;
			// 
			// buttonSearchStart
			// 
			this->buttonSearchStart->Enabled = false;
			this->buttonSearchStart->Location = System::Drawing::Point(370, 20);
			this->buttonSearchStart->Name = L"buttonSearchStart";
			this->buttonSearchStart->Size = System::Drawing::Size(120, 45);
			this->buttonSearchStart->TabIndex = 4;
			this->buttonSearchStart->Text = L"Поиск";
			this->buttonSearchStart->UseVisualStyleBackColor = true;
			this->buttonSearchStart->Click += gcnew System::EventHandler(this, &MyForm::buttonSearchStart_Click);
			// 
			// listViewData1
			// 
			this->listViewData1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
				this->columnHeader1,
					this->columnHeader2, this->columnHeader3
			});
			this->listViewData1->HideSelection = false;
			this->listViewData1->Location = System::Drawing::Point(40, 135);
			this->listViewData1->Name = L"listViewData1";
			this->listViewData1->Size = System::Drawing::Size(450, 250);
			this->listViewData1->TabIndex = 5;
			this->listViewData1->UseCompatibleStateImageBehavior = false;
			this->listViewData1->View = System::Windows::Forms::View::Details;
			this->listViewData1->ItemSelectionChanged += gcnew System::Windows::Forms::ListViewItemSelectionChangedEventHandler(this, &MyForm::listViewData1_ItemSelectionChanged);
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"Поле 1";
			this->columnHeader1->Width = 148;
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"Поле 2";
			this->columnHeader2->Width = 148;
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"Поле 3";
			this->columnHeader3->Width = 148;
			// 
			// labelSearch
			// 
			this->labelSearch->AutoSize = true;
			this->labelSearch->Location = System::Drawing::Point(40, 104);
			this->labelSearch->Name = L"labelSearch";
			this->labelSearch->Size = System::Drawing::Size(47, 16);
			this->labelSearch->TabIndex = 6;
			this->labelSearch->Text = L"Поиск";
			// 
			// textBoxInputData1
			// 
			this->textBoxInputData1->Location = System::Drawing::Point(520, 135);
			this->textBoxInputData1->Name = L"textBoxInputData1";
			this->textBoxInputData1->Size = System::Drawing::Size(200, 22);
			this->textBoxInputData1->TabIndex = 7;
			textBoxInputData1->Enabled = false;
			// 
			// labelInputData1
			// 
			this->labelInputData1->AutoSize = true;
			this->labelInputData1->Location = System::Drawing::Point(520, 160);
			this->labelInputData1->Name = L"labelInputData1";
			this->labelInputData1->Size = System::Drawing::Size(94, 16);
			this->labelInputData1->TabIndex = 8;
			this->labelInputData1->Text = L"Поле ввода 1";
			// 
			// textBoxInputData2
			// 
			this->textBoxInputData2->Location = System::Drawing::Point(520, 190);
			this->textBoxInputData2->Name = L"textBoxInputData2";
			this->textBoxInputData2->Size = System::Drawing::Size(200, 22);
			this->textBoxInputData2->TabIndex = 9;
			textBoxInputData2->Enabled = false;
			// 
			// labelInputData2
			// 
			this->labelInputData2->AutoSize = true;
			this->labelInputData2->Location = System::Drawing::Point(520, 215);
			this->labelInputData2->Name = L"labelInputData2";
			this->labelInputData2->Size = System::Drawing::Size(94, 16);
			this->labelInputData2->TabIndex = 10;
			this->labelInputData2->Text = L"Поле ввода 2";
			// 
			// textBoxInputData3
			// 
			this->textBoxInputData3->Location = System::Drawing::Point(520, 245);
			this->textBoxInputData3->Name = L"textBoxInputData3";
			this->textBoxInputData3->Size = System::Drawing::Size(200, 22);
			this->textBoxInputData3->TabIndex = 11;
			textBoxInputData3->Enabled = false;
			// 
			// labelInputData3
			// 
			this->labelInputData3->AutoSize = true;
			this->labelInputData3->Location = System::Drawing::Point(520, 275);
			this->labelInputData3->Name = L"labelInputData3";
			this->labelInputData3->Size = System::Drawing::Size(94, 16);
			this->labelInputData3->TabIndex = 12;
			this->labelInputData3->Text = L"Поле ввода 3";
			// 
			// buttonRemoveNode
			// 
			this->buttonRemoveNode->Enabled = false;
			this->buttonRemoveNode->Location = System::Drawing::Point(520, 325);
			this->buttonRemoveNode->Name = L"buttonRemoveNode";
			this->buttonRemoveNode->Size = System::Drawing::Size(90, 40);
			this->buttonRemoveNode->TabIndex = 13;
			this->buttonRemoveNode->Text = L"Удалить";
			this->buttonRemoveNode->UseVisualStyleBackColor = true;
			this->buttonRemoveNode->Click += gcnew System::EventHandler(this, &MyForm::buttonRemoveNode_Click);
			// 
			// buttonAddNode
			// 
			this->buttonAddNode->Enabled = false;
			this->buttonAddNode->Location = System::Drawing::Point(630, 325);
			this->buttonAddNode->Name = L"buttonAddNode";
			this->buttonAddNode->Size = System::Drawing::Size(90, 40);
			this->buttonAddNode->TabIndex = 14;
			this->buttonAddNode->Text = L"Записать";
			this->buttonAddNode->UseVisualStyleBackColor = true;
			this->buttonAddNode->Click += gcnew System::EventHandler(this, &MyForm::buttonAddNode_Click);
			// 
			// MyForm
			// 
			this->ClientSize = System::Drawing::Size(750, 400);
			this->Controls->Add(this->buttonAddNode);
			this->Controls->Add(this->buttonRemoveNode);
			this->Controls->Add(this->labelInputData3);
			this->Controls->Add(this->textBoxInputData3);
			this->Controls->Add(this->labelInputData2);
			this->Controls->Add(this->textBoxInputData2);
			this->Controls->Add(this->labelInputData1);
			this->Controls->Add(this->textBoxInputData1);
			this->Controls->Add(this->labelSearch);
			this->Controls->Add(this->listViewData1);
			this->Controls->Add(this->buttonSearchStart);
			this->Controls->Add(this->textBoxSearch);
			this->Controls->Add(this->buttonSearchSubject);
			this->Controls->Add(this->buttonSearchBook);
			this->Controls->Add(this->buttonSearchLink);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Name = L"MyForm";
			this->Text = L"Библиотечная картотека";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: bool IsChangeSearchButtonClicked = false;
		     bool IsDataInitialized = false;
		     SearchStatus searchStatus = S_NOTHING;

	private: Void initializationData();
	private: Void buttonSearchLink_Click(System::Object^ sender, System::EventArgs^ e);
	private: Void buttonSearchBook_Click(Object^ sender, EventArgs^ e);
	private: Void buttonSearchSubject_Click(Object^ sender, EventArgs^ e);
	private: Void buttonSearchStart_Click(Object^ sender, EventArgs^ e);
	private: Void buttonRemoveNode_Click(Object^ sender, EventArgs^ e);
	private: Void buttonAddNode_Click(Object^ sender, EventArgs^ e);
	private: Void listViewData1_ItemSelectionChanged(Object^ sender, ListViewItemSelectionChangedEventArgs^ e);
};
}