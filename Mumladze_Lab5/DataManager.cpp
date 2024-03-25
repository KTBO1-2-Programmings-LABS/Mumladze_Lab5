#include "DataManager.h"

using namespace System;
using namespace System::IO;

LinkManager::LinkManager() {
    this->fileName = gcnew String("./Data/Links.txt");
    this->links = gcnew List<Object^>();
}
void LinkManager::ReadLinkListFromFile(void) {
    StreamReader^ sr = gcnew StreamReader(this->fileName);
    String^ line;
    while ((line = sr->ReadLine()) != nullptr) {
        this->AddLinkToList(line);
    }
    sr->Close();
}
void LinkManager::WriteLinkListToFile(void) {
    StreamWriter^ sw = File::CreateText(this->fileName);
    try {
        for each (Link ^ link in (this->links)) {
            sw->WriteLine("{0}, {1}", link->ISBN, link->dis_code);
        }
    }
    finally {
        if (sw != nullptr) sw->Close();
    }
}
void LinkManager::AddLinkToList(String^ line) {
    array<String^>^ linkData = line->Split(';');
    if (linkData->Length == 2) {
        Link^ temp = gcnew Link();
        temp->ISBN = linkData[0]->Trim();
        temp->dis_code = linkData[1]->Trim();
        this->links->Add(temp);
    }
}
void LinkManager::RemoveLinkFromList(String^ ISBN, String^ dis_code) {
    for (int i = 0; i < this->links->Count; ++i) {
        Link^ link = dynamic_cast <Link^> (this->links[i]);
        if (link != nullptr && link->ISBN == ISBN && link->dis_code == dis_code) {
            this->links->RemoveAt(i);
            break;
        }
    }
}
void LinkManager::RemoveAllLinksByBook(String^ ISBN) {
    for (int i = 0; i < this->links->Count; ++i) {
        Link^ link = dynamic_cast <Link^> (this->links[i]);
        if (link != nullptr && link->ISBN == ISBN) {
            this->links->RemoveAt(i);
        }
    }
}
void LinkManager::RemoveAllLinksBySubject(String^ dis_code) {
    for (int i = 0; i < this->links->Count; ++i) {
        Link^ link = dynamic_cast <Link^> (this->links[i]);
        if (link != nullptr && link->dis_code == dis_code) {
            this->links->RemoveAt(i);
        }
    }
}
List<Object^>^ LinkManager::FindSubjectsByBook(String^ ISBN) {
    List<Object^>^ subjects = gcnew List<Object^>();
    for (int i = 0; i < this->links->Count; ++i) {
        Link^ link = dynamic_cast <Link^> (this->links[i]);
        if (link != nullptr && link->ISBN == ISBN) {
            subjects->Add(link->dis_code);
        }
    }
    return subjects;
}
List<Object^>^ LinkManager::FindBooksBySubject(String^ dis_code) {
    List<Object^>^ books = gcnew List<Object^>();
    for (int i = 0; i < this->links->Count; ++i) {
        Link^ link = dynamic_cast <Link^> (this->links[i]);
        if (link != nullptr && link->dis_code == dis_code) {
            books->Add(link->dis_code);
        }
    }
    return books;
}


BookManager::BookManager(LinkManager^ lm) {
    this->fileName = gcnew String("./Data/Books.txt");
    this->books = gcnew List<Object^>();
    this->lm = lm;
}
void BookManager::ReadBookListFromFile(void) {
    StreamReader^ sr = gcnew StreamReader(this->fileName);
    String^ line;
    while ((line = sr->ReadLine()) != nullptr) {
        this->AddBookToList(line);
    }
    sr->Close();
}
void BookManager::WriteBookListToFile(void) {
    StreamWriter^ sw = File::CreateText(this->fileName);
    try {
        for each (Book^ book in (this->books)) {
            sw->WriteLine("{0}, {1}, {2}", book->ISBN, book->title, book->author);
        }
    }
    finally {
        if (sw != nullptr) sw->Close();
    }
}
void BookManager::AddBookToList(String^ line) {
    array<String^>^ bookData = line->Split(';');
    if (bookData->Length == 3) {
        Book^ temp = gcnew Book();
        temp->ISBN = bookData[0]->Trim();
        temp->title = bookData[1]->Trim();
        temp->author = bookData[2]->Trim();
        this->books->Add(temp);
    }
}
void BookManager::RemoveBookFromList(String^ ISBN) {
    for (int i = 0; i < this->books->Count; ++i) {
        Book^ book = dynamic_cast <Book^> (this->books[i]);
        if (book != nullptr && book->ISBN == ISBN) {
            lm->RemoveAllLinksByBook(ISBN);
            this->books->RemoveAt(i);
            break; 
        }
    }
}
String^ BookManager::FindISBNByName(String^ title) {
    for (int i = 0; i < this->books->Count; i++) {
        Book^ book = dynamic_cast <Book^> (this->books[i]);
        if (book != nullptr && book->title == title) {
            return book->ISBN;
        }
    }
    return nullptr;
}


SubjectManager::SubjectManager(LinkManager^ lm) {
    this->fileName = gcnew String("./Data/Subjects.txt");
    this->subjects = gcnew List<Object^>();
    this->lm = lm;
}
void SubjectManager::ReadSubjectListFromFile(void) {
    StreamReader^ sr = gcnew StreamReader(this->fileName);
    String^ line;
    while ((line = sr->ReadLine()) != nullptr) {
        this->AddSubjectToList(line);
    }
    sr->Close();
}
void SubjectManager::WriteSubjectListToFile(void) {
    StreamWriter^ sw = File::CreateText(this->fileName);
    try {
        for each (Subject^ subject in (this->subjects)) {
            sw->WriteLine("{0}, {1}, {2}", subject->dis_code, subject->name, subject->description);
        }
    }
    finally {
        if (sw != nullptr) sw->Close();
    }
}
void SubjectManager::AddSubjectToList(String^ line) {
    array<String^>^ subjectData = line->Split(';');
    if (subjectData->Length == 3) {
        Subject^ temp = gcnew Subject();
        temp->dis_code = subjectData[0]->Trim();
        temp->name = subjectData[1]->Trim();
        temp->description = subjectData[2]->Trim();
        this->subjects->Add(temp);
    }
}
void SubjectManager::RemoveSubjectFromList(String^ dis_code) {
    for (int i = 0; i < this->subjects->Count; ++i) {
        Subject^ subject = dynamic_cast <Subject^> (this->subjects[i]);
        if (subject != nullptr && subject->dis_code == dis_code) {
            lm->RemoveAllLinksBySubject(dis_code);
            this->subjects->RemoveAt(i);
            break;
        }
    }
}
String^ SubjectManager::FindDisCodeByName(String^ name) {
    for (int i = 0; i < this->subjects->Count; i++) {
        Subject^ subject = dynamic_cast <Subject^> (this->subjects[i]);
        if (subject != nullptr && subject->name == name) {
            return subject->dis_code;
        }
    }
    return nullptr;
}