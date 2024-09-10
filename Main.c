#include <iostream> // standard library for c++
#include <ctime>    //library for time
#include <unistd.h>
#include <string> //library for string1

#include <stdlib.h>
using namespace std;

class seats_reserving
{
    char **Arr_Seats;
    char arr2[3];
    char answer;
    int Numberofrow;
    int Numberofseats;
    int Available_seats;
    int rows;
    int seats;
    friend class Ticket;

public:
    char **ArrayOfSeats(int Numberofrow, int seats);
    void Initializing_seats(char **Arr_Seats, int Numberofrow, int seats);
    void DisplaySeats(char **Arr_Seats, int Numberofrow, int Numberofseats);
    void MemoryCleanup(char **Arr_Seats, int Numberofrow, int Numberofseats);
    string mainfunction();
};

//// CreatArrayOfSeats Function
char **seats_reserving::ArrayOfSeats(int Numberofrow, int seats)
{
    /*  char **Arr_Seats;
    Arr_Seats = new char*[Numberofrow];
    for (int r=0; r<Numberofrow; r++)
    Arr_Seats[r] = new char[seats];
    return Arr_Seats;*/

    char **Arr_Seats;
    Arr_Seats = new char *[Numberofrow];
    for (int r = 0; r < Numberofrow; r++)
        Arr_Seats[r] = new char[seats];
    return Arr_Seats;
}

///// Initializing_seats Function
void seats_reserving::Initializing_seats(char **Arr_Seats, int Numberofrow, int seats)
{
    for (int i = 0; i < Numberofrow; i++)
    {
        for (int j = 0; j < seats; j++)
            Arr_Seats[i][j] = 'A' + j;
    }
}

///// DisplaySeats Function
void seats_reserving::DisplaySeats(char **Arr_Seats, int Numberofrows, int Numberofseats)
{
    for (int i = 0; i < Numberofrow; i++)
    {
        cout.width(2);
        cout << i + 1 << ' ';
        for (int j = 0; j < Numberofseats; j++)
            cout << Arr_Seats[i][j] << ' ';
        cout << endl;
    }
}

///// MemoryCleanup Function
void seats_reserving::MemoryCleanup(char **Arr_Seats, int Numberofrow, int Numberofseats)
{
    for (int i = 0; i < Numberofrow; i++)
        delete[] Arr_Seats[i];
    delete[] Arr_Seats;
}

string seats_reserving::mainfunction()
{
    cout << "*THIS IS PERSONALIZED SEAT RESERVING SYSTEM*" << endl
         << "ENTER THE NUMBER OF ROWS OF YOUR DESIRED: ";
    cin >> Numberofrow;
    cout << "NOW ENTER THE NUMBER OF SEATS IN EACH ROW: ";
    cin >> Numberofseats;
    string seatsArr[Numberofseats];
    Available_seats = Numberofrow * Numberofseats;

    Arr_Seats = ArrayOfSeats(Numberofrow, Numberofseats);
    Initializing_seats(Arr_Seats, Numberofrow, Numberofseats);
    DisplaySeats(Arr_Seats, Numberofrow, Numberofseats);
    string reservedSeats = " ";

    do
    {
        do
        {
            cout << " " << endl;
            cout << "THERE ARE " << Available_seats << " SEATS AVAILABLE, CHOOSE ANY ONE:(SELECT LIKE 1A)" << endl;
            cin >> arr2;
            reservedSeats = reservedSeats + " " + arr2;

            rows = arr2[0] - '1';
            if (arr2[1] >= '0' && arr2[1] <= '9') // In case there are more than 9 rows
            {
                rows += 1;
                rows *= 10;
                rows += (arr2[1] - '1');
                arr2[1] = arr2[2];
            }
            arr2[1] = toupper(arr2[1]);
            seats = arr2[1] - 'A';
            if (rows < 0 || rows > Numberofrow - 1)
                cout << "Row selections go from 1 to " << Numberofrow << ". Try a different row.." << endl;
            if (seats < 0 || seats > Numberofseats - 1)
                cout << "Seat selections go from A to " << char('A' + (Numberofseats - 1)) << ". Try a different seat.." << endl;

        } while (rows < 0 || rows > Numberofrow - 1 || seats < 0 || seats > Numberofseats - 1);
        if (rows >= 0)
        {
            if (Arr_Seats[rows][seats] == '*')
                cout << "ERROR! THIS SEAT IS ALREADY BOOKED" << endl;
            else
            {
                Arr_Seats[rows][seats] = '*';
                Available_seats--;
            }
            if (Available_seats == 0)
                cout << "NO MORE SEATS" << endl;
        }
        DisplaySeats(Arr_Seats, Numberofrow, Numberofseats);
        do
        {
            cout << endl
                 << "DO YOU WANT TO RESERVE ANOTHER SEAT? (Y/N)" << endl;
            cin >> answer;
            answer = toupper(answer);
            if (answer != 'Y' && answer != 'N')
                cout << "INCORRECT INPUT TRY 'Y' OR 'N' " << endl;
        } while (answer != 'Y' && answer != 'N');
        if (answer == 'N')
            rows = -1;
    } while (Available_seats > 0 && rows >= 0);

    MemoryCleanup(Arr_Seats, Numberofrow, Numberofseats);
    char buff[100];
    cin.getline(buff, 100);

    return reservedSeats;
}

//Base class
class Ticket
{
private:
    //data members
    int price;
    int No_of_show;
    string show;
    int dateNum;
    int timeNum;
    string date;
    string showTime;
    string dateArr[6];
    string timeArr[6];

    int n0_of_tickets;

public:
    //member functions

