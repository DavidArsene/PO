#include <iostream>

class Book {
	char *author, *title;
	int pages_nr;
	int *page_wordcount;
	bool online;

public:
	void set_author(char* author) {
        int length = strlen(author) + 1;
		this->author = new char[length];
		strcpy_s(this->author, length, author);
	}

	void set_title(char* title) {
        int length = strlen(title) + 1;
		this->title = new char[length];
		strcpy_s(this->title, length, title);
	}

	void set_pages_nr(int pages_nr) { this->pages_nr = pages_nr; }

	void set_page_wordcount(int* page_wordcount) {
		this->page_wordcount = new int[this->pages_nr];
        memcpy(this->page_wordcount, page_wordcount, this->pages_nr * sizeof(int));
	}

	void set_online(bool online) { this->online = online; }

	Book(char* author, char* title, int pages_nr, int* page_wordcount, bool online) {
		set_author(author);
		set_title(title);
		set_pages_nr(pages_nr);
		set_page_wordcount(page_wordcount);
		set_online(online);
	}

	Book(const Book& book) : Book(book.author, book.title, book.pages_nr, book.page_wordcount, book.online) {}
	
	~Book() {
		delete[] this->author;
		delete[] this->title;
		delete[] this->page_wordcount;
	}
};

int main() {
	int page_wordcount[5] = { 500, 1000, 10000, 20, 12 };
	Book book("George Orwell", "1984", 5, page_wordcount, true);
}
