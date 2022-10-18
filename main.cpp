//03-3-2022
//This program creates a linked list of composers and the date they
//died. Then it gives the user the option to display the list, remove
//a composer from the list, search for a composer in the list, or exit.

#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Composer.h"
#include <iomanip>

using namespace std;

void parseFile(ifstream&, LinkedList<Composer>&);
void userOptions(LinkedList<Composer>&);

int main() {
    ifstream inFile;
    inFile.open("composers.txt");

    if(inFile) {
        LinkedList<Composer> composer;
        parseFile(inFile, composer);
        inFile.close();
        userOptions(composer);
    }
    else
        cout << "File is not found or can not be opened" << endl;

    return 0;
}

typedef struct data_t {
    string Name;
    string Death;
};

data_t parseLine(ifstream& inFile) {
    data_t data;
    getline(inFile, data.Name, ',');
    getline(inFile, data.Death);
    return data;
}

//This function receives and linked list composer object and a file
//of composers and their deaths and assigns names and deaths to the
// linked list
void parseFile(ifstream& inFile, LinkedList<Composer>& composer) {

    data_t data;
    data = parseLine(inFile);

    while(inFile){
        Composer c2(data.Name, stoi(data.Death));
        composer.insert(c2);

        data = parseLine(inFile);
    }
}

//This function receives and linked list composer object and gives
//the user options to edit the composer list.
void userOptions(LinkedList<Composer>& composer) {
    char decision;
    int exit = 0;
    string Name;

    do {
        cout << "Enter 's' to search, 'r' to remove, "
                "'d' to display, or 'e' to exit: ";
        cin >> decision;

        if (decision == 's' || decision == 'S') {
            cout << "Enter a composer's name to search for: ";
            cin.ignore();
            getline(cin, Name);

            cout << endl;
            Composer temp;
            temp.setName(Name);

            int found = false;
            found = composer.find(temp);

            if(found){
                cout << left << setw(10) << " " << Name
                            << " was found in the list\n" << endl;
            }
            else
                cout << left << setw(10) << " " << Name << " was not found "
                                                "in the list\n" << endl;
        }
        else if (decision == 'r' || decision == 'R') {
            string removeName;
            cout << "Enter a composer's name to remove: ";
            cin.ignore();
            getline(cin, removeName);

            Composer temp;
            temp.setName( removeName);

            int found = composer.find(temp);
            if(!found){
                cout << left << setw(10) << " " << "Composer "
                                                   "can't be removed because "
                        << removeName << " is not in the list." << endl;
            }
            else {
                composer.remove(temp);
                cout << endl;
                cout << left << setw(10) << " " << removeName
                                            << " was successfully "
                                            "removed from the list\n" << endl;
            }
        }
        else if (decision == 'd' || decision == 'D') {
            cout << endl;
            composer.printList();
            cout << "\n\n";
        }
        else if (decision == 'e' || decision == 'E') {
            exit = 1;
        }
        else {
            cout << left << setw(10) << " " << "Please enter a valid option:"
                               " s, r, d, or e" << endl;
        }

    } while (exit == 0);
}

/*
Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit: d

Claudio Monteverdi - 1643
Henry Purcell - 1695
Antonio Vivaldi - 1741
Johann Sebastian Bach - 1750
George Frideric Handel - 1759
Wolfgang Amadeus Mozart - 1791
Joseph Haydn - 1809
Ludwig van Beethoven - 1827
Franz Schubert - 1828
Felix Mendelssohn - 1847
Frederic Chopin - 1849
Robert Schumann - 1856
Hector Berlioz - 1869
Richard Wagner - 1883
Franz Liszt - 1886
Pyotr Ilyich Tchaikovsky - 1893
Johannes Brahms - 1897
Giuseppe Verdi - 1901
Antonin Dvorak - 1904
Edvard Grieg - 1907
Gustav Mahler - 1911
Claude Debussy - 1918
Camille Saint-Saens - 1921
Giacomo Puccini - 1924
George Gershwin - 1937
Maurice Ravel - 1937
Sergei Rachmaninoff - 1943
Bela Bartok - 1945
Arnold Schoenberg - 1951
Sergei Prokofiev - 1953
Igor Stravinsky - 1971
Dmitri Shostakovich - 1975
Leonard Bernstein - 1990
Aaron Copland - 1990


Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit: s
Enter a composer's name to search for: Franz Liszt

          Franz Liszt was found in the list

Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit: r
Enter a composer's name to remove: Hector Berlioz

          Hector Berlioz was successfully removed from the list

Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit: f
          Please enter a valid option: s, r, d, or e
Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit: d

Claudio Monteverdi - 1643
Henry Purcell - 1695
Antonio Vivaldi - 1741
Johann Sebastian Bach - 1750
George Frideric Handel - 1759
Wolfgang Amadeus Mozart - 1791
Joseph Haydn - 1809
Ludwig van Beethoven - 1827
Franz Schubert - 1828
Felix Mendelssohn - 1847
Frederic Chopin - 1849
Robert Schumann - 1856
Richard Wagner - 1883
Franz Liszt - 1886
Pyotr Ilyich Tchaikovsky - 1893
Johannes Brahms - 1897
Giuseppe Verdi - 1901
Antonin Dvorak - 1904
Edvard Grieg - 1907
Gustav Mahler - 1911
Claude Debussy - 1918
Camille Saint-Saens - 1921
Giacomo Puccini - 1924
George Gershwin - 1937
Maurice Ravel - 1937
Sergei Rachmaninoff - 1943
Bela Bartok - 1945
Arnold Schoenberg - 1951
Sergei Prokofiev - 1953
Igor Stravinsky - 1971
Dmitri Shostakovich - 1975
Leonard Bernstein - 1990
Aaron Copland - 1990


Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit: e

Process finished with exit code 0
 */