    void Time()
    {
        cout << "\n\n\n"
             << endl;
        //time
        cout << "\t   _____                  .__ .__           ___.    .__                 _________.__             __           " << endl;
        cout << "\t  /  _  \\  ___  _______   |__||  |  _____   \\_ |__  |  |    ____       /   _____/|  |    ____  _/  |_   ______" << endl;
        cout << "\t /  /_\\  \\ \\  \\/ /\\__  \\  |  ||  |  \\__  \\   | __ \\ |  |  _/ __ \\      \\_____  \\ |  |   /  _ \\ \\   __\\ /  ___/" << endl;
        cout << "\t/    |    \\ \\   /  / __ \\_|  ||  |__ / __ \\_ | \\_\\ \\|  |__\\  ___/      /        \\|  |__(  <_> ) |  |   \\___ \\ " << endl;
        cout << "\t\\____|__  /  \\_/  (____  /|__||____/(____  / |___  /|____/ \\___  >    /_______  /|____/ \\____/  |__|  /____  >" << endl;
        cout << "\t        \\/             \\/                \\/      \\/            \\/             \\/                           \\/" << endl;
        time_t now = time(0);
        tm *ltm = localtime(&now);

        for (int i = 0; i < 6; i++)
        {
            //generating random minutes and hours from local time
            ltm->tm_hour = i + ltm->tm_hour;
            ltm->tm_min = ltm->tm_min + 30;

            //if number of minutes is greater than 60
            if (ltm->tm_min > 60)
            {
                //subtract minutes from 60 and increment hour
                ltm->tm_min = ltm->tm_min - 60;
                ltm->tm_hour += 1;
            }
            if (ltm->tm_min == 60)
            {
                ltm->tm_min = 0;
                ltm->tm_hour += 1;
            }
            //if number of hours is greater than 60
            if (ltm->tm_hour > 24)
            {
                //subtract hours from 24
                ltm->tm_hour = ltm->tm_hour - 24;
            }
            //adding a double 0 if minutes are 0-9
            if ((ltm->tm_min >= 0 && ltm->tm_min <= 9))
            {

                showTime = to_string(ltm->tm_hour) + ":0" + to_string(ltm->tm_min) + ":" + to_string(ltm->tm_sec);
            }
            else if ((ltm->tm_sec >= 0 && ltm->tm_sec <= 9))
            {
                showTime = to_string(ltm->tm_hour) + ":" + to_string(ltm->tm_min) + ":0" + to_string(ltm->tm_sec);
            }
            else if ((ltm->tm_hour >= 0 && ltm->tm_hour <= 9))
            {
                showTime = "0" + to_string(ltm->tm_hour) + ":" + to_string(ltm->tm_min) + ":" + to_string(ltm->tm_sec);
            }
            else
            {
                //generating time by concatinating strings of hour, minute and second
                showTime = to_string(ltm->tm_hour) + ":" + to_string(ltm->tm_min) + ":" + to_string(ltm->tm_sec);
                timeArr[i] = showTime;
            }
            //printing time slot
            cout << "\t\tSlot " << i + 1 << " = " << showTime << endl;
        }
    }

    void set_date()
    {
        cout << "\n\n\n"
             << endl;
        cout << "     _____                  .__ .__           ___.    .__               ________             __                   " << endl;
        cout << "    /  _  \\  ___  _______   |__||  |  _____   \\_ |__  |  |    ____      \\______ \\  _____   _/  |_   ____    ______" << endl;
        cout << "   /  /_\\  \\ \\  \\/ /\\__  \\  |  ||  |  \\__  \\   | __ \\ |  |  _/ __ \\      |    |  \\ \\__  \\  \\   __\\_/ __ \\  /  ___/" << endl;
        cout << "  /    |    \\ \\   /  / __ \\_|  ||  |__ / __ \\_ | \\_\\ \\|  |__\\  ___/      |    `   \\ / __ \\_ |  |  \\  ___/  \\___ \\ " << endl;
        cout << "  \\____|__  /  \\_/  (____  /|__||____/(____  / |___  /|____/ \\___  >    /_______  /(____  / |__|   \\___  >/____  >" << endl;
        cout << "          \\/             \\/                \\/      \\/            \\/             \\/      \\/             \\/      \\/" << endl;
        time_t now = time(0);
        tm *ltm = localtime(&now);

        ltm->tm_year = ltm->tm_year + 1900;
        ltm->tm_mon = ltm->tm_mon + 1;
        for (int i = 0; i < 6; i++)
        {
            //generating random days and months from local time
            ltm->tm_mday = 1 + ltm->tm_mday;

            //if number of month is greater than 12
            if (ltm->tm_mon > 12)
            {
                //subtract months from 12
                ltm->tm_mon = ltm->tm_mon - 12;
            }
            //for months having 30 days
            if ((ltm->tm_mon == 9 || ltm->tm_mon == 4 || ltm->tm_mon == 6 || ltm->tm_mon == 11) && ltm->tm_mday > 30)
            {
                ltm->tm_mday = 1;
                ltm->tm_mon += 1;
            }
            //if days are greater than 31 for other months
            else if (ltm->tm_mon != 9 && ltm->tm_mon != 4 && ltm->tm_mon != 6 && ltm->tm_mon != 11 && ltm->tm_mday > 31)
            {
                ltm->tm_mday = 1;
                ltm->tm_mon += 1;
            }
            //generating time by concatinating strings of days, month and year
            date = to_string(ltm->tm_mday) + ":" + to_string(ltm->tm_mon) + ":" + to_string(ltm->tm_year);
            dateArr[i] = date;
            //printing date slot
            cout << "\t\tDate " << i + 1 << " = " << date << endl;
        }
    }

