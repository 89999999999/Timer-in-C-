#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <unistd.h>
using namespace std;

const int size = 100;

struct Timer_app
{
    double hours;
    double minutes;
    double seconds;
};

void display_menu()
{
    cout << endl;
    cout << "MAIN MENU" << endl;
    cout << "1. RESET TIMER" << endl;
    cout << "2. DISPLAY TIMER" << endl;
    cout << "3. ADD HOURS" << endl;
    cout << "4. ADD MINUTES" << endl;
    cout << "5. ADD SECONDS" << endl;
    cout << "6. MINUS HOURS" << endl;
    cout << "7. MINUS MINUTES" << endl;
    cout << "8. MINUS SECONDS" << endl;
    cout << "9. START TIMER" << endl;
    cout << "10. TURN OFF" << endl;

    cout << endl;

    cout << "Enter an option: " << endl;
}


void display_timer_hours(struct Timer_app timer_test[])
{
    cout << "Current timer: " << timer_test[0].hours << ":" << timer_test[0].minutes << ":" << timer_test[0].seconds << endl;
    cout << endl;
}

void display_timer_minutes(struct Timer_app timer_test[])
{
    int current_minutes = timer_test[0].minutes;

    if (current_minutes > 59)
    {
        cout << "ERROR: 59 is the maximum minutes that can be added." << endl;
        cout << endl;
    }
    
    else
    {
        cout << "Current timer: " << timer_test[0].hours << ":" << timer_test[0].minutes << ":" << timer_test[0].seconds << endl;
        cout << endl;
    }
}

void display_timer_seconds(struct Timer_app timer_test[])
{
    cout << "Current timer: " << timer_test[0].hours << ":" << timer_test[0].minutes << ":" << timer_test[0].seconds << endl;
    cout << endl;
}


void reset_timer(struct Timer_app timer_test[])
{
    timer_test[0].hours = 0;
    timer_test[0].minutes = 0;
    timer_test[0].seconds = 0;
}

void add_hours(struct Timer_app timer_test[])
{
    int add_hours;
    int current_hours;
    current_hours = timer_test[0].hours;

    cout << "Enter hours to add: " << endl;
    cin >> add_hours;

    timer_test[0].hours = add_hours + current_hours;
}   

void add_minutes(struct Timer_app timer_test[])
{
    int add_minutes;
    int current_minutes = timer_test[0].minutes;

    cout << "Enter minutes to add: " << endl;
    cin >> add_minutes;

    timer_test[0].minutes = add_minutes + current_minutes;
} 

void add_seconds(struct Timer_app timer_test[])
{
    int add_seconds;
    int current_seconds = timer_test[0].seconds;

    cout << "Enter seconds to add: " << endl;
    cin >> add_seconds;

    timer_test[0].seconds = add_seconds + current_seconds;
}

void subtract_hours(struct Timer_app timer_test[])
{
    unsigned int subtract_hours;

    cout << "Enter hours to subtract: " << endl;
    cin >> subtract_hours;

    timer_test[0].hours = timer_test[0].hours - subtract_hours;
}

void subtract_minutes(struct Timer_app timer_test[])
{
    unsigned int subtract_minutes;

    cout << "Enter hours to subtract: " << endl;
    cin >> subtract_minutes;

    timer_test[0].hours = timer_test[0].minutes - subtract_minutes;
}

void subtract_seconds(struct Timer_app timer_test[])
{
    unsigned int subtract_seconds;

    cout << "Enter hours to subtract: " << endl;
    cin >> subtract_seconds;

    timer_test[0].hours = timer_test[0].seconds - subtract_seconds;
}

void start_timer(struct Timer_app timer_test[])
{
    while (timer_test[0].hours != -1 & timer_test[0].minutes != -1 & timer_test[0].seconds != -1)
    {
        cout << "Current timer: " << timer_test[0].hours << ":" << timer_test[0].minutes << ":" << timer_test[0].seconds << endl;
        cout << endl;

        if (timer_test[0].seconds > 0)
        {
            timer_test[0].seconds--;
            sleep(1);
        }
        

        if (timer_test[0].seconds == 0)
        {
            /*
            timer_test[0].minutes--;
            
            
            timer_test[0].seconds = 60;
            */

            if (timer_test[0].minutes == 0)
            {
                timer_test[0].hours--;
                timer_test[0].minutes = 59;
                timer_test[0].seconds = 59;
            }

            else
            {
                timer_test[0].minutes--;
                timer_test[0].seconds = 59;
            }
            /*
            if (timer_test[0].hours == 0)
            {
                timer_test[0].hours--;
                timer_test[0].minutes = 60;
                timer_test[0].seconds = 60;
            }
            
            timer_test[0].seconds--;
            sleep(1);

            
            if (timer_test[0].minutes == 0 & timer_test[0].seconds == 0)
            {
                timer_test[0].hours--;
                timer_test[0].minutes = 60;
                timer_test[0].seconds = 60;
            }
            */
        }

        

        
    }
}


int main()
{
    Timer_app timer_test[0];
    int user_option = 0;

    timer_test[0].hours = 0;
    timer_test[0].minutes = 0;
    timer_test[0].seconds = 0;

    while (user_option != 9)
    {
        display_menu();
        cin >> user_option;
        cout << endl;

        if (user_option == 1)
        {
            reset_timer(timer_test);
            display_timer_hours(timer_test);
        }

        if (user_option == 2)
        {
            display_timer_hours(timer_test);
        }

        if (user_option == 3)
        {
            add_hours(timer_test);
            display_timer_hours(timer_test);
        }

        if (user_option == 4)
        {
            add_minutes(timer_test);
            display_timer_minutes(timer_test);
        }

        if (user_option == 5)
        {
            add_seconds(timer_test);
            display_timer_seconds(timer_test);
        }

        if (user_option == 6)
        {
            subtract_hours(timer_test);
            display_timer_hours(timer_test);
        }

        if (user_option == 7)
        {
            subtract_minutes(timer_test);
            display_timer_minutes(timer_test);
        }

        if (user_option == 8)
        {
            subtract_seconds(timer_test);
            display_timer_seconds(timer_test);
        }


    }

    start_timer(timer_test);
    cout << "TIMER ENDED" << endl;
    


}
