#include <iostream>

using namespace std;

int bookids[100];
string booktitles[100];
string bookauthors[100];
bool isborrowed[100];
int bookcount=0;

void addbook()
{

    int id;
    string title,author;
    bool uID = false;

    while(!uID)
    {
        cout << "Enter book ID : " << endl;
        cin >> id;

        uID = true;
        for(int i = 0; i < bookcount; i++)
        {
            if(bookids[i] == id)
            {
                cout << "This ID already exists! Please enter a different ID." << endl;
                uID = false;
                break;
            }
        }
    }
    cout<<endl;
    cout<<"Enter book title : "<<endl;
    cin>>title;
    cout<<endl;
    cout<<"Enter book author : "<<endl;
    cin>>author;
    cout<<endl;
    bookids[bookcount]=id;
    booktitles[bookcount]=title;
    bookauthors[bookcount]=author;
    isborrowed[bookcount]=false;

    bookcount++;

    cout<<"The book has been added"<<endl;

    cout<<endl<<endl<<endl;
    cout<<"____________________________________________________\n";
    cout<<endl;

}

void displayBooks()
{
    if (bookcount == 0)
    {
        cout << " there are no books in the library. "<<endl;
        cout<<endl;
        cout<<"____________________________________________________\n";

        return;
    }
    for(int i=0; i<bookcount; i++)
    {
        cout<<" Book ID     : "<<bookids[i]<<endl;
        cout<<" Book title  : "<<booktitles[i]<<endl;
        cout<<" Book author : "<<bookauthors[i]<<endl;
        cout<<" Book status : "<<(isborrowed[i]==0 ? " available " : " not available ")<<endl;
        cout<<"---------------------------\n";
    }
    cout<<endl<<endl;
    cout<<"          Done!"<<endl;
    cout<<endl<<endl;
    cout<<"____________________________________________________\n";
    cout<<endl;
}

void borrowBook()
{
    cout<<endl;
    cout<<endl;
    int idr;
    bool found = false;

    cout<<"Enter the book ID : "<<endl;
    cin>>idr;
    cout<<endl;
    for(int i=0; i<bookcount; i++)
    {
        if(idr==bookids[i])
        {
            if (!isborrowed[i])
            {
                isborrowed[i]=true;
                cout<<" the book has been borrowed "<<endl;
            }
            else
            {
                cout<<"you can not borrow the book"<<endl;

            }
            found=true;
            break;

        }
    }
    if (!found)
    {
        cout << " Book not found. ";
    }
    cout<<endl;
    cout<<"____________________________________________________\n";
    cout<<endl;
}

void returnBook()
{
    cout<<endl;
    cout<<endl;
    int idr;
    bool found=false;
    cout<<"Enter the book ID : "<<endl;
    cin>>idr;
    cout<<endl;
    cout<<endl;
    for(int i=0; i<bookcount; i++)
    {
        if(idr==bookids[i])
        {
            if(isborrowed[i])
            {
                cout<<" the book has been returned "<<endl;
                isborrowed[i]=false;
            }
            else
            {
                cout<<" this book is not borrowed "<<endl;
            }
            found=true;
            break;
        }
    }
    if (!found)
    {
        cout << " Book not found. ";
    }
    cout<<endl;
    cout<<"____________________________________________________\n";
    cout<<endl;
}

int main()
{
    bookids[bookcount] = 1;
    booktitles[bookcount] = "C++";
    bookauthors[bookcount] = "Samer";
    isborrowed[bookcount] = false;
    bookcount++;

    bookids[bookcount] = 2;
    booktitles[bookcount] = "Data Structures";
    bookauthors[bookcount] = "Anas";
    isborrowed[bookcount] = false;
    bookcount++;

    bookids[bookcount] = 3;
    booktitles[bookcount] = "java";
    bookauthors[bookcount] = "Rateb";
    isborrowed[bookcount] = false;
    bookcount++;

    bookids[bookcount] = 4;
    booktitles[bookcount] = "AI";
    bookauthors[bookcount] = "Baraa";
    isborrowed[bookcount] = false;
    bookcount++;

    bookids[bookcount] = 5;
    booktitles[bookcount] = "c#";
    bookauthors[bookcount] = "Ahmed";
    isborrowed[bookcount] = false;
    bookcount++;

    while(true)
    {
        cout<<"      //Library menu//  "<<endl;
        cout<<endl;
        cout<<" 1. add new book "<<endl;
        cout<<" 2. display the books "<<endl;
        cout<<" 3. borrow book "<<endl;
        cout<<" 4. retern book  "<<endl;
        cout<<" 0. Exit "<<endl;
        cout<<endl;
        cout<<"____________________________________________________"<<endl;
        cout<<endl;

        int choice;

        cout<<"Choose: ";

        cin>>choice;
        cout<<endl;
        cout<<"____________________________________________________"<<endl;
        cout<<endl;

        switch (choice)
        {
        case 1:
            addbook();
            break;
            cout<<endl;
            cout<<"____________________________________________________"<<endl;
            cout<<endl;
        case 2:
            displayBooks();
            break;
            cout<<endl;
            cout<<endl;
            cout<<"____________________________________________________"<<endl;
            cout<<endl;
        case 3:
            borrowBook();
            break;
            cout<<endl;
            cout<<"____________________________________________________"<<endl;
            cout<<endl;
        case 4:
            returnBook();
            break;
            cout<<endl;
            cout<<"____________________________________________________"<<endl;
            cout<<endl;
        case 0:
            cout<<"thanks for using our library!!"<<endl;
            cout<<endl;
            cout<<"____________________________________________________"<<endl;
            cout<<endl;

            return 0;
        default :
            cout<<endl;
            cout<<"Enter a Correct Choice !!"<<endl;
            cout<<endl;
            cout<<"____________________________________________________"<<endl;
            cout<<endl;
        }
    }
}