    //function for display
    void
    display()
    {

        cout << "\t\t\t                 .__                                  " << endl;
        sleep(1);
        cout << "\t\t\t__  _  __  ____  |  |    ____    ____    _____    ____" << endl;
        sleep(1);
        cout << "\t\t\t\\ \\/ \\/ /_/ __ \\ |  |  _/ ___\\  /  _ \\  /     \\ _/ __ \\ " << endl;
        sleep(1);
        cout << "\t\t\t \\     / \\  ___/ |  |__\\  \\___ (  <_> )|  Y Y  \\  ___ /" << endl;
        sleep(1);
        cout << "\t\t\t  \\/\\_/   \\___  >|____/ \\___  > \\____/ |__|_|  / \\___  >" << endl;
        sleep(1);
        cout << "\t\t\t              \\/            \\/               \\/      \\/" << endl;
        sleep(1);

        cout << "\t\t\t\t\t    __ " << endl;
        sleep(1);
        cout << "\t\t\t\t\t  _/  |_   ____" << endl;
        sleep(1);
        cout << "\t\t\t\t\t  \\   __\\ /  _ \\" << endl;
        sleep(1);
        cout << "\t\t\t\t\t   |  |  (  <_> )" << endl;
        sleep(1);
        cout << "\t\t\t\t\t   |__|   \\____/" << endl;
        sleep(1);

        cout << "\t\t\t       __   .__          __              __ " << endl;
        sleep(1);
        cout << "\t\t\t     _/  |_ |__|  ____  |  | __  ____  _/  |_" << endl;
        sleep(1);
        cout << "\t\t\t     \\   __\\|  |_/ ___\\ |  |/ /_/ __ \\ \\   __\\" << endl;
        sleep(1);
        cout << "\t\t\t      |  |  |  |\\  \\___ |    < \\  ___/  |  |  " << endl;
        sleep(1);
        cout << "\t\t\t      |__|  |__| \\___  >|__|_ \\ \\___  > |__|   " << endl;
        sleep(1);
        cout << "\t\t\t                     \\/      \\/     \\/         " << endl;
        sleep(1);

        cout << "\t\t\t                             .___.__              " << endl;
        sleep(1);
        cout << "\t\t\t  ___  __  ____    ____    __| _/|__|  ____     ____ " << endl;
        sleep(1);
        cout << "\t\t\t  \\  \\/ /_/ __ \\  /    \\  / __ | |  | /    \\   / ___\\  " << endl;
        sleep(1);
        cout << "\t\t\t   \\   / \\  ___/ |   |  \\/ /_/ | |  ||   |  \\ / /_/  > " << endl;
        sleep(1);
        cout << "\t\t\t    \\_/   \\___  >|___|  /\\____ | |__||___|  / \\___  /  " << endl;
        sleep(1);
        cout << "\t\t\t              \\/      \\/      \\/          \\/ /_____/" << endl;
        sleep(1);

        cout << "\t\t\t                         .__     .__ " << endl;
        sleep(1);
        cout << "\t\t\t  _____  _____     ____  |  |__  |__|  ____    ____  " << endl;
        sleep(1);
        cout << "\t\t\t /     \\ \\__  \\  _/ ___\\ |  |  \\ |  | /    \\ _/ __ \\ " << endl;
        sleep(1);
        cout << "\t\t\t|  Y Y  \\ / __ \\_\\  \\___ |   Y  \\|  ||   |  \\\\  ___/ " << endl;
        sleep(1);
        cout << "\t\t\t|__|_|  /(____  / \\___  >|___|  /|__||___|  / \\___  >" << endl;
        sleep(1);
        cout << "\t\t\t      \\/      \\/      \\/      \\/          \\/      \\/ " << endl;
        sleep(1);

        cout << "\n\n\n\n\n\n"
             << endl;
        cout
            << "\t\tSELECT ANY MOVIE (1-10)\n"
               "\t\t1. Spider-man: No Way Home\n"
               "\t\t2. Hera Pheri\n"
               "\t\t3. The Matrix\n"
               "\t\t4. Teefa in Trouble\n"
               "\t\t5. Frozen 2\n"
               "\t\t6. Toy story 5\n"
               "\t\t7. Maula Jutt\n"
               "\t\t8. Forrest Gump\n"
               "\t\t9. Parasyte\n"
               "\t\t10. Demon Slayer: The Mugen Train"
            << endl;
    }

