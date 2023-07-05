#include"library.h"

int main()
{
    Library *library = new Library;
    library->run();
    delete library;
    library = nullptr;
}
