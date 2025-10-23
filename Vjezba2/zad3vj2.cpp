#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

struct Matrica
{
    int m, n;
    double** el;
};

void alociraj(Matrica& A, int m, int n)
{
    A.m = m; A.n = n;
    A.el = new double*[m];
    for (int i = 0; i < m; i++)
        A.el[i] = new double[n]{};
}

void dealociraj(Matrica& A)
{
    for (int i = 0; i < A.m; i++)
        delete[] A.el[i];
    delete[] A.el;
    A.el = nullptr;
}

void unos(Matrica& A)
{
    for (int i = 0; i < A.m; i++)
        for (int j = 0; j < A.n; j++)
            std::cin >> A.el[i][j];
}

void generiraj(Matrica& A, double a, double b)
{
    for (int i = 0; i < A.m; i++)
        for (int j = 0; j < A.n; j++)
            A.el[i][j] = a + (b - a) * rand() / (double)RAND_MAX;
}

Matrica zbroji(const Matrica& A, const Matrica& B)
{
    Matrica C; alociraj(C, A.m, A.n);
    for (int i = 0; i < A.m; i++)
        for (int j = 0; j < A.n; j++)
            C.el[i][j] = A.el[i][j] + B.el[i][j];
    return C;
}

Matrica oduzmi(const Matrica& A, const Matrica& B)
{
    Matrica C; alociraj(C, A.m, A.n);
    for (int i = 0; i < A.m; i++)
        for (int j = 0; j < A.n; j++)
            C.el[i][j] = A.el[i][j] - B.el[i][j];
    return C;
}

Matrica mnozi(const Matrica& A, const Matrica& B)
{
    Matrica C; alociraj(C, A.m, B.n);
    for (int i = 0; i < A.m; i++)
        for (int j = 0; j < B.n; j++)
            for (int k = 0; k < A.n; k++)
                C.el[i][j] += A.el[i][k] * B.el[k][j];
    return C;
}

Matrica transponiraj(const Matrica& A)
{
    Matrica T; alociraj(T, A.n, A.m);
    for (int i = 0; i < A.m; i++)
        for (int j = 0; j < A.n; j++)
            T.el[j][i] = A.el[i][j];
    return T;
}

void ispisi(const Matrica& A)
{
    for (int i = 0; i < A.m; i++)
    {
        for (int j = 0; j < A.n; j++)
            std::cout << std::setw(10) << std::fixed << std::setprecision(4) << A.el[i][j];
        std::cout << '\n';
    }
}

int main()
{
    srand((unsigned)time(nullptr));

    Matrica A, B, C;
    alociraj(A, 2, 3);
    alociraj(B, 3, 2);

    generiraj(A, 1, 5);
    generiraj(B, 1, 5);

    ispisi(A);
    std::cout << '\n';
    ispisi(B);
    std::cout << '\n';

    C = mnozi(A, B);
    ispisi(C);

    Matrica T = transponiraj(A);
    std::cout << '\n';
    ispisi(T);

    dealociraj(A);
    dealociraj(B);
    dealociraj(C);
    dealociraj(T);
    return 0;
}