    //function for selecting show
    void set_show()
    {
        cin >> No_of_show; //getting show from user
        //using switch case statement
        switch (No_of_show)
        {
            //when user selects a movie
        case 1:
            show = "Spider-man: No Way Home";

            cout << "\t\t\t  _________        .__     .___                   _____                   " << endl;
            cout << "\t\t\t /   _____/______  |__|  __| _/  ____  _______   /     \\  _____     ____  " << endl;
            cout << "\t\t\t \\_____  \\ \\____ \\ |  | / __ | _/ __ \\ \\_  __ \\ /  \\ /  \\ \\__  \\   /    \\ " << endl;
            cout << "\t\t\t /        \\|  |_> >|  |/ /_/ | \\  ___/  |  | \\//    Y    \\ / __ \\_|   |  \\" << endl;
            cout
                << "\t\t\t/_______  /|   __/ |__|\\____ |  \\___  > |__|   \\____|__  /(____  /|___|  /" << endl;
            cout << "\t\t\t        \\/ |__|             \\/      \\/                 \\/      \\/      \\/" << endl;

            set_date(); //calling date function
            cout << "\t\tSelect date for the show" << endl;
            cin >> dateNum;

            Time(); //calling time function
            cout << "\t\tSelect time for the show" << endl;
            cin >> timeNum;
            cout << "\t\tEnter number of tickets" << endl;
            cin >> n0_of_tickets;
            price = n0_of_tickets * 800;
            break;

        case 2:
            show = "Hera Pheri";
            cout << "\t\t\t  ___ ___                              __________ .__                     .__ " << endl;
            cout << "\t\t\t /   |   \\   ____  _______ _____       \\______   \\|  |__    ____  _______ |__|" << endl;
            cout << "\t\t\t/    ~    \\_/ __ \\ \\_  __ \\\\__  \\       |     ___/|  |  \\ _/ __ \\ \\_  __ \\|  |" << endl;
            cout << "\t\t\t\\    Y    /\\  ___/  |  | \\/ / __ \\_     |    |    |   Y  \\\\  ___/  |  | \\/|  |" << endl;
            cout << "\t\t\t \\___|_  /  \\___  > |__|   (____  /     |____|    |___|  / \\___  > |__|   |__|" << endl;
            cout << "\t\t\t       \\/       \\/              \\/                     \\/      \\/             " << endl;
            set_date(); //calling date function
            cout << "\t\tSelect date for the show" << endl;
            cin >> dateNum;

            Time(); //calling time function
            cout << "\t\tSelect time for the show" << endl;
            cin >> timeNum;
            cout << "\t\tEnter number of tickets" << endl;
            cin >> n0_of_tickets;
            price = n0_of_tickets * 600;
            break;

        case 3:
            show = "The Matrix";
            cout << "\t\t\t___________.__                    _____             __           .__         " << endl;
            cout << "\t\t\t\\__    ___/|  |__    ____        /     \\  _____   _/  |_ _______ |__|___  ___ " << endl;
            cout << "\t\t\t  |    |   |  |  \\ _/ __ \\      /  \\ /  \\ \\__  \\  \\   __\\\\_  __ \\|  |\\  \\/  / " << endl;
            cout << "\t\t\t  |    |   |   Y  \\\\  ___/     /    Y    \\ / __ \\_ |  |   |  | \\/|  | >    <  " << endl;
            cout << "\t\t\t  |____|   |___|  / \\___  >    \\____|__  /(____  / |__|   |__|   |__|/__/\\_ \\ " << endl;
            cout << "\t\t\t                \\/      \\/             \\/      \\/                          \\/ " << endl;
            set_date(); //calling date function
            cout
                << "\t\tSelect date for the show" << endl;
            cin >> dateNum;

            Time(); //calling time function
            cout << "\t\tSelect time for the show" << endl;
            cin >> timeNum;

            cout << "\t\tEnter number of tickets" << endl;
            cin >> n0_of_tickets;
            price = n0_of_tickets * 700;
            break;

        case 4:
            show = "Teefa in Trouble";
            cout << "\t___________                  _____          .___          ___________                       ___.    .__           " << endl;
            cout << "\t\\__    ___/  ____    ____  _/ ____\\_____    |   |  ____   \\__    ___/_______   ____   __ __ \\_ |__  |  |    ____  " << endl;
            cout << "\t  |    |   _/ __ \\ _/ __ \\ \\   __\\ \\__  \\   |   | /    \\    |    |   \\_  __ \\ /  _ \\ |  |  \\ | __ \\ |  |  _/ __ \\ " << endl;
            cout << "\t  |    |   \\  ___/ \\  ___/  |  |    / __ \\_ |   ||   |  \\   |    |    |  | \\/(  <_> )|  |  / | \\_\\ \\|  |__\\  ___/ " << endl;
            cout << "\t  |____|    \\___  > \\___  > |__|   (____  / |___||___|  /   |____|    |__|    \\____/ |____/  |___  /|____/ \\___  >" << endl;
            cout << "\t                \\/      \\/              \\/            \\/                                         \\/            \\/" << endl;
            set_date(); //calling date function
            cout << "\t\tSelect date for the show" << endl;
            cin >> dateNum;

            Time(); //calling time function
            cout << "\t\tSelect time for the show" << endl;
            cin >> timeNum;

            cout << "\t\tEnter number of tickets" << endl;
            cin >> n0_of_tickets;
            price = n0_of_tickets * 800;
            break;

        case 5:
            show = "Frozen 2";
            cout << "\t\t\t___________                                             ________  " << endl;
            cout << "\t\t\t\\_   _____/_______   ____  ________  ____    ____       \\_____  \\ " << endl;
            cout << "\t\t\t |    __)  \\_  __ \\ /  _ \\ \\___   /_/ __ \\  /    \\       /  ____/ " << endl;
            cout << "\t\t\t |     \\    |  | \\/(  <_> ) /    / \\  ___/ |   |  \\     /       \\ " << endl;
            cout << "\t\t\t \\___  /    |__|    \\____/ /_____ \\ \\___  >|___|  /     \\_______ \\" << endl;
            cout << "\t\t\t     \\/                          \\/     \\/      \\/              \\/" << endl;

            set_date(); //calling date function
            cout << "\t\tSelect date for the show" << endl;
            cin >> dateNum;

            Time(); //calling time function
            cout << "\t\tSelect time for the show" << endl;
            cin >> timeNum;
            cout << "\t\tEnter number of tickets" << endl;
            cin >> n0_of_tickets;
            price = n0_of_tickets * 1000;
            break;

        case 6:
            show = "Toy story 5";
            cout << "\t\t___________                      _________  __                                .________" << endl;
            cout << "\t\t\\__    ___/  ____   ___.__.     /   _____/_/  |_   ____  _______  ___.__.     |   ____/" << endl;
            cout << "\t\t  |    |    /  _ \\ <   |  |     \\_____  \\ \\   __\\ /  _ \\ \\_  __ \\<   |  |     |____  \\ " << endl;
            cout << "\t\t  |    |   (  <_> ) \\___  |     /        \\ |  |  (  <_> ) |  | \\/ \\___  |     /       \\" << endl;
            cout << "\t\t  |____|    \\____/  / ____|    /_______  / |__|   \\____/  |__|    / ____|    /______  /" << endl;
            cout << "\t\t                    \\/                 \\/                         \\/                \\/" << endl;
            set_date(); //calling date function
            cout << "\t\tSelect date for the show" << endl;
            cin >> dateNum;

            Time(); //calling time function
            cout << "\t\tSelect time for the show" << endl;
            cin >> timeNum;

            cout << "\t\tEnter number of tickets" << endl;
            cin >> n0_of_tickets;
            price = n0_of_tickets * 900;
            break;

        case 7:
            show = "Maula Jutt";
            cout << "\t\t\t   _____                  .__                     ____.         __     __   " << endl;
            cout << "\t\t\t  /     \\  _____    __ __ |  |  _____            |    | __ __ _/  |_ _/  |_ " << endl;
            cout << "\t\t\t /  \\ /  \\ \\__  \\  |  |  \\|  |  \\__  \\           |    ||  |  \\\\   __\\\\   __\\" << endl;
            cout << "\t\t\t/    Y    \\ / __ \\_|  |  /|  |__ / __ \\_     /\\__|    ||  |  / |  |   |  |  " << endl;
            cout << "\t\t\t\\____|__  /(____  /|____/ |____/(____  /     \\________||____/  |__|   |__|  " << endl;
            cout << "\t\t\t        \\/      \\/                   \\/                                    " << endl;
            set_date(); //calling date function
            cout << "\t\tSelect date for the show" << endl;
            cin >> dateNum;

            Time(); //calling time function
            cout << "\t\tSelect time for the show" << endl;
            cin >> timeNum;

            cout << "\t\tEnter number of tickets" << endl;
            cin >> n0_of_tickets;
            price = n0_of_tickets * 800;
            break;

        case 8:
            show = "Forest Gump";
            cout << "\t\t\t___________                                  __          ________                         " << endl;
            cout << "\t\t\t\\_   _____/  ____  _______   ____    _______/  |_       /  _____/  __ __   _____  ______  " << endl;
            cout << "\t\t\t |    __)   /  _ \\ \\_  __ \\_/ __ \\  /  ___/\\   __\\     /   \\  ___ |  |  \\ /     \\ \\____ \\ " << endl;
            cout << "\t\t\t |     \\   (  <_> ) |  | \\/\\  ___/  \\___ \\  |  |       \\    \\_\\  \\|  |  /|  Y Y  \\|  |_> >" << endl;
            cout << "\t\t\t \\___  /    \\____/  |__|    \\___  >/____  > |__|        \\______  /|____/ |__|_|  /|   __/ " << endl;
            cout << "\t\t\t     \\/                         \\/      \\/                     \\/              \\/ |__| " << endl;
            set_date(); //calling date function
            cout << "\t\tSelect date for the show" << endl;
            cin >> dateNum;

            Time(); //calling time function
            cout << "\t\tSelect time for the show" << endl;
            cin >> timeNum;
            cout << "\t\tEnter number of tickets" << endl;
            cin >> n0_of_tickets;
            price = n0_of_tickets * 800;
            break;

        case 9:
            show = "Parasyte";
            cout << "\t\t\t__________                                           __           " << endl;
            cout << "\t\t\t\\______   \\_____   _______ _____     ______ ___.__._/  |_   ____  " << endl;
            cout << "\t\t\t |     ___/\\__  \\  \\_  __ \\\\__  \\   /  ___/<   |  |\\   __\\_/ __ \\ " << endl;
            cout << "\t\t\t |    |     / __ \\_ |  | \\/ / __ \\_ \\___ \\  \\___  | |  |  \\  ___/ " << endl;
            cout << "\t\t\t |____|    (____  / |__|   (____  //____  > / ____| |__|   \\___  >" << endl;
            cout << "\t\t\t                \\/              \\/      \\/  \\/                 \\/" << endl;
            set_date(); //calling date function
            cout << "\t\tSelect date for the show" << endl;
            cin >> dateNum;

            Time(); //calling time function
            cout << "\t\tSelect time for the show" << endl;
            cin >> timeNum;

            cout << "\t\tEnter number of tickets" << endl;
            cin >> n0_of_tickets;
            price = n0_of_tickets * 900;
            break;

        case 10:
            show = "Demon Slayer: The Mugen Train";
            cout << "\t\t________                                            _________.__                                   " << endl;
            cout << "\t\t\\______ \\    ____    _____    ____    ____         /   _____/|  |  _____    ___.__.  ____  _______ " << endl;
            cout << "\t\t |    |  \\ _/ __ \\  /     \\  /  _ \\  /    \\        \\_____  \\ |  |  \\__  \\  <   |  |_/ __ \\ \\_  __ \\" << endl;
            cout << "\t\t |    `   \\\\  ___/ |  Y Y  \\(  <_> )|   |  \\       /        \\|  |__ / __ \\_ \\___  |\\  ___/  |  | \\/" << endl;
            cout << "\t\t/_______  / \\___  >|__|_|  / \\____/ |___|  /      /_______  /|____/(____  / / ____| \\___  > |__|   " << endl;
            cout << "\t\t        \\/      \\/       \\/              \\/               \\/            \\/  \\/          \\/       " << endl;
            set_date(); //calling date function
            cout << "\t\tSelect date for the show" << endl;
            cin >> dateNum;

            Time(); //calling time function
            cout << "\t\tSelect time for the show" << endl;
            cin >> timeNum;

            cout << "\t\tEnter number of tickets" << endl;
            cin >> n0_of_tickets;

            price = n0_of_tickets * 600;
            break;
        }
    }
    //function for displaying ticket of movie
    void display_ticket(string seats)
    {
        cout << "\t\t\t_____.___.                             ___________.__          __              __   " << endl;
        cout << "\t\t\t\\__  |   |  ____   __ __ _______       \\__    ___/|__|  ____  |  | __  ____  _/  |_" << endl;
        cout << "\t\t\t /   |   | /  _ \\ |  |  \\\\_  __ \\        |    |   |  |_/ ___\\ |  |/ /_/ __ \\ \\   __\\" << endl;
        cout
            << "\t\t\t \\____   |(  <_> )|  |  / |  | \\/        |    |   |  |\\  \\___ |    < \\  ___/  |  |  " << endl;
        cout << "\t\t\t / ______| \\____/ |____/  |__|           |____|   |__| \\___  >|__|_ \\ \\___  > |__|  " << endl;
        cout << "\t\t\t \\/                                                        \\/      \\/     \\/       " << endl;
        cout << ""
             << endl;

        cout << "\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
        cout << "\t*\t  ____    _                        \t\t\t\t\t\t\t\t\t*" << endl;
        cout << "\t*\t / ___|  | |__     ___   __      __\t\t\t\t\t\t\t\t\t*" << endl;
        cout << "\t*\t \\___ \\  | '_ \\   / _ \\  \\ \\ /\\ / / \t\t\t\t\t\t\t\t\t*" << endl;
        cout << "\t*\t  ___) | | | | | | (_) |  \\ V  V /  :  " << show << "\t\t\t\t\t\t\t*" << endl;
        cout << "\t*\t |____/  |_| |_|  \\___/    \\_/\\_/ \t\t\t\t\t\t\t\t\t*" << endl;
        cout << "\t*\t                                 \t\t\t\t\t\t\t\t\t*" << endl;
        cout << "\t*\t  ____                   _           \t\t\t\t\t\t\t\t\t*" << endl;
        cout << "\t*\t / ___|    ___    __ _  | |_ \t\t\t\t\t\t\t\t\t\t*" << endl;
        cout << "\t*\t \\___ \\   / _ \\  / _` | | __|\t\t\t\t\t\t\t\t\t\t*" << endl;
        cout << "\t*\t  ___) | |  __/ | (_| | | |_ \t" << seats << "\t\t\t\t\t\t\t\t*" << endl;
        cout << "\t*\t |____/   \\___|  \\__,_|  \\__|\t\t\t\t\t\t\t\t\t\t*" << endl;
        cout << "\t*\t                                   \t\t\t\t\t\t\t\t\t*";
        cout << "\n\t*\t                                   \t\t\t\t\t\t\t\t\t*"
             << endl;
        cout << "\t*\t  ____            _               ___       _____   _                    \t\t\t\t*" << endl;
        cout << "\t*\t |  _ \\    __ _  | |_    ___     ( _ )     |_   _| (_)  _ __ ___     ___ \t\t\t\t*" << endl;
        cout << "\t*\t | | | |  / _` | | __|  / _ \\    / _ \\/\\     | |   | | | '_ ` _ \\   / _ \\ \t\t\t\t*" << endl;
        cout << "\t*\t | |_| | | (_| | | |_  |  __/   | (_>  <     | |   | | | | | | | | |  __/ :  " << dateArr[dateNum - 1] << " " << timeArr[timeNum] << "\t\t*" << endl;
        cout << "\t*\t |____/   \\__,_|  \\__|  \\___|    \\___/\\/     |_|   |_| |_| |_| |_|  \\___|\t\t\t\t*" << endl;
        cout << "\t*\t                                   \t\t\t\t\t\t\t\t\t*" << endl;
        cout << "\t*\t                                   \t\t\t\t\t\t\t\t\t*" << endl;

        cout << "\t*\t   ____           _               \t\t\t\t\t\t\t\t\t*" << endl;
        cout << "\t*\t  |  _ \\   _ __  (_)   ___    ___ \t\t\t\t\t\t\t\t\t*" << endl;
        cout << "\t*\t  | |_) | | '__| | |  / __|  / _ \\ \t\t\t\t\t\t\t\t\t*" << endl;
        cout << "\t*\t  |  __/  | |    | | | (__  |  __/:\t" << price << "\t\t\t\t\t\t\t\t*" << endl;
        cout << "\t*\t  |_|     |_|    |_|  \\___|  \\___|\t\t\t\t\t\t\t\t\t*" << endl;
        cout << "\t*\t                                 \t\t\t\t\t\t\t\t\t*" << endl;
        cout << "\t*\t                                 \t\t\t\t\t\t\t\t\t*" << endl;
        cout << "\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
    }
};

