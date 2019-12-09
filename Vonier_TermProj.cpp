/* Jack's song information program
    This program will provide information on a selected song
    James vonier
    12/2/19*/



//THINGS I STILL WANT TO DO
    //Load file names and project them on the screen. It would take a little bit of reworking, but I could get it.  


#include <iomanip>      
#include <dirent.h>     
#include <fstream>  
#include <iostream> 
#include <stdlib.h>

using namespace std;







/*
#include <iostream>
#include <fstream>
using namespace std;
*/

////////////////////
//Global Variables//
////////////////////

bool cancel = false;                    //Cancel the current genre
bool quit = false;                      //Quit program
string title = "Title not found!";
string artist = "Artist not Found!";
string album = "Album not Found!";
string run_time = "Run Time not Found!";
string release_date = "Release Date not Found";
string url = "URL not Found!";
//Genre Directories
const string CHILL_FOLDER_PATH = "C:\\Users\\banda\\Documents\\GitHub\\cosc-a211-term-project-jackvonier\\music\\chill";
const string ROCK_FOLDER_PATH = "C:\\Users\\banda\\Documents\\GitHub\\cosc-a211-term-project-jackvonier\\music\\rock";
//Song file names
string first_song_file = "song1.txt";
string second_song_file = "song2.txt";
string third_song_file = "song3.txt";
string fourth_song_file = "song4.txt";
string fifth_song_file = "song5.txt";



///////////////////////
//FUNCTION PROTOTYPES//
///////////////////////

int load_song (string file_dir);
int track_select(int selected_genre);
int open_genre(int selection);
void list_dir(string directory);







/////////////////
//MAIN FUNCTION//
/////////////////

int main(){
    double genre;

    


    //Loop through the function
    while (!quit){
        //resetting cancel var
        cancel = false;

        //Prompts/main menu
        cout << "-----------------------------Welcome------------------------------" << endl;
        cout << "Welcome to Jack's Song Information Program! Please select your genre of music!" << endl;
        cout << "1. Chill\n2. Rock\n3. Quit Program\nInput: ";
        cin >> genre;

        //Check if Open Genre fails, if so end the program
        cout << "------------------------------------------------------------------" << endl;
        if (open_genre(genre) == 1){
            return 1;
        }
    }

    //Exit program
    cout << "Exiting program. ";
    return 0;
}






//////////////////////////
//Functions used in main//
//////////////////////////


//Declaring the function to open files
int load_song (string file_dir){
    ifstream fileHandle;
    //Open the file
    fileHandle.open (file_dir);
    if (!fileHandle){
        cout << "Failed to open " + file_dir << endl;
        return 1;
    }

    //Get the song information

    for (int index = 0; index < 6; index++){
        switch (index){
            case 0:
                fileHandle >> title;
                break;
            case 1:
                fileHandle >> artist;
                break;
            case 2:
                fileHandle >> album;
                break;
            case 3:
                fileHandle >> run_time;
                break;
            case 4:
                fileHandle >> release_date;
                break;
            case 5:
                fileHandle >> url;
                break;
        }
    }
    //close the file
    fileHandle.close();
    return 0;
}


