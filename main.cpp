
#include <iostream>
#include <cctype>
using namespace std;

// Function declarations (prototypes)
char **CreateArrayOfSeats(int NumberOfRows, int seats);
void InitializeSeats (char **ArrayOfSeats, int NumberOfRows, int seats);
void DisplayArrayOfSeats (char **ArrayOfSeats, int NumberOfRows, int seats, int rowNumber, int columnNumber, char seatSelection);
void MemoryCleanup (char **ArrayOfSeats, int NumberOfRows, int seats);

int numberOfSeatsOccupied = 0;

int main(int argc, char* argv[])
{
char **ArrayOfSeats;
int NumberOfRows = 0;
int NumberOfSeats = 0;
int rowNumber = 0;
int columnNumber = 0;
char rowSelection; // 1 to max NumberOfRows, input from the user
char seatSelection='*'; // 'A' to max seats, input from the user, convert to a number
int row; // index into ArrayOfSeats, 0 to NumberOfRows-1
int seat; // index into ArrayOfSeats, 0 to seats-1

// get the number of NumberOfRows and seats from the user
{
cout << "Enter the number of NumberOfRows: ";
cin >> NumberOfRows;
cout << "Enter the number of seats on each row: ";
cin >> NumberOfSeats;
}
ArrayOfSeats = CreateArrayOfSeats(NumberOfRows, NumberOfSeats);
InitializeSeats (ArrayOfSeats, NumberOfRows, NumberOfSeats);
DisplayArrayOfSeats (ArrayOfSeats, NumberOfRows, NumberOfSeats, rowNumber, columnNumber, seatSelection);

do
{
cout << endl << "Enter a seat selection" << endl << " (example 5F -or- 00 to quit): ";
cin >> rowSelection; // get row from the user
cin >> seatSelection;

// get the seat from the user
if (rowSelection=='0')
continue; // skip the rest of the loop

seatSelection = toupper(seatSelection); // convert to upper case
row = rowSelection - '1'; // count from zero to work with the array
seat = seatSelection - 'A';

DisplayArrayOfSeats (ArrayOfSeats, NumberOfRows, NumberOfSeats, row, seat, seatSelection);

} while (rowSelection != '0');
MemoryCleanup (ArrayOfSeats, NumberOfRows, NumberOfSeats); // return the memory
return 0;
}

char **CreateArrayOfSeats (int NumberOfRows, int seats) // ** means pointer to pointers
{
char **ArrayOfSeats;
ArrayOfSeats = new char*[NumberOfRows]; // create array of pointers for

for(int r = 0; r < NumberOfRows; r++)
ArrayOfSeats[r] = new char[seats]; // create an array of seats for each row
return ArrayOfSeats; // return pointer to the array back to main program
}

void InitializeSeats (char **ArrayOfSeats, int NumberOfRows, int seats)
{
for (int r=0; r<NumberOfRows; r++) // initialize the data for each row
{
for (int s=0; s<seats; s++)
ArrayOfSeats[r][s] = 'A' + s; // put 'A' 'B' 'C' etc in each row
}
}
void DisplayArrayOfSeats (char **ArrayOfSeats, int NumberOfRows, int NumberOfSeats, int rowNumber, int columnNumber, char seatSelection)
{
if(ArrayOfSeats[rowNumber][columnNumber] == '-')
{
cout<<"The seat is already taken"<<endl;
}
else
{
for (int r=0; r<NumberOfRows; r++) // for each row
{
cout.width(2);
cout << r+1 << ' '; // Display row numbers starting from 1

for (int s=0; s<NumberOfSeats; s++)
{
if(seatSelection != '*')
{
ArrayOfSeats[rowNumber][columnNumber] = '-';
}
cout << ArrayOfSeats[r][s] << ' ';
} // Display info for each seat
cout << endl; // new line after each row
}
//Print total number of seats and occupied seats

if(seatSelection != '*')
numberOfSeatsOccupied++;
cout<<"Total number of seats: "<<((NumberOfSeats*NumberOfRows)-numberOfSeatsOccupied)<<endl;

if(numberOfSeatsOccupied > 0)
{
cout<<"Total seats occupied: "<<numberOfSeatsOccupied<<endl;

//Check if all the seats are taken
if((NumberOfSeats*NumberOfRows) == numberOfSeatsOccupied)
{
cout<<"All the seats are taken";

//Exit the program
exit(0);
}
}
}
}
void MemoryCleanup (char **ArrayOfSeats, int NumberOfRows, int NumberOfSeats)
{
for (int r=0; r<NumberOfRows; r++)
delete [] ArrayOfSeats[r]; // delete each row of seats individually
delete [] ArrayOfSeats; // delete the row array
}
