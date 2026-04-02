#include "List.h"

List::List():head(nullptr), tail(nullptr), count(0)
{
}

List::~List()
{
	while (head) {
		Link* temp = head;
		head = head->GetNextLink();
		delete temp;
	}
	tail = nullptr;
	count = 0;
}

List& List::operator=(const List& other)
{
    if (this != &other) {
        Link* curr = head;
        while (curr != nullptr) {
            Link* temp = curr;
            curr = curr->GetNextLink();
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
        count = 0;
        curr = other.head;
        while (curr != nullptr) {
            Monom* newMonom = new Monom(curr->GetMonomData()->GetKoeff(),
                curr->GetMonomData()->GetSvertka());
            Link* newLink = new Link(newMonom);
            if (head == nullptr) {
                head = newLink;
                tail = newLink;
            }
            else {
                tail->SetNextLink(newLink);
                tail = newLink;
            }
            count++;
            curr = curr->GetNextLink();
        }
    }
    return *this;
}

void List::Insert(Link* newLink)
{
	if (head == nullptr) {
		head = newLink;
		tail = newLink;
	}
	else {
		tail->SetNextLink(newLink);
		tail = newLink;
	}
	count++;
}

Link* List::FindBySvertka(int _svertka) const
{
    Link* curr = head;
    while (curr != nullptr) {
        if (curr->GetMonomData()->GetSvertka() == _svertka) {
            return curr;
        }
        curr = curr->GetNextLink();
    }
    return nullptr;
}

Link* List::GetHead() const
{
    return head;
}

bool List::IsEmpty() const
{
    return count==0;
}

void List::Remove(Link* linkToRemove)
{
    if (linkToRemove == nullptr) return;
    if (head == linkToRemove) {
        head = head->GetNextLink();
        if (head == nullptr) {
            tail = nullptr;
        }
        delete linkToRemove;
        count--;
        return;
    }
    Link* curr = head;
    while (curr != nullptr && curr->GetNextLink() != linkToRemove) {
        curr = curr->GetNextLink();
    }
    if (curr != nullptr) {
        curr->SetNextLink(linkToRemove->GetNextLink());
        if (linkToRemove == tail) {
            tail = curr;
        }
        delete linkToRemove;
        count--;
    }
}

int List::GetCount() const
{
    return count;
}

std::ostream& operator<<(std::ostream& out, const List& list)
{
    out << "[";
    if (list.head == nullptr) {
        out << "] head=nullptr tail=nullptr count=0";
        return out;
    }
    Link* curr = list.head;
    while (curr) {
        out << *curr->GetMonomData();
        curr = curr->GetNextLink();
        if (curr) out << "; ";
    }
    out << "] head=" << *list.head->GetMonomData();
    out << "; tail=" << *list.tail->GetMonomData();
    out << "; count=" << list.count;
    return out;
}