//Food vending part

class RestockMode
{
public:
    int drinkArraySize;
    int popcornArraySize;
    string drinks[50];
    string popcorns[50];
    int drinksPrice[50];
    int popcornsPrice[50];
    int liters[50];
    int quantity[50];
    int cups_popcorns;
    int cups_drinks;
    int password = 1234;

public:
    RestockMode()
    {
    }
    RestockMode(int d, int p)
    {
        if (d > 0)
        {
            setDrinkArraySize(d);
        }
        else
            cout << "INVALID INPUT.";

        setDrinks(d);
        setDrinkPrice(d);
        setDrinkLiters(d);
        cout << "\nENTER CUPS FOR DRINK TO STORE: ";
        cin >> cups_drinks;
        system("CLS");
        if (p > 0)
        {
            setPopcornArraySize(p);
        }
        else
            cout << "INVALID INPUT.";

        setPopcorns(p);
        setPopcornPrice(p);
        setPopcornQuantity(p);
        cout << "\nENTER CUPS FOR POPCORN TO STORE: ";
        cin >> cups_popcorns;
        system("CLS");
    }

    void setDrinkArraySize(int d)
    {
        drinkArraySize = d;
    }

    int getDrinkArraySize()
    {
        return drinkArraySize;
    }

    void setPopcornArraySize(int p)
    {
        popcornArraySize = p;
    }

