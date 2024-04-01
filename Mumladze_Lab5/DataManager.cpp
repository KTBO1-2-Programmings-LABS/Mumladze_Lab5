#include "DataManager.h"

using namespace System;
using namespace System::IO;

DataManager::DataManager() {
    this->fileLinkPath = gcnew String("./Data/Links.txt");
    this->fileBookPath = gcnew String("./Data/Books.txt");
    this->fileSubjectPath = gcnew String("./Data/Subjects.txt");

    this->listLinks = gcnew List<Object^>();
    this->listBooks = gcnew List<Object^>();
    this->listSubjects = gcnew List<Object^>();

    Console::WriteLine("Создан объект класса DataManager");
}
void DataManager::ReadDataFiles() {
    try {
        StreamReader^ sr = gcnew StreamReader(this->fileLinkPath);
        String^ line;
        while ((line = sr->ReadLine()) != nullptr) {
            this->AddNode(T_LINK, this->MakeNode(T_LINK, line));
        }
        sr->Close();
        Console::WriteLine("Прочитан файл Links.txt");
    }
    catch (Exception^ e) {
        Console::WriteLine("Ошибка, невозможно прочитать Links.txt\n" + e);
        Environment::Exit(1);
    }
    try {
        StreamReader^ sr = gcnew StreamReader(this->fileBookPath);
        String^ line;
        while ((line = sr->ReadLine()) != nullptr) {
            this->AddNode(T_BOOK, this->MakeNode(T_BOOK, line));
        }
        sr->Close();
        Console::WriteLine("Прочитан файл Books.txt");
    }
    catch (Exception^ e) {
        Console::WriteLine("Ошибка, невозможно прочитать Books.txt\n" + e);
        Environment::Exit(1);
    }
    try {
        StreamReader^ sr = gcnew StreamReader(this->fileSubjectPath);
        String^ line;
        while ((line = sr->ReadLine()) != nullptr) {
            this->AddNode(T_SUBJECT, this->MakeNode(T_SUBJECT, line));
        }
        sr->Close();
        Console::WriteLine("Прочитан файл Subjects.txt");
    }
    catch (Exception^ e) {
        Console::WriteLine("Ошибка, невозможно прочитать Subjects.txt\n" + e);
        Environment::Exit(1);
    }
}
void DataManager::WriteDataFiles() {
    StreamWriter^ sw = nullptr;
    sw = File::CreateText(this->fileLinkPath);
    for each (Link^ link in (this->listLinks)) {
        String^ text = String::Format("{0}; {1}", link->ISBN, link->dis_code);
        sw->WriteLine(text);
    }
    sw->Close();
    Console::WriteLine("Файл Links.txt обновлен новыми данными");
    sw = File::CreateText(this->fileBookPath);
    for each (Book ^ book in (this->listBooks)) {
        String^ text = String::Format("{0}; {1}; {2}", book->ISBN, book->title, book->author);
        sw->WriteLine(text);
    }
    sw->Close();
    Console::WriteLine("Файл Books.txt обновлен новыми данными");
    sw = File::CreateText(this->fileSubjectPath);
    for each (Subject ^ subject in (this->listSubjects)) {
        String^ text = String::Format("{0}; {1}; {2}", subject->dis_code, subject->name, subject->description);
        sw->WriteLine(text);
    }
    sw->Close();
    Console::WriteLine("Файл Books.txt обновлен новыми данными");
}
Object^ DataManager::MakeNode(DataType type, String^ line) {
    Object^ node = nullptr;
    array<String^>^ data = line->Split(';');
    switch (type) {
    case T_LINK:
        if (data->Length == 2) {
            Link^ temp = gcnew Link();
            temp->ISBN = data[0]->Trim();
            temp->dis_code = data[1]->Trim();
            node = temp;
        }
        break;
    case T_BOOK:
        if (data->Length == 3) {
            Book^ temp = gcnew Book();
            temp->ISBN = data[0]->Trim();
            temp->title = data[1]->Trim();
            temp->author = data[2]->Trim();
            node = temp;
        }
        break;
    case T_SUBJECT:
        if (data->Length == 3) {
            Subject^ temp = gcnew Subject();
            temp->dis_code = data[0]->Trim();
            temp->name = data[1]->Trim();
            temp->description = data[2]->Trim();
            node = temp;
        }
        break;
    default:
        Console::WriteLine("Ошибка, выбран некорректный формат данных");
        break;
    }
    return node;
}
void DataManager::AddNode(DataType type, Object^ node) {
    switch (type) {
    case T_LINK:
        this->listLinks->Add(node);
        Console::WriteLine("В список связей добавлена запись");
        break;
    case T_BOOK:
        this->listBooks->Add(node);
        Console::WriteLine("В список книг добавлена запись");
        break;
    case T_SUBJECT:
        this->listSubjects->Add(node);
        Console::WriteLine("В список дисциплин добавлена запись");
        break;
    default:
        Console::WriteLine("Ошибка, выбран некорректный формат данных");
        break;
    }
}
void DataManager::DeleteNode(DataType type, Object^ node) {
    Link^ t_link = nullptr;
    Book^ t_book = nullptr;
    Subject^ t_subj = nullptr;
    int del_count = 0;
    switch (type) {
    case T_LINK:
        t_link = dynamic_cast <Link^> (node);
        for (int i = 0; i < this->listLinks->Count; i++) {
            Link^ link = dynamic_cast <Link^> (this->listLinks[i]);
            if (t_link->ISBN == link->ISBN && t_link->dis_code == link->dis_code) {
                this->listLinks->RemoveAt(i);
                break;
            }
        }
        Console::WriteLine("Из списка связей удалена запись");
        break;
    case T_BOOK:
        t_book = dynamic_cast<Book^>(node);
        for (int i = 0; i < this->listBooks->Count; i++) {
            Book^ book = dynamic_cast <Book^> (this->listBooks[i]);
            if (t_book->ISBN == book->ISBN) {
                for (int j = 0; j < this->listLinks->Count; j++) {
                    Link^ link = dynamic_cast <Link^> (this->listLinks[j]);
                    if (link->ISBN == t_book->ISBN) {
                        this->listLinks->RemoveAt(j);
                        del_count++;
                    }
                }
                this->listBooks->RemoveAt(i);
                break;
            }
        }
        Console::WriteLine("Из списка книг удалена запись");
        if (del_count > 0) {
            Console::WriteLine("Вслед удалено " + del_count + " записей из списка связей");
        }
        break;
    case T_SUBJECT:
        t_subj = dynamic_cast<Subject^>(node);
        for (int i = 0; i < this->listSubjects->Count; i++) {
            Subject^ subj = dynamic_cast <Subject^> (this->listSubjects[i]);
            if (t_subj->dis_code == subj->dis_code) {
                for (int j = 0; j < this->listLinks->Count; j++) {
                    Link^ link = dynamic_cast <Link^> (this->listLinks[j]);
                    if (link->dis_code == t_subj->dis_code) {
                        this->listLinks->RemoveAt(j);
                        del_count++;
                    }
                }
                this->listSubjects->RemoveAt(i);
                break;
            }
        }
        Console::WriteLine("Из списка дисциплин удалена запись");
        if (del_count > 0) {
            Console::WriteLine("Вслед удалено " + del_count + " записей из списка связей");
        }
        break;
    default:
        Console::WriteLine("Ошибка, выбран некорректный формат данных");
        break;
    }
}
List<Object^>^ DataManager::FindNodes(DataType type, String^ line) {
    int find_count = 0;
    List<Object^>^ list = gcnew List<Object^>();
    switch (type) {
    case T_LINK:
        for each (Link^ link in (this->listLinks)) {
            if (link->ISBN->ToLower()->Contains(line) || link->dis_code->ToLower()->Contains(line)) {
                list->Add(link);
                find_count++;
            }
        }
        break;
    case T_BOOK:
        for each (Book^ book in (this->listBooks)) {
            if (book->ISBN->ToLower()->Contains(line) || book->title->ToLower()->Contains(line) || book->author->ToLower()->ToLower()->Contains(line)) {
                list->Add(book);
                find_count++;
            }
        }
        break;
    case T_SUBJECT:
        for each (Subject^ subj in (this->listSubjects)) {
            if (subj->dis_code->ToLower()->Contains(line) || subj->name->ToLower()->Contains(line) || subj->description->ToLower()->Contains(line)) {
                list->Add(subj);
                find_count++;
            }
        }
        break;
    default:
        Console::WriteLine("Ошибка, выбран некорректный формат данных");
        break;
    }
    Console::WriteLine("Найдено " + find_count + " записей по заданной строке");
    return list;
}