//Declaring the Track selection function
int track_select(int selected_genre){
    //Show new menu
    cout << "----------------------------TRACKLIST-----------------------------" << endl;

    //The input for the selected track
    int input;
    string song_file = "Error (line 161) song file not defined!\n";
    string file_dir = "Error (line 162) file directory not defined\n";

    //If the genre is Chill
    if (selected_genre == 1){
        //Setting file directory
        file_dir = CHILL_FOLDER_PATH;
        
        
        //Prompts
        list_dir(file_dir);
        // cout << "TRACKLIST:" << endl;
        // cout << "1. First Chill Song" << endl;
        // cout << "2. Second Chill Song" << endl;
        // cout << "3. Third Chill Song" << endl;
        // cout << "4. Fourth Chill Song" << endl;
        // cout << "5. Fifth Chill Song" << endl;
        // cout << "6. Cancel" << endl;

        //Get the input
        cout << "Input: ";
        cin >> input;

        //testing the input
        switch (input){
            case 1:
                cout << "Selected chill 1 \n";
                song_file = first_song_file;
                break;
            case 2:
                cout << "Selected chill 2 \n";
                song_file = second_song_file;
                break;
            case 3:
                cout << "Selected chill 3 \n";
                song_file = third_song_file;
                break;
            case 4:
                cout << "Selected chill 4 \n";
                song_file = fourth_song_file;
                break;
            case 5:
                cout << "Selected chill 5 \n";
                song_file = fifth_song_file;
                break;
            case 6:
                cout << "\nCancelled. Returning to main menu" << endl;
                cancel = true;
                cout << "------------------------------------------------------------------\n\n\n\n" << endl;
                return 0;
                break;
            default:
                cout << "Invaild Track number!\n";
                return 1;
        }


    //If the genre is rock
    }else if (selected_genre == 2){
        //Setting file directory
        file_dir = ROCK_FOLDER_PATH;

        //Prompt
        list_dir(file_dir);
        // cout << "TRACKLIST:" << endl;
        // cout << "1. First Rock Song" << endl;
        // cout << "2. Second Rock Song" << endl;
        // cout << "3. Third Rock Song" << endl;
        // cout << "4. Fourth Rock Song" << endl;
        // cout << "5. Fifth Rock Song" << endl;
        // cout << "6. Cancel" << endl;

        //Get the input
        cout << "Input: ";
        cin >> input;

        //testing the input
        switch (input){
            case 1:
                cout << "Selected rock 1 \n";
                song_file = first_song_file;
                break;
            case 2:
                cout << "Selected rock 2 \n";
                song_file = second_song_file;
                break;
            case 3:
                cout << "Selected rock 3 \n";
                song_file = third_song_file;
                break;
            case 4:
                cout << "Selected rock 4 \n";
                song_file = fourth_song_file;
                break;
            case 5:
                cout << "Selected rock 5 \n";
                song_file = fifth_song_file;
                break;
            case 6:
                cout << "\nCancelled. Returning to main menu" << endl;
                cancel = true;
                cout << "------------------------------------------------------------------\n\n\n\n" << endl;
                return 0;
                break;
            default:
                cout << "Invaild Track number!\n";
                return 1;
        }
    }

    

    //Load songs
    if (!cancel){       //Don't bother trying to load if cancelling
    
    //Show Loading
    cout << "------------------------------------------------------------------" << endl;
    cout << "----------------------------Loading-------------------------------" << endl;

    cout << "Loading songs from " << file_dir + "\\" + song_file << endl;

    //Combine directory and file name and test if loads
    if (load_song(file_dir + "\\" + song_file) == 0){
            cout << "Loaded song successfully\n" << endl;
            return 0;
        }else{
            //If song fail to load, end the program
            cout << "Failed to load song\n" << endl;
            return 1;
        }
    }
    
    return 0;

}

//List the songs and order them
void list_dir(string directory){
    DIR * dir;
    struct dirent* entry;
    dir = opendir (directory.c_str());


    cout << "Please select your song: " << endl;

    //Loop through
    for(int i=0; i<7; i++){

        entry=readdir(dir); 

        //Order Songs
        switch (i){
            case 2:
                first_song_file = ("%s\n",entry->d_name);
                cout << i - 1 << ". ";
                printf("%s\n",entry->d_name);
                break;
            case 3:
                second_song_file = ("%s\n",entry->d_name);
                cout << i - 1 << ". ";
                printf("%s\n",entry->d_name);
                break;
            case 4:
                third_song_file = ("%s\n",entry->d_name);
                cout << i - 1 << ". ";
                printf("%s\n",entry->d_name);
                break;
            case 5:
                fourth_song_file = ("%s\n",entry->d_name);
                cout << i - 1 << ". ";
                printf("%s\n",entry->d_name);
                break;
            case 6:
                fifth_song_file = ("%s\n",entry->d_name);
                cout << i - 1 << ". ";
                printf("%s\n",entry->d_name);
                break;
        }
        
    }
    cout << "6. Cancel" << endl;
}

//Declaring the genre selection function
int open_genre(int selection){

    //check the selection variable for the genre selection and confirms it
    switch (selection){

        case 1:

            //Call and then check if track select failed. if so, end the program
            if (track_select(selection) == 1){
                return 1;
            }

            if (!cancel){
                //Print the info
                cout << "The song title is: " << title << endl;            //I have the file dir and I can read from the file
                cout << "The artist is: " << artist << endl;
                cout << "The album is: " << album << endl;
                cout << "The release date is: " << release_date << endl;
                cout << "The run time is: " << run_time << endl;
                cout << "You can listen to the song at: " << url << endl;
                cout << "------------------------------------------------------------------\n\n\n\n" << endl;
            }
            break;
        case 2:

            //Check if track select failed if so, end the program
            if (track_select(selection) == 1){
                return 1;
            }
            if (!cancel){
                //Print the info
                cout << "The song title is: " << title << endl;            //I have the file dir and I can read from the file
                cout << "The artist is: " << artist << endl;
                cout << "The album is: " << album << endl;
                cout << "The release date is: " << release_date << endl;
                cout << "The run time is: " << run_time << endl;
                cout << "You can listen to the song at: " << url << endl;
                cout << "------------------------------------------------------------------\n\n\n\n" << endl;
            }
            break;
        case 3:
            //Set quit variable to true
            cout << "Quitting program, see you again soon!\n" << endl;
            quit = true;
            break;
        default:
            cout << "Not a valid genre!\n";
            return 1;
    }

        return 0;
}

