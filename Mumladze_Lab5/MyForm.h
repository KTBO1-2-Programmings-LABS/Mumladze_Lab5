#pragma once

namespace MumladzeLab5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ ButtonSearchBook;
	private: System::Windows::Forms::Button^ ButtonSearchSubject;
	private: System::Windows::Forms::TextBox^ TextBoxSearch;
	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void) {
			this->ButtonSearchBook = (gcnew System::Windows::Forms::Button());
			this->ButtonSearchSubject = (gcnew System::Windows::Forms::Button());
			this->TextBoxSearch = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// ButtonSearchBook
			// 
			this->ButtonSearchBook->Location = System::Drawing::Point(40, 20);
			this->ButtonSearchBook->Name = L"ButtonSearchBook";
			this->ButtonSearchBook->Size = System::Drawing::Size(120, 45);
			this->ButtonSearchBook->TabIndex = 0;
			this->ButtonSearchBook->Text = L" ниги";
			this->ButtonSearchBook->UseVisualStyleBackColor = true;
			this->ButtonSearchBook->Click += gcnew System::EventHandler(this, &MyForm::ButtonSearchBook_Click);
			// 
			// ButtonSearchSubject
			// 
			this->ButtonSearchSubject->Location = System::Drawing::Point(200, 20);
			this->ButtonSearchSubject->Name = L"ButtonSearchSubject";
			this->ButtonSearchSubject->Size = System::Drawing::Size(120, 45);
			this->ButtonSearchSubject->TabIndex = 1;
			this->ButtonSearchSubject->Text = L"ƒисциплины";
			this->ButtonSearchSubject->UseVisualStyleBackColor = true;
			this->ButtonSearchSubject->Click += gcnew System::EventHandler(this, &MyForm::ButtonSearchSubject_Click);
			// 
			// TextBoxSearch
			// 
			this->TextBoxSearch->Location = System::Drawing::Point(40, 90);
			this->TextBoxSearch->Name = L"TextBoxSearch";
			this->TextBoxSearch->Size = System::Drawing::Size(280, 22);
			this->TextBoxSearch->TabIndex = 2;
			this->TextBoxSearch->Text = L"ѕоиск";
			this->TextBoxSearch->TextChanged += gcnew System::EventHandler(this, &MyForm::TextBoxSearch_TextChanged);
			// 
			// MyForm
			// 
			this->ClientSize = System::Drawing::Size(900, 400);
			this->Controls->Add(this->TextBoxSearch);
			this->Controls->Add(this->ButtonSearchSubject);
			this->Controls->Add(this->ButtonSearchBook);
			this->Name = L"MyForm";
			this->Text = L"Ѕиблиотечна€ картотека";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: bool IsChangeSearchButtonClicked = false;

	private: Void ButtonSearchBook_Click(Object^ sender, EventArgs^ e) {
		IsChangeSearchButtonClicked = true;
		TextBoxSearch->Enabled = true;
		TextBoxSearch->Text = L"¬ведите название книги";
		ButtonSearchBook->FlatStyle = FlatStyle::Popup;
		ButtonSearchSubject->FlatStyle = FlatStyle::Standard;
	}
	private: Void ButtonSearchSubject_Click(Object^ sender, EventArgs^ e) {
		IsChangeSearchButtonClicked = true;
		TextBoxSearch->Enabled = true;
		TextBoxSearch->Text = L"¬ведите название дисциплины";
		ButtonSearchBook->FlatStyle = FlatStyle::Standard;
		ButtonSearchSubject->FlatStyle = FlatStyle::Popup;
	}
	private: Void TextBoxSearch_TextChanged(Object^ sender, EventArgs^ e) {
		String^ text = TextBoxSearch->Text;
		if (IsChangeSearchButtonClicked) {
			IsChangeSearchButtonClicked = false;
		}
		else if (text->StartsWith("¬ведите название книги") || text->StartsWith("¬ведите название дисциплины")) {
			text = text->Substring(text->Length - 1);
			TextBoxSearch->Text = text;
			TextBoxSearch->Select(TextBoxSearch->Text->Length, 1);
		}
	}

};
}