    int getPopcornArraySize()
    {
        return popcornArraySize;
    }

    void setDrinks(int d)
    {
        for (int i = 0; i < d; i++)
        {
            cout << "ENTER NAME OF " << (i + 1) << " DRINK: ";
            cin >> drinks[i];
        }
    }

    string getDrinks(int a)
    {
        return drinks[a];
    }

    void setDrinkPrice(int d)
    {
        for (int i = 0; i < d; i++)
        {
            cout << "ENTER PRICE FOR " << drinks[i] << ": ";
            cin >> drinksPrice[i];
        }
    }

    int getDrinkPrice(int a)
    {
        return drinksPrice[a];
    }

    void setDrinkLiters(int d)
    {
        for (int i = 0; i < d; i++)
        {
            cout << "ENTER LITERS FOR " << drinks[i] << ": ";
            cin >> liters[i];
        }
    }

    int getDrinkLiters(int a)
    {
        return liters[a];
    }

    void setPopcorns(int p)
    {
        for (int i = 0; i < p; i++)
        {
            cout << "ENTER " << (i + 1) << " POPCORN FLAVOUR: ";
            cin >> popcorns[i];
        }
    }

    string getPopcorns(int a)
    {
        return popcorns[a];
    }

    void setPopcornPrice(int p)
    {
        for (int i = 0; i < p; i++)
        {
            cout << "ENTER PRICE FOR " << popcorns[i] << ": ";
            cin >> popcornsPrice[i];
        }
    }

    int getPopcornPrice(int a)
    {
        return popcornsPrice[a];
    }

    void setPopcornQuantity(int p)
    {
        for (int i = 0; i < p; i++)
        {
            cout << "ENTER QUANTITY FOR " << popcorns[i] << ": ";
            cin >> quantity[i];
        }
    }

    int getPopcornQuantity(int a)
    {
        return quantity[a];
    }

    void setDrinkCups(int cup_d)
    {
        cups_drinks = cup_d;
    }

    int getDrinkCups()
    {
        return cups_drinks;
    }

    void setPopcornCups(int cup_p)
    {
        cups_popcorns = cup_p;
    }

    int getPopcornCups()
    {
        return cups_popcorns;
    }

    int getPassword()
    {
        return password;
    }

    void decrementInDrinkCups()
    {
        cups_drinks = cups_drinks - 1;
    }

    void decrementInPopcornCups()
    {
        cups_popcorns = cups_popcorns - 1;
    }

    void decrementInLiters(int a)
    {
        liters[a] = liters[a] - 50;
    }

    void decrementInQuantity(int a)
    {
        quantity[a] = quantity[a] - 100;
    }

