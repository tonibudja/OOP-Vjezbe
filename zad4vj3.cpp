#include <iostream>
#include <string>
#include <cstddef>

struct Student
{
    std::string ime;
    std::string JMBAG;
    int godinaStudija;
    int ectsBodovi;
    double prosjek;
};

void filter_students(Student studenti[], std::size_t n,
    void (*akcija)(Student&),
    bool (*filter)(Student&))
{
    for (std::size_t i = 0; i < n; i++)
    {
        if (filter(studenti[i]))
        {
            akcija(studenti[i]);
        }
    }
}

void ispisiStudenta(Student& s)
{
    std::cout << s.ime << " (" << s.JMBAG << "), godina: "
        << s.godinaStudija << ", ECTS: " << s.ectsBodovi
        << ", prosjek: " << s.prosjek << "\n";
}

void povecajGodinu(Student& s)
{
    s.godinaStudija++;
}

int main()
{
    Student studenti[] = {
        {"Ivan Ivi?", "001", 1, 5, 3.2},
        {"Ana Ani?i?", "002", 1, 0, 4.0},
        {"Marko Marki?", "003", 2, 50, 3.8},
        {"Lucija Luci?", "004", 3, 60, 4.2},
        {"Petar Petri?", "005", 1, 10, 2.8}
    };
    std::size_t n = sizeof(studenti) / sizeof(studenti[0]);

    std::cout << "Prva godina, barem jedan ispit:\n";
    filter_students(studenti, n, ispisiStudenta,
        [](Student& s) { return s.godinaStudija == 1 && s.ectsBodovi > 0; });

    std::cout << "\nStudenti s prosjekom > 3.5:\n";
    filter_students(studenti, n, ispisiStudenta,
        [](Student& s) { return s.prosjek > 3.5; });

    filter_students(studenti, n, povecajGodinu,
        [](Student& s) { return s.ectsBodovi >= 45; });

    std::cout << "\nStudenti nakon pove?anja godine za ECTS >= 45:\n";
    for (auto& s : studenti)
        ispisiStudenta(s);

    return 0;
}
