#include <stdio.h>
#include <stdlib.h>

void * operator new(size_t unSize)
{
    printf("operator new called, size: %u\n", unSize);
    return malloc(unSize);
}

void * operator new(size_t unSize, int nLine, const char * pFunc)
{
    printf("operator new called, size: %u, line: %d, func: %s\n", unSize, nLine, pFunc);
    return malloc(unSize);
}

void operator delete(void * pMem)
{
    printf("delete1\n");
    free(pMem);
}

class A
{
public:
    A(int a = 0) : _a(a)
    {
        printf("constructor A called\n");
    }

    ~A()
    {
        printf("~A()\n");
    }

    static void operator delete(void * pMem, size_t unSize)
    {
        printf("delete2: %u\n", unSize);
        free(pMem);
    }

private:
    int _a;
};

class B : public A
{
public:
    B()
    {
        printf("constructor B called\n");
    }

    ~B()
    {
        printf("~B()\n");
    }

    int _b;
    int _bb;
};

int main()
{
    A * pA = new A(10);
    printf("#####\n");

    A * pB = new (__LINE__, __func__) B();
    B * pB2 = new (__LINE__, __func__) B();
    printf("#####\n");

    A * szA = new A[10];
    printf("#####\n");

    delete pA;
    printf("#####\n");

    delete pB;  // mem leak?
    delete pB2;
    printf("#####\n");

    delete [] szA;
    printf("#####\n");

    char * pC = NULL;
    delete pC;
}