    void display()
    {
        cout << "STORAGE: \n";
        for (int i = 0; i < drinkArraySize; i++)
        {
            cout << drinks[i] << "  " << liters[i] << " Liters" << endl;
        }
        for (int i = 0; i < popcornArraySize; i++)
        {
            cout << popcorns[i] << "  " << quantity[i] << " Quantity" << endl;
        }
        cout << "\nCUPS FOR DRINKS: " << cups_drinks;
        cout << "\nCUPS FOR POPCORNS: " << cups_popcorns << endl;
    }
};

class CashHandlingMode
{
protected:
    string cash_type[6] = {"THOUSAND", "FIVE HUNDRED", "HUNDRED", "FIFTY", "TWENTY", "TEN"};
    int cash_stored[6];
    int password = 5678;

public:
    CashHandlingMode()
    {
    }

    CashHandlingMode(int th, int fh, int h, int f, int tw, int te)
    {
        setThousand(th);
        setFiveHundred(fh);
        setHundred(h);
        setFifty(f);
        setTwenty(tw);
        setTen(te);
    }

    void setThousand(int th)
    {
        cash_stored[0] = th;
    }

    int getThousands()
    {
        return cash_stored[0];
    }

    void setFiveHundred(int fh)
    {
        cash_stored[1] = fh;
    }

    int getFiveHundred()
    {
        return cash_stored[1];
    }

    void setHundred(int h)
    {
        cash_stored[2] = h;
    }

    int getHundred()
    {
        return cash_stored[2];
    }

    void setFifty(int f)
    {
        cash_stored[3] = f;
    }

    int getFifty()
    {
        return cash_stored[3];
    }

    void setTwenty(int tw)
    {
        cash_stored[4] = tw;
    }

    int getTwenty()
    {
        return cash_stored[4];
    }

    void setTen(int te)
    {
        cash_stored[5] = te;
    }

    int getTen()
    {
        return cash_stored[5];
    }

    void decrementInCash(int th, int fh, int h, int f, int tw, int te)
    {
        cash_stored[0] = cash_stored[0] - th;
        cash_stored[1] = cash_stored[1] - fh;
        cash_stored[2] = cash_stored[2] - h;
        cash_stored[3] = cash_stored[3] - f;
        cash_stored[4] = cash_stored[4] - tw;
        cash_stored[5] = cash_stored[5] - te;
    }

    int getPassword()
    {
        return password;
    }

    void displayCashBox()
    {
        cout << "\n\t\tCASH LEFT\n";
        for (int i = 0; i < 6; i++)
        {
            cout << cash_type[i] << "   " << cash_stored[i];
            cout << endl;
        }
    }
};

class FoodVendingMode : public RestockMode, CashHandlingMode
{
protected:
    int choose;
    int choose2;
    int selection;
    int entered_cash;
    bool invalid = false;
    int total_cash = 0;
    int thousand;
    int fivehundred;
    int hundred;
    int fifty;
    int twenty;
    int ten;
    int cash_return;

public:
    void displayMenu(RestockMode R)
    {
        if (choose == 1)
        {
            cout << "\n\n\t\tDRINKS \t\tPRICE\n";
            for (int i = 0; i < R.getDrinkArraySize(); i++)
            {
                cout << "\t\t" << (i + 1) << ". " << R.getDrinks(i) << "\t\t" << R.getDrinkPrice(i) << endl;
            }
        }
        else if (choose == 2)
        {
            cout << "\n\n\t\tPOPCORNS \t\tPRICE\n";
            for (int i = 0; i < R.getPopcornArraySize(); i++)
            {
                cout << "\t\t" << (i + 1) << ". " << R.getPopcorns(i) << "\t\t" << R.getPopcornPrice(i) << endl;
            }
        }
        else
        {
            invalid = true;
        }
    }

    void selectType(RestockMode R)
    {
        cout << "CHOOSE BETWEEN THE TWO: ";
        cout << "\n\t\t1. DRINKS\n\t\t2. POPCORNS\n\t\t";
        cin >> choose;
        displayMenu(R);
    }

    void selectItem(RestockMode r, CashHandlingMode c)
    {
        cout << "PLEASE ENTER THE RESPECTIVE SERIAL NUMBER FOR THE ITEM: ";
        cin >> selection;
        if (choose == 1)
        {
            if (selection > 0 && selection <= r.getDrinkArraySize())
            {
                checkItem(r, c);
            }
            else
            {
                invalid = true;
            }
        }

        if (choose == 2)
        {
            if (selection > 0 && selection <= r.getPopcornArraySize())
            {
                checkItem(r, c);
            }
            else
            {
                invalid = true;
            }
        }
    }

    void checkItem(RestockMode r, CashHandlingMode c)
    {
        if (choose == 1)
        {
            if (r.getDrinkLiters(selection - 1) > 0)
            {
            }
            else
            {
                cout << "ITEM IS NOT AVAILABLE";
                invalid = true;
            }
        }
        if (choose == 2)
        {
            if (r.getPopcornQuantity(selection - 1) > 0)
            {
            }
            else
            {
                cout << "ITEM IS NOT AVAILABLE";
                invalid = true;
            }
        }
    }

    void insertCash(RestockMode r, CashHandlingMode c)
    {
        cout << "\n\t\tPLEASE INSERT CASH\n\t\t";
        cin >> entered_cash;

        setTotalCash();
        checkCash(r, c);
    }

    void setTotalCash()
    {
        total_cash += entered_cash;
    }

    void checkCash(RestockMode r, CashHandlingMode c)
    {
        if (choose == 1)
        {
            if (r.getDrinkPrice(selection - 1) <= total_cash)
            {
                cout << "PLEASE COLLECT YOUR ITEM FROM BELOW" << endl;
                cash_return = total_cash - r.getDrinkPrice(selection - 1);
                cout << "\nHERE IS YOUR CHANGE " << cash_return << endl;
                system("pause");
                system("CLS");
                invalid = false;
            }
            else
            {
                cout << "\nNOT ENOUGH AMOUNT\n";
                invalid = true;
            }
        }

        if (choose == 2)
        {
            if (r.getPopcornPrice(selection - 1) <= total_cash)
            {
                cout << "PLEASE COLLECT YOUR ITEM FROM BELOW" << endl;
                cash_return = total_cash - r.getPopcornPrice(selection - 1);
                cout << "HERE IS YOUR CHANGE " << cash_return << endl;
                system("pause");
                system("CLS");
                invalid = false;
            }
            else
            {
                cout << "\nNOT ENOUGH AMOUNT\n";
                invalid = true;
            }
        }
    }

