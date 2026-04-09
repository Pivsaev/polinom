#include "List.h"

List::List():count(0)
{
    head = new Link(nullptr, nullptr);
    head->SetNextLink(head);
    tail = head;
}

List::~List()
{
    if (head == nullptr) return;
    Link* curr = head->GetNextLink();
    while (curr != head) {
        Link* temp = curr;
        curr = curr->GetNextLink();
        delete temp;
    }
    delete head;
    head = nullptr;
    tail = nullptr;
    count = 0;
}

List& List::operator=(const List& other)
{
    if (this != &other) {
        if (head != nullptr) {
            Link* curr = head->GetNextLink();
            while (curr != head) {
                Link* temp = curr;
                curr = curr->GetNextLink();
                delete temp;
            }
            head->SetNextLink(head);
            tail = head;
            count = 0;
        }
        if (!other.IsEmpty()) {
            Link* currOther = other.head->GetNextLink();
            while (currOther != other.head) {
                Monom* newMonom = new Monom(currOther->GetMonomData()->GetKoeff(),
                    currOther->GetMonomData()->GetSvertka());
                Link* newLink = new Link(newMonom);
                Insert(newLink);
                currOther = currOther->GetNextLink();
            }
        }
    }
    return *this;
}

void List::Insert(Link* newLink)
{
    tail->SetNextLink(newLink);
    newLink->SetNextLink(head);
    tail = newLink;
    count++;
}

Link* List::FindBySvertka(int _svertka) const
{
    if (IsEmpty()) return nullptr;
    Link* curr = head->GetNextLink();
    while (curr != head) {
        if (curr->GetMonomData()->GetSvertka() == _svertka)
            return curr;
        curr = curr->GetNextLink();
    }
    return nullptr;
}

Link* List::GetHead() const
{
    return head->GetNextLink();
}

bool List::IsEmpty() const
{
    return count==0;
}

void List::Remove(Link* linkToRemove)
{
    if (linkToRemove == nullptr || IsEmpty()) return;
    Link* prev = head;
    Link* curr = head->GetNextLink();
    while (curr != head && curr != linkToRemove) {
        prev = curr;
        curr = curr->GetNextLink();
    }
    if (curr == linkToRemove) {
        prev->SetNextLink(curr->GetNextLink());
        if (curr == tail) {
            tail = prev;
        }
        delete curr;
        count--;

        if (IsEmpty()) {
            head->SetNextLink(head);
            tail = head;
        }
    }
}

int List::GetCount() const
{
    return count;
}

Link* List::GetDummy() const {
    return head;
}

std::ostream& operator<<(std::ostream& out, const List& list)
{
    if (list.IsEmpty()) {
        out << "[]";
        return out;
    }
    out << "[";
    Link* curr = list.head->GetNextLink();
    bool first = true;
    while (curr != list.head) {
        if (!first) out << "; ";
        out << *curr->GetMonomData();
        first = false;
        curr = curr->GetNextLink();
    }
    out << "] head=" << *list.head->GetNextLink()->GetMonomData();
    out << "; tail=" << *list.tail->GetMonomData();
    out << "; count=" << list.count;
    return out;
}