    int getCashReturn()
    {
        return cash_return;
    }

    int getSelection()
    {
        return selection;
    }

    int getChoose()
    {
        return choose;
    }

    int getEnteredCash()
    {
        return entered_cash;
    }
    void setInvalid()
    {
        invalid = false;
    }

    bool getInvalid()
    {
        return invalid;
    }
};

//------------------------------------------

class Card_managment
{
    int rupees;
    int cardID;
    int password;

public:
    void setdata()
    {
        cout << "ENTER CARD ID:";
        cin >> cardID;
        cout << "ENTER YOUR PASSWORD:";
        cin >> password;
        cout << "SUCCESFULL\n";
    }

    void display()
    {
        rupees = rand() % 10000;

        cout << "TOTAL RUPEES" << rupees << endl;
    }
};

//-------------------------------------------------------
////////////////////////////////////////////////////////
///////////////////////////////////////////////////////
//////////////////////////////////////////////////////
/////////////////////////////////////////////////////

//main function
int main()
{
    RestockMode Rptr;
    CashHandlingMode Cptr; //needed to deal with the scope
    int startChoice = 0;
    int choice;
    int th, h, fh, f, tw, te;
    int d, p;
    bool stocked = false;
start:
    cout << "Choose an option:\n1. Ticket mode\n2. Food mode\n3. Restock mode\n";
    cin >> startChoice;

    if (startChoice == 1)
    {
        //----------------------------------------
        //Ticketing

        //creating object of ticket class
        Ticket customer1;
        cout << "NOW SELECT SEAT OF YOUR OWN CHOICE";
        seats_reserving s1;
        string seats;
        //calling functions
        customer1.display();
        customer1.set_show();
        seats = s1.mainfunction();
        customer1.display_ticket(seats);

        goto start;
        //---------------------------------------
    }
    else if (startChoice == 2)
    {
        if (stocked)
        {
            //for user to get items
            FoodVendingMode F;
        selectitem:
            F.setInvalid();
            F.selectType(Rptr);
            if (F.getInvalid())
            {
                cout << "\nINVALID ENTRY\n";
                goto selectitem;
            }

            F.selectItem(Rptr, Cptr);
            if (F.getInvalid())
            {
                goto selectitem;
            }

            //-----------------------

            int payChoice;
        selectPay:
            cout << "Payment method?\n1. Cash\n2. Credit\n";

            cin >> payChoice;

            if (payChoice == 1)
            {

                F.insertCash(Rptr, Cptr);
                if (F.getInvalid())
                {
                    goto selectitem;
                }
            }
            else if (payChoice == 2)
            {
                Card_managment c1;
                c1.setdata();
                c1.display();
            }
            else
            {
                cout << "INVALID ENTRY\n";
                goto selectPay;
            }

            int select;
            select = F.getSelection() - 1;

            //decrement in quantity and cups after user has used the vending
            if (F.getChoose() == 1)
            {
                (Rptr).decrementInLiters(select);
                (Rptr).decrementInDrinkCups();
            }
            else if (F.getChoose() == 2)
            {
                (Rptr).decrementInQuantity(select);
                (Rptr).decrementInPopcornCups();
            }

            //tasking cash returned to user and subtracting that cash from the one already stored
            int cash;
            th = fh = h = f = tw = te = 0;
            cash = F.getCashReturn();
            th = cash / 1000;
            cash = cash - (th * 100);

            fh = cash / 500;
            cash = cash - (fh * 500);

            h = cash / 100;
            cash = cash - (h * 100);

            f = cash / 50;
            cash = cash - (f * 50);

            tw = cash / 20;
            cash = cash - (tw * 20);

            te = cash / 10;

            (Cptr).decrementInCash(th, fh, h, f, tw, te);

            //-------------------------------------------------------------------------
            string s;
            cout<<"DO YOU WANT TO CHECK STORAGE: (Y/N)";
            cin >>s;
            if(s=="Y");
            {
                int pass =0000;
                cout <<"ENTER PASSWORD: ";
                cin >>pass;
                if(pass==0000)
                {
            (Rptr).display();
            (Cptr).displayCashBox();
                }
            }
            goto start;
        }
        else
        {
            cout << "Vending is empty, please restock first\n";
            goto start;
        }
    }
    else if (startChoice == 3)
    {
        stocked = true;
        //restock
        //for storing items
        int pw;
        cout << "Enter password:";
        cin >> pw;
        if (pw == 0000)
        {
            cout << "\t\tRESTOCK MODE:\n";
            cout << "ENTER NUMBER OF DRINKS TO STORE: ";
            cin >> d;

            cout << "ENTER NUMBER OF POPCORNS TO STORE: ";
            cin >> p;
            system("CLS");

            RestockMode R(d, p);
            Rptr = R;
            //-----------------------------------------
            //for cash storing
            system("CLS");
            cout << "\nCASH HANDLING MODE\n";
            //int th, h,fh, f, tw, te;
            cout << "ENTER NUMBER OF THOUSAND RUPPES NOTE TO STORE: ";
            cin >> th;
            cout << "ENTER NUMBER OF FIVE HUNDRED RUPEES NOTE TO STORE: ";
            cin >> fh;
            cout << "ENTER NUMBER OF HUNDRED RUPPES NOTE TO STORE: ";
            cin >> h;
            cout << "ENTER NUMBER OF FIFTY RUPPES NOTE TO STORE: ";
            cin >> f;
            cout << "ENTER NUMBER OF TWENTY RUPPES NOTE TO STORE: ";
            cin >> tw;
            cout << "ENTER NUMBER OF TEN RUPPES NOTE TO STORE: ";
            cin >> te;

            CashHandlingMode C(th, fh, h, f, tw, te);
            Cptr = C;

            system("CLS");
            goto start;

            //-----------------------------------------------
        }
        else
        {
            cout << "Wrong input, try again\n";
            goto start;
        }
    }
    return 0;